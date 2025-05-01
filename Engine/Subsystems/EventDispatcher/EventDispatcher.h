#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include "Core/EngineSubsystem.h"

namespace Engine
{
    class EventDispatcher final : EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;
        void Shutdown() override;
    };
} // namespace Engine

#endif // EVENT_DISPATCHER_H
