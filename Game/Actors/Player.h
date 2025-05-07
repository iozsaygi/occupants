#ifndef PLAYER_H
#define PLAYER_H

#include "Engine.h"

enum MovementDirection
{
    Upwards,
    Downwards,
    Left,
    Right
};

enum ControlScheme
{
    WASD,
    Arrows
};

class OccupationManager;

class Player final : public Engine::Actor
{
public:
    Engine::Color AssociatedColor;

    Player( ControlScheme controlScheme, int spawnNodeID, Engine::Color associatedColor,
            OccupationManager* occupationManager );

    void OnSceneStart() override;
    void OnSceneUpdate( float deltaTime, Engine::DispatchableEvent dispatchedEventForCurrentFrame ) override;
    void OnSceneRender( Engine::Renderer* rendererSubsystem ) override;
    void OnSceneShutdown() override;

    bool TryGetMovableNodeBasedOnMovementDirection( MovementDirection movementDirection, const Engine::Node& origin,
                                                    Engine::Node& node ) const;
    void MoveToNode( Engine::Node& node );

private:
    Engine::Grid* m_GridSubsystem = nullptr;
    OccupationManager* m_OccupationManager;

    int m_SpawnNodeID;
    Engine::Node m_OccupiedNode;

    ControlScheme m_ControlScheme;
};

#endif // PLAYER_H
