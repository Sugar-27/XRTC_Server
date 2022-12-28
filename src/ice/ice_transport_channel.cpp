/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-27 21:27:46
 * @Describe:
 */
#include "ice/ice_transport_channel.h"
#include "rtc_base/logging.h"
namespace xrtc {
IceTransportChannel::IceTransportChannel(EventLoop* el,
                                         const std::string& transport_name,
                                         IceCandidateComponent component)
    : _el(el), _transport_name(transport_name), _component(component) {
        RTC_LOG(LS_INFO) << "ice transport channel created, transport_name: " << _transport_name << ", component: " << _component;
    }

IceTransportChannel::~IceTransportChannel() {}

void IceTransportChannel::gathering_candidate() {
    
}
} // namespace xrtc