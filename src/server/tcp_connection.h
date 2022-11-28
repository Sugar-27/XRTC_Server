/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-28 16:09:31
 * @Describe:
 */
#ifndef __TCP_CONNECTION_H
#define __TCP_CONNECTION_H

#include "base/event_loop.h"
namespace xrtc {
class TcpConnection {
  public:
    TcpConnection(int fd);
    ~TcpConnection();

  public:
    int fd;
    char ip[64];
    int port;
    IOWatcher* io_watcher = nullptr;
};
} // namespace xrtc

#endif