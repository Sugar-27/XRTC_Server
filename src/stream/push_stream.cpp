/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:23:30
 * @Describe:
 */
#include "stream/push_stream.h"

#include "pc/peer_connection.h"
#include "stream/rtc_stream.h"
namespace xrtc {
PushStream::PushStream(
    EventLoop* el, uint64_t uid, const std::string& stream_name, bool audio, bool video, uint32_t log_id)
    : RtcStream(el, uid, stream_name, audio, video, log_id) {}

PushStream::~PushStream() {}

std::string PushStream::create_offer() {
    RtcOfferAnswerOptions options;
    options.recv_audio = audio;
    options.recv_video = video;
    return pc->create_offer(options);
}
} // namespace xrtc