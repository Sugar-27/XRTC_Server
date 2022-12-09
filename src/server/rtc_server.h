/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-09 10:48:55
 * @Describe:
 */
#ifndef __RTC_SERVER_H
#define __RTC_SERVER_H

#include "base/event_loop.h"
#include "xrtcserver_def.h"

#include <memory>
#include <mutex>
#include <queue>
#include <thread>
namespace xrtc {
struct RtcServerOptions {
    int worker_num;
};

class RtcServer {
  public:
    enum { QUIT = 0, RTC_MSG = 1 };

    RtcServer();
    ~RtcServer();

    int init(const char* conf_file);
    bool start();
    void stop();
    int notify(int msg);
    void join();
    int send_rtc_msg(std::shared_ptr<RtcMsg> msg);
    void push_msg(std::shared_ptr<RtcMsg> msg);
    std::shared_ptr<RtcMsg> pop_msg();

  public:
    friend void rtc_server_recv_notify(EventLoop*, IOWatcher*, int, int, void*);

  private:
    void _process_notify(int msg);
    void _process_rtc_msg();
    void _stop();

  private:
    EventLoop* _el;
    RtcServerOptions _options;

    std::thread* _thread = nullptr;
    std::queue<std::shared_ptr<RtcMsg>> _q_msg;
    std::mutex _q_msg_mtx;

    IOWatcher* _pipe_watcher = nullptr;
    int _notify_recv_fd = -1;
    int _notify_send_fd = -1;
};
} // namespace xrtc

#endif