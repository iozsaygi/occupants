#ifndef ENGINE_H
#define ENGINE_H

#include "Core/EngineSubsystemRegistry.h"

namespace Engine
{
    class Engine
    {
    public:
        EngineSubsystemRegistry SubsystemRegistry;

        void TryInitializingSubsystems();
        void ShutdownSubsystems();
    };
} // namespace Engine

#endif // ENGINE_H
