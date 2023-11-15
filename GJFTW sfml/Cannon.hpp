#pragma once
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Maths.hpp"

class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, sf::RenderWindow* window);
	~Cannon();
	
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void rotate();
};
