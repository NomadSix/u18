cmake_minimum_required(VERSION 3.12)
project(hm03)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(Sources src/Album.cpp src/main.cpp src/Rando.cpp)
set(Headers src/Album.hpp src/List.hpp src/List.I src/Rando.hpp src/Reverse_Iterator.I src/test_interface.hpp)
include_directories( ${MY_SOURCE_DIR}/src )

add_executable(hm03 ${Sources} ${Headers})
