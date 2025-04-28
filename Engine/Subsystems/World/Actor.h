#ifndef ACTOR_H
#define ACTOR_H

namespace Engine
{
    // No component architecture implemented and will not be implemented until really needed.
    // Directly using inheritance at the moment. Consider other architectures when problems start to arise.
    // Derive from this to create your own custom gameplay behaviours.
    // ReSharper disable once CppClassCanBeFinal
    class Actor
    {
    public:
        virtual ~Actor();
        virtual void OnSceneStart();
        virtual void OnSceneUpdate( float deltaTime );
        virtual void OnSceneShutdown();
    };
} // namespace Engine

#endif // ACTOR_H
