#include "Grid.h"
#include <cassert>
#include <random>
#include "EngineEntry.h"

namespace Engine
{
    EngineSubsystemInitializationResult Grid::Initialize()
    {
        ActorRegistry = new GridActorRegistry();

        m_RendererSubsystem = &EngineEntry::Singleton().SubsystemRegistry.RendererSubsystem;
        m_AssetManagerSubsystem = &EngineEntry::Singleton().SubsystemRegistry.AssetManagerSubsystem;

        return SuccessfullyInitialized;
    }

    void Grid::Create( const int width, const int height )
    {
        Width = width;
        Height = height;

        const int length = width * height;

        Length = length;

        m_NodeGraph = new Node[ length ];

        const int gridWidthPixels = width * NODE_SCALE;
        const int gridHeightPixels = height * NODE_SCALE;

        // TODO: Replace hard coded resolution calls with subsystem access. (Platform)
        const int originX = ( 640 - gridWidthPixels ) / 2;
        const int originY = ( 480 - gridHeightPixels ) / 2;

        for ( int y = 0; y < height; y++ )
        {
            for ( int x = 0; x < width; x++ )
            {
                // This index will be matched with node's ID field.
                const int index = y * width + x;

                m_NodeGraph[ index ].ID = index;
                m_NodeGraph[ index ].Position = Vector2D( static_cast<float>( originX ) + NODE_SCALE * x,
                                                          static_cast<float>( originY ) + NODE_SCALE * y );

                // Possible top neighbor.
                m_NodeGraph[ index ].Neighbors[ 0 ] = y > 0 ? index - width : INVALID_NODE_ID;

                // Possible right neighbor.
                m_NodeGraph[ index ].Neighbors[ 1 ] = x < width - 1 ? index + 1 : INVALID_NODE_ID;

                // Possible bottom neighbor.
                m_NodeGraph[ index ].Neighbors[ 2 ] = y < height - 1 ? index + width : INVALID_NODE_ID;

                // Possible left neighbor.
                m_NodeGraph[ index ].Neighbors[ 3 ] = x > 0 ? index - 1 : INVALID_NODE_ID;
            }
        }
    }

    bool Grid::TryGetNodeWithID( const int id, Node& node ) const
    {
        assert( id >= 0 && id < Length );

        node = m_NodeGraph[ id ];

        return true;
    }

    void Grid::ProcedurallyBlockNodes() const
    {
        // Clear existing blockage state.
        for ( int i = 0; i < Length; i++ )
        {
            if ( m_NodeGraph[ i ].State == Blocked ) m_NodeGraph[ i ].State = Available;
        }

        constexpr int capacity = 12;
        constexpr int lowerIndex = 31;
        constexpr int upperIndex = 68;

        // See: https://stackoverflow.com/questions/36922371/generate-different-random-numbers
        std::vector<int> indexTable;
        for ( int i = lowerIndex; i < upperIndex; i++ ) indexTable.push_back( i );

        const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle( indexTable.begin(), indexTable.end(), std::default_random_engine( seed ) );

        for ( int i = 0; i < capacity; i++ ) m_NodeGraph[ indexTable[ i ] ].State = Blocked;
    }

    void Grid::Render( const Renderer* rendererSubsystem ) const
    {
        for ( int i = 0; i < Length; i++ )
        {
            const Vector2D at( m_NodeGraph[ i ].Position.X, m_NodeGraph[ i ].Position.Y );
            const Vector2D size( NODE_SCALE, NODE_SCALE );

            m_RendererSubsystem->RenderTextureAtPosition( at, size, m_AssetManagerSubsystem->TileTexture );

            if ( m_NodeGraph[ i ].State == Blocked )
            {
                m_RendererSubsystem->RenderTextureAtPosition( at, size, m_AssetManagerSubsystem->BlockedNodeTexture );
            }
        }
    }

    void Grid::Shutdown()
    {
        delete ActorRegistry;
        delete m_NodeGraph;
    }
} // namespace Engine
