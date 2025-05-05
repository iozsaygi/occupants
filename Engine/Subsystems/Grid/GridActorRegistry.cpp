#include "GridActorRegistry.h"
#include <assert.h>

namespace Engine
{
    GridActorRegistry::GridActorRegistry()
    {
        m_Registry = std::unordered_map<int, Actor*>();
    }

    bool GridActorRegistry::TryRegisterActor( Node& node, Actor* actor )
    {
        assert( actor != nullptr );

        const auto lookupQuery = m_Registry.find( node.ID );
        if ( lookupQuery == m_Registry.end() )
        {
            // Failed to find actor on the target node, it is safe to register.
            m_Registry.insert( { node.ID, actor } );
            return true;
        }

        // The target node already contains another actor.
        return false;
    }

    bool GridActorRegistry::TryRemoveActor( const Actor* actor )
    {
        assert( actor != nullptr );

        Node nodeOccupiedByActor;
        if ( TryGetNodeOccupiedByActor( actor, nodeOccupiedByActor ) )
        {
            m_Registry.erase( nodeOccupiedByActor.ID );
            return true;
        }

        return false;
    }

    bool GridActorRegistry::TryGetNodeOccupiedByActor( const Actor* actor, Node& node ) const
    {
        for ( const auto pair: m_Registry )
        {
            if ( pair.second == actor )
            {
                node.ID = pair.first;
                return true;
            }
        }

        return false;
    }
} // namespace Engine
