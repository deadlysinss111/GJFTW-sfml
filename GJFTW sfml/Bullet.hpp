#pragma once
#include "GameObject.hpp"


class Bullet : public GameObject {
public:
	Bullet(sf::RenderWindow* window, int x, int y);
	~Bullet();
	bool update(float deltaT, std::vector<GameObject*>* objectVector);

	void move(float deltaT);
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition();
	void onHit(GameObject* target);
	void collideEffect(GameObject*);

};
