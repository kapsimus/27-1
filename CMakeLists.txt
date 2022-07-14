cmake_minimum_required(VERSION 3.18)
project(27_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(27_1 src/main.cpp include/branch.h src/branch.cpp)
target_include_directories(27_1 PUBLIC include)
