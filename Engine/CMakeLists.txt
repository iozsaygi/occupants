project(Engine)

add_library(${PROJECT_NAME} SHARED Engine.cpp EngineEntry.cpp Core/EngineSubsystem.cpp Core/EngineSubsystemRegistry.cpp Subsystems/Debugger/Debugger.cpp Subsystems/Platform/Platform.cpp Subsystems/Renderer/Renderer.cpp Subsystems/World/World.cpp Subsystems/World/Actor.cpp Subsystems/World/Scene.cpp Subsystems/Grid/Grid.cpp Subsystems/Grid/Node.cpp Mathematics/Vector2D.cpp)

# Setup further compilation flags for macOS.
if (APPLE)
    message(STATUS "Adding compile definitions for macOS")
    target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_BUILD_SHARED_OBJECT)
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Engine)

# Link SDL libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
