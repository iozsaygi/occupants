cmake_minimum_required(VERSION 3.31)
project(Occupants)

set(CMAKE_CXX_STANDARD 11)

# Set output directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

# Prevent in-source builds.
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed, please create a separate 'build' directory to trigger CMake build.")
endif ()

# Download SDL source code from specific revision.
include(FetchContent)
set(SDL_TARGET_REVISION 877399b2b2cf21e67554ed9046410f268ce1d1b2)
FetchContent_Declare(SDL GIT_REPOSITORY https://github.com/libsdl-org/SDL.git GIT_TAG ${SDL_TARGET_REVISION} GIT_SHALLOW TRUE)

# Download and extract SDL image by using specific revision.
set(SDL_IMAGE_REVISION 11154afb7855293159588b245b446a4ef09e574f)
FetchContent_Declare(SDL_image GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git GIT_TAG ${SDL_IMAGE_REVISION} GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(SDL SDL_image)

add_subdirectory(Engine)
add_subdirectory(Game)
