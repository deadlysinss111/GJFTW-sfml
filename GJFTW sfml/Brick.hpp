#pragma once
#include "GameObject.hpp"

class Brick : public GameObject {
public:
	Brick(sf::RenderWindow* window, int x, int y, int hp);
	~Brick();
private:

	void onHit(GameObject* target);
	void update(float deltaT, std::vector<GameObject*>* objectVector);

	int hp;

	static std::map<int, sf::Color> colorMap;
};