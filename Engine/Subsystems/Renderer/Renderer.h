#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include "Core/EngineSubsystem.h"

namespace Engine
{
    class Renderer final : public EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;

        void Shutdown() override;

    private:
        // Native SDL pointers that we want to hide from client.
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
    };
} // namespace Engine

#endif // RENDERER_H
