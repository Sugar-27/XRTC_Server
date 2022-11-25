/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-23 22:35:16
 * @Describe:
 */
#include "base/conf.h"
#include "base/log.h"
#include "rtc_base/logging.h"

#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

xrtc::GeneralConf* g_conf = nullptr;
xrtc::XrtcLog* g_log = nullptr;

int init_general_conf(const char* filename) {
    if (!filename) {
        fprintf(stderr, "filename is nullptr\n");
        return -1;
    }

    g_conf = new xrtc::GeneralConf();

    int ret = xrtc::load_general_conf(filename, g_conf);
    if (ret != 0) {
        fprintf(stderr, "load %s config file failed\n", filename);
        return -1;
    }

    return 0;
}

int init_log(const std::string& log_dir,
             const std::string& log_name,
             std::string& log_level) {
    g_log = new xrtc::XrtcLog(log_dir, log_name, log_level);

    int ret = g_log->init();
    if (ret != 0) {
        fprintf(stderr, "init log failed\n");
        return -1;
    }
    g_log->start();

    return 0;
}

int main() {
    int ret = init_general_conf("./conf/general.yaml");
    if (ret != 0) {
        return -1;
    }

    ret = init_log(g_conf->log_dir, g_conf->log_name, g_conf->log_level);
    if (ret != 0) {
        return -1;
    }

    g_log->setLogToStderr(g_conf->log_to_stderr);

    RTC_LOG(LS_VERBOSE) << "hello, world!";
    RTC_LOG(LS_WARNING) << "xxxx";

    g_log->join();

    return 0;
}
