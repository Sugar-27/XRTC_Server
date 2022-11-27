/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-26 22:30:15
 * @Describe:
 */

#include "server/signaling_server.h"

#include "base/socket.h"
#include "rtc_base/logging.h"
#include "yaml-cpp/yaml.h"

#include <cstdio>
#include <iostream>
#include <string>

namespace xrtc {
SignalingServer::SignalingServer() {}

SignalingServer::~SignalingServer() {}

int SignalingServer::init(const char* conf_file) {
    if (!conf_file) {
        RTC_LOG(LS_WARNING) << "signaling server conf_file is null";
        return -1;
    }
    try {
        YAML::Node config = YAML::LoadFile(conf_file);
        RTC_LOG(LS_INFO) << "signaling server options: \n" << config;

        _options.host = config["host"].as<std::string>();
        _options.port = config["port"].as<int>();
        _options.worker_num = config["worker_num"].as<int>();
        _options.connection_timeout = config["connection_timeout"].as<int>();
    } catch (YAML::Exception& e) {
        RTC_LOG(LS_WARNING) << "catch a YAML exception, line:" << e.mark.line + 1
                            << ", column: " << e.mark.column + 1 << ", error" << e.msg;
    }

    // 创建TCP_Server
    _listen_fd = create_tcp_server(_options.host.c_str(), _options.port);

    return 0;
}
} // namespace xrtc