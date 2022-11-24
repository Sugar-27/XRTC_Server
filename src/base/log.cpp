/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-24 15:56:16
 * @Describe:
 */
#include "base/log.h"

#include "rtc_base/logging.h"

#include <iostream>

namespace xrtc {
XrtcLog::XrtcLog(const std::string& log_dir,
                 const std::string& log_name,
                 const std::string& log_level)
    : _log_dir(log_dir),
      _log_name(log_name),
      _log_level(log_level) {}

XrtcLog::~XrtcLog() {}

void XrtcLog::OnLogMessage(const std::string& message,
                           rtc::LoggingSeverity severity) {
    std::cout << "======OnLogMessage: " << message;
}
void XrtcLog::OnLogMessage(const std::string& message) {
    // 不需要实现，直接覆盖掉上面的函数，这个纯虚函数不会被调用
}
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
int XrtcLog::init() {
    rtc::LogMessage::ConfigureLogging("thread tstamp");
    rtc::LogMessage::SetLogPathPrefix("/src");
    rtc::LogMessage::AddLogToStream(this, getLogSeverity(_log_level));
    return 0;
}
void XrtcLog::setLogToStderr(bool on) { rtc::LogMessage::SetLogToStderr(on); }
} // namespace xrtc