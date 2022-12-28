/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-27 21:18:08
 * @Describe:
 */
#ifndef __ICE_AGENT_H
#define __ICE_AGENT_H

#include "base/event_loop.h"
#include "ice/ice_def.h"
#include "ice/ice_transport_channel.h"

#include <string>
#include <vector>
namespace xrtc {
class IceAgent {
  public:
    IceAgent(EventLoop* el);
    ~IceAgent();

    bool create_channel(EventLoop* el, const std::string& transport_name, IceCandidateComponent component);
    IceTransportChannel* get_channel(const std::string& transport_name, IceCandidateComponent component);
    void gathering_candidate();

  private:
    std::vector<IceTransportChannel*>::iterator _get_channel(const std::string& transport_name,
                                                             IceCandidateComponent component);

  private:
    EventLoop* _el;
    std::vector<IceTransportChannel*> _channels;
};
} // namespace xrtc

#endif