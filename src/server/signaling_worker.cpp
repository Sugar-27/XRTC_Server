/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-27 22:50:12
 * @Describe:
 */

#include "server/signaling_worker.h"

#include "base/event_loop.h"
#include "rtc_base/logging.h"
#include "server/signaling_server.h"

#include <cstring>
#include <thread>
#include <unistd.h>
namespace xrtc {
void signaling_worker_recv_notify(EventLoop* el, IOWatcher* w, int fd, int events, void* data) {
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

void SignalingWorker::_new_conn(int fd) {
    RTC_LOG(LS_INFO) << "signaling worker " << _worker_id << ", receive fd: " << fd;
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