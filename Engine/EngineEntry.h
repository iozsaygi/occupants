#ifndef ENGINE_ENTRY_H
#define ENGINE_ENTRY_H

#include "Core/EngineSubsystemRegistry.h"

namespace Engine
{
    class EngineEntry
    {
    public:
        EngineSubsystemRegistry SubsystemRegistry;

        void TryInitializingSubsystems();
        void ShutdownSubsystems();
    };
} // namespace Engine

#endif // ENGINE_ENTRY_H
