/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:53:02
 * @Describe:
 */
#ifndef __PEER_CONNECTION_H
#define __PEER_CONNECTION_H

#include "base/event_loop.h"
#include "ice/port_allocator.h"
#include "pc/session_description.h"
#include "pc/transport_controller.h"
#include "rtc_base/rtc_certificate.h"

#include <memory>
#include <string>
namespace xrtc {
struct RtcOfferAnswerOptions {
    bool send_audio = true;
    bool send_video = true;
    bool recv_audio = true;
    bool recv_video = true;
    bool use_rtp_mux = true;
    bool use_rtcp_mux = true;
    bool dtls_on = true;
};

class PeerConnection {
  public:
    PeerConnection(EventLoop* el, PortAllocator* allocator);
    ~PeerConnection();

    std::string create_offer(const RtcOfferAnswerOptions& options);
    int init(rtc::RTCCertificate* certificate);

  private:
    EventLoop* _el;
    std::unique_ptr<SessionDescription> _local_desc;
    rtc::RTCCertificate* _certificate = nullptr;
    std::unique_ptr<TransportController> _transport_controller;
};
} // namespace xrtc

#endif