#include "Collision.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Cannon.hpp"

bool Collision::collisionResult = false;

void Collision::rectToRect(GameObject* objOne, GameObject* objTwo) {
    bool result = false;

    if (objTwo != objOne) {
        if (objOne->x < objTwo->x + objTwo->w && objOne->x + objOne->w > objTwo->x && objOne->y < objTwo->y + objTwo->h && objOne->y + objOne->h > objTwo->y) {
            result = true;
        }
    }
}

void Collision::circleToRect(GameObject* objOne, GameObject* objTwo) {
    bool result = false;

    float disatanceX = std::abs(objOne->x - objTwo->x);
    float disatanceY = std::abs(objOne->y - objTwo->y);
    if (disatanceX > (objTwo->w / 2 + objOne->h) || disatanceY > (objTwo->h / 2 + objOne->h)) {
        return;
    }
    if (disatanceX <= (objTwo->w / 2) || disatanceY <= (objTwo->h / 2)) {
        result = true;
        return;
    }

    auto cornerDistance_sq = (disatanceX - objTwo->w / 2) * (disatanceX - objTwo->w / 2) + (disatanceY - objTwo->h / 2) * (disatanceY - objTwo->h / 2);

    if (cornerDistance_sq <= (objOne->h * objOne->h)) {
        result = true;
    }
}

void Collision::circleToCircle(GameObject* objOne, GameObject* objTwo) {
    bool result = false;

    float distanceX = std::abs(objOne->x - objTwo->x);
    float distanceY = std::abs(objOne->y - objTwo->y);
    float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
    if ((objOne->w + objTwo->w) >= distance) {
        result = true;
    }
}
