/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-28 21:44:19
 * @Describe:
 */
#ifndef __PORT_ALLOCATOR_H
#define __PORT_ALLOCATOR_H

#include "base/network.h"
#include <memory>
#include <vector>
namespace xrtc {
class PortAllocator {
  public:
    PortAllocator();
    ~PortAllocator();

    const std::vector<Network*>& get_networks();

  private:
    std::unique_ptr<NetworkManager> _network_manager;
};
} // namespace xrtc

#endif