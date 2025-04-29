#include "Grid.h"
#include <cassert>

namespace Engine
{
    EngineSubsystemInitializationResult Grid::Initialize()
    {
        return SuccessfullyInitialized;
    }

    void Grid::Create( const int width, const int height )
    {
        Width = width;
        Height = height;

        const int length = width * height;

        Length = length;

        m_NodeGraph = new Node[ length ];

        for ( int y = 0; y < height; y++ )
        {
            for ( int x = 0; x < width; x++ )
            {
                // This index will be matched with node's ID field.
                const int index = y * width + x;

                m_NodeGraph[ index ].ID = index;
                m_NodeGraph[ index ].Position = Vector2D( static_cast<float>( x ), static_cast<float>( y ) );

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

    void Grid::Render( const Renderer* rendererSubsystem ) const
    {
        for ( int i = 0; i < Length; i++ )
        {
            SDL_RenderPoint( rendererSubsystem->NativeRenderer, m_NodeGraph[ i ].Position.X,
                             m_NodeGraph[ i ].Position.Y );
        }
    }

    void Grid::Shutdown()
    {
        delete m_NodeGraph;
    }
} // namespace Engine
