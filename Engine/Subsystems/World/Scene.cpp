#include "Scene.h"

namespace Engine
{
    void Scene::Start()
    {
    }

    void Scene::Update()
    {
    }

    void Scene::Render()
    {
    }

    void Scene::Shutdown()
    {
        if ( IsActive ) IsActive = false;
    }

} // namespace Engine
