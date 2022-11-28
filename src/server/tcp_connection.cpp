/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-28 16:10:51
 * @Describe:
 */
#include "server/tcp_connection.h"
namespace xrtc {
TcpConnection::TcpConnection(int fd) : fd(fd) {}
TcpConnection::~TcpConnection() {}
} // namespace xrtc