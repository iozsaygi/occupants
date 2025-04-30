#ifndef SCENE_H
#define SCENE_H

#include "SceneGraph.h"
#include "Subsystems/Grid/Grid.h"
#include "Subsystems/Renderer/Renderer.h"

namespace Engine
{
    class Scene final
    {
    public:
        bool IsActive = false;

        Scene();

        // Core scene lifetime cycle.
        void Start() const;
        void Update();
        void Render( const Renderer* rendererSubsystem, const Grid* gridSubsystem ) const;
        void Shutdown();

    private:
        SceneGraph* m_SceneGraph = nullptr;
    };
} // namespace Engine

#endif // SCENE_H
