#include "Renderer.h"

namespace Engine
{
    EngineSubsystemInitializationResult Renderer::Initialize()
    {
        m_Window = SDL_CreateWindow( "Test", 800, 600, 0 );
        if ( m_Window == nullptr ) return FailedToInitialize;

        m_Renderer = SDL_CreateRenderer( m_Window, nullptr );
        if ( m_Renderer == nullptr ) return FailedToInitialize;

        return SuccessfullyInitialized;
    }

    void Renderer::Shutdown()
    {
        SDL_DestroyRenderer( m_Renderer );
        SDL_DestroyWindow( m_Window );
    }

} // namespace Engine
