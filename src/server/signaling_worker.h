/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-27 22:47:50
 * @Describe:
 */
#ifndef __SIGNALING_WORKER_H
#define __SIGNALING_WORKER_H

#include "base/event_loop.h"

#include <thread>
namespace xrtc {
class SignalingWorker {
  public:
    SignalingWorker(int worker_id);
    ~SignalingWorker();

    int init();
    bool start();
    void stop();
    int notify(int msg);
    void join();

  public:
    enum { QUIT = 0 };
    friend void signaling_worker_recv_notify(EventLoop* el, IOWatcher* w, int fd, int events, void* data);

  private:
    void _process_notify(int msg);
    void _stop();

  private:
    int _worker_id;
    EventLoop* _el;
    IOWatcher* _pipe_watcher = nullptr;
    int _notify_recv_fd = -1;
    int _notify_send_fd = -1;

    std::thread* _thread = nullptr;
};
} // namespace xrtc

#endif