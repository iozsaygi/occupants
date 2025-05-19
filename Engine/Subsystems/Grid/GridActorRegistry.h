#ifndef GRID_ACTOR_REGISTRY_H
#define GRID_ACTOR_REGISTRY_H

#include <map>
#include "Node.h"
#include "Subsystems/World/Actor.h"

namespace Engine
{
    class GridActorRegistry final
    {
    public:
        GridActorRegistry();

        bool TryRegisterActor( Node& node, Actor* actor );
        bool TryRemoveActor( const Actor* actor );
        bool TryGetActorFromNode( const Node& node, const Actor* actor );
        bool TryGetNodeOccupiedByActor( const Actor* actor, Node& node ) const;

    private:
        // Using 'int' as key to avoid custom hashing for 'Node' types.
        // The 'ID' property within 'Node' struct is already unique one.
        // So this is essentially maps to 'std::unordered_map<Node.ID, Actor*>'.
        std::unordered_map<int, Actor*> m_Registry;
    };
} // namespace Engine

#endif // GRID_ACTOR_REGISTRY_H
