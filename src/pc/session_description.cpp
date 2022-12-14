/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 23:02:20
 * @Describe:
 */

#include "pc/session_description.h"

#include "pc/codec_info.h"

#include <memory>
#include <sstream>
#include <string>
#include <vector>
namespace xrtc {
const char k_media_protocol_dtls_savpf[] = "UDP/TLS/RTP/SAVPF"; // 加密
const char k_media_protocol_savpf[] = "RTP/SAVPF";              // 不加密

AudioContentDescription::AudioContentDescription() {
    auto codec = std::make_shared<AudioCodecInfo>();
    codec->id = 111;
    codec->name = "opus";
    codec->clockrate = 48000;
    codec->channels = 2;

    _codecs.push_back(codec);
}

VideoContentDescription::VideoContentDescription() {
    auto codec = std::make_shared<VideoCodecInfo>();
    codec->id = 107;
    codec->name = "H264";
    codec->clockrate = 90000;

    // rtx包用于重传
    auto rtx_codec = std::make_shared<VideoCodecInfo>();
    rtx_codec->id = 99;
    rtx_codec->name = "rtx";
    rtx_codec->clockrate = 90000;

    _codecs.push_back(codec);
    _codecs.push_back(rtx_codec);
}

void ContentGroup::add_content_name(const std::string& content_name) {
    if (!has_content_name(content_name)) {
        _content_names.push_back(content_name);
    }
}

bool ContentGroup::has_content_name(const std::string& content_name) {
    for (auto name : _content_names) {
        if (name == content_name) {
            return true;
        }
    }
    return false;
}

SessionDescription::SessionDescription(SdpType type) : _sdp_type(type) {}

SessionDescription::~SessionDescription() {}

std::string SessionDescription::to_string() {
    std::stringstream ss;
    // 第一行：version
    ss << "v=0\r\n";
    // session origin
    // RFC 4566
    // o=<username> <sess-id> <sess-version> <nettype> <addrtype> <unicast-address>
    ss << "o=- 0 2 IN IP4 127.0.0.1\r\n";
    // session name
    ss << "s=-\r\n";
    // time description
    ss << "t=0 0\r\n";

    // BUNDLE
    auto content_group = get_group_by_name("BUNDLE");
    if (!content_group.empty()) {
        ss << "a=group:BUNDLE";
        for (auto group : content_group) {
            for (auto content_name : group->content_names()) {
                ss << " " << content_name;
            }
        }
        ss << "\r\n";
        // 写死
        ss << "a=msid-semantic: WMS\r\n";
        // RFC 4566
        // m=<media> <port> <proto> <fmt>
        for (auto content : _contents) {
            std::string fmt;
            for (auto codec : content->get_codecs()) {
                fmt.append(" ");
                fmt.append(std::to_string(codec->id));
            }

            ss << "m=" << content->mid() << " 9 " << k_media_protocol_dtls_savpf << fmt << "\r\n";

            // 写死
            ss << "c=IN IP4 0.0.0.0\r\n";
            ss << "a=rtcp:9 IN IP4 0.0.0.0\r\n";
        }
    }

    return ss.str();
}

void SessionDescription::add_content(std::shared_ptr<MediaContentDescription> content) { _contents.push_back(content); }

void SessionDescription::add_group(const ContentGroup& group) { _content_groups.push_back(group); }

std::vector<const ContentGroup*> SessionDescription::get_group_by_name(const std::string& name) const {
    std::vector<const ContentGroup*> content_groups;
    for (const ContentGroup& group : _content_groups) {
        if (group.semantics() == name) {
            content_groups.push_back(&group);
        }
    }

    return content_groups;
}
} // namespace xrtc