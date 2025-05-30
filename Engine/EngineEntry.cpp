#include "EngineEntry.h"

namespace Engine
{
    EngineEntryStabilityState EngineEntry::TryInitializingSubsystems()
    {
        if ( SubsystemRegistry.DebuggerSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.PlatformSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.RendererSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.WorldSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.GridSubsystem.Initialize() == FailedToInitialize ) return Unstable;
        if ( SubsystemRegistry.AssetManagerSubsystem.Initialize() == FailedToInitialize ) return Unstable;

        SubsystemRegistry.DebuggerSubsystem.Trace( "Successfully initialized registered engine subsystems." );

        return Stable;
    }

    void EngineEntry::ShutdownSubsystems()
    {
        SubsystemRegistry.AssetManagerSubsystem.Shutdown();
        SubsystemRegistry.GridSubsystem.Shutdown();
        SubsystemRegistry.WorldSubsystem.Shutdown();
        SubsystemRegistry.RendererSubsystem.Shutdown();
        SubsystemRegistry.PlatformSubsystem.Shutdown();
        SubsystemRegistry.DebuggerSubsystem.Shutdown();

        SubsystemRegistry.DebuggerSubsystem.Trace( "Completed shutdown for registered engine subsystems." );
    }
} // namespace Engine
