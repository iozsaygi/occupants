#ifndef TURN_MANAGER_H
#define TURN_MANAGER_H

#include "Player.h"

class TurnManager final : public Engine::Actor
{
public:
    TurnManager( Player* firstPlayer, Player* secondPlayer );

    bool CanPlayerMove( const Player* player ) const;
    void UpdateTurnStateAfterPlayer( const Player* player );
    void ResetTurnState();

private:
    Player* m_FirstPlayer = nullptr;
    Player* m_SecondPlayer = nullptr;
    Player* m_PlayerWithInCurrentTurn = nullptr;
};

#endif // TURN_MANAGER_H
