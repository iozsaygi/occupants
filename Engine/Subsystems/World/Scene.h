#ifndef SCENE_H
#define SCENE_H

#include "Subsystems/Renderer/Renderer.h"

namespace Engine
{
    class Scene final
    {
    public:
        bool IsActive;

        // Core scene lifetime cycle.
        void Start();
        void Update();
        void Render( const Renderer* rendererSubsystem );
        void Shutdown();
    };
} // namespace Engine

#endif // SCENE_H
