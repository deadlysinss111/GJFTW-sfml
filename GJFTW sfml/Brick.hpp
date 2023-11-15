#pragma once
#include "GameObject.hpp"

class Brick : public GameObject {
public:
	Brick(sf::RenderWindow* window, int x, int y, int hp);
	~Brick();

	int hp;
	static std::map<int, sf::Color> colorMap;

	void update(float deltaT, std::vector<GameObject*>* objectVector) override;
	void onHit(GameObject* target);
};