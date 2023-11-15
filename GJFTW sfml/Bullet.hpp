#pragma once
#include "GameObject.hpp"


class Bullet : public GameObject {
public:
	Bullet(sf::RenderWindow* window, int x, int y);
	~Bullet();
	void update(float deltaT, std::vector<GameObject*>* objectVector) override;

	void move(float deltaT);
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition();
	void onHit(GameObject* target);
	void collideEffect(GameObject*);

};
