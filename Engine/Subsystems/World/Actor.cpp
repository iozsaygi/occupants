#include "Actor.h"

namespace Engine
{
    Actor::~Actor() = default;

    void Actor::OnSceneStart()
    {
    }

    void Actor::OnSceneUpdate( float deltaTime, DispatchableEvent dispatchedEventForCurrentFrame )
    {
    }

    void Actor::OnSceneRender( Renderer* rendererSubsystem )
    {
    }

    void Actor::OnSceneShutdown()
    {
    }

} // namespace Engine
