#include "SceneGraph.h"
#include <cassert>

namespace Engine
{
    SceneGraph::SceneGraph( const int actorCapacity )
    {
        assert( actorCapacity > 0 );

        m_Actors = new Actor*[ actorCapacity ];
        Length = actorCapacity;
    }

    SceneGraph::~SceneGraph()
    {
        delete[] m_Actors;
    }

    bool SceneGraph::TryRegisterActor( Actor* actor ) const
    {
        assert( actor != nullptr );

        int availableSceneGraphIndex = -1;
        if ( !TryFindFirstAvailableSceneGraphIndex( availableSceneGraphIndex ) ) return false;

        m_Actors[ availableSceneGraphIndex ] = actor;

        return true;
    }

    bool SceneGraph::TryGetActorBySceneGraphIndex( const int index, Actor*& actor ) const
    {
        if ( index < 0 || index >= Length ) return false;

        actor = m_Actors[ index ];
        return true;
    }

    bool SceneGraph::TryFindFirstAvailableSceneGraphIndex( int& index ) const
    {
        for ( int i = 0; i < Length; i++ )
        {
            if ( m_Actors[ i ] == nullptr )
            {
                index = i;
                return true;
            }
        }

        // This is indicating that we reached our actor capacity.
        return false;
    }

} // namespace Engine
