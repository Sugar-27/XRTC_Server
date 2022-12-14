/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-14 19:18:00
 * @Describe:
 */
#ifndef __CODEC_INFO_H
#define __CODEC_INFO_H

#include <string>
namespace xrtc {
class CodecInfo {
  public:
    int id;
    std::string name;
    int clockrate; // 支持的频率
};

class AudioCodecInfo : public CodecInfo {
  public:
    int channels;
};

class VideoCodecInfo : public CodecInfo {};
} // namespace xrtc

#endif