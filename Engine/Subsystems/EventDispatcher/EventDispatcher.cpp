#include "EventDispatcher.h"

namespace Engine
{
    EngineSubsystemInitializationResult EventDispatcher::Initialize()
    {
        return SuccessfullyInitialized;
    }

    void EventDispatcher::Shutdown()
    {
    }
} // namespace Engine
