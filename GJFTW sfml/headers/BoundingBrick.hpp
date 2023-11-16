#pragma once

#include"Brick.hpp"

class BoundingBrick : public Brick
{
public:
	BoundingBrick(sf::RenderWindow* window, int x, int y, int hp);
	~BoundingBrick();
	void onHit(GameObject* target);
};
