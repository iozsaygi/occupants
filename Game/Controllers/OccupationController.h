#ifndef OCCUPATION_CONTROLLER_H
#define OCCUPATION_CONTROLLER_H

#include <vector>

class OccupationController final
{
public:
    OccupationController();

    bool IsNodeAlreadyOccupied( int nodeID ) const;
    void OccupyNode( int nodeID );

private:
    std::vector<int> m_OccupiedNodeIDs;
};

#endif // OCCUPATION_CONTROLLER_H
