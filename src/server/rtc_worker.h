/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-09 21:22:11
 * @Describe:
 */
#ifndef __RTC_WORKER_H
#define __RTC_WORKER_H

#include "base/event_loop.h"
#include "base/lock_free_queue.h"
#include "server/rtc_server.h"
#include "stream/rtc_stream_manager.h"
#include <memory>
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
    int send_rtc_msg(std::shared_ptr<RtcMsg> msg);
    void push_msg(std::shared_ptr<RtcMsg> msg);
    bool pop_msg(std::shared_ptr<RtcMsg>* msg);

  public:
    friend void rtc_worker_recv_notify(EventLoop* /*el*/, IOWatcher* /*w*/, int fd, int /*events*/, void* data);

  private:
    void _process_notify(int msg);
    void _process_rtc_msg();
    void _process_push(std::shared_ptr<RtcMsg> msg);
    void _stop();

  private:
    int _worker_id;
    RtcServerOptions _options;
    EventLoop* _el;
    IOWatcher* _pipe_watcher = nullptr;

    int _notify_recv_fd = -1;
    int _notify_send_fd = -1;

    std::thread* _thread = nullptr;
    LockFreeQueue<std::shared_ptr<RtcMsg>> _q_msg;
    
    std::unique_ptr<RtcStreamManager> _rtc_stream_manager;
};
} // namespace xrtc

#endif