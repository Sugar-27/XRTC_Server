/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-12-28 13:44:47
 * @Describe:
 */
#ifndef __BASE_NETWORK_H
#define __BASE_NETWORK_H

#include "rtc_base/ip_address.h"

#include <string>
#include <vector>
namespace xrtc {
class Network {
  public:
    Network(const std::string& name, const rtc::IPAddress& ip) : _name(name), _ip(ip) {}
    ~Network() = default;

    const std::string& name() { return _name; }
    const rtc::IPAddress& ip() { return _ip; }

    std::string to_string() { return _name + ":" + _ip.ToString(); }

  private:
    std::string _name;
    rtc::IPAddress _ip;
};

class NetworkManager {
  public:
    NetworkManager();
    ~NetworkManager();

    int create_networks();
    const std::vector<Network*>& get_networks() { return _network_list; };

  private:
    std::vector<Network*> _network_list;
};
} // namespace xrtc

#endif