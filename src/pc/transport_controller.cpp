/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-28 11:07:31
 * @Describe:
 */
#include "pc/transport_controller.h"

#include "base/event_loop.h"
#include "ice/ice_agent.h"
#include "ice/ice_def.h"
#include "rtc_base/logging.h"
#include <string>
namespace xrtc {
TransportController::TransportController(EventLoop* el) : _el(el), _ice_agent(new IceAgent(el)) {}

TransportController::~TransportController() {}

int TransportController::set_local_description(SessionDescription *desc) {
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
    }

    _ice_agent->gathering_candidate();

    return 0;
}
} // namespace xrtc