/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:13:10
 * @Describe:
 */
#include "stream/rtc_stream.h"

#include "pc/peer_connection.h"
namespace xrtc {
RtcStream::RtcStream(
    EventLoop* el, uint64_t uid, const std::string& stream_name, bool audio, bool video, uint32_t log_id)
    : el(el),
      uid(uid),
      stream_name(stream_name),
      audio(audio),
      video(video),
      log_id(log_id),
      pc(new PeerConnection(el)) {}

RtcStream::~RtcStream() {}

int RtcStream::start(rtc::RTCCertificate *certificate) {
    return pc->init(certificate);
}
} // namespace xrtc