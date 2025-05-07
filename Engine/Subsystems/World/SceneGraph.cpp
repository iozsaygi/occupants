#include "SceneGraph.h"
#include <cassert>

namespace Engine
{
    SceneGraph::SceneGraph( const int actorCapacity )
    {
        assert( actorCapacity > 0 );

        m_Actors = new Actor*[ actorCapacity ];
        Capacity = actorCapacity;
        Count = 0;
    }

    SceneGraph::~SceneGraph()
    {
        delete[] m_Actors;
    }

    bool SceneGraph::TryRegisterActor( Actor* actor )
    {
        assert( actor != nullptr );

        int availableSceneGraphIndex = -1;
        if ( !TryFindFirstAvailableSceneGraphIndex( availableSceneGraphIndex ) ) return false;

        m_Actors[ availableSceneGraphIndex ] = actor;
        Count++;

        return true;
    }

    bool SceneGraph::TryGetActorBySceneGraphIndex( const int index, Actor*& actor ) const
    {
        if ( index < 0 || index >= Capacity ) return false;

        actor = m_Actors[ index ];
        return true;
    }

    bool SceneGraph::TryGetActorByName( const std::string& name,
                                        Actor*& actor ) const // NOLINT(*-convert-member-functions-to-static)
    {
        assert( !name.empty() );

        for ( int i = 0; i < Capacity; i++ )
        {
            if ( m_Actors[ i ]->Name == name )
            {
                actor = m_Actors[ i ];
                return true;
            }
        }

        return false;
    }

    bool SceneGraph::TryFindFirstAvailableSceneGraphIndex( int& index ) const
    {
        for ( int i = 0; i < Capacity; i++ )
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
