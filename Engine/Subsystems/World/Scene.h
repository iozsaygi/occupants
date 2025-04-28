#ifndef SCENE_H
#define SCENE_H

namespace Engine
{
    class Scene final
    {
    public:
        bool IsActive;

        // Core scene lifetime cycle.
        void Start();
        void Update();
        void Render();
        void Shutdown();
    };
} // namespace Engine

#endif // SCENE_H
