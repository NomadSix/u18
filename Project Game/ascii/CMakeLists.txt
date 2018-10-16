cmake_minimum_required(VERSION 3.12)
project(ascii)

set(CMAKE_CXX_STANDARD 11)

add_executable(ascii src/main.cpp src/Items/Item.h src/Items/Item.cpp)