cmake_minimum_required(VERSION 3.9)
project(Assignment03)

# 设定编译参数
set(CMAKE_CXX_STANDARD 17)

# 设定源码列表.cpp
set(SOURCE_FILES ./main.cpp)

# 生成可执行文件
add_executable(Adventure ${SOURCE_FILES})
