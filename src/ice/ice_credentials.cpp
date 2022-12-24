/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-24 20:00:21
 * @Describe:
 */

#include "ice/ice_credentials.h"

#include "ice/ice_def.h"
#include "rtc_base/helpers.h"
namespace xrtc {
IceParameters IceCredentials::create_random_ice_credentials() {
    return IceParameters(rtc::CreateRandomString(ICE_UFRAG_LENGTH), rtc::CreateRandomString(ICE_PWD_LENGTH));
}
} // namespace xrtc