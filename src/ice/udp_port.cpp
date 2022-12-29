/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-29 11:33:59
 * @Describe:
 */
#include "ice/udp_port.h"

#include "base/socket.h"
#include "rtc_base/logging.h"

#include <netinet/in.h>
#include <sys/socket.h>
namespace xrtc {
UDPPort::UDPPort(EventLoop* el,
                 const std::string& transport_name,
                 IceCandidateComponent component,
                 IceParameters ice_params)
    : _el(el), _transport_name(transport_name), _component(component), _ice_params(ice_params) {}

UDPPort::~UDPPort() {}

int UDPPort::create_ice_candidate(Network* network, int min_port, int max_port, Candidate& c) {
    _socket = create_udp_socket(network->ip().family());
    if (_socket < 0) {
        return -1;
    }

    if (sock_setnonblock(_socket) != 0) {
        return -1;
    }

    sockaddr_in addr_in;
    addr_in.sin_family = network->ip().family();
    addr_in.sin_addr = network->ip().ipv4_address();
    if (sock_bind(_socket, (struct sockaddr*)&addr_in, sizeof(sockaddr), min_port, max_port) != 0) {
        return -1;
    }

    int port = 0;
    if (sock_get_address(_socket, nullptr, &port) != 0) {
        return -1;
    }

    _local_addr.SetIP(network->ip());
    _local_addr.SetPort(port);

    RTC_LOG(LS_INFO) << "prepared socket address: " << _local_addr.ToString();

    return 0;
}
} // namespace xrtc