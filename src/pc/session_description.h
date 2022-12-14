/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 23:00:36
 * @Describe:
 */
#ifndef __SESSION_DESCRIPTION_H
#define __SESSION_DESCRIPTION_H

#include <memory>
#include <string>
#include <vector>
namespace xrtc {
enum class SdpType {
    k_offer = 0,
    k_answer = 1,
};

enum class MediaType { MEDIA_TYPE_AUDIO, MEDIA_TYPE_VIDEO };

class MediaContentDescription {
  public:
    virtual ~MediaContentDescription() {}
    virtual MediaType type() = 0;
    virtual std::string mid() = 0;
};

class AudioContentDescription : public MediaContentDescription {
  public:
    MediaType type() override { return MediaType::MEDIA_TYPE_AUDIO; }
    std::string mid() override { return "audio"; }
};

class VideoContentDescription : public MediaContentDescription {
  public:
    MediaType type() override { return MediaType::MEDIA_TYPE_VIDEO; }
    std::string mid() override { return "video"; }
};

class SessionDescription {
  public:
    SessionDescription(SdpType type);
    ~SessionDescription();

    std::string to_string();
    void add_content(std::shared_ptr<MediaContentDescription> content);

  private:
    SdpType _sdp_type;
    std::vector<std::shared_ptr<MediaContentDescription>> _contents;
};
} // namespace xrtc

#endif