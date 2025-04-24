#ifndef DEBUGGER_H
#define DEBUGGER_H

#include "Core/EngineSubsystem.h"

namespace Engine
{
    class Debugger final : EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;

        void Shutdown() override;
    };
} // namespace Engine

#endif // !DEBUGGER_H
