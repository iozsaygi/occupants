#ifndef OCCUPATION_MANAGER_H
#define OCCUPATION_MANAGER_H

#include <vector>
#include "Player.h"
#include "Subsystems/World/Actor.h"

struct OccupationData
{
    Player* Owner;
    int NodeID;
};

class OccupationManager final : public Engine::Actor
{
public:
    OccupationManager();

    void OnSceneStart() override;
    void OnSceneRender( Engine::Renderer* rendererSubsystem ) override;

    bool TryGetOccupationDataWithNodeID( int nodeID, OccupationData& occupationData ) const;
    int GetNumberOfOccupationsForPlayer( const Player* player ) const;

    void OccupyNode( int nodeID, Player* player );
    void RemoveOccupation( int nodeID );

private:
    Engine::Grid* m_GridSubsystem = nullptr;
    std::vector<OccupationData> m_OccupationRegistry;
};

#endif // OCCUPATION_MANAGER_H
