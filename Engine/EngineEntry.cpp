#include "EngineEntry.h"

namespace Engine
{
    EngineEntryStabilityState EngineEntry::TryInitializingSubsystems()
    {
        if ( SubsystemRegistry.DebuggerSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.PlatformSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.RendererSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.WorldSubsystem.Initialize() == FailedToInitialize ) return Unstable;

        SubsystemRegistry.DebuggerSubsystem.Trace( "Successfully initialized registered engine subsystems." );

        return Stable;
    }

    void EngineEntry::ShutdownSubsystems()
    {
        SubsystemRegistry.WorldSubsystem.Shutdown();
        SubsystemRegistry.RendererSubsystem.Shutdown();
        SubsystemRegistry.PlatformSubsystem.Shutdown();
        SubsystemRegistry.DebuggerSubsystem.Shutdown();
    }
} // namespace Engine
