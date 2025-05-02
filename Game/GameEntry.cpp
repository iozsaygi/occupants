#include "Actors/Player.h"
#include "Engine.h"

int main( int argc, char* argv[] )
{
    // Create and try to initialize engine entry and related subsystems.
    Engine::EngineEntry engineEntry;
    if ( engineEntry.TryInitializingSubsystems() == Engine::Unstable ) return -1;

    // Let the world know about subsystems. (This step probably needs reconsideration in terms of meaningful API usage)
    engineEntry.SubsystemRegistry.WorldSubsystem.AttachSubsystemRegistry( &engineEntry.SubsystemRegistry );

    // Create an empty scene.
    const auto scene = new Engine::Scene();

    // Attach scene to world.
    engineEntry.SubsystemRegistry.WorldSubsystem.AttachScene( scene );

    // Create a grid.
    engineEntry.SubsystemRegistry.GridSubsystem.Create( 10, 10 );

    // Create instances of our actors.
    const auto player = new Player();

    // Register actors to the scene.
    if ( !scene->ActiveSceneGraph->TryRegisterActor( player ) )
    {
        engineEntry.SubsystemRegistry.DebuggerSubsystem.Error(
            "Failed to register 'Player' actor to the attached scene!" );
    }

    // Run the attached scene.
    engineEntry.SubsystemRegistry.WorldSubsystem.RunAttachedScene();

    // Shutdown the subsystems, clean up resources.
    engineEntry.ShutdownSubsystems();

    // Pointer clean up.
    delete player;
    delete scene;

    return 0;
}
