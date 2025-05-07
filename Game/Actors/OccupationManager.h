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

    bool TryGetOccupationDataWithNodeID( int nodeID, OccupationData& occupationData ) const;

    void OccupyNode( int nodeID, Player* player );
    void RemoveOccupation( int nodeID );

    void OnSceneStart() override;
    void OnSceneRender( Engine::Renderer* rendererSubsystem ) override;

private:
    Engine::Grid* m_GridSubsystem = nullptr;
    std::vector<OccupationData> m_OccupationRegistry;
};

#endif // OCCUPATION_MANAGER_H
