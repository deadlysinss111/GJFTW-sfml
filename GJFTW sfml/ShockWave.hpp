#pragma once
#include "GameObject.hpp"


class InputManager;

namespace Maths {
	float normalizing(sf::Vector2f* vect);
	void normalized(sf::Vector2f* vect);
}

class ShockWave : public GameObject {
public:
	ShockWave(sf::RenderWindow* window, sf::Vector2f* direction);
	~ShockWave();

	sf::Vector2f v1;
	sf::Vector2f v2;

	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void calculateBase(sf::Vector2f*);
	void rotateShape();
};
