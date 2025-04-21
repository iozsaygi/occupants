#include "EngineSubsystem.h"

namespace Engine
{
    EngineSubsystemInitializationResult EngineSubsystem::Initialize()
    {
        return SuccessfullyInitialized;
    }

    void EngineSubsystem::Shutdown()
    {
    }
} // namespace Engine
