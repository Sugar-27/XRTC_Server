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

    void set_port_range(int min_port, int max_port);
    int min_port() { return _min_port; }
    int max_port() { return _max_port; }

  private:
    std::unique_ptr<NetworkManager> _network_manager;
    int _min_port = 0;
    int _max_port = 0;
};
} // namespace xrtc

#endif