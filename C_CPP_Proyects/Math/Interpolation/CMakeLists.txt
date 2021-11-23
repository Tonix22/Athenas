cmake_minimum_required(VERSION 3.13)

project(Lagrange VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/koolplot)
include_directories(/usr/include/python3.6)

# we add the sub-directories that we want CMake to scan
add_subdirectory(include)
add_subdirectory(thirdparty)
add_subdirectory(src)
