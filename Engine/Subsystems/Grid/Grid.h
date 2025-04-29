#ifndef GRID_H
#define GRID_H

#include "Core/EngineSubsystem.h"
#include "Node.h"

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
        void Shutdown() override;

    private:
        Node* m_NodeGraph = nullptr;
    };
} // namespace Engine

#endif // GRID_H
