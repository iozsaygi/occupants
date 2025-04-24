project(Engine)

add_library(${PROJECT_NAME} Core/EngineSubsystem.cpp Core/EngineSubsystemRegistry.cpp Subsystems/Debugger/Debugger.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Engine)

# Link SDL libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
