#include "OccupationManager.h"
#include <cassert>

OccupationManager::OccupationManager()
{
    m_OccupiedNodeIDs = std::vector<int>();
}

bool OccupationManager::IsNodeAlreadyOccupied( const int nodeID ) const
{
    assert( nodeID >= 0 );

    // Quick linear search until hitting performance issues.
    for ( const int m_OccupiedNodeID: m_OccupiedNodeIDs ) // NOLINT(*-use-anyofallof)
    {
        if ( m_OccupiedNodeID == nodeID ) return true;
    }

    return false;
}

void OccupationManager::OccupyNode( const int nodeID )
{
    assert( nodeID >= 0 );

    // Do not proceed if the node already occupied by this occupation controller.
    if ( IsNodeAlreadyOccupied( nodeID ) ) return;

    m_OccupiedNodeIDs.push_back( nodeID );
}
