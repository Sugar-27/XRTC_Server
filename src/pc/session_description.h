/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 23:00:36
 * @Describe:
 */
#ifndef __SESSION_DESCRIPTION_H
#define __SESSION_DESCRIPTION_H

#include "pc/codec_info.h"

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

    const std::vector<std::shared_ptr<CodecInfo>>& get_codecs() const { return _codecs; }

  protected:
    std::vector<std::shared_ptr<CodecInfo>> _codecs;
};

class AudioContentDescription : public MediaContentDescription {
  public:
    AudioContentDescription();
    MediaType type() override { return MediaType::MEDIA_TYPE_AUDIO; }
    std::string mid() override { return "audio"; }
};

class VideoContentDescription : public MediaContentDescription {
  public:
    VideoContentDescription();
    MediaType type() override { return MediaType::MEDIA_TYPE_VIDEO; }
    std::string mid() override { return "video"; }
};

class ContentGroup {
  public:
    ContentGroup(const std::string& semantics) : _semantics(semantics) {}
    ~ContentGroup() {}

    std::string semantics() const { return _semantics; }
    const std::vector<std::string>& content_names() const { return _content_names; }
    void add_content_name(const std::string& content_name);
    bool has_content_name(const std::string& content_name);

  private:
    std::string _semantics;
    std::vector<std::string> _content_names;
};

class SessionDescription {
  public:
    SessionDescription(SdpType type);
    ~SessionDescription();

    std::string to_string();
    void add_content(std::shared_ptr<MediaContentDescription> content);
    void add_group(const ContentGroup& group);
    const std::vector<std::shared_ptr<MediaContentDescription>>& contents() const { return _contents; }
    std::vector<const ContentGroup*> get_group_by_name(const std::string& name) const;

  private:
    SdpType _sdp_type;
    std::vector<std::shared_ptr<MediaContentDescription>> _contents;
    std::vector<ContentGroup> _content_groups;
};
} // namespace xrtc

#endif