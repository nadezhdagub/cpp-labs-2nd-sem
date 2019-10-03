cmake_minimum_required(VERSION 3.10)
project(B2)

set(CMAKE_CXX_STANDARD 14)

add_executable(B2 main.cpp TextAnalize.hpp TextAnalize.cpp "TextFormatAndPrint.cpp" token.hpp format.hpp)

set(BOOST_ROOT "C:/boost_1_55_0")
find_package(Boost 1.55.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()