#include "Renderer.h"

namespace Engine
{
    EngineSubsystemInitializationResult Renderer::Initialize()
    {
        m_Window = SDL_CreateWindow( "Test", 800, 600, 0 );
        if ( m_Window == nullptr ) return FailedToInitialize;

        m_Renderer = SDL_CreateRenderer( m_Window, nullptr );
        if ( m_Renderer == nullptr ) return FailedToInitialize;

        // TODO: This is for testing until we implement update loop for the scene graph, remove later.
        SDL_Delay( 5000 );

        return SuccessfullyInitialized;
    }

    void Renderer::Shutdown()
    {
    }

} // namespace Engine
