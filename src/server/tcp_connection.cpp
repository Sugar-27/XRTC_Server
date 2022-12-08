/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-28 16:10:51
 * @Describe:
 */
#include "server/tcp_connection.h"
#include "rtc_base/sds.h"
namespace xrtc {
TcpConnection::TcpConnection(int fd) : fd(fd), querybuf(sdsempty()) {}
TcpConnection::~TcpConnection() {
    sdsfree(querybuf);
}
} // namespace xrtc