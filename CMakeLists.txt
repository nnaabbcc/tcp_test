
cmake_minimum_required(VERSION 3.13)

project(tcp_test)

# Use the standard c++17 for this project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)

add_subdirectory(tcp_test)
add_subdirectory(udp_test)
