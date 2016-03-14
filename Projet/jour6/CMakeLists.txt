cmake_minimum_required(VERSION 3.0)

project (cassebrique)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O0 -ggdb -Wall -Werror -std=c++14")

include_directories(src)
add_subdirectory (src) 

# tests

enable_testing()

include_directories(test)
add_subdirectory (test) 

