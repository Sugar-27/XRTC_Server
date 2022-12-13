/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 23:00:36
 * @Describe:
 */
#ifndef __SESSION_DESCRIPTION_H
#define __SESSION_DESCRIPTION_H

#include <string>
namespace xrtc {
enum class SdpType {
    k_offer = 0,
    k_answer = -1,
};

class SessionDescription {
  public:
    SessionDescription(SdpType type);
    ~SessionDescription();

    std::string to_string();

  private:
    SdpType _sdp_type;
};
} // namespace xrtc

#endif