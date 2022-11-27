/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-24 11:38:02
 * @Describe:
 */

#ifndef __BASE_CONF_H
#define __BASE_CONF_H

#include <string>
namespace xrtc {
struct GeneralConf {
    std::string log_dir;
    std::string log_name;
    std::string log_level;
    bool log_to_stderr;
};

int load_general_conf(const char* filename, GeneralConf* conf);
} // namespace xrtc

#endif