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

        bool TryRegisterActorToNode( Node& node, Actor* actor );
        bool TryGetNodeOccupiedByActor( const Actor* actor, Node& node ) const;

    private:
        std::map<Node, Actor*> m_Registry;
    };
} // namespace Engine

#endif // GRID_ACTOR_REGISTRY_H
