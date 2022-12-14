/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 23:02:20
 * @Describe:
 */

#include "pc/session_description.h"

#include <sstream>
#include <string>
namespace xrtc {
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
    ss << "t = 0 0\r\n";

    return ss.str();
}

void SessionDescription::add_content(std::shared_ptr<MediaContentDescription> content) { _contents.push_back(content); }
} // namespace xrtc