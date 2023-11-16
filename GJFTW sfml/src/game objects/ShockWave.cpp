#include "ShockWave.hpp"
#include "Collision.hpp"
#include "Bullet.hpp"

#define NOMINMAX
#include <Windows.h>
#include <functional>
#include <iostream>


ShockWave::ShockWave(sf::RenderWindow* window, sf::Vector2f* direction, float lifespan) : GameObject(window, window->getSize().x / 2, window->getSize().y, 300, 100) { // Onde de choc qui fait rebondir la bullet
	this->lifespan = lifespan;
	this->shape->setFillColor(sf::Color::Cyan);
	this->calculateBase(direction);
	this->rotateShape();
}

ShockWave::~ShockWave() {

}

void ShockWave::calculateBase(sf::Vector2f* direction) { // Calcul de la base pour envoyer la vague dans la bonne direction
	this->v1 = sf::Vector2f(direction->x - GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) - direction->y);
	Maths::normalized(&v1);
	this->v2 = sf::Vector2f(this->v1.x, - this->v1.y);
}

void ShockWave::rotateShape() {
	this->shape->setRotation(Maths::getAngle(&this->v1)-90);
}

void ShockWave::move(float deltaT) {
	this->x += this->v2.x * deltaT * 500;
	this->y += this->v2.y * deltaT * 500;
	this->shape->setPosition(x, y);
}

void ShockWave::update(float deltaT, std::vector<GameObject*>* objectVector) { // Update collision entre l'onde et les bullets
	this->move(deltaT);
	for (int i = 0; i < objectVector->size(); i++) {
		auto target = objectVector->at(i);
		if (typeid(*target) == typeid(Bullet) && !std::count(this->collidedObjects.begin(), this->collidedObjects.end(), target)) {
			
			if (Collision::circleToRect(target, this)) {
				target->velocity.x = this->v2.x * 500;
				target->velocity.y = this->v2.y * 500;
				this->collidedObjects.push_back(target);
			}
		}
	}
	this->lifespan -= deltaT;
	if (this->lifespan <= 0) {
		this->dead = true;
	}
}