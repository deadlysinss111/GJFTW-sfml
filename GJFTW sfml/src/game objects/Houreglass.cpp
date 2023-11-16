#include "Houreglass.hpp"

#define NOMINMAX
#include <Windows.h>
#include <functional>
#include <iostream>


Houreglass::Houreglass(sf::RenderWindow* window, int x, int y, int w, int h, float lifespan) : GameObject(window, x, y, w, h) { // Barre de rechargement de onde de choc
	this->lifespan = lifespan;
	this->remainingLife = h;
	this->meltingSpeed = (float)h / lifespan;
	this->shape->setFillColor(sf::Color::Cyan);
}

Houreglass::~Houreglass() {

}

void Houreglass::melt(float deltaT) { // Visuel du temps de rechargement
	float meltThisTic = meltingSpeed * deltaT;
	this->remainingLife -= meltThisTic;
	this->lifespan -= deltaT;
	this->shape->setScale(1, (this->remainingLife/h));
	this->y += meltThisTic / 2;
	this->shape->setPosition(this->x, this->y);
}

void Houreglass::update(float deltaT, std::vector<GameObject*>* objectVector) {
	this->melt(deltaT);
	if (this->lifespan <= 0) {
		this->dead = 1;
	}
}

