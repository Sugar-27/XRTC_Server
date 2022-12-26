/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 21:48:31
 * @Describe:
 */
#ifndef __RTC_STREAM_MANAGER_H
#define __RTC_STREAM_MANAGER_H

#include "base/event_loop.h"
#include "rtc_base/rtc_certificate.h"
#include "stream/push_stream.h"

#include <cstdint>
#include <string>
#include <unordered_map>
namespace xrtc {
class PushStream;

class RtcStreamManager {
  public:
    RtcStreamManager(EventLoop* el);
    ~RtcStreamManager();

    int create_push_stream(uint64_t uid,
                           const std::string& stream_name,
                           bool audio,
                           bool video,
                           uint32_t log_id,
                           rtc::RTCCertificate* certificate,
                           std::string& offer);
    PushStream* find_push_stream(const std::string& stream_name);

  private:
    EventLoop* _el;
    std::unordered_map<std::string, PushStream*> _push_streams;
};
} // namespace xrtc

#endif