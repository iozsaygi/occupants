cmake_minimum_required(VERSION 3.31)
project(Occupants)

set(CMAKE_CXX_STANDARD 11)

# Set output directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

add_subdirectory(Engine)
add_subdirectory(Game)
