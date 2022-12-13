/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-28 16:10:51
 * @Describe:
 */
#include "server/tcp_connection.h"
#include "rtc_base/sds.h"
#include "rtc_base/slice.h"
#include "rtc_base/zmalloc.h"
namespace xrtc {
TcpConnection::TcpConnection(int fd) : fd(fd), querybuf(sdsempty()) {}
TcpConnection::~TcpConnection() {
    sdsfree(querybuf);

    while (!reply_list.empty()) {
        auto reply = reply_list.front();
        zfree((void*)reply.data());
        reply_list.pop_front();
    }
    reply_list.clear();
}
} // namespace xrtc