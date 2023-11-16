#pragma once
#include "GameObject.hpp"

class InputManager;

namespace sf
{
	class RenderWindow; // Demander si utile car fonctionne sans mais permet peut être opti de InputManager.
}

class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, sf::RenderWindow* window);
	~Cannon();
private:

	void rotate();

	void update(float deltaT, std::vector<GameObject*>* objectVector);
};
