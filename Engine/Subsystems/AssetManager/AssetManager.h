#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "Core/EngineSubsystem.h"

namespace Engine
{
    class AssetManager final : public EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;
        void Shutdown() override;
    };
} // namespace Engine

#endif // ASSET_MANAGER_H
