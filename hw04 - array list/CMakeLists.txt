cmake_minimum_required(VERSION 3.12)
project(hm04)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(Sources src/Album.cpp src/main.cpp)
set(Headers src/Album.hpp src/List.hpp src/test_interface.hpp src/Stack.hpp)
include_directories( ${MY_SOURCE_DIR}/src )

add_executable(hm04 ${Sources} ${Headers})