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

    return ss.str();
}
} // namespace xrtc