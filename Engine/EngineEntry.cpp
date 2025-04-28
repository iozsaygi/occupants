#include "EngineEntry.h"

namespace Engine
{
    void EngineEntry::TryInitializingSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Initialize();
        SubsystemRegistry.PlatformSubsystem.Initialize();
        SubsystemRegistry.RendererSubsystem.Initialize();
    }

    void EngineEntry::ShutdownSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Shutdown();
        SubsystemRegistry.PlatformSubsystem.Shutdown();
        SubsystemRegistry.RendererSubsystem.Shutdown();
    }
} // namespace Engine
