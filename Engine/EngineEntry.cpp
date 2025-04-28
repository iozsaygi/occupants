#include "EngineEntry.h"

namespace Engine
{
    EngineEntryStabilityState EngineEntry::TryInitializingSubsystems()
    {
        if ( SubsystemRegistry.DebuggerSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.PlatformSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.RendererSubsystem.Initialize() == FailedToInitialize ) return Unstable;

        SubsystemRegistry.DebuggerSubsystem.Trace( "Successfully initialized registered engine subsystems." );

        return Stable;
    }

    void EngineEntry::ShutdownSubsystems()
    {
        SubsystemRegistry.DebuggerSubsystem.Shutdown();
        SubsystemRegistry.PlatformSubsystem.Shutdown();
        SubsystemRegistry.RendererSubsystem.Shutdown();
    }
} // namespace Engine
