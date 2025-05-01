#ifndef SCENE_H
#define SCENE_H

#include "EventDispatcher.h"
#include "SceneGraph.h"
#include "Subsystems/Grid/Grid.h"
#include "Subsystems/Renderer/Renderer.h"

namespace Engine
{
    class Scene final
    {
    public:
        SceneGraph* ActiveSceneGraph = nullptr;
        bool IsActive = false;

        Scene();

        // Core scene lifetime cycle.
        void Start() const;
        void Update( float deltaTime );
        void Render( Renderer* rendererSubsystem, const Grid* gridSubsystem ) const;
        void Shutdown();

    private:
        EventDispatcher m_EventDispatcher;
    };
} // namespace Engine

#endif // SCENE_H
