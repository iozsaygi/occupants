#include "Platform.h"
#include <SDL3/SDL.h>

namespace Engine
{
    EngineSubsystemInitializationResult Platform::Initialize()
    {
        // Initialize SDL with only video subsystem.
        if ( SDL_Init( SDL_INIT_VIDEO ) == false ) return FailedToInitialize;

        return SuccessfullyInitialized;
    }

    void Platform::Shutdown()
    {
        SDL_Quit();
    }

} // namespace Engine
