#include "Node.h"

namespace Engine
{
    Node::Node() : Position( 0.0f, 0.0f ) // NOLINT(*-pro-type-member-init)
    {
        ID = INVALID_NODE_ID;
        State = Available;

        for ( int& Neighbor: Neighbors ) Neighbor = INVALID_NODE_ID;
    }

    bool Node::operator==( const Node& node ) const
    {
        return ID == node.ID;
    }

    bool Node::operator!=( const Node& node ) const
    {
        return ID != node.ID;
    }

} // namespace Engine
