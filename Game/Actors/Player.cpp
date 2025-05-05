#include "Player.h"

void Player::OnSceneStart()
{
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

void Player::MoveToNode( const Engine::Node& node )
{
    Position.X = node.Position.X;
    Position.Y = node.Position.Y;
}
