#include "Actors/Player.h"
#include "Engine.h"

int main( int argc, char* argv[] )
{
    Engine::EngineEntry engineEntry;
    if ( engineEntry.TryInitializingSubsystems() == Engine::Unstable ) return -1;

    // Let the world know about subsystems. (This step probably needs reconsideration in terms of meaningful API usage)
    engineEntry.SubsystemRegistry.WorldSubsystem.AttachSubsystemRegistry( &engineEntry.SubsystemRegistry );

    const auto scene = new Engine::Scene();

    engineEntry.SubsystemRegistry.WorldSubsystem.AttachScene( scene );

    engineEntry.SubsystemRegistry.GridSubsystem.Create( 10, 10 );

    const auto player = new Player();

    if ( !scene->ActiveSceneGraph->TryRegisterActor( player ) )
    {
        engineEntry.SubsystemRegistry.DebuggerSubsystem.Error(
            "Failed to register 'Player' actor to the attached scene!" );
    }

    Engine::Node firstPlayerSpawnNode;

    if ( engineEntry.SubsystemRegistry.GridSubsystem.TryGetNodeWithID( 90, firstPlayerSpawnNode ) )
    {
        player->MoveToNode( firstPlayerSpawnNode );
    }

    engineEntry.SubsystemRegistry.WorldSubsystem.RunAttachedScene();

    // Shutdown the subsystems, clean up resources.
    engineEntry.ShutdownSubsystems();

    // Pointer clean up.
    delete player;
    delete scene;

    return 0;
}
