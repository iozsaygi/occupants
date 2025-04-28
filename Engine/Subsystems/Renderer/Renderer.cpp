#include "Renderer.h"

namespace Engine
{
    EngineSubsystemInitializationResult Renderer::Initialize()
    {
        NativeWindow = SDL_CreateWindow( "Test", 800, 600, 0 );
        if ( NativeWindow == nullptr ) return FailedToInitialize;

        NativeRenderer = SDL_CreateRenderer( NativeWindow, nullptr );
        if ( NativeRenderer == nullptr ) return FailedToInitialize;

        return SuccessfullyInitialized;
    }

    void Renderer::Shutdown()
    {
        SDL_DestroyRenderer( NativeRenderer );
        SDL_DestroyWindow( NativeWindow );
    }

} // namespace Engine
