#include "Actors/OccupationManager.h"
#include "Actors/Player.h"
#include "Actors/TurnManager.h"
#include "Engine.h"

int main( int argc, char* argv[] )
{
    auto& engineEntry = Engine::EngineEntry::Singleton();
    if ( engineEntry.TryInitializingSubsystems() == Engine::Unstable ) return -1;

    // Let the world know about subsystems. (This step probably needs reconsideration in terms of meaningful API usage)
    engineEntry.SubsystemRegistry.WorldSubsystem.AttachSubsystemRegistry( &engineEntry.SubsystemRegistry );

    const auto scene = new Engine::Scene();

    engineEntry.SubsystemRegistry.WorldSubsystem.AttachScene( scene );
    engineEntry.SubsystemRegistry.GridSubsystem.Create( 10, 10 );
    engineEntry.SubsystemRegistry.GridSubsystem.ProcedurallyBlockNodes();

    constexpr Engine::Color blue = { 0, 0, 255, 255 };
    constexpr Engine::Color red = { 255, 0, 0, 255 };

    const auto occupationManager = new OccupationManager();
    const auto firstPlayer = new Player( WASD, 90, blue, occupationManager );
    const auto secondPlayer = new Player( Arrows, 9, red, occupationManager );
    const auto turnManager = new TurnManager( firstPlayer, secondPlayer );

    firstPlayer->Name = "Player 1";
    secondPlayer->Name = "Player 2";
    occupationManager->Name = "Occupation Manager";
    turnManager->Name = "Turn Manager";

    if ( !scene->ActiveSceneGraph->TryRegisterActor( firstPlayer ) )
    {
        engineEntry.SubsystemRegistry.DebuggerSubsystem.Error(
            "Failed to register 'First Player' actor to the attached scene!" );
    }

    if ( !scene->ActiveSceneGraph->TryRegisterActor( secondPlayer ) )
    {
        engineEntry.SubsystemRegistry.DebuggerSubsystem.Error(
            "Failed to register 'Second Player' actor to the attached scene!" );
    }

    if ( !scene->ActiveSceneGraph->TryRegisterActor( occupationManager ) )
    {
        engineEntry.SubsystemRegistry.DebuggerSubsystem.Error(
            "Failed to register 'Occupation Manager' actor to the attached scene!" );
    }

    if ( !scene->ActiveSceneGraph->TryRegisterActor( turnManager ) )
    {
        engineEntry.SubsystemRegistry.DebuggerSubsystem.Error(
            "Failed to register 'Turn Manager' actor to the attached scene!" );
    }

    engineEntry.SubsystemRegistry.WorldSubsystem.RunAttachedScene();

    // Shutdown the subsystems, clean up resources.
    engineEntry.ShutdownSubsystems();

    // Pointer clean up.
    delete firstPlayer;
    delete secondPlayer;
    delete occupationManager;
    delete turnManager;
    delete scene;

    return 0;
}
