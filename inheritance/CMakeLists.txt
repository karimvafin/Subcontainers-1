cmake_minimum_required(VERSION 3.17)
project(inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(inheritance main.cpp subcontainer.h subvector.h subforwardlist.h subvector.cpp subforwardlist.cpp)