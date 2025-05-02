#ifndef ACTOR_H
#define ACTOR_H

#include "EventDispatcher.h"
#include "Mathematics/Vector2D.h"
#include "Subsystems/Renderer/Renderer.h"

namespace Engine
{
    // No component architecture implemented and will not be implemented until really needed.
    // Directly using inheritance at the moment. Consider other architectures when problems start to arise.
    // Derive from this to create your own custom gameplay behaviours.
    // ReSharper disable once CppClassCanBeFinal
    class Actor
    {
    public:
        Vector2D Position;

        Actor();

        virtual ~Actor();
        virtual void OnSceneStart();
        virtual void OnSceneUpdate( float deltaTime, DispatchableEvent dispatchedEventForCurrentFrame );
        virtual void OnSceneRender( Renderer* rendererSubsystem );
        virtual void OnSceneShutdown();
    };
} // namespace Engine

#endif // ACTOR_H
