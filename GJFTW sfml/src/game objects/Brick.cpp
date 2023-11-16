#define NOMINMAX
#include <windows.h>
#include "Brick.hpp"


std::map<int, sf::Color> Brick::colorMap{ // Donne la couleur aux briques
	{1, sf::Color::Red},
	{2, sf::Color::Blue},
	{3, sf::Color::Green}
};

Brick::Brick(sf::RenderWindow* window, int x, int y, int hp) : GameObject(window, 100 +121 * x , 20 + 32 * y, 120, 30) {
	this->hp = hp; // points de vie des briques
	this->shape->setFillColor(this->colorMap.find(hp)->second);
}


Brick::~Brick() {};

void Brick::update(float deltaT, std::vector<GameObject*>* objectVector){
}

void Brick::onHit(GameObject* target) { // Perte de point de vie si impact et changement de couleur si hit
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