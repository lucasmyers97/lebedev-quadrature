# Set the minimum version of CMake that's required
cmake_minimum_required(VERSION 3.12)

project(lebedev-quadrature VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER "g++" CACHE STRING "Compiler")
add_compile_options(-Wall -Wextra -pedantic)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# library source code
add_subdirectory(src)

# tests
add_subdirectory(test)
