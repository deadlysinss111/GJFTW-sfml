#pragma once
#include <vector>
#include "GameObject.hpp"


class InputManager;

namespace Maths {
	float normalizing(sf::Vector2f* vect);
	void normalized(sf::Vector2f* vect);
	int getAngle(sf::Vector2f* target);
}

class ShockWave : public GameObject {
public:
	ShockWave(sf::RenderWindow* window, sf::Vector2f* direction, float lifespan);
	~ShockWave();

	sf::Vector2f v1;
	sf::Vector2f v2;
	float lifespan;
	std::vector<GameObject*> collidedObjects;

	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void calculateBase(sf::Vector2f*);
	void rotateShape();
	void move(float deltaT);
	bool circleToRect(GameObject* objOne, GameObject* objTwo);
};
