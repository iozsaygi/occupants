#ifndef WORLD_H
#define WORLD_H

#include "Core/EngineSubsystem.h"
#include "Scene.h"

namespace Engine
{
    class EngineSubsystemRegistry;

    class World final : EngineSubsystem
    {
    public:
        Scene* AttachedScene = nullptr;

        EngineSubsystemInitializationResult Initialize() override;
        void AttachSubsystemRegistry( EngineSubsystemRegistry* engineSubsystemRegistry );
        void AttachScene( Scene* scene );
        void RunAttachedScene() const;
        void Shutdown() override;

    private:
        EngineSubsystemRegistry* m_AttachedEngineSubsystemRegistry = nullptr;
    };
} // namespace Engine

#endif // WORLD_H
