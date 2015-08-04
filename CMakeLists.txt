cmake_minimum_required(VERSION 2.8)
project (static_test)

set (CMAKE_CXX_FLAGS "-std=c++11")

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -fno-inline")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

add_library(a SHARED a.cpp a.h externs.h)
add_library(inst SHARED inst.cpp)

target_link_libraries(a inst)

add_executable(static_test test.cpp)

target_link_libraries(static_test a inst)
