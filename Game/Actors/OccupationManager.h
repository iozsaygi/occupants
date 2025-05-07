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

private:
    std::vector<OccupationData> m_OccupationRegistry;
};

#endif // OCCUPATION_MANAGER_H
