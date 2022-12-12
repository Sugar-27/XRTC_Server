/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-27 22:50:12
 * @Describe:
 */

#include "server/signaling_worker.h"

#include "base/event_loop.h"
#include "base/socket.h"
#include "base/x_header.h"
#include "rtc_base/logging.h"
#include "rtc_base/sds.h"
#include "rtc_base/slice.h"
#include "server/rtc_server.h"
#include "server/signaling_server.h"
#include "server/tcp_connection.h"
#include "xrtcserver_def.h"

#include "json/config.h"
#include "json/value.h"
#include <cstdint>
#include <cstring>
#include <memory>
#include <mutex>
#include <thread>
#include <unistd.h>

extern xrtc::RtcServer* g_rtc_server;
namespace xrtc {
void signaling_worker_recv_notify(EventLoop* /*el*/, IOWatcher* /*w*/, int fd, int /*events*/, void* data) {
    int msg;
    if (read(fd, &msg, sizeof(int)) != sizeof(int)) {
        RTC_LOG(LS_WARNING) << "read from pipe error: " << strerror(errno) << ", errno: " << errno;
        return;
    }

    SignalingWorker* worker = (SignalingWorker*)data;
    worker->_process_notify(msg);
}

SignalingWorker::SignalingWorker(int worker_id, const SignalingServerOptions& options)
    : _worker_id(worker_id), _options(options), _el(new EventLoop(this)) {}

SignalingWorker::~SignalingWorker() {
    // 连接的清理要在Evenloop之前，否则close_conn时还要用到el
    for (auto c : _conns) {
        if (c) {
            _close_conn(c);
        }
    }
    _conns.clear();

    if (_el) {
        delete _el;
        _el = nullptr;
    }

    if (_thread) {
        delete _thread;
        _thread = nullptr;
    }
}

int SignalingWorker::init() {
    int fds[2];
    if (pipe(fds)) {
        RTC_LOG(LS_WARNING) << "create pipe error" << strerror(errno) << ", errno: " << errno;
        return -1;
    }

    _notify_recv_fd = fds[0];
    _notify_send_fd = fds[1];

    _pipe_watcher = _el->create_io_event(signaling_worker_recv_notify, this);
    _el->start_io_event(_pipe_watcher, _notify_recv_fd, EventLoop::READ);

    return 0;
}

bool SignalingWorker::start() {
    if (_thread) {
        RTC_LOG(LS_WARNING) << "signaling worker already start, worker_id: " << _worker_id;
        return false;
    }
    _thread = new std::thread([=]() {
        RTC_LOG(LS_INFO) << "signaling worker event loop start, worker_id: " << _worker_id;
        _el->start();
        RTC_LOG(LS_INFO) << "signaling worker event loop stop, worker_id: " << _worker_id;
    });
    return true;
}

void SignalingWorker::stop() { notify(SignalingWorker::QUIT); }

int SignalingWorker::notify(int msg) {
    int written = write(_notify_send_fd, &msg, sizeof(int));
    return written == sizeof(int) ? 0 : -1;
}

void SignalingWorker::join() {
    if (_thread && _thread->joinable()) {
        _thread->join();
    }
}

int SignalingWorker::notify_new_conn(int fd) {
    _q_conn.produce(fd);
    return notify(SignalingWorker::NEW_CONN);
}

int SignalingWorker::send_rtc_msg(std::shared_ptr<RtcMsg> msg) {
    push_msg(msg);
    return notify(RTC_MSG);
}

void SignalingWorker::push_msg(std::shared_ptr<RtcMsg> msg) {
    std::unique_lock<std::mutex> lock(_q_msg_mtx);
    _q_msg.push(msg);
}

std::shared_ptr<RtcMsg> SignalingWorker::pop_msg() {
    std::unique_lock<std::mutex> lock(_q_msg_mtx);
    if (_q_msg.empty()) {
        return nullptr;
    }
    auto msg = _q_msg.front();
    _q_msg.pop();
    return msg;
}

void SignalingWorker::_stop() {
    if (!_thread) {
        RTC_LOG(LS_WARNING) << "signaling worker not running, worker_id: " << _worker_id;
        return;
    }

    _el->delete_io_event(_pipe_watcher);
    _el->stop();

    close(_notify_recv_fd);
    close(_notify_send_fd);
}

void conn_io_cb(EventLoop* /*el*/, IOWatcher* /*w*/, int fd, int events, void* data) {
    SignalingWorker* worker = (SignalingWorker*)data;

    if (events & EventLoop::READ) {
        worker->_read_query(fd);
    }
}

void SignalingWorker::_process_timeout(TcpConnection* c) {
    if (_el->now() - c->last_interaction >= static_cast<unsigned long>(_options.connection_timeout)) {
        RTC_LOG(LS_INFO) << "connection timeout, fd: " << c->fd;
        _close_conn(c);
    }
}

// 定时器回调函数
void conn_timer_cb(EventLoop* el, TimerWatcher* /*w*/, void* data) {
    SignalingWorker* worker = static_cast<SignalingWorker*>(el->owner());
    TcpConnection* c = static_cast<TcpConnection*>(data);

    worker->_process_timeout(c);
}

void SignalingWorker::_new_conn(int fd) {
    RTC_LOG(LS_INFO) << "signaling worker " << _worker_id << ", receive fd: " << fd;

    if (fd < 0) {
        RTC_LOG(LS_WARNING) << "invalid fd: " << fd;
        return;
    }

    sock_setnonblock(fd);
    sock_setnodelay(fd);

    TcpConnection* c = new TcpConnection(fd);
    sock_peer_to_str(fd, c->ip, &(c->port));
    c->io_watcher = _el->create_io_event(conn_io_cb, this);
    _el->start_io_event(c->io_watcher, fd, EventLoop::READ);

    c->timer_watcher = _el->create_timer(conn_timer_cb, c, true);
    _el->start_timer(c->timer_watcher, 100000);

    c->last_interaction = _el->now();

    if ((size_t)fd >= _conns.size()) {
        _conns.resize(fd * 2, nullptr);
    }
    _conns[fd] = c;
}

void SignalingWorker::_read_query(int fd) {
    RTC_LOG(LS_INFO) << "signaling worker " << _worker_id << " receive read event, fd: " << fd;
    if (fd < 0 || (size_t)fd >= _conns.size()) {
        RTC_LOG(LS_WARNING) << "invalid fd: " << fd;
        return;
    }

    TcpConnection* c = _conns[fd];
    int nread = 0;                                       // 用于存放实际读取的大小
    int read_len = c->bytes_expected;                    // 期待读取的大小
    int qb_len = sdslen(c->querybuf);                    // buffer里已经有的大小
    c->querybuf = sdsMakeRoomFor(c->querybuf, read_len); // 扩充buffer可用空间大小
    nread = sock_read_data(fd, c->querybuf + qb_len, read_len);
    c->last_interaction = _el->now(); // 接收到数据，更新最后一次更新的时间
    RTC_LOG(LS_INFO) << "sock read data, len: " << nread;
    if (nread == -1) {
        _close_conn(c);
        return;
    } else if (nread > 0) {
        sdsIncrLen(c->querybuf, nread); // 变更读取的长度
    }

    int ret = _process_query_buffer(c);
    if (ret != 0) {
        _close_conn(c);
        return;
    }
}

void SignalingWorker::_close_conn(TcpConnection* c) {
    RTC_LOG(LS_INFO) << "close connection, fd: " << c->fd;
    close(c->fd);
    _remove_conn(c);
}

void SignalingWorker::_remove_conn(TcpConnection* c) {
    _el->delete_timer(c->timer_watcher);
    _el->delete_io_event(c->io_watcher);
    _conns[c->fd] = nullptr;
    delete c;
}

int SignalingWorker::_process_query_buffer(TcpConnection* c) {
    while (sdslen(c->querybuf) >= c->bytes_processed + c->bytes_expected) {
        // 数据已经读取完整了
        xhead_t* head = (xhead_t*)(c->querybuf);
        if (c->current_state == TcpConnection::STATE_HEAD) { // 读头部
            // 使用magic number判断合法性
            if (head->magic_num != XHEAD_MAGIC_NUM) {
                RTC_LOG(LS_WARNING) << "invalid data, fd: " << c->fd;
                return -1;
            }
            c->current_state = TcpConnection::STATE_BODY;
            c->bytes_processed = XHEAD_SIZE;
            c->bytes_expected = head->body_len;
        } else { // 读报文
            rtc::Slice header(c->querybuf, XHEAD_SIZE);
            rtc::Slice body(c->querybuf + XHEAD_SIZE, head->body_len);

            int ret = _process_request(c, header, body);
            if (ret != 0) {
                return -1;
            }

            // 假定是一个短连接请求，后续处理不考虑
            c->bytes_expected = 65535;
        }
    }
    return 0;
}

int SignalingWorker::_process_request(TcpConnection* c, const rtc::Slice& header, const rtc::Slice& body) {
    RTC_LOG(LS_INFO) << "receive body: " << body.data();

    xhead_t* xh = (xhead_t*)header.data();

    // 解析body数据
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    Json::Value root;
    JSONCPP_STRING err;
    reader->parse(body.data(), body.data() + body.size(), &root, &err);
    if (!err.empty()) {
        RTC_LOG(LS_WARNING) << "parse json body error: " << err << ", fd: " << c->fd << ", log_id: " << xh->log_id;
    }

    int cmdno;
    try {
        cmdno = root["cmdno"].asInt();
    } catch (const Json::Exception& e) {
        RTC_LOG(LS_WARNING) << "no cmdno field in body, log_id: " << xh->log_id;
        return -1;
    }

    switch (cmdno) {
    case CMDNO_PUSH:
        return _process_push(cmdno, c, root, xh->log_id);
    default:
        break;
    }

    return 0;
}

int SignalingWorker::_process_push(int cmdno, TcpConnection* c, const Json::Value& root, uint32_t log_id) {
    uint64_t uid;
    std::string stream_name;
    int audio;
    int video;

    try {
        uid = root["uid"].asUInt64();
        stream_name = root["stream_name"].asString();
        audio = root["audio"].asInt();
        video = root["video"].asInt();
    } catch (const Json::Exception& e) {
        RTC_LOG(LS_WARNING) << "parse json body error: " << e.what() << ", log_id: " << log_id;
        return -1;
    }

    RTC_LOG(LS_INFO) << "cmdno[" << cmdno << "], uid[" << uid << "], stream_name[" << stream_name << "], audio["
                     << audio << "], video[" << video << "] signaling server push request";

    std::shared_ptr<RtcMsg> msg = std::make_shared<RtcMsg>();
    msg->cmdno = cmdno;
    msg->uid = uid;
    msg->stream_name = stream_name;
    msg->audio = audio;
    msg->video = video;
    msg->log_id = log_id;
    msg->worker = this;
    msg->conn = c;

    // 全局xrtc指针用于消息队列传送消息
    return g_rtc_server->send_rtc_msg(msg);
}

void SignalingWorker::_response_server_offer(std::shared_ptr<RtcMsg> msg) {
    RTC_LOG(LS_WARNING) << "==========response server offer: " << msg->sdp;
}

void SignalingWorker::_process_rtc_msg() {
    auto msg = pop_msg();
    if (!msg) {
        return;
    }

    switch (msg->cmdno) {
    case CMDNO_PUSH:
        _response_server_offer(msg);
        break;
    default:
        RTC_LOG(LS_WARNING) << "unknown cmdno: " << msg->cmdno << ", log_id: " << msg->log_id;
    }
}

void SignalingWorker::_process_notify(int msg) {
    switch (msg) {
    case QUIT:
        _stop();
        break;
    case NEW_CONN:
        int fd;
        if (_q_conn.consume(&fd)) {
            _new_conn(fd);
        }
        break;
    case RTC_MSG:
        _process_rtc_msg();
        break;
    default:
        RTC_LOG(LS_WARNING) << "unknown msg: " << msg;
        break;
    }
}
} // namespace xrtc