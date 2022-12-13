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

std::string PeerConnection::create_offer() {
    _local_desc = std::make_unique<SessionDescription>(SdpType::k_offer);

    return _local_desc->to_string();
}
}