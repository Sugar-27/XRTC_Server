/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-27 21:24:22
 * @Describe:
 */
#ifndef __ICE_TRANSPORT_CHANNEL_H
#define __ICE_TRANSPORT_CHANNEL_H

#include "base/event_loop.h"
#include "ice/ice_credentials.h"
#include "ice/ice_def.h"
#include "ice/port_allocator.h"

#include <string>
namespace xrtc {
class IceTransportChannel {
  public:
    IceTransportChannel(EventLoop* el, PortAllocator* allocator, const std::string& transport_name, IceCandidateComponent component);
    virtual ~IceTransportChannel();

    std::string transport_name() { return _transport_name; }
    IceCandidateComponent component() { return _component; }
    void gathering_candidate();
    void set_ice_params(const IceParameters& ice_params);

  private:
    EventLoop* _el;
    PortAllocator* _allocator;
    std::string _transport_name;
    IceCandidateComponent _component;
    IceParameters _ice_params;
};
} // namespace xrtc

#endif