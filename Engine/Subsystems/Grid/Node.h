#ifndef NODE_H
#define NODE_H

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
    };
} // namespace Engine

#endif // NODE_H
