#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL3/SDL_render.h"

namespace Engine
{
    // Very basic texture struct to wrap around SDL rendering calls for the game client.
    struct Texture final
    {
        SDL_Texture* Native;
    };
} // namespace Engine

#endif // TEXTURE_H
