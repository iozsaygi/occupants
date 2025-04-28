#include "Engine.h"

int main( int argc, char* argv[] )
{
    // Create and try to initialize engine entry and related subsystems.
    Engine::EngineEntry engineEntry;

    if ( engineEntry.TryInitializingSubsystems() == Engine::Unstable ) return -1;

    engineEntry.ShutdownSubsystems();

    return 0;
}
