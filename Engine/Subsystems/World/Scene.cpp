#include "Scene.h"

// ReSharper disable CppMemberFunctionMayBeStatic

namespace Engine
{
    void Scene::Start()
    {
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
        }
    }

    void Scene::Render( const Renderer* rendererSubsystem )
    {
        SDL_SetRenderDrawColor( rendererSubsystem->NativeRenderer, 0, 0, 0, 255 );
        SDL_RenderClear( rendererSubsystem->NativeRenderer );

        // TODO: Render actors here via actor registry.

        SDL_RenderPresent( rendererSubsystem->NativeRenderer );
    }

    void Scene::Shutdown()
    {
        if ( IsActive ) IsActive = false;
    }

} // namespace Engine
