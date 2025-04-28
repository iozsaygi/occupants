#ifndef SCENE_H
#define SCENE_H

namespace Engine
{
    class Scene final
    {
    public:
        // Core scene lifetime cycle.
        void Start();
        void Update();
        void Render();
        void Shutdown();
    };
} // namespace Engine

#endif // SCENE_H
