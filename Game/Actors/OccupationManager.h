#ifndef OCCUPATION_MANAGER_H
#define OCCUPATION_MANAGER_H

#include <vector>
#include "Subsystems/World/Actor.h"

class OccupationManager final : public Engine::Actor
{
public:
    OccupationManager();

    bool IsNodeAlreadyOccupied( int nodeID ) const;
    void OccupyNode( int nodeID );

private:
    std::vector<int> m_OccupiedNodeIDs;
};

#endif // OCCUPATION_MANAGER_H
