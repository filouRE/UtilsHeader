# only for cmake --version >= 3.0
cmake_minimum_required(VERSION 3.0)

# project name
project(reutils_header_only)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 20)

# I../includes
include_directories(includes)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES *.cpp)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})

# Set the output directory to be in the src directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src"
)