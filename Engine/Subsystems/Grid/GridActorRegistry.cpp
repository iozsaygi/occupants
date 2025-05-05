#include "GridActorRegistry.h"
#include <assert.h>

namespace Engine
{
    GridActorRegistry::GridActorRegistry()
    {
        m_Registry = std::map<Node, Actor*>();
    }

    bool GridActorRegistry::TryRegisterActorToNode( Node& node, Actor* actor )
    {
        assert( actor != nullptr );

        const auto lookupQuery = m_Registry.find( node );
        if ( lookupQuery == m_Registry.end() )
        {
            // Failed to find actor on the target node, it is safe to register.
            m_Registry.insert( { node, actor } );
            return true;
        }

        // The target node already contains another actor.
        return false;
    }

    bool GridActorRegistry::TryGetNodeOccupiedByActor( const Actor* actor, Node& node ) const
    {
        for ( const auto pair: m_Registry )
        {
            if ( pair.second == actor )
            {
                node = pair.first;
                return true;
            }
        }

        return false;
    }
} // namespace Engine
