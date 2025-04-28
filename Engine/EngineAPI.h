#ifndef ENGINE_API_H
#define ENGINE_API_H

#ifdef _WIN32
#ifdef ENGINE_BUILD_DLL
#define ENGINE_API __declspec( dllexport )
#else
#define ENGINE_API __declspec( dllimport )
#endif
#elif __APPLE__
#ifdef ENGINE_BUILD_SHARED_OBJECT
#define ENGINE_API __attribute__( ( visibility( "default" ) ) )
#else
#define ENGINE_API
#endif
#else
#error Failed to define ENGINE_API for current platform!
#endif

#endif // ENGINE_API_H
