#ifndef PLAYER_H
#define PLAYER_H

#include "Engine.h"

class Player final : public Engine::Actor
{
public:
    void OnSceneStart() override;
    void OnSceneUpdate( float deltaTime, Engine::DispatchableEvent dispatchedEventForCurrentFrame ) override;
    void OnSceneRender( Engine::Renderer* rendererSubsystem ) override;
    void OnSceneShutdown() override;

    void MoveToNode( Engine::Node& node );

private:
    Engine::Grid* m_GridSubsystem = nullptr;
};

#endif // PLAYER_H
