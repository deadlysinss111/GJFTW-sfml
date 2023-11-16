#pragma once
class GameObject;

namespace Collision {
	bool rectToRect(GameObject* objOne, GameObject* objTwo);
	bool circleToRect(GameObject* objOne, GameObject* objTwo);
	bool circleToCircle(GameObject* objOne, GameObject* objTwo);
}