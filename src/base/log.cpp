/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-24 15:56:16
 * @Describe:
 */
#include "base/log.h"

#include "log.h"
#include "rtc_base/logging.h"

#include <asm-generic/errno-base.h>
#include <chrono>
#include <cstddef>
#include <cstdio>
#include <ios>
#include <iostream>
#include <mutex>
#include <sstream>
#include <sys/stat.h>
#include <thread>

namespace xrtc {
static rtc::LoggingSeverity getLogSeverity(const std::string& level) {
    if (level == "verbose") {
        return rtc::LS_VERBOSE;
    } else if (level == "info") {
        return rtc::LS_INFO;
    } else if (level == "warning") {
        return rtc::LS_WARNING;
    } else if (level == "error") {
        return rtc::LS_ERROR;
    } else {
        return rtc::LS_NONE;
    }
}

XrtcLog::XrtcLog(const std::string& log_dir,
                 const std::string& log_name,
                 const std::string& log_level)
    : _log_dir(log_dir),
      _log_name(log_name),
      _log_level(log_level),
      _log_file(log_dir + "/" + log_name + ".log"),
      _log_file_wf(log_dir + "/" + log_name + ".log.wf") {}

XrtcLog::~XrtcLog() {
    stop();
    _out_file.close();
    _out_file_wf.close();
}

void XrtcLog::setLogToStderr(bool on) { rtc::LogMessage::SetLogToStderr(on); }

int XrtcLog::init() {
    rtc::LogMessage::ConfigureLogging("thread tstamp");
    rtc::LogMessage::SetLogPathPrefix("/src");
    rtc::LogMessage::AddLogToStream(this, getLogSeverity(_log_level));

    int ret = mkdir(_log_dir.c_str(), 0755);
    if (ret != 0 && errno != EEXIST) {
        fprintf(stderr, "create log_dir[%s] failed\n", _log_dir.c_str());
        return -1;
    }

    // 打开文件
    _out_file.open(_log_file, std::ios::app);
    if (!_out_file.is_open()) {
        fprintf(stderr, "open log_file[%s] failed\n", _log_file.c_str());
        return -1;
    }

    _out_file_wf.open(_log_file_wf, std::ios::app);
    if (!_out_file_wf.is_open()) {
        fprintf(stderr, "open log_file[%s] failed\n", _log_file_wf.c_str());
        return -1;
    }

    return 0;
}

bool XrtcLog::start() {
    if (_running) {
        fprintf(stderr, "log thread already running\n");
        return false;
    }
    _running = true;
    _thread = new std::thread([=]() {
        struct stat stat_data;
        std::stringstream ss;
        while (_running) {
            // 检查日志文件是否被删除或移动
            if (stat(_log_file.c_str(), &stat_data) < 0) {
                _out_file.close();
                _out_file.open(_log_file, std::ios::app);
            }
            if (stat(_log_file_wf.c_str(), &stat_data) < 0) {
                _out_file_wf.close();
                _out_file_wf.open(_log_file_wf, std::ios::app);
            }
            bool write_log = false;
            {
                std::unique_lock<std::mutex> lock(_mtx);
                if (!_log_queue.empty()) {
                    write_log = true;
                    while (!_log_queue.empty()) {
                        ss << _log_queue.front();
                        _log_queue.pop();
                    }
                }
            }
            if (write_log) {
                _out_file << ss.str();
                _out_file.flush();
            }
            ss.str("");

            bool write_log_wf = false;
            {
                std::unique_lock<std::mutex> lock(_mtx_wf);
                if (!_log_wf_queue.empty()) {
                    write_log_wf = true;
                    while (!_log_wf_queue.empty()) {
                        ss << _log_wf_queue.front();
                        _log_wf_queue.pop();
                    }
                }
            }
            if (write_log_wf) {
                _out_file_wf << ss.str();
                _out_file_wf.flush();
            }
            ss.str("");

            std::this_thread::sleep_for(std::chrono::milliseconds(30));
        }
    });

    return true;
}

void XrtcLog::stop() {
    _running = false;

    if (!_thread) {
        return;
    }
    if (_thread->joinable()) {
        _thread->join();
    }

    delete _thread;
    _thread = nullptr;
}

void XrtcLog::join() {
    if (_thread && _thread->joinable()) {
        _thread->join();
    }
}

void XrtcLog::OnLogMessage(const std::string& message,
                           rtc::LoggingSeverity severity) {
    // 异步写入到队列中
    if (severity >= rtc::LS_WARNING) {
        std::unique_lock<std::mutex> lock(_mtx_wf);
        _log_wf_queue.push(message);
    } else {
        std::unique_lock<std::mutex> lock(_mtx);
        _log_queue.push(message);
    }
}

void XrtcLog::OnLogMessage(const std::string& /*message*/) {
    // 不需要实现，直接覆盖掉上面的函数，这个纯虚函数不会被调用
}

} // namespace xrtc