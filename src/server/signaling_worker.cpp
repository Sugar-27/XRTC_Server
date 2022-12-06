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
#include "server/signaling_server.h"
#include "server/tcp_connection.h"

#include <cstring>
#include <thread>
#include <unistd.h>
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

SignalingWorker::SignalingWorker(int worker_id) : _worker_id(worker_id), _el(new EventLoop(this)) {}

SignalingWorker::~SignalingWorker() {}

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
    close(c->fd);
    _remove_conn(c);
}

void SignalingWorker::_remove_conn(TcpConnection* c) {
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

    return 0;
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
    default:
        RTC_LOG(LS_WARNING) << "unknown msg: " << msg;
        break;
    }
}
} // namespace xrtc