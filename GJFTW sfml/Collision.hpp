#pragma once
class GameObject;

namespace Collision {
    extern bool collisionResult;
    void rectToRect(GameObject* objOne, GameObject* objTwo);
    void circleToRect(GameObject* objOne, GameObject* objTwo);
    void circleToCircle(GameObject* objOne, GameObject* objTwo);
}