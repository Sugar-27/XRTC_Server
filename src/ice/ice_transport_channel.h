/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-27 21:24:22
 * @Describe:
 */
#ifndef __ICE_TRANSPORT_CHANNEL_H
#define __ICE_TRANSPORT_CHANNEL_H

#include "base/event_loop.h"
#include "ice/ice_def.h"

#include <string>
namespace xrtc {
class IceTransportChannel {
  public:
    IceTransportChannel(EventLoop* el, const std::string& transport_name, IceCandidateComponent component);
    virtual ~IceTransportChannel();

    std::string transport_name() { return _transport_name; }
    IceCandidateComponent component() { return _component; }
    void gathering_candidate();

  private:
    EventLoop* _el;
    std::string _transport_name;
    IceCandidateComponent _component;
};
} // namespace xrtc

#endif