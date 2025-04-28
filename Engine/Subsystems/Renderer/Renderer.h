#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include "Core/EngineSubsystem.h"

namespace Engine
{
    class Renderer final : public EngineSubsystem
    {
    public:
        SDL_Window* NativeWindow = nullptr;
        SDL_Renderer* NativeRenderer = nullptr;

        EngineSubsystemInitializationResult Initialize() override;

        void Shutdown() override;
    };
} // namespace Engine

#endif // RENDERER_H
