cmake_minimum_required(VERSION 2.6)

project(EffectiveSTL CXX)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra")

# Boost is necessary for item 7.
#find_package(Boost REQUIRED)

add_subdirectory(utils)
#add_subdirectory(introduction)
#add_subdirectory(item01)
add_subdirectory(item02)
add_subdirectory(item03)
add_subdirectory(item04)
add_subdirectory(item05)
add_subdirectory(item06)
add_subdirectory(item07)
add_subdirectory(item08)
add_subdirectory(item09)
