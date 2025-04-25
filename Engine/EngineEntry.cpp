#include "EngineEntry.h"

namespace Engine
{
    void EngineEntry::TryInitializingSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Initialize();
        SubsystemRegistry.PlatformSubsystem.Initialize();
    }

    void EngineEntry::ShutdownSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Shutdown();
        SubsystemRegistry.PlatformSubsystem.Shutdown();
    }
} // namespace Engine
