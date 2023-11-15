#include "ShockWave.hpp"

#define NOMINMAX
#include <Windows.h>
#include <functional>
#include <iostream>


ShockWave::ShockWave(sf::RenderWindow* window, sf::Vector2f* direction) : GameObject(window, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN), 100, 300) {
	this->shape->setFillColor(sf::Color::Cyan);
	this->calculateBase(direction);
	this->rotateShape();
};

ShockWave::~ShockWave() {

};

void ShockWave::calculateBase(sf::Vector2f* direction) {
	this->v1 = sf::Vector2f(direction->x - GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) - direction->y);
	Maths::normalized(direction);
	this->v2 = sf::Vector2f(this->v1.x, - this->v1.y);
}

void ShockWave::rotateShape() {
	sf::Vector2f baseVect(this->v1.x, 0);
	//std::cout << this->v2.x << "||" << this->v2.y << std::endl;
	float signe = (this->v1.x > 0) ? -1.f : 1.f;
	this->shape->setRotation(90 + signe * 180 * cos(Maths::normalizing(&baseVect) / Maths::normalizing(&this->v1)));
}

bool ShockWave::update(float deltaT, std::vector<GameObject*>* objectVector) {
	return 0;
}

