#include "Player.h"

void Player::OnSceneStart()
{
    auto& engineEntry = Engine::EngineEntry::Singleton();
    m_GridSubsystem = &engineEntry.SubsystemRegistry.GridSubsystem;

    Engine::Node spawnNode;
    if ( m_GridSubsystem->TryGetNodeWithID( 90, spawnNode ) )
    {
        MoveToNode( spawnNode );
    }
}

void Player::OnSceneUpdate( float deltaTime, Engine::DispatchableEvent dispatchedEventForCurrentFrame )
{
}

void Player::OnSceneRender( Engine::Renderer* rendererSubsystem )
{
    constexpr Engine::Color color = { 0, 0, 255, 0 };
    rendererSubsystem->RenderDebugRectangleAtPosition( Position, Scale, color );
}

void Player::OnSceneShutdown()
{
}

bool Player::TryGetMovableNodeBasedOnMovementDirection( const MovementDirection movementDirection,
                                                        const Engine::Node& origin, Engine::Node& node ) const
{
    switch ( movementDirection )
    {
        case Upwards:
            if ( origin.Neighbors[ 0 ] != INVALID_NODE_ID )
            {
                m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 0 ], node );
                return true;
            }
            break;
        case Downwards:
            if ( origin.Neighbors[ 2 ] != INVALID_NODE_ID )
            {
                m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 2 ], node );
                return true;
            }
            break;
        case Left:
            if ( origin.Neighbors[ 3 ] != INVALID_NODE_ID )
            {
                m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 3 ], node );
                return true;
            }
            break;
        case Right:
            if ( origin.Neighbors[ 1 ] != INVALID_NODE_ID )
            {
                m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 1 ], node );
                return true;
            }
            break;
    }

    return false;
}

void Player::MoveToNode( Engine::Node& node )
{
    // First try to remove existing storage.
    m_GridSubsystem->ActorRegistry->TryRemoveActor( this );

    // Now try to actually move actor to target node.
    if ( m_GridSubsystem->ActorRegistry->TryRegisterActor( node, this ) )
    {
        Position.X = node.Position.X;
        Position.Y = node.Position.Y;
    }
}
