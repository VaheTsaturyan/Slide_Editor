cmake_minimum_required(VERSION 3.10)
project(SlideEditor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-D_GLIBCXX_ASSERTIONS=0)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/Cantroler/inc
    ${CMAKE_SOURCE_DIR}/Dacument/inc
    ${CMAKE_SOURCE_DIR}/Dacument/inc/Slide
    ${CMAKE_SOURCE_DIR}/Dacument/slideMeneger
    ${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Editor
    ${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Sterializer
    ${CMAKE_SOURCE_DIR}/UI/CLI/inc
    ${CMAKE_SOURCE_DIR}/UI/CLI/inc/Parser
)

# Add source files
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/Cantroler/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Editor/*.cpp"
    "${CMAKE_SOURCE_DIR}/Dacument/slideMeneger/Sterializer/*.cpp"
    "${CMAKE_SOURCE_DIR}/UI/CLI/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp"
)

# Create executable
add_executable(SlideEditor ${SOURCES})

# Set build configurations
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # Enable debug symbols, disable optimization
set(CMAKE_CXX_FLAGS_RELEASE "-O3")   # Enable optimization for release

# Set default build type to Debug if none specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
