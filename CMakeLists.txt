cmake_minimum_required(VERSION 3.30)
project(Warpix)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Warpix main.cpp)
target_link_libraries(Warpix ${OpenCV_LIBS})

