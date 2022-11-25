/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-24 15:38:19
 * @Describe:
 */
#ifndef __BASE_LOG_H
#define __BASE_LOG_H

#include "rtc_base/logging.h"

#include <atomic>
#include <fstream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
namespace xrtc {
class XrtcLog : public rtc::LogSink {
  public:
    XrtcLog(const std::string& log_dir,
            const std::string& log_name,
            const std::string& log_level);

    ~XrtcLog() override;

    int init();
    void setLogToStderr(bool on);
    bool start();
    void stop();
    void join(); 
    void OnLogMessage(const std::string& message,
                      rtc::LoggingSeverity severity) override;
    void OnLogMessage(const std::string& message) override;

  private:
    std::string _log_dir;
    std::string _log_name;
    std::string _log_level;
    std::string _log_file;
    std::string _log_file_wf;

    // 输出的文件
    std::ofstream _out_file;
    std::ofstream _out_file_wf;

    // 输出时使用的队列
    std::queue<std::string> _log_queue;
    std::mutex _mtx;
    std::queue<std::string> _log_wf_queue;
    std::mutex _mtx_wf;

    // 定时线程用于写入到日志文件中去
    std::thread* _thread = nullptr;
    std::atomic<bool> _running{false};
};
} // namespace xrtc

#endif