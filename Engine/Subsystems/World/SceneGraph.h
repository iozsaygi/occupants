#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "Actor.h"

namespace Engine
{
    // The manager of the actors within the scene. No matter if they are visible (rendered) or not.
    class SceneGraph final
    {
    public:
        int Capacity;
        int Count;

        explicit SceneGraph( int actorCapacity );
        ~SceneGraph();

        bool TryRegisterActor( Actor* actor );
        bool TryGetActorBySceneGraphIndex( int index, Actor*& actor ) const;
        bool TryGetActorByName( const std::string& name, Actor*& actor ) const;

    private:
        Actor** m_Actors = nullptr;

        bool TryFindFirstAvailableSceneGraphIndex( int& index ) const;
    };
} // namespace Engine

#endif // SCENE_GRAPH_H
