#ifndef TURN_MANAGER_H
#define TURN_MANAGER_H

#include "Player.h"

class TurnManager final : public Engine::Actor
{
public:
    TurnManager( Player* firstPlayer, Player* secondPlayer );

private:
    Player* m_FirstPlayer = nullptr;
    Player* m_SecondPlayer = nullptr;
};

#endif // TURN_MANAGER_H
