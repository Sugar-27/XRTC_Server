/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 22:21:27
 * @Describe:
 */
#ifndef __PUSH_STREAM_H
#define __PUSH_STREAM_H

#include "ice/port_allocator.h"
#include "stream/rtc_stream.h"
namespace xrtc {
class PushStream : public RtcStream {
  public:
    PushStream(EventLoop* el,
               PortAllocator* allocator,
               uint64_t uid,
               const std::string& stream_name,
               bool audio,
               bool video,
               uint32_t log_id);
    ~PushStream() override;

    std::string create_offer() override;
};
} // namespace xrtc

#endif