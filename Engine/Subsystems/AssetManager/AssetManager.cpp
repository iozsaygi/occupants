#include "AssetManager.h"
#include <SDL3_image/SDL_image.h>

#include "AssetConstants.h"
#include "EngineEntry.h"

namespace Engine
{
    EngineSubsystemInitializationResult AssetManager::Initialize()
    {
        m_RendererSubsystem = EngineEntry::Singleton().SubsystemRegistry.RendererSubsystem;

        if ( !TryLoadTexture( AssetConstants::TileTexturePath, TileTexture ) ) return FailedToInitialize;

        return SuccessfullyInitialized;
    }

    bool AssetManager::TryLoadTexture( const char* path, Texture& texture ) const
    {
        texture.Native = IMG_LoadTexture( m_RendererSubsystem.NativeRenderer, path );
        if ( texture.Native == nullptr ) return false;

        return true;
    }

    void AssetManager::Shutdown()
    {
        SDL_DestroyTexture( TileTexture.Native );
    }
} // namespace Engine
