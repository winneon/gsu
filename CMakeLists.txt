# define project name
project(gsu LANGUAGES CXX)

# prevent building in-source
if (CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Building in-source is not supported! Create a build dir and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt.")
endif()

# generic configuration
cmake_minimum_required(VERSION 3.15)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# set main entry point into program
add_executable(gsu src/main.cpp)

# include dependencies
find_package(Boost REQUIRED COMPONENTS program_options)
target_link_libraries(gsu PUBLIC Boost::program_options)