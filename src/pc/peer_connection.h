/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:53:02
 * @Describe:
 */
#ifndef __PEER_CONNECTION_H
#define __PEER_CONNECTION_H

#include "base/event_loop.h"
#include "pc/session_description.h"

#include <memory>
#include <string>
namespace xrtc {
struct RtcOfferAnswerOptions {
    bool recv_audio = true;
    bool recv_video = true;
};

class PeerConnection {
  public:
    PeerConnection(EventLoop* el);
    ~PeerConnection();

    std::string create_offer(const RtcOfferAnswerOptions& options);

  private:
    EventLoop* _el;

    std::unique_ptr<SessionDescription> _local_desc;
};
} // namespace xrtc

#endif