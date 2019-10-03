cmake_minimum_required(VERSION 3.10)
project(B3)

set(CMAKE_CXX_STANDARD 11)

add_executable(B3 main.cpp task.hpp queueWithPriority.hpp firstItem.cpp secondItem.cpp)