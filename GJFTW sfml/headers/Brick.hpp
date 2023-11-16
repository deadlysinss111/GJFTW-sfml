#pragma once
#include "GameObject.hpp"

class Brick : public GameObject {
public:
	Brick(sf::RenderWindow* window, int x, int y, int hp);
	~Brick();
private:

	void onHit(GameObject* target);
	void update(float deltaT, std::vector<GameObject*>* objectVector);
	void display(sf::RenderWindow* window);

	int hp;
};