#include "Player.h"

#include "OccupationManager.h"
#include "TurnManager.h"

Player::Player( const ControlScheme controlScheme, const int spawnNodeID, const Engine::Color associatedColor,
                OccupationManager* occupationManager )
{
    m_ControlScheme = controlScheme;
    m_SpawnNodeID = spawnNodeID;
    AssociatedColor = associatedColor;
    m_OccupationManager = occupationManager;
}

void Player::OnSceneStart()
{
    auto& engineEntry = Engine::EngineEntry::Singleton();
    m_GridSubsystem = &engineEntry.SubsystemRegistry.GridSubsystem;
    m_DebuggerSubsystem = &engineEntry.SubsystemRegistry.DebuggerSubsystem;

    Actor* turnManager = nullptr;

    if ( engineEntry.SubsystemRegistry.WorldSubsystem.AttachedScene->ActiveSceneGraph->TryGetActorByName(
             "Turn Manager", turnManager ) )
    {
        m_TurnManager = dynamic_cast<TurnManager*>( turnManager );
    }

    Engine::Node spawnNode;
    if ( m_GridSubsystem->TryGetNodeWithID( m_SpawnNodeID, spawnNode ) )
    {
        MoveToNode( spawnNode );
    }
}

void Player::OnSceneUpdate( float deltaTime, const Engine::DispatchableEvent dispatchedEventForCurrentFrame )
{
    if ( m_ControlScheme == WASD )
    {
        switch ( dispatchedEventForCurrentFrame )
        {
            case Engine::WKeyDown:
            {
                Engine::Node upwardsNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Upwards, m_OccupiedNode, upwardsNode ) )
                {
                    MoveToNode( upwardsNode );
                }
            }
            break;
            case Engine::AKeyDown:
            {
                Engine::Node leftNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Left, m_OccupiedNode, leftNode ) )
                {
                    MoveToNode( leftNode );
                }
            }
            break;
            case Engine::SKeyDown:
            {
                Engine::Node downwardsNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Downwards, m_OccupiedNode, downwardsNode ) )
                {
                    MoveToNode( downwardsNode );
                }
            }
            break;
            case Engine::DKeyDown:
            {
                Engine::Node rightNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Right, m_OccupiedNode, rightNode ) )
                {
                    MoveToNode( rightNode );
                }
            }
            break;
            default:;
        }
    }
    else
    {
        switch ( dispatchedEventForCurrentFrame )
        {
            case Engine::UpKeyDown:
            {
                Engine::Node upwardsNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Upwards, m_OccupiedNode, upwardsNode ) )
                {
                    MoveToNode( upwardsNode );
                }
            }
            break;
            case Engine::LeftKeyDown:
            {
                Engine::Node leftNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Left, m_OccupiedNode, leftNode ) )
                {
                    MoveToNode( leftNode );
                }
            }
            break;
            case Engine::DownKeyDown:
            {
                Engine::Node downwardsNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Downwards, m_OccupiedNode, downwardsNode ) )
                {
                    MoveToNode( downwardsNode );
                }
            }
            break;
            case Engine::RightKeyDown:
            {
                Engine::Node rightNode;
                if ( TryGetMovableNodeBasedOnMovementDirection( Right, m_OccupiedNode, rightNode ) )
                {
                    MoveToNode( rightNode );
                }
            }
            break;
            default:;
        }
    }
}

void Player::OnSceneRender( Engine::Renderer* rendererSubsystem )
{
    rendererSubsystem->RenderDebugRectangleAtPosition( Position, Scale, AssociatedColor );
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
                return m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 0 ], node );
            }
            break;
        case Downwards:
            if ( origin.Neighbors[ 2 ] != INVALID_NODE_ID )
            {
                return m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 2 ], node );
            }
            break;
        case Left:
            if ( origin.Neighbors[ 3 ] != INVALID_NODE_ID )
            {
                return m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 3 ], node );
            }
            break;
        case Right:
            if ( origin.Neighbors[ 1 ] != INVALID_NODE_ID )
            {
                return m_GridSubsystem->TryGetNodeWithID( origin.Neighbors[ 1 ], node );
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
        m_OccupiedNode = node;

        OccupationData occupationDataOnNode {};
        if ( m_OccupationManager->TryGetOccupationDataWithNodeID( node.ID, occupationDataOnNode ) )
        {
            if ( occupationDataOnNode.Owner != this )
            {
                m_OccupationManager->RemoveOccupation( node.ID );
            }
        }
        else
        {
            m_OccupationManager->OccupyNode( node.ID, this );

            m_DebuggerSubsystem->Trace( "Current score for %s is %d", Name.c_str(),
                                        m_OccupationManager->GetNumberOfOccupationsForPlayer( this ) );
        }

        m_TurnManager->UpdateTurnStateAfterPlayer( this );
    }
}
