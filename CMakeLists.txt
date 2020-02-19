cmake_minimum_required(VERSION 3.0)
project(dlist_cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wpedantic -O3 ")
enable_testing()
add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(run)
add_subdirectory(doc)

