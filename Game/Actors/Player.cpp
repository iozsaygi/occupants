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
