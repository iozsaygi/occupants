project(Game)

add_executable(${PROJECT_NAME} Entry.cpp)

# Include engine source directories.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Engine)

target_link_libraries(${PROJECT_NAME} PRIVATE Engine)
