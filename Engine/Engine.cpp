#include "Engine.h"

namespace Engine
{
    void Engine::TryInitializingSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Initialize();
        SubsystemRegistry.PlatformSubsystem.Initialize();
    }

    void Engine::ShutdownSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Shutdown();
        SubsystemRegistry.PlatformSubsystem.Shutdown();
    }

} // namespace Engine
