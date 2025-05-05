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
        // ReSharper disable once CppDFANotInitializedField
        EngineSubsystemRegistry SubsystemRegistry;

        static EngineEntry& Singleton()
        {
            static EngineEntry Singleton;
            return Singleton;
        }

        EngineEntryStabilityState TryInitializingSubsystems();
        void ShutdownSubsystems();

        EngineEntry( const EngineEntry& ) = delete;
        EngineEntry& operator=( const EngineEntry& ) = delete;
        EngineEntry( EngineEntry&& ) = delete;
        EngineEntry& operator=( EngineEntry&& ) = delete;

    private:
        EngineEntry() = default;

        static EngineEntry* s_Singleton;
    };
} // namespace Engine

#endif // ENGINE_ENTRY_H
