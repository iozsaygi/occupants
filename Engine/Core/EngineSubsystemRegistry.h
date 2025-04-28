#ifndef ENGINE_SUBSYSTEM_REGISTRY_H
#define ENGINE_SUBSYSTEM_REGISTRY_H

#include "EngineAPI.h"
#include "Subsystems/Debugger/Debugger.h"
#include "Subsystems/Platform/Platform.h"

namespace Engine
{
    // Will store direct/hard references to the engine subsystems.
    // No arrays, no lists, no further requirements for type casting. Just direct references.
    class ENGINE_API EngineSubsystemRegistry
    {
    public:
        Debugger DebuggerSubsystem;
        Platform PlatformSubsystem;
    };
} // namespace Engine

#endif // ENGINE_SUBSYSTEM_REGISTRY_H
