#include "EngineSubsystem.h"

namespace Engine
{
    EngineSubsystem::~EngineSubsystem() = default;

    EngineSubsystemInitializationResult EngineSubsystem::Initialize()
    {
        return SuccessfullyInitialized;
    }

    void EngineSubsystem::Shutdown()
    {
    }
} // namespace Engine
