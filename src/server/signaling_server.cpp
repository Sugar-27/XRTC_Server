/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-26 22:30:15
 * @Describe:
 */

#include "server/signaling_server.h"

#include "base/event_loop.h"
#include "base/socket.h"
#include "rtc_base/logging.h"
#include "server/signaling_worker.h"
#include "yaml-cpp/yaml.h"

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

namespace xrtc {
void signaling_server_recv_notify(EventLoop* el, IOWatcher* w, int fd, int events, void* data) {
    int msg;
    if (read(fd, &msg, sizeof(int)) != sizeof(int)) {
        RTC_LOG(LS_WARNING) << "read from pipe error: " << strerror(errno) << ", errno: " << errno;
        return;
    }

    SignalingServer* server = (SignalingServer*)data;
    server->_process_notify(msg);
}

void accept_new_conn(EventLoop* el, IOWatcher* w, int fd, int events, void* data) {}

SignalingServer::SignalingServer() : _el(new EventLoop(this)) {}

SignalingServer::~SignalingServer() {}

int SignalingServer::init(const char* conf_file) {
    if (!conf_file) {
        RTC_LOG(LS_WARNING) << "signaling server conf_file is null";
        return -1;
    }
    try {
        YAML::Node config = YAML::LoadFile(conf_file);
        RTC_LOG(LS_INFO) << "signaling server options: \n" << config;

        _options.host = config["host"].as<std::string>();
        _options.port = config["port"].as<int>();
        _options.worker_num = config["worker_num"].as<int>();
        _options.connection_timeout = config["connection_timeout"].as<int>();
    } catch (YAML::Exception& e) {
        RTC_LOG(LS_WARNING) << "catch a YAML exception, line:" << e.mark.line + 1 << ", column: " << e.mark.column + 1
                            << ", error" << e.msg;
    }

    // 创建管道，用于线程间通信
    int fds[2];
    if (pipe(fds)) {
        RTC_LOG(LS_WARNING) << "create pipe error: " << strerror(errno) << ", errno: " << errno;
        return -1;
    }
    _notify_recv_fd = fds[0];
    _notify_send_fd = fds[1];
    // 将recv_fd添加到时间循环，进行管理
    _pipe_watcher = _el->create_io_event(signaling_server_recv_notify, this);
    _el->start_io_event(_pipe_watcher, _notify_recv_fd, EventLoop::READ);

    // 创建TCP_Server
    _listen_fd = create_tcp_server(_options.host.c_str(), _options.port);
    if (_listen_fd == -1) {
        return -1;
    }
    _io_watcher = _el->create_io_event(accept_new_conn, this);
    _el->start_io_event(_io_watcher, _listen_fd, EventLoop::READ);

    // 创建worker
    for (int i = 0; i < _options.worker_num; ++i) {
        if (_create_worker(i) != 0) {
        }
    }

    return 0;
}

bool SignalingServer::start() {
    if (_thread) {
        // thread不为空说明之前已经start了
        RTC_LOG(LS_WARNING) << "signaling server already start";
        return false;
    }
    _thread = new std::thread([=]() {
        RTC_LOG(LS_INFO) << "signaling server event loop run";
        _el->start();
        RTC_LOG(LS_INFO) << "signaling server event loop run";
    });
    return true;
}

void SignalingServer::stop() { notify(SignalingServer::QUIT); }

int SignalingServer::notify(int msg) {
    int written = write(_notify_send_fd, &msg, sizeof(int));
    return written == sizeof(int) ? 0 : -1;
}

void SignalingServer::_process_notify(int msg) {
    switch (msg) {
    case QUIT:
        _stop();
        break;
    default:
        RTC_LOG(LS_WARNING) << "unknown msg: " << msg;
        break;
    }
}

void SignalingServer::_stop() {
    if (!_thread) {
        RTC_LOG(LS_WARNING) << "signaling server not running";
        return;
    }

    _el->delete_io_event(_pipe_watcher);
    _el->delete_io_event(_io_watcher);
    _el->stop();

    close(_notify_recv_fd);
    close(_notify_send_fd);
    close(_listen_fd);

    RTC_LOG(LS_INFO) << "signaling server stop";
}

int SignalingServer::_create_worker(int worker_id) {
    RTC_LOG(LS_INFO) << "create worker, worker_id: " << worker_id;
    SignalingWorker* worker = new SignalingWorker(worker_id);
    if (worker->init() != 0) {
        return -1;
    }

    if (!worker->start()) {
        return -1;
    }
    return 0;
}

void SignalingServer::join() {
    if (_thread && _thread->joinable()) {
        _thread->join();
    }
}
} // namespace xrtc