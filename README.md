<!--
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-24 11:12:42
 * @Describe: 
-->
# XRTC_Server

这个是实时共享音视频系统的XRTC服务器部分

## 编译环境
CMake: VERSION 3.16
CPP: -std=gnu++14

## 文件目录
### out
CMake编译中间文件以及最后生成的二进制可执行文件（xrtcserver）
### conf
系统配置模块，包括系统配置文件（general.yaml）
### src
源代码模块，包含基础组件（base）以及main.cpp
### third_part
本项目使用的第三方库
系统配置解析库：[yaml-cpp](https://github.com/jbeder/yaml-cpp)
事件通知处理库：[libev](https://github.com/enki/libev)
LOG日志模块库增强：使用[absl]增强rtc_base/logging中的日志库
JSON序列化与反序列化库：[Jsoncpp](https://github.com/open-source-parsers/jsoncpp)