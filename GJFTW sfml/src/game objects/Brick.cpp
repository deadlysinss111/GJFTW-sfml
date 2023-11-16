#define NOMINMAX
#include <windows.h>
#include "Brick.hpp"


std::map<int, sf::Color> Brick::colorMap{
	{1, sf::Color::Red},
	{2, sf::Color::Blue},
	{3, sf::Color::Green}
};

Brick::Brick(sf::RenderWindow* window, int x, int y, int hp) : GameObject(window, 100 + 121 * x, 20 + 42 * y, 120, 40) {
	this->sprite.setOrigin(w / 2, h / 2);
	this->sprite.setPosition(100 + 121 * x, 20 + 42 * y);
	this->hp = hp;
	this->shape->setFillColor(this->colorMap.find(hp)->second);
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
		auto found = this->colorMap.find(this->hp);
		if(found != colorMap.end()){
			this->shape->setFillColor(found->second);
		}
	}
}

void Brick::display(sf::RenderWindow* window) {
	window->draw(this->sprite);
}