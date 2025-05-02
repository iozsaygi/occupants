#include "Player.h"

void Player::OnSceneStart()
{
}

void Player::OnSceneUpdate( float deltaTime, Engine::DispatchableEvent dispatchedEventForCurrentFrame )
{
}

void Player::OnSceneRender( Engine::Renderer* rendererSubsystem )
{
    rendererSubsystem->RenderDebugRectangleAtPosition( Position, Scale );
}

void Player::OnSceneShutdown()
{
}
