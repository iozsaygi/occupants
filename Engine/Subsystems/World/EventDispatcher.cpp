#include "EventDispatcher.h"
#include <SDL3/SDL_events.h>

namespace Engine
{
    // ReSharper disable once CppMemberFunctionMayBeStatic
    DispatchableEvent EventDispatcher::TryDispatchingEvent()
    {
        SDL_Event event;

        while ( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
                case SDL_EVENT_QUIT:
                    return EngineShutdown;
                case SDL_EVENT_KEY_DOWN:
                    switch ( event.key.key )
                    {
                        case SDLK_ESCAPE:
                            return EngineShutdown;
                        default:;
                    }
                    break;
                default:;
            }
        }

        return None;
    }

} // namespace Engine
