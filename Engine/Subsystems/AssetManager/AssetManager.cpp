#include "AssetManager.h"
#include <SDL3_image/SDL_image.h>

#ifdef __APPLE__
#include <climits>
#include <mach-o/dyld.h>
#include <unistd.h>
#endif // __APPLE__

#include "AssetConstants.h"
#include "EngineEntry.h"

namespace Engine
{
    EngineSubsystemInitializationResult AssetManager::Initialize()
    {
        m_DebuggerSubsystem = &EngineEntry::Singleton().SubsystemRegistry.DebuggerSubsystem;
        m_RendererSubsystem = &EngineEntry::Singleton().SubsystemRegistry.RendererSubsystem;

        // TODO: This will require porting to other operating systems such as Windows.
        // TODO: Another question to answer is, "Is this in a correct place?"
        // Currently, it just ensures working directory is the same directory with executable on macOS.
#ifdef __APPLE__
        char executablePath[ PATH_MAX ];
        uint32_t size = sizeof( executablePath );
        if ( _NSGetExecutablePath( executablePath, &size ) == 0 )
        {
            char resolvedPath[ PATH_MAX ];
            if ( realpath( executablePath, resolvedPath ) != nullptr )
            {
                const std::string fullPath( resolvedPath );
                const std::string directory = fullPath.substr( 0, fullPath.find_last_of( '/' ) );
                chdir( directory.c_str() );

                char buffer[ PATH_MAX ];
                if ( getcwd( buffer, sizeof( buffer ) ) != nullptr )
                {
                    m_DebuggerSubsystem->Trace( "Current working directory is: %s", buffer );
                }
            }
        }
#endif // __APPLE__

        if ( !TryLoadTexture( AssetConstants::TileTexturePath, TileTexture ) ) return FailedToInitialize;

        return SuccessfullyInitialized;
    }

    bool AssetManager::TryLoadTexture( const char* path, Texture& texture ) const
    {
        texture.Native = IMG_LoadTexture( m_RendererSubsystem->NativeRenderer, path );
        if ( texture.Native == nullptr )
        {
            m_DebuggerSubsystem->Error( "Failed to load texture at path: %s, the reason was: %s",
                                        AssetConstants::TileTexturePath, SDL_GetError() );
            return false;
        }

        return true;
    }

    void AssetManager::Shutdown()
    {
        SDL_DestroyTexture( TileTexture.Native );
    }
} // namespace Engine
