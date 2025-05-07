#include "World.h"
#include <cassert>
#include <chrono>
#include <thread>

#include "Core/EngineSubsystemRegistry.h"

namespace Engine
{
    EngineSubsystemInitializationResult World::Initialize()
    {
        return SuccessfullyInitialized;
    }

    void World::AttachSubsystemRegistry( EngineSubsystemRegistry* engineSubsystemRegistry )
    {
        assert( engineSubsystemRegistry != nullptr );
        assert( m_AttachedEngineSubsystemRegistry == nullptr );

        m_AttachedEngineSubsystemRegistry = engineSubsystemRegistry;
    }

    void World::AttachScene( Scene* scene )
    {
        assert( scene != nullptr );

        // Shutdown the active scene before attaching new one.
        if ( AttachedScene != nullptr ) AttachedScene->Shutdown();

        AttachedScene = scene;
    }

    void World::RunAttachedScene() const
    {
        assert( AttachedScene != nullptr );

        m_AttachedEngineSubsystemRegistry->DebuggerSubsystem.Trace(
            "Starting to run update loop for attached scene. There are %d actors registered to the scene.",
            AttachedScene->ActiveSceneGraph->Count );

        AttachedScene->IsActive = true;
        AttachedScene->Start();

        auto lastRegisteredTime = std::chrono::high_resolution_clock::now();

        // Targeting 30 frames per second, maybe make this somehow adjustable by game.
        constexpr float targetFrameTime = 1.0f / 30.0f;

        while ( AttachedScene->IsActive )
        {
            auto currentTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> elapsedTime = currentTime - lastRegisteredTime;

            float deltaTime = elapsedTime.count();

            lastRegisteredTime = currentTime;

            if ( deltaTime < targetFrameTime )
            {
                std::this_thread::sleep_for( std::chrono::duration<float>( targetFrameTime - deltaTime ) );
                currentTime = std::chrono::high_resolution_clock::now();
                elapsedTime = currentTime - lastRegisteredTime;
                deltaTime = elapsedTime.count();
                lastRegisteredTime = currentTime;
            }

            AttachedScene->Update( deltaTime );
            AttachedScene->Render( &m_AttachedEngineSubsystemRegistry->RendererSubsystem,
                                   &m_AttachedEngineSubsystemRegistry->GridSubsystem );
        }

        AttachedScene->Shutdown();

        m_AttachedEngineSubsystemRegistry->DebuggerSubsystem.Trace(
            "Finished running update loop of attached scene and cleaned up scene resources." );
    }

    void World::Shutdown()
    {
    }

} // namespace Engine
