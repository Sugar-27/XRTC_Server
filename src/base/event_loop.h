/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-27 17:23:14
 * @Describe:
 */
#ifndef __BASE_EVENT_LOOP_H
#define __BASE_EVENT_LOOP_H

struct ev_loop;

namespace xrtc {
class EventLoop;
class IOWatcher;
class TimerWatcher;

typedef void (*io_cb_t)(EventLoop* e1, IOWatcher* w, int fd, int events, void* data);
typedef void (*time_cb_t)(EventLoop* el, TimerWatcher* w, void* data);

class EventLoop {
  public:
    EventLoop(void* owner);
    ~EventLoop();

    void start();
    void stop();

    // IOWatcher
    IOWatcher* create_to_event(io_cb_t cb, void* data);
    void start_io_event(IOWatcher* w, int fd, int mask);
    void stop_io_event(IOWatcher* w, int fd, int mask);
    void delete_io_event(IOWatcher* w);

    // TimerWatcher
    TimerWatcher* create_timer(time_cb_t cb, void* data, bool need_repeat);
    void start_timer(TimerWatcher* w, unsigned int usec);
    void stop_timer(TimerWatcher* w);
    void delete_timer(TimerWatcher* w);

  public:
    enum { READ = 0x1, WRITE = 0x2 };

  private:
    void* _owner;
    struct ev_loop* _loop;
};
} // namespace xrtc

#endif