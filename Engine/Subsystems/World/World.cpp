#include "World.h"
#include <assert.h>

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

        m_AttachedScene->IsActive = true;
        m_AttachedScene->Start();

        while ( m_AttachedScene->IsActive )
        {
            m_AttachedScene->Update();
            m_AttachedScene->Render();
        }
    }

    void World::Shutdown()
    {
        if ( m_AttachedScene != nullptr ) m_AttachedScene->Shutdown();
    }

} // namespace Engine
