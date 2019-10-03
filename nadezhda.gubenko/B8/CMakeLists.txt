cmake_minimum_required(VERSION 3.10)
project(B8)

set(CMAKE_CXX_STANDARD 14)

add_executable(B8 main.cpp task.hpp circle.hpp circle.cpp shape.hpp shape.cpp square.hpp square.cpp triangle.hpp triangle.cpp firstItem.cpp secondItem.cpp)