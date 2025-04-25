#ifndef PLATFORM_H
#define PLATFORM_H

#include "Core/EngineSubsystem.h"

namespace Engine
{
    // Platform layer is working on top of SDL (Such as any possible other engine subsystem available).
    // It requires SDL to create windows and setup further game context.
    class Platform final : public EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;

        void Shutdown() override;
    };
} // namespace Engine

#endif // PLATFORM_H
