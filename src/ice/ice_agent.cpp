/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-27 21:19:20
 * @Describe:
 */
#include "ice/ice_agent.h"

#include "base/event_loop.h"
#include "ice/ice_transport_channel.h"
#include "ice/port_allocator.h"
#include "rtc_base/logging.h"

#include <algorithm>
namespace xrtc {
IceAgent::IceAgent(EventLoop* el, PortAllocator* allocator) : _el(el), _allocator(allocator) {}
IceAgent::~IceAgent() {}

bool IceAgent::create_channel(EventLoop* el, const std::string& transport_name, IceCandidateComponent component) {
    if (get_channel(transport_name, component)) {
        return true;
    }

    auto channel = new IceTransportChannel(el, _allocator, transport_name, component);
    _channels.push_back(channel);

    return true;
}

IceTransportChannel* IceAgent::get_channel(const std::string& transport_name, IceCandidateComponent component) {
    auto iter = _get_channel(transport_name, component);
    return iter == _channels.end() ? nullptr : *iter;
}

void IceAgent::gathering_candidate() {
    for (auto channel : _channels) {
        channel->gathering_candidate();
    }
}

void IceAgent::set_ice_params(const std::string& transport_name,
                              IceCandidateComponent component,
                              const IceParameters& ice_params) {
    auto channel = get_channel(transport_name, component);
    if (channel) {
        channel->set_ice_params(ice_params);
    }
}

std::vector<IceTransportChannel*>::iterator IceAgent::_get_channel(const std::string& transport_name,
                                                                   IceCandidateComponent component) {
    return std::find_if(_channels.begin(), _channels.end(), [transport_name, component](IceTransportChannel* channel) {
        return channel->transport_name() == transport_name && channel->component() == component;
    });
}
} // namespace xrtc