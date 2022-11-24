/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-24 15:38:19
 * @Describe:
 */
#ifndef __BASE_LOG_H
#define __BASE_LOG_H

#include "rtc_base/logging.h"

#include <string>
namespace xrtc {
class XrtcLog : public rtc::LogSink {
  public:
    XrtcLog(const std::string& log_dir,
            const std::string& log_name,
            const std::string& log_level);

    ~XrtcLog() override;

    void OnLogMessage(const std::string& message, rtc::LoggingSeverity severity) override;
    void OnLogMessage(const std::string& message) override;
    int init();
    void setLogToStderr(bool on);

  private:
    std::string _log_dir;
    std::string _log_name;
    std::string _log_level;
};
} // namespace xrtc

#endif