#ifndef GRID_H
#define GRID_H

#include "Core/EngineSubsystem.h"
#include "Node.h"
#include "Subsystems/Renderer/Renderer.h"

namespace Engine
{
    class Grid final : EngineSubsystem
    {
    public:
        int Width;
        int Height;
        int Length;

        EngineSubsystemInitializationResult Initialize() override;
        void Create( int width, int height );
        bool TryGetNodeWithID( int id, Node& node ) const;

        // So most of the engine subsystems doesn't require to be rendered at all.
        // This could be virtual method on the base engine subsystem class but for now grid is the only subsystem to be
        // rendered.
        void Render( const Renderer* rendererSubsystem ) const;

        void Shutdown() override;

    private:
        Node* m_NodeGraph = nullptr;
    };
} // namespace Engine

#endif // GRID_H
