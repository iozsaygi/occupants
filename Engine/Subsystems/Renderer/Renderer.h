#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

#include "Color.h"
#include "Core/EngineSubsystem.h"
#include "Mathematics/Vector2D.h"

namespace Engine
{
    class Renderer final : public EngineSubsystem
    {
    public:
        SDL_Window* NativeWindow = nullptr;
        SDL_Renderer* NativeRenderer = nullptr;

        EngineSubsystemInitializationResult Initialize() override;

        // This function is only intended for debugging purposes. Not really required for production.
        void RenderDebugRectangleAtPosition( Vector2D at, Vector2D size, Color color ) const;

        void Shutdown() override;
    };
} // namespace Engine

#endif // RENDERER_H
