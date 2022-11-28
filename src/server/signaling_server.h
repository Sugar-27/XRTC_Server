/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-26 22:25:08
 * @Describe:
 */
#ifndef __SIGNALING_SERVER_H
#define __SIGNALING_SERVER_H

#include "base/event_loop.h"

#include <string>
#include <thread>
#include <vector>

namespace xrtc {
class SignalingWorker;

struct SignalingServerOptions {
    std::string host;
    int port;
    int worker_num;
    int connection_timeout;
};

class SignalingServer {
  public:
    enum { QUIT = 0 };
    SignalingServer();
    ~SignalingServer();

    int init(const char* conf_file);
    bool start();
    void stop();
    int notify(int msg);
    void join();

  public:
    friend void signaling_server_recv_notify(EventLoop* el, IOWatcher* w, int fd, int events, void* data);

  private:
    void _process_notify(int msg);
    void _stop();
    int _create_worker(int worker_id);

  private:
    SignalingServerOptions _options;
    EventLoop* _el;
    IOWatcher* _io_watcher = nullptr;
    IOWatcher* _pipe_watcher = nullptr; // 线程中的通信管道，用于停止线程
    int _notify_recv_fd = -1;
    int _notify_send_fd = -1;
    std::thread* _thread = nullptr;

    int _listen_fd = -1;
    std::vector<SignalingWorker*> _works;
};

} // namespace xrtc

#endif