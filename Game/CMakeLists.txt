project(Game)

add_executable(${PROJECT_NAME} Entry.cpp)

# Include engine source directories.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Engine)

# Link SDL libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
