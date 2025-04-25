#include "Engine.h"

int main( int argc, char* argv[] )
{
    // Create and try to initialize engine entry and related subsystems.
    Engine::EngineEntry engineEntry;
    engineEntry.TryInitializingSubsystems();
    engineEntry.ShutdownSubsystems();

    return 0;
}
