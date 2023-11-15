#pragma once
#include "GameObject.hpp"


class Bullet : public GameObject {
public:
	Bullet(sf::RenderWindow* window, int x, int y);
	~Bullet();

	void setVelocity(sf::Vector2f* vect);

private:

	void move(float deltaT);
	void adjustPosition();
	void onHit(GameObject* target);
	void collideEffect(GameObject*);

	bool update(float deltaT, std::vector<GameObject*>* objectVector);

};
