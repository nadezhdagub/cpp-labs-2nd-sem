cmake_minimum_required(VERSION 3.10)
project(B4)

set(CMAKE_CXX_STANDARD 14)

add_executable(B4 main.cpp tasks.hpp notebook.hpp notebook.cpp firstItem.cpp interfaceOfNotebook.hpp interfaceOfNotebook.cpp factorialContainer.hpp factorialContainer.cpp secondItem.cpp)