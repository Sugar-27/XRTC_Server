/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-28 11:07:31
 * @Describe:
 */
#include "pc/transport_controller.h"

#include "base/event_loop.h"
#include "ice/ice_agent.h"
#include "ice/ice_credentials.h"
#include "ice/ice_def.h"
#include "ice/port_allocator.h"
#include "rtc_base/logging.h"

#include <string>
namespace xrtc {
TransportController::TransportController(EventLoop* el, PortAllocator* allocator)
    : _el(el), _ice_agent(new IceAgent(el, allocator)) {}

TransportController::~TransportController() {}

int TransportController::set_local_description(SessionDescription* desc) {
    if (!desc) {
        RTC_LOG(LS_WARNING) << "desc is null";
        return -1;
    }

    for (auto content : desc->contents()) {
        std::string mid = content->mid();
        if (desc->is_bundle(mid) && mid != desc->get_first_bundle_mid()) {
            continue;
        }

        _ice_agent->create_channel(_el, mid, IceCandidateComponent::RTP);
        auto td = desc->get_transport_info(mid);
        if (td) {
            _ice_agent->set_ice_params(mid, IceCandidateComponent::RTP, IceParameters(td->ice_ufrag, td->ice_pwd));
        }
    }

    _ice_agent->gathering_candidate();

    return 0;
}
} // namespace xrtc