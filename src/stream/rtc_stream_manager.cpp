/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 21:49:41
 * @Describe:
 */

#include "stream/rtc_stream_manager.h"

#include "base/conf.h"
#include "base/event_loop.h"
#include "ice/port_allocator.h"
#include "rtc_base/rtc_certificate.h"
#include "stream/push_stream.h"
#include <memory>

extern xrtc::GeneralConf* g_conf;
namespace xrtc {
RtcStreamManager::RtcStreamManager(EventLoop* el) : _el(el), _allocator(std::make_unique<PortAllocator>()) {
    _allocator->set_port_range(g_conf->ice_min_port, g_conf->ice_max_port);
}

RtcStreamManager::~RtcStreamManager() {}

int RtcStreamManager::create_push_stream(uint64_t uid,
                                         const std::string& stream_name,
                                         bool audio,
                                         bool video,
                                         uint32_t log_id,
                                         rtc::RTCCertificate* certificate,
                                         std::string& offer) {
    auto stream = find_push_stream(stream_name);
    if (stream) {
        _push_streams.erase(stream_name);
        delete stream;
    }
    stream = new PushStream(_el, _allocator.get(), uid, stream_name, audio, video, log_id);
    stream->start(certificate);
    offer = stream->create_offer();

    return 0;
}

PushStream* RtcStreamManager::find_push_stream(const std::string& stream_name) {
    auto it = _push_streams.find(stream_name);
    if (it != _push_streams.end()) {
        return it->second;
    }

    return nullptr;
}
} // namespace xrtc