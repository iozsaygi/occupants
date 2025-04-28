#ifndef WORLD_H
#define WORLD_H

#include "Core/EngineSubsystem.h"

namespace Engine
{
    class World final : EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;

        void Shutdown() override;
    };
} // namespace Engine

#endif // WORLD_H
