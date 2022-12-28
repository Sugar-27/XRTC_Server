/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:23:30
 * @Describe:
 */
#include "stream/push_stream.h"

#include "ice/port_allocator.h"
#include "pc/peer_connection.h"
#include "stream/rtc_stream.h"
namespace xrtc {
PushStream::PushStream(EventLoop* el,
                       PortAllocator* allocator,
                       uint64_t uid,
                       const std::string& stream_name,
                       bool audio,
                       bool video,
                       uint32_t log_id)
    : RtcStream(el, allocator, uid, stream_name, audio, video, log_id) {}

PushStream::~PushStream() {}

std::string PushStream::create_offer() {
    RtcOfferAnswerOptions options;
    options.send_audio = false;
    options.send_video = false;
    options.recv_audio = audio;
    options.recv_video = video;
    return pc->create_offer(options);
}
} // namespace xrtc