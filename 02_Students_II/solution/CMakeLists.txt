cmake_minimum_required(VERSION 3.9)
project(Assignment02)
 
 
#设定编译参数
set(CMAKE_CXX_STANDARD 11)
 
#设定源码列表.cpp
set(SOURCE_FILES ./main.cpp)
 
#生成可执行文件
add_executable(Assignment02   ${SOURCE_FILES} )
 
 
