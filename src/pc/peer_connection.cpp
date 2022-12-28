/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:53:53
 * @Describe:
 */
#include "pc/peer_connection.h"

#include "base/event_loop.h"
#include "ice/ice_credentials.h"
#include "pc/session_description.h"
#include "pc/transport_controller.h"
#include "rtc_base/logging.h"

#include <memory>

namespace xrtc {
static RtpDirection get_direction(bool send, bool recv) {
    if (send && recv) {
        return RtpDirection::k_send_recv;
    } else if (send && !recv) {
        return RtpDirection::k_send_only;
    } else if (!send && recv) {
        return RtpDirection::k_recv_only;
    } else {
        return RtpDirection::k_inactive;
    }
}

PeerConnection::PeerConnection(EventLoop* el) : _el(el), _transport_controller(new TransportController(el)) {}

PeerConnection::~PeerConnection() {}

std::string PeerConnection::create_offer(const RtcOfferAnswerOptions& options) {
    if (options.dtls_on && !_certificate) {
        RTC_LOG(LS_WARNING) << "certificate is null";
        return "";
    }

    _local_desc = std::make_unique<SessionDescription>(SdpType::k_offer);

    IceParameters ice_param = IceCredentials::create_random_ice_credentials();

    if (options.recv_audio) { // 推送音频
        auto audio = std::make_shared<AudioContentDescription>();
        audio->set_direction(get_direction(options.send_audio, options.recv_audio));
        audio->set_rtcp_mux(options.use_rtcp_mux);
        _local_desc->add_content(audio);
        _local_desc->add_transport_info(audio->mid(), ice_param, _certificate);
    }

    if (options.recv_video) { // 推送视频
        auto video = std::make_shared<VideoContentDescription>();
        video->set_direction(get_direction(options.send_video, options.recv_video));
        video->set_rtcp_mux(options.use_rtcp_mux);
        _local_desc->add_content(video);
        _local_desc->add_transport_info(video->mid(), ice_param, _certificate);
    }

    if (options.use_rtp_mux) { // 通道服用，使用bundle进行传输，音视频使用一条传输通道
        ContentGroup offer_bundle("BUNDLE");
        for (auto content : _local_desc->contents()) {
            offer_bundle.add_content_name(content->mid());
        }

        if (!offer_bundle.content_names().empty()) {
            _local_desc->add_group(offer_bundle);
        }
    }

    _transport_controller->set_local_description(_local_desc.get());

    return _local_desc->to_string();
}

int PeerConnection::init(rtc::RTCCertificate* certificate) {
    _certificate = certificate;
    return 0;
}
} // namespace xrtc