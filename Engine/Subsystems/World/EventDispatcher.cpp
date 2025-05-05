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
                        case SDLK_W:
                            return WKeyDown;
                        case SDLK_A:
                            return AKeyDown;
                        case SDLK_S:
                            return SKeyDown;
                        case SDLK_D:
                            return DKeyDown;
                        case SDLK_UP:
                            return UpKeyDown;
                        case SDLK_LEFT:
                            return LeftKeyDown;
                        case SDLK_DOWN:
                            return DownKeyDown;
                        case SDLK_RIGHT:
                            return RightKeyDown;
                        default:;
                    }
                    break;
                default:;
            }
        }

        return None;
    }

} // namespace Engine
