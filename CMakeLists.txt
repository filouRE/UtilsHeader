cmake_minimum_required(VERSION 3.15)
project(reutils)

# Header file directory
include_directories(${CMAKE_SOURCE_DIR})

# Source files
add_executable(reutils ../example/main.cpp)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# For Windows (Visual Studio 2022)
if (WIN32)
  # Specify that we want to use Visual Studio 2022
  set(CMAKE_GENERATOR_TOOLSET "host=x64" CACHE STRING "Platform toolset" FORCE)

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")  # Enable multi-threaded compilation
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT reutils)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set(CMAKE_SUPPRESS_REGENERATION true)

  # Specify the output directory for Visual Studio
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif ()
