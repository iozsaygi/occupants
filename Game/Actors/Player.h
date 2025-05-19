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
class TurnManager;

class Player final : public Engine::Actor
{
public:
    int SpawnNodeID;
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
    void MoveToNodeWithoutConstraints( Engine::Node& node );

private:
    Engine::Grid* m_GridSubsystem = nullptr;
    Engine::Debugger* m_DebuggerSubsystem = nullptr;
    OccupationManager* m_OccupationManager;
    TurnManager* m_TurnManager;

    Engine::Node m_OccupiedNode;

    ControlScheme m_ControlScheme;
};

#endif // PLAYER_H
