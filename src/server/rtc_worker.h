/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-09 21:22:11
 * @Describe:
 */
#ifndef __RTC_WORKER_H
#define __RTC_WORKER_H

#include "base/event_loop.h"
#include "server/rtc_server.h"
#include <thread>
namespace xrtc {
class RtcWorker {
  public:
    enum { QUIT = 0, RTC_MSG = 1 };

  public:
    RtcWorker(int worker_id, const RtcServerOptions& options);
    ~RtcWorker();

    int init();
    bool start();
    void stop();
    void join();
    int notify(int msg);

  public:
    friend void rtc_worker_recv_notify(EventLoop* /*el*/, IOWatcher* /*w*/, int fd, int /*events*/, void* data);

  private:
    void _process_notify(int msg);
    void _stop();

  private:
    int _worker_id;
    RtcServerOptions _options;
    EventLoop* _el;
    IOWatcher* _pipe_watcher = nullptr;
    std::thread* _thread = nullptr;
    int _notify_recv_fd = -1;
    int _notify_send_fd = -1;
};
} // namespace xrtc

#endif