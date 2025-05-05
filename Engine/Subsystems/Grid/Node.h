#ifndef NODE_H
#define NODE_H

#include <cstddef>


#include "Mathematics/Vector2D.h"

#define INVALID_NODE_ID ( -1 )
#define NODE_NEIGHBOR_CAPACITY 4
#define NODE_SCALE 32

namespace Engine
{
    enum NodeState
    {
        Available,
        Blocked
    };

    struct Node
    {
        // Unique ID representing the node within the grid. Can be useful if node equality checks required.
        int ID;

        Vector2D Position;
        NodeState State;

        int Neighbors[ NODE_NEIGHBOR_CAPACITY ];

        Node();
        bool operator()( const Node& first, const Node& second ) const;
        bool operator==( const Node& node ) const;
        bool operator!=( const Node& node ) const;
    };
} // namespace Engine

namespace std
{
    template<>
    struct hash<Engine::Node>
    {
        std::size_t operator()( const Engine::Node& node ) const
        {
            return std::hash<int>()(node.ID)  << 1;
        }
    };
} // namespace std

#endif // NODE_H
