#ifndef GRID_H
#define GRID_H

#include "Core/EngineSubsystem.h"

namespace Engine
{
    class Grid final : EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;
        void Shutdown() override;
    };
} // namespace Engine

#endif // GRID_H
