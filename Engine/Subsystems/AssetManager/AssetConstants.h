#ifndef ASSET_CONSTANTS_H
#define ASSET_CONSTANTS_H

namespace Engine
{
    struct AssetConstants final
    {
        // Texture constants.
        static constexpr auto TileTexturePath = "Assets/Textures/Tile.png";
        static constexpr auto BlockedNodeTexturePath = "Assets/Textures/Block.png";
        static constexpr auto PlayerOneTexturePath = "Assets/Textures/Player 1.png";
        static constexpr auto PlayerTwoTexturePath = "Assets/Textures/Player 2.png";
        static constexpr auto PlayerOneSpreadTexturePath = "Assets/Textures/Player 1 Spread.png";
        static constexpr auto PlayerTwoSpreadTexturePath = "Assets/Textures/Player 2 Spread.png";
    };
} // namespace Engine

#endif // ASSET_CONSTANTS_H
