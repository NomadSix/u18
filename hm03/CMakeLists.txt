cmake_minimum_required(VERSION 3.12)
project(HW02)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
include_directories( ${MY_SOURCE_DIR}/src )
add_executable(HW02 src/main.cpp)
#add_executable(HW02 src/*.cpp)
