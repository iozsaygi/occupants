#ifndef WORLD_H
#define WORLD_H

#include "Core/EngineSubsystem.h"
#include "Scene.h"

namespace Engine
{
    class World final : EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;
        void AttachScene( Scene* scene );
        void RunAttachedScene() const;
        void Shutdown() override;

    private:
        Scene* m_AttachedScene = nullptr;
    };
} // namespace Engine

#endif // WORLD_H
