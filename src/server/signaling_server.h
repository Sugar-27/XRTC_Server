/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-26 22:25:08
 * @Describe:
 */
#ifndef __SIGNALING_SERVER_H
#define __SIGNALING_SERVER_H

#include <string>

namespace xrtc {
struct SignalingServerOptions {
    std::string host;
    int port;
    int worker_num;
    int connection_timeout;
};

class SignalingServer {
  public:
    SignalingServer();
    ~SignalingServer();

    int init(const char* conf_file);

  private:
    SignalingServerOptions _options;
};

} // namespace xrtc

#endif