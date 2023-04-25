cmake_minimum_required(VERSION 3.24)
project(privateLibrary)

set(CMAKE_CXX_STANDARD 17)

add_executable(privateLibrary test.cpp book.h book.cpp library.h library.cpp)
