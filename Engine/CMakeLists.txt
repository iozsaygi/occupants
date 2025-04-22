project(Engine)

add_library(${PROJECT_NAME} Core/EngineSubsystem.cpp Core/EngineSubsystemRegistry.cpp)

# Bind SDL libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
