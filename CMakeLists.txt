cmake_minimum_required(VERSION 3.30)
project(Warpix)

set(CMAKE_CXX_STANDARD 23)


# Find packages
find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${YAML_CPP_INCLUDE_DIR} include)
link_directories(${YAML_CPP_LIBRARY_DIR})

# Source files
set(SOURCES
        src/main.cpp
        src/config.cpp
        src/utils.cpp
        src/align.cpp
)

# Add executable
add_executable(Warpix ${SOURCES})

# Link libraries
target_link_libraries(Warpix ${OpenCV_LIBS} yaml-cpp)
