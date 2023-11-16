#pragma once
#include "GameObject.hpp"


class InputManager;

namespace Maths {
	float normalizing(sf::Vector2f* vect);
	void normalized(sf::Vector2f* vect);
}

class Houreglass : public GameObject {
public:
	Houreglass(sf::RenderWindow* window, int x, int y, int w, int h, float lifespan);
	~Houreglass();
private:

	void melt(float deltaT);

	void update(float deltaT, std::vector<GameObject*>* objectVector);

	float lifespan;
	float meltingSpeed;
	float remainingLife;
};
