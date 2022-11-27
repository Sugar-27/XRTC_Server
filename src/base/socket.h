/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-27 10:54:03
 * @Describe: 
 */
#ifndef __BASE_SOCKET_H
#define __BASE_SOCKET_H

#include <sys/socket.h>

namespace xrtc {
int create_tcp_server(const char* addr, int port);
}


#endif