/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-29 11:38:38
 * @Describe:
 */
#ifndef __CANDIDATE_H
#define __CANDIDATE_H

#include "ice/ice_def.h"
#include "rtc_base/socket_address.h"

#include <cstdint>
#include <string>
namespace xrtc {
class Candidate {
  public:
    uint32_t get_priority(uint32_t type_preference, int network_adapter_preference, int relay_preference);

  public:
    IceCandidateComponent component;
    std::string protocol;
    rtc::SocketAddress address;
    int port = 0;
    uint32_t priority;
    std::string username;
    std::string password;
    std::string type;
    std::string foundation;
};
} // namespace xrtc

#endif