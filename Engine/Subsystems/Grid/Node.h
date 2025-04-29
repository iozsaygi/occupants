#ifndef NODE_H
#define NODE_H

#include "Mathematics/Vector2D.h"

#define INVALID_NODE_ID -1
#define NODE_NEIGHBOR_CAPACITY 4

namespace Engine
{
    struct Node
    {
        // Unique ID representing the node within the grid. Can be useful if node equality checks required.
        int ID;

        Vector2D Position;

        int Neighbors[ NODE_NEIGHBOR_CAPACITY ];

        // Just default 'ctor'.
        Node();
    };
} // namespace Engine

#endif // NODE_H
