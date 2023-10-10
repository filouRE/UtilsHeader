cmake_minimum_required(VERSION 3.15)
project(reutils)

# Header file directory
include_directories(${CMAKE_SOURCE_DIR})

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# For Windows (Visual Studio 2022)
if (WIN32)
  # Source files
  add_executable(reutils ../example/main.cpp)

  # Specify that we want to use Visual Studio 2022
  set(CMAKE_GENERATOR_TOOLSET "host=x64" CACHE STRING "Platform toolset" FORCE)

  # Enable multi-threaded compilation
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP") 

  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT reutils)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set(CMAKE_SUPPRESS_REGENERATION true)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

else ()
  # For Linux
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

  # Source files
  file(GLOB SOURCES "example/*.cpp")

  # creates the variable EXEC and sets it to hello
  set(EXEC main.o)

  # I../includes
  include_directories(../**/*.h)
  # Enable multi-threaded compilation
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  # Enable debug symbols
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  # Enable optimization
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  # Enable profile guided optimization
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_CXX_STANDARD 20)

  # Set the exec
  add_executable(${EXEC} ${SOURCES})

endif ()
