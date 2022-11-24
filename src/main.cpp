/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-23 22:35:16
 * @Describe:
 */
#include "base/conf.h"

#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

xrtc::GeneralConf* g_conf = nullptr;

int init_general_conf(const char* filename) {
    if (!filename) {
        fprintf(stderr, "filename is nullptr\n");
        return -1;
    }

    g_conf = new xrtc::GeneralConf();

    int ret = xrtc::load_general_conf(filename, g_conf);
    if (ret != 0) {
        fprintf(stderr, "load %s config file failed\n", filename);
        return -1;
    }

    return 0;
}

int main() { 
    int ret = init_general_conf("./conf/general.yaml");
    if (ret != 0) {
        return -1;
    }
    
    return 0; }
