/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:53:53
 * @Describe:
 */
#include "pc/peer_connection.h"

#include "base/event_loop.h"
#include "pc/session_description.h"

#include <memory>

namespace xrtc {
PeerConnection::PeerConnection(EventLoop* el) : _el(el) {}

PeerConnection::~PeerConnection() {}

std::string PeerConnection::create_offer(const RtcOfferAnswerOptions& options) {
    _local_desc = std::make_unique<SessionDescription>(SdpType::k_offer);

    if (options.recv_audio) { // 推送音频
        auto audio = std::make_shared<AudioContentDescription>();
        _local_desc->add_content(audio);
    }

    if (options.recv_video) { // 推送视频
        auto video = std::make_shared<VideoContentDescription>();
        _local_desc->add_content(video);
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

    return _local_desc->to_string();
}
} // namespace xrtc