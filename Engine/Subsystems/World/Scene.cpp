#include "Scene.h"

// ReSharper disable CppMemberFunctionMayBeStatic

namespace Engine
{
    Scene::Scene()
    {
        m_SceneGraph = new SceneGraph( 2 );
    }

    void Scene::Start() const
    {
        for ( int i = 0; i < m_SceneGraph->Length; i++ )
        {
            Actor* actor = nullptr;
            if ( !m_SceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

            actor->OnSceneStart();
        }
    }

    void Scene::Update()
    {
        // TODO: For now, we hare handling events from here, we can create event subsystem later on.
        SDL_Event event;

        while ( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
                case SDL_EVENT_QUIT:
                    IsActive = false;
                case SDL_EVENT_KEY_DOWN:
                    switch ( event.key.key )
                    {
                        case SDLK_ESCAPE:
                            IsActive = false;
                            break;
                        default:;
                    }
                    break;
                default:;
            }

            // Updating order is the exact same with the scene graph registry indices.
            for ( int i = 0; i < m_SceneGraph->Length; i++ )
            {
                Actor* actor = nullptr;
                if ( !m_SceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

                // TODO: Replace the delta time with the actual value.
                actor->OnSceneUpdate( 1.0f );
            }
        }
    }

    void Scene::Render( const Renderer* rendererSubsystem, const Grid* gridSubsystem ) const
    // NOLINT(*-convert-member-functions-to-static)
    {
        SDL_SetRenderDrawColor( rendererSubsystem->NativeRenderer, 0, 0, 0, 255 );
        SDL_RenderClear( rendererSubsystem->NativeRenderer );

        // Render subsystems first. (Optional)
        gridSubsystem->Render( rendererSubsystem );

        SDL_RenderPresent( rendererSubsystem->NativeRenderer );
    }

    void Scene::Shutdown()
    {
        if ( IsActive ) IsActive = false;

        for ( int i = 0; i < m_SceneGraph->Length; i++ )
        {
            Actor* actor = nullptr;
            if ( !m_SceneGraph->TryGetActorBySceneGraphIndex( i, actor ) ) continue;

            actor->OnSceneShutdown();
        }

        delete m_SceneGraph;
    }

} // namespace Engine
