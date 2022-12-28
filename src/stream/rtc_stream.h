/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:09:05
 * @Describe: 推拉流的基类
 */
#ifndef __RTC_STREAM_H
#define __RTC_STREAM_H

#include "base/event_loop.h"
#include "ice/port_allocator.h"
#include "pc/peer_connection.h"
#include "rtc_base/rtc_certificate.h"

#include <cstdint>
#include <memory>
#include <string>
namespace xrtc {
class RtcStream {
  public:
    RtcStream(EventLoop* el, PortAllocator* allocator, uint64_t uid, const std::string& stream_name, bool audio, bool video, uint32_t log_id);
    virtual ~RtcStream();

    virtual std::string create_offer() = 0;
    int start(rtc::RTCCertificate* certificate);

  protected:
    EventLoop* el;
    uint64_t uid;
    std::string stream_name;
    bool audio;
    bool video;
    uint32_t log_id;

    std::unique_ptr<PeerConnection> pc;
    std::unique_ptr<PortAllocator> allocator;
};
} // namespace xrtc

#endif