#include "TurnManager.h"
#include <assert.h>

TurnManager::TurnManager( Player* firstPlayer, Player* secondPlayer )
{
    m_FirstPlayer = firstPlayer;
    m_SecondPlayer = secondPlayer;

    // The first movement always goes to first player.
    m_PlayerWithInCurrentTurn = firstPlayer;
}

bool TurnManager::CanPlayerMove( const Player* player ) const
{
    assert( player != nullptr );

    return m_PlayerWithInCurrentTurn == player;
}

void TurnManager::UpdateTurnStateAfterPlayer( const Player* player )
{
    assert( player != nullptr );

    if ( player == m_FirstPlayer )
        m_PlayerWithInCurrentTurn = m_SecondPlayer;
    else
        m_PlayerWithInCurrentTurn = m_FirstPlayer;
}
