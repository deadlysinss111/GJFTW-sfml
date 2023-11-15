#pragma once
#include "GameObject.hpp"

class InputManager;

namespace sf
{
	class RenderWindow; // Demander si utile car fonctionne sans mais permet peut être opti de InputManager.
}

namespace Maths {
	float normalizing(sf::Vector2f* vect);
	int getAngle(sf::Vector2f* target);
}

class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, sf::RenderWindow* window);
	~Cannon();
	
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void rotate();
};
