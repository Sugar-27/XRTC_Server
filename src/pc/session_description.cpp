/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-13 23:02:20
 * @Describe:
 */

#include "pc/session_description.h"

#include "pc/codec_info.h"
#include "rtc_base/logging.h"
#include "rtc_base/ssl_fingerprint.h"

#include <memory>
#include <sstream>
#include <string>
#include <vector>
namespace xrtc {
const char k_media_protocol_dtls_savpf[] = "UDP/TLS/RTP/SAVPF"; // 加密
const char k_media_protocol_savpf[] = "RTP/SAVPF";              // 不加密

AudioContentDescription::AudioContentDescription() {
    auto codec = std::make_shared<AudioCodecInfo>();
    codec->id = 111;
    codec->name = "opus";
    codec->clockrate = 48000;
    codec->channels = 2;

    // add feedback param
    codec->feedback_param.push_back(FeedbackParam("transport-cc"));

    // add codec param
    codec->codec_param["minptime"] = "10";
    codec->codec_param["useinbandfec"] = "1";

    _codecs.push_back(codec);
}

VideoContentDescription::VideoContentDescription() {
    auto codec = std::make_shared<VideoCodecInfo>();
    codec->id = 107;
    codec->name = "H264";
    codec->clockrate = 90000;

    // add feedback param
    codec->feedback_param.push_back(FeedbackParam("goog-remb"));
    codec->feedback_param.push_back(FeedbackParam("transport-cc"));
    codec->feedback_param.push_back(FeedbackParam("ccm", "fir"));
    codec->feedback_param.push_back(FeedbackParam("nack"));
    codec->feedback_param.push_back(FeedbackParam("nack", "pli"));

    // add codec param
    codec->codec_param["level-asymmetry-allowed"] = "1";
    codec->codec_param["packetization-mode"] = "1";
    codec->codec_param["profile-level-id"] = "42e01";

    // rtx包用于重传
    auto rtx_codec = std::make_shared<VideoCodecInfo>();
    rtx_codec->id = 99;
    rtx_codec->name = "rtx";
    rtx_codec->clockrate = 90000;

    // add codec param
    rtx_codec->codec_param["apt"] = std::to_string(codec->id);

    _codecs.push_back(codec);
    _codecs.push_back(rtx_codec);
}

void ContentGroup::add_content_name(const std::string& content_name) {
    if (!has_content_name(content_name)) {
        _content_names.push_back(content_name);
    }
}

bool ContentGroup::has_content_name(const std::string& content_name) {
    for (auto name : _content_names) {
        if (name == content_name) {
            return true;
        }
    }
    return false;
}

SessionDescription::SessionDescription(SdpType type) : _sdp_type(type) {}

SessionDescription::~SessionDescription() {}

static void add_rtcp_fb_line(std::shared_ptr<CodecInfo> codec, std::stringstream& ss) {
    for (auto param : codec->feedback_param) {
        ss << "a=rtcp-fd:" << codec->id << " " << param.id();
        if (!param.param().empty()) {
            ss << " " << param.param();
        }
        ss << "\r\n";
    }
}

static void add_fmtpp_line(std::shared_ptr<CodecInfo> codec, std::stringstream& ss) {
    if (!codec->codec_param.empty()) {
        ss << "a=fmtp:" << codec->id << " ";
        std::string data;
        for (auto param : codec->codec_param) {
            data += (";" + param.first + "=" + param.second);
        }
        // data = ";key1=value1;key2=value2"
        data = data.substr(1);
        ss << data << "\r\n";
    }
}

static void build_rtp_map(std::shared_ptr<MediaContentDescription> content, std::stringstream& ss) {
    for (auto codec : content->get_codecs()) {
        ss << "a=rtpmap:" << codec->id << " " << codec->name << "/" << codec->clockrate;
        if (content->type() == MediaType::MEDIA_TYPE_AUDIO) {
            auto audio_codec = codec->as_audio();
            ss << "/" << audio_codec->channels;
        }
        ss << "\r\n";

        add_rtcp_fb_line(codec, ss);
        add_fmtpp_line(codec, ss);
    }
}

static void build_rtp_direction(std::shared_ptr<MediaContentDescription> content, std::stringstream& ss) {
    switch (content->direction()) {
    case RtpDirection::k_send_recv:
        ss << "a=sendrecv\r\n";
        break;
    case RtpDirection::k_send_only:
        ss << "a=sendonly\r\n";
        break;
    case RtpDirection::k_recv_only:
        ss << "a=recvonly\r\n";
        break;
    case RtpDirection::k_inactive:
        ss << "a=inactive\r\n";
        break;
    }
}

static std::string connection_role_to_string(ConnectionRole role) {
    switch (role) {
    case ConnectionRole::ACTIVE:
        return "active";
    case ConnectionRole::PASSIVE:
        return "passive";
    case ConnectionRole::ACTPASS:
        return "actpass";
    case ConnectionRole::HOLDCONN:
        return "holdconn";
    default:
        return "none";
    }
}

void SessionDescription::add_content(std::shared_ptr<MediaContentDescription> content) { _contents.push_back(content); }

void SessionDescription::add_group(const ContentGroup& group) { _content_groups.push_back(group); }

std::vector<const ContentGroup*> SessionDescription::get_group_by_name(const std::string& name) const {
    std::vector<const ContentGroup*> content_groups;
    for (const ContentGroup& group : _content_groups) {
        if (group.semantics() == name) {
            content_groups.push_back(&group);
        }
    }

    return content_groups;
}

bool SessionDescription::add_transport_info(const std::string& mid,
                                            const IceParameters& ice_param,
                                            rtc::RTCCertificate* certificate) {
    auto tdesc = std::make_shared<TransportDescription>();
    tdesc->mid = mid;
    tdesc->ice_ufrag = ice_param.ice_ufrag;
    tdesc->ice_pwd = ice_param.ice_pwd;
    if (certificate) {
        tdesc->identity_fingerprint = rtc::SSLFingerprint::CreateFromCertificate(*certificate);
        if (!tdesc->identity_fingerprint) {
            RTC_LOG(LS_WARNING) << "get fingerprint failed";
            return false;
        }
    }

    if (_sdp_type == SdpType::k_offer) {
        tdesc->connection_role = ConnectionRole::ACTPASS;
    } else {
        tdesc->connection_role = ConnectionRole::ACTIVE;
    }

    _transport_infos.push_back(tdesc);

    return true;
}

std::shared_ptr<TransportDescription> SessionDescription::get_transport_info(const std::string& mid) {
    for (auto tdesc : _transport_infos) {
        if (tdesc->mid == mid) {
            return tdesc;
        }
    }

    return nullptr;
}

bool SessionDescription::is_bundle(const std::string &mid) {
    auto content_group = get_group_by_name("BUNDLE");
    if (content_group.empty()) {
        return false;
    }

    for (auto group : content_group) {
        for (auto name : group->content_names()) {
            if (name == mid) {
                return true;
            }
        }
    }

    return false;
}

std::string SessionDescription::get_first_bundle_mid() {
    auto content_group = get_group_by_name("BUNDLE");
    if (content_group.empty()) {
        return "";
    }

    return content_group[0]->content_names()[0];
}

std::string SessionDescription::to_string() {
    std::stringstream ss;
    // 第一行：version
    ss << "v=0\r\n";
    // session origin
    // RFC 4566
    // o=<username> <sess-id> <sess-version> <nettype> <addrtype> <unicast-address>
    ss << "o=- 0 2 IN IP4 127.0.0.1\r\n";
    // session name
    ss << "s=-\r\n";
    // time description
    ss << "t=0 0\r\n";

    // BUNDLE
    auto content_group = get_group_by_name("BUNDLE");
    if (!content_group.empty()) {
        ss << "a=group:BUNDLE";
        for (auto group : content_group) {
            for (auto content_name : group->content_names()) {
                ss << " " << content_name;
            }
        }
        ss << "\r\n";
        // 写死
        ss << "a=msid-semantic: WMS\r\n";
        // RFC 4566
        // m=<media> <port> <proto> <fmt>
        for (auto content : _contents) {
            std::string fmt;
            for (auto codec : content->get_codecs()) {
                fmt.append(" ");
                fmt.append(std::to_string(codec->id));
            }

            ss << "m=" << content->mid() << " 9 " << k_media_protocol_dtls_savpf << fmt << "\r\n";

            // 写死
            ss << "c=IN IP4 0.0.0.0\r\n";
            ss << "a=rtcp:9 IN IP4 0.0.0.0\r\n";

            auto transport_info = get_transport_info(content->mid());
            if (transport_info) {
                ss << "a=ice-ufrag:" << transport_info->ice_ufrag << "\r\n";
                ss << "a=ice-pwd:" << transport_info->ice_pwd << "\r\n";

                auto fp = transport_info->identity_fingerprint.get();
                if (fp) {
                    ss << "a=fingerprint:" << fp->algorithm << " " << fp->GetRfc4572Fingerprint() << "\r\n";
                    ss << "a=setup:" << connection_role_to_string(transport_info->connection_role) << "\r\n";
                }
            }

            ss << "a=mid:" << content->mid() << "\r\n";

            if (content->rtcp_mux()) {
                ss << "a=rtcp-mux\r\n";
            }
            build_rtp_direction(content, ss);
            build_rtp_map(content, ss);
        }
    }

    return ss.str();
}
} // namespace xrtc