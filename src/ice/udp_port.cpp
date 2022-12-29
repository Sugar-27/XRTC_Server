/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-29 11:33:59
 * @Describe:
 */
#include "ice/udp_port.h"
namespace xrtc {
UDPPort::UDPPort(EventLoop* el,
                 const std::string& transport_name,
                 IceCandidateComponent component,
                 IceParameters ice_params)
    : _el(el), _transport_name(transport_name), _component(component), _ice_params(ice_params) {}

UDPPort::~UDPPort() {}

int UDPPort::create_ice_candidate(Network* network, Candidate& c) { return 0; }
} // namespace xrtc