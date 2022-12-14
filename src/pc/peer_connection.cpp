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

    if (options.recv_audio) {
        auto audio = std::make_shared<AudioContentDescription>();
        _local_desc->add_content(audio);
    }

    if (options.recv_video) {
        auto video = std::make_shared<VideoContentDescription>();
        _local_desc->add_content(video);
    }

    return _local_desc->to_string();
}
}