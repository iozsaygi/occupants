#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <cstdarg>
#include "Core/EngineSubsystem.h"

namespace Engine
{
    class Debugger final : public EngineSubsystem
    {
    public:
        EngineSubsystemInitializationResult Initialize() override;

        void Shutdown() override;

        void Trace( const char* trace, ... );
        void Warning( const char* warning, ... );
        void Error( const char* error, ... );

    private:
        static void LogWrapper( const char* tag, const char* message, va_list args );
    };
} // namespace Engine

#endif // DEBUGGER_H
