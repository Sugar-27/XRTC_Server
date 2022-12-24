/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-24 19:56:58
 * @Describe:
 */
#ifndef __ICE_CREDENTIALS_H
#define __ICE_CREDENTIALS_H

#include <string>

namespace xrtc {
struct IceParameters {
    IceParameters() = default;
    IceParameters(const std::string& ufrag, const std::string& pwd) : ice_ufrag(ufrag), ice_pwd(pwd) {}

    std::string ice_ufrag;
    std::string ice_pwd;
};

class IceCredentials {
    public:
    static IceParameters create_random_ice_credentials();
};
} // namespace xrtc

#endif