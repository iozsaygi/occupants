#include "OccupationManager.h"
#include <cassert>

OccupationManager::OccupationManager()
{
    m_OccupationRegistry = std::vector<OccupationData>();
}

bool OccupationManager::TryGetOccupationDataWithNodeID( const int nodeID, OccupationData& occupationData ) const
{
    assert( nodeID >= 0 );

    for ( const auto& occupationDataInRegistry: m_OccupationRegistry )
    {
        if ( occupationDataInRegistry.NodeID == nodeID )
        {
            occupationData = occupationDataInRegistry;
            return true;
        }
    }

    return false;
}

void OccupationManager::OccupyNode( const int nodeID, Player* player )
{
    assert( nodeID >= 0 );
    assert( player != nullptr );

    OccupationData occupationData {};
    occupationData.NodeID = nodeID;
    occupationData.Owner = player;

    m_OccupationRegistry.push_back( occupationData );
}

void OccupationManager::RemoveOccupation( const int nodeID )
{
    assert( nodeID >= 0 );

    // Maybe a good reason to dislike 'std'?
    m_OccupationRegistry.erase( std::remove_if( m_OccupationRegistry.begin(), m_OccupationRegistry.end(),
                                                [ nodeID ]( const OccupationData& data )
                                                { return data.NodeID == nodeID; } ),
                                m_OccupationRegistry.end() );
}

void OccupationManager::OnSceneStart()
{
    auto& engineEntry = Engine::EngineEntry::Singleton();
    m_GridSubsystem = &engineEntry.SubsystemRegistry.GridSubsystem;
}

void OccupationManager::OnSceneRender( Engine::Renderer* rendererSubsystem )
{
    for ( const auto& occupationData: m_OccupationRegistry )
    {
        Engine::Node occupationNode;
        if ( !m_GridSubsystem->TryGetNodeWithID( occupationData.NodeID, occupationNode ) ) continue;

        const Engine::Vector2D scale( 16.0f, 16.0f );

        rendererSubsystem->RenderDebugRectangleAtPosition( occupationNode.Position, scale,
                                                           occupationData.Owner->AssociatedColor );
    }
}
