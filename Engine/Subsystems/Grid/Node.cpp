#include "Node.h"

namespace Engine
{
    Node::Node() : Position( 0.0f, 0.0f ) // NOLINT(*-pro-type-member-init)
    {
        ID = INVALID_NODE_ID;

        for ( int& Neighbor: Neighbors ) Neighbor = INVALID_NODE_ID;
    }

} // namespace Engine
