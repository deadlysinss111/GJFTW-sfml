#define NOMINMAX
#include <windows.h>
#include <iostream>
#include "Brick.hpp"


std::map<int, sf::Texture> Brick::textureMap;

Brick::Brick(sf::RenderWindow* window, int x, int y, int hp) : GameObject(window, 100 + 121 * x, 20 + 42 * y, 120, 40) {
	this->hp = hp;
	this->sprite.setTexture(this->textureMap.find(hp)->second);
}


Brick::~Brick() {};

void Brick::update(float deltaT, std::vector<GameObject*>* objectVector){
}

void Brick::onHit(GameObject* target) {
	this->hp -= 1;
	if (hp == 0) {
		this->dead = true;
	}
	else {
		auto found = this->textureMap.find(this->hp);
		if(found != textureMap.end()){
			this->setTexture(&found->second);
		}
	}
}

void Brick::display(sf::RenderWindow* window) {
	window->draw(this->sprite);
}