#include "World.h"
#include <assert.h>

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
        if ( m_AttachedScene != nullptr ) m_AttachedScene->Shutdown();

        m_AttachedScene = scene;
    }

    void World::RunAttachedScene() const
    {
        assert( m_AttachedScene != nullptr );

        m_AttachedEngineSubsystemRegistry->DebuggerSubsystem.Trace( "Starting to run update loop for attached scene" );

        m_AttachedScene->IsActive = true;
        m_AttachedScene->Start();

        while ( m_AttachedScene->IsActive )
        {
            m_AttachedScene->Update();
            m_AttachedScene->Render( &m_AttachedEngineSubsystemRegistry->RendererSubsystem );
        }

        m_AttachedScene->Shutdown();

        m_AttachedEngineSubsystemRegistry->DebuggerSubsystem.Trace(
            "Finished running update loop of attached scene and cleaned up scene resources" );
    }

    void World::Shutdown()
    {
    }

} // namespace Engine
