/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-29 11:39:21
 * @Describe:
 */
#include "ice/candidate.h"

#include "rtc_base/ip_address.h"

#include <cstdint>
namespace xrtc {
uint32_t Candidate::get_priority(uint32_t type_preference, int network_adapter_preference, int relay_preference) {
    /*
    priority = (2 ^ 24) * (type preference) +
               (2 ^ 8) * (local preference) +
               (2 ^ 0) * (256 - component ID)
    */

    /*
    Local preference: 2 个字节
    0   1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    | NIC Pref      | Addr Pref     |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    NIC type：3G/wifi
    Addr pref: 定义在 RFC3484
    local preference = (NIC Type << 8 | Addr_Pref) + relay preference
    */
    int addr_ref = rtc::IPAddressPrecedence(address.ipaddr());
    int local_pref = (network_adapter_preference << 8) | addr_ref + relay_preference;
    return (type_preference << 24) | (local_pref << 8) | (256 - (int)component);
}
} // namespace xrtc