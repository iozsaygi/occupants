#include "Renderer.h"

namespace Engine
{
    EngineSubsystemInitializationResult Renderer::Initialize()
    {
        NativeWindow = SDL_CreateWindow( "Occupants", 640, 480, 0 );
        if ( NativeWindow == nullptr ) return FailedToInitialize;

        NativeRenderer = SDL_CreateRenderer( NativeWindow, nullptr );
        if ( NativeRenderer == nullptr ) return FailedToInitialize;

        return SuccessfullyInitialized;
    }

    void Renderer::RenderDebugRectangleAtPosition( const Vector2D at, const Vector2D size, const Color color ) const
    {
        SDL_SetRenderDrawColor( NativeRenderer, color.R, color.G, color.B, color.A );

        SDL_FRect fRect;
        fRect.x = at.X;
        fRect.y = at.Y;
        fRect.w = size.X;
        fRect.h = size.Y;
        SDL_RenderFillRect( NativeRenderer, &fRect );
    }

    void Renderer::Shutdown()
    {
        SDL_DestroyRenderer( NativeRenderer );
        SDL_DestroyWindow( NativeWindow );
    }

} // namespace Engine
