/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-04 22:22:48
 * @Describe: 
 */
#ifndef __BASE_XHEADER_H
#define __BASE_XHEADER_H

#include <cstdint>
namespace xrtc {
const int XHEAD_SIZE = 36;
const uint32_t XHEAD_MAGIC_NUM = 0xfb202202;

struct xhead_t {
    uint16_t id;
    uint16_t version;
    uint32_t log_id;
    char provider[16];
    uint32_t magic_num;
    uint32_t reserved;
    uint32_t body_len;
};
}

#endif