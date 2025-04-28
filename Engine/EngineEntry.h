#ifndef ENGINE_ENTRY_H
#define ENGINE_ENTRY_H

#include "Core/EngineSubsystemRegistry.h"

namespace Engine
{
    // Will directly communicate about engine's health to the client via this enum.
    enum EngineEntryStabilityState
    {
        Stable,
        Unstable
    };

    class ENGINE_API EngineEntry
    {
    public:
        EngineSubsystemRegistry SubsystemRegistry;

        EngineEntryStabilityState TryInitializingSubsystems();
        void ShutdownSubsystems();
    };
} // namespace Engine

#endif // ENGINE_ENTRY_H
