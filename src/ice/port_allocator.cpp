/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-28 21:49:29
 * @Describe:
 */
#include "ice/port_allocator.h"

#include "base/network.h"

#include <memory>
#include <vector>
namespace xrtc {
PortAllocator::PortAllocator() : _network_manager(std::make_unique<NetworkManager>()) {
    _network_manager->create_networks();
}

PortAllocator::~PortAllocator() = default;

const std::vector<Network*>& PortAllocator::get_networks() { return _network_manager->get_networks(); }
} // namespace xrtc