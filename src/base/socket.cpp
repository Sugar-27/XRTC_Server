/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-27 10:55:44
 * @Describe:
 */
#include "base/socket.h"

#include "rtc_base/logging.h"
#include "server/signaling_server.h"

#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>

namespace xrtc {
int create_tcp_server(const char* addr, int port) {
    // 1. 创建socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        RTC_LOG(LS_WARNING) << "create socket error, errno: " << errno
                            << ", error: " << strerror(errno);
        return -1;
    }

    // 2. 设置SO_REUSEADDR端口复用
    int on = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if (ret == -1) {
        RTC_LOG(LS_WARNING) << "setsockopt SO_REUSEADDR error, errno: " << errno
                            << ", error" << strerror(errno);
        close(sock);
        return -1;
    }

    // 3. 创建addr
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    if (addr && inet_aton(addr, &sa.sin_addr) == 0) {
        RTC_LOG(LS_WARNING) << "invalid address";
        close(sock);
        return -1;
    }

    // 4. bind
    ret = bind(sock, (struct sockaddr*)&sa, sizeof(sa));
    if (ret == -1) {
        RTC_LOG(LS_WARNING) << "bind error, errno" << errno << ", error: " << strerror(errno);
        close(sock);
        return -1;
    }

    // 5. listen
    ret = listen(sock, 4095);
    if (ret == -1) {
        RTC_LOG(LS_WARNING) << "listen error, errno" << errno << ", error: " << strerror(errno);
        close(sock);
        return -1;
    }

    return sock;
}
} // namespace xrtc