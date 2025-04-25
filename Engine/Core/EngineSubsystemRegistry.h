#ifndef ENGINE_SUBSYSTEM_REGISTRY_H
#define ENGINE_SUBSYSTEM_REGISTRY_H

#include "Subsystems/Debugger/Debugger.h"

namespace Engine
{
    // Will store direct/hard references to the engine subsystems.
    // No arrays, no lists, no further requirements for type casting. Just direct references.
    class EngineSubsystemRegistry
    {
    public:
        Debugger DebuggerSubsystem;
    };
} // namespace Engine

#endif // ENGINE_SUBSYSTEM_REGISTRY_H
