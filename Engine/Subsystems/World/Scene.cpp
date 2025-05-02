#include "Scene.h"

// ReSharper disable CppMemberFunctionMayBeStatic

namespace Engine
{
    Scene::Scene()
    {
        ActiveSceneGraph = new SceneGraph( 1 );
    }

    void Scene::Start() const
    {
        for ( int i = 0; i < ActiveSceneGraph->Capacity; i++ )
        {
            Actor* actor = nullptr;
            if ( !ActiveSceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

            actor->OnSceneStart();
        }
    }

    void Scene::Update( const float deltaTime )
    {
        const DispatchableEvent dispatchedEventForCurrentFrame = m_EventDispatcher.TryDispatchingEvent();

        if ( dispatchedEventForCurrentFrame == EngineShutdown ) IsActive = false;

        // Updating order is the exact same with the scene graph registry indices.
        for ( int i = 0; i < ActiveSceneGraph->Capacity; i++ )
        {
            Actor* actor = nullptr;
            if ( !ActiveSceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

            actor->OnSceneUpdate( deltaTime, dispatchedEventForCurrentFrame );
        }
    }

    void Scene::Render( Renderer* rendererSubsystem,
                        const Grid* gridSubsystem ) const // NOLINT(*-convert-member-functions-to-static)
    {
        SDL_SetRenderDrawColor( rendererSubsystem->NativeRenderer, 0, 0, 0, 255 );
        SDL_RenderClear( rendererSubsystem->NativeRenderer );

        // Render subsystems first. (Optional)
        gridSubsystem->Render( rendererSubsystem );

        // Render the registered actors within active scene graph.
        // Currently, the order of rendering is totally dependent on the indices of actors within their scene graph.
        for ( int i = 0; i < ActiveSceneGraph->Capacity; i++ )
        {
            Actor* actor = nullptr;
            if ( !ActiveSceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

            actor->OnSceneRender( rendererSubsystem );
        }

        SDL_RenderPresent( rendererSubsystem->NativeRenderer );
    }

    void Scene::Shutdown()
    {
        if ( IsActive ) IsActive = false;

        for ( int i = 0; i < ActiveSceneGraph->Capacity; i++ )
        {
            Actor* actor = nullptr;
            if ( !ActiveSceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

            actor->OnSceneShutdown();
        }

        delete ActiveSceneGraph;
    }

} // namespace Engine
