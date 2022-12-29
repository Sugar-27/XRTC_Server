/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-29 11:27:35
 * @Describe:
 */
#ifndef __UDP_PORT_H
#define __UDP_PORT_H

#include "base/event_loop.h"
#include "base/network.h"
#include "ice/candidate.h"
#include "ice/ice_credentials.h"
#include "ice/ice_def.h"
#include "rtc_base/socket_address.h"

#include <string>
namespace xrtc {
class UDPPort {
  public:
    UDPPort(EventLoop* el,
            const std::string& transport_name,
            IceCandidateComponent component,
            IceParameters ice_params);
    ~UDPPort();

    int create_ice_candidate(Network* network, int min_port, int max_port, Candidate& c);

  private:
    EventLoop* _el;
    std::string _transport_name;
    IceCandidateComponent _component;
    IceParameters _ice_params;
    int _socket = -1;
    rtc::SocketAddress _local_addr;
};
} // namespace xrtc

#endif