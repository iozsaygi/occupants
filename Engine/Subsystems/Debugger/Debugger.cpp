// ReSharper disable CppMemberFunctionMayBeStatic

#include "Debugger.h"
#include <cstdio>

namespace Engine
{
    EngineSubsystemInitializationResult Debugger::Initialize()
    {
        return SuccessfullyInitialized;
    }

    void Debugger::Shutdown()
    {
    }

    void Debugger::Trace( const char* trace ) // NOLINT(*-convert-member-functions-to-static)
    {
        va_list args;
        va_start( args, trace );
        LogWrapper( "Trace", trace, args );
        va_end( args );
    }

    void Debugger::Warning( const char* warning ) // NOLINT(*-convert-member-functions-to-static)
    {
        va_list args;
        va_start( args, warning );
        LogWrapper( "Warning", warning, args );
        va_end( args );
    }

    void Debugger::Error( const char* error ) // NOLINT(*-convert-member-functions-to-static)
    {
        va_list args;
        va_start( args, error );
        LogWrapper( "Error", error, args );
        va_end( args );
    }

    void Debugger::LogWrapper( const char* tag, const char* message, const va_list arguments )
    {
        constexpr size_t bufferSize = 1024;
        char buffer[ bufferSize ];
        vsnprintf( buffer, bufferSize, message, arguments );
        printf( "[%s] %s\n", tag, buffer );
    }

} // namespace Engine
