# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.0)

# project name
project(reutils_header_only)

# creates the variable EXEC and sets it to hello
set(EXEC main.out)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 20)

# I../includes
include_directories(includes)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES *.cpp)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})