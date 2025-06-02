#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "Core/EngineSubsystem.h"
#include "Subsystems/Debugger/Debugger.h"
#include "Subsystems/Renderer/Renderer.h"
#include "Subsystems/Renderer/Texture.h"

namespace Engine
{
    class AssetManager final : public EngineSubsystem
    {
    public:
        Texture TileTexture;
        Texture BlockedNodeTexture;
        Texture PlayerOneTexture;
        Texture PlayerTwoTexture;

        EngineSubsystemInitializationResult Initialize() override;

        bool TryLoadTexture( const char* path, Texture& texture ) const;

        void Shutdown() override;

    private:
        Debugger* m_DebuggerSubsystem = nullptr;
        Renderer* m_RendererSubsystem = nullptr;
    };
} // namespace Engine

#endif // ASSET_MANAGER_H
