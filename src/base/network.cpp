/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-28 13:49:38
 * @Describe:
 */
#include "base/network.h"

#include "rtc_base/ip_address.h"
#include "rtc_base/logging.h"

#include <cerrno>
#include <cstddef>
#include <cstring>
#include <ifaddrs.h>
#include <sys/socket.h>
namespace xrtc {
NetworkManager::NetworkManager() = default;

NetworkManager::~NetworkManager() {
    for (auto network : _network_list) {
        delete network;
    }

    _network_list.clear();
}

int NetworkManager::create_networks() {
    struct ifaddrs* interface;
    int err = getifaddrs(&interface);
    if (err != 0) {
        RTC_LOG(LS_WARNING) << "getifaddrs error: " << strerror(errno) << ", errno: " << errno;
        return -1;
    }

    for (auto cur = interface; cur != nullptr; cur = cur->ifa_next) {
        if (cur->ifa_addr->sa_family != AF_INET) {
            // 过滤非IPV4的地址
            continue;
        }
        struct sockaddr_in* addr = (struct sockaddr_in*)(cur->ifa_addr);
        rtc::IPAddress ip_address(addr->sin_addr);

        // if (rtc::IPIsPrivateNetwork(ip_address) || rtc::IPIsLoopback(ip_address)) {
            if (rtc::IPIsLoopback(ip_address)) {
            // 过滤局域网的地址以及本地回环地址--由于腾讯云不支持，这里先不过滤局域网的地址，然后后面把局域网内的地址替换为公网ip
            continue;
        }

        Network* network = new Network(cur->ifa_name, ip_address);

        RTC_LOG(LS_INFO) << "gathered network interface: " << network->to_string();

        _network_list.push_back(network);
    }

    freeifaddrs(interface);

    return 0;
}
} // namespace xrtc