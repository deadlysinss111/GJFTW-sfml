#include "BoundingBrick.hpp"
#include <cstdlib>


BoundingBrick::BoundingBrick(sf::RenderWindow* window, int x, int y, int hp) : Brick(window,  x,  y, hp) {
    this->sprite.setTexture(this->textureMap.find(hp+4)->second);
}


BoundingBrick::~BoundingBrick() {};

void BoundingBrick::onHit(GameObject* target) { // Perte de point de vie si impact et changement de couleur si hit
	this->hp -= 1;
	if (hp == 0) {
		this->dead = true;
	}
	else {
		auto found = this->textureMap.find(this->hp+4);
		if (found != textureMap.end()) {
			this->setTexture(&found->second);
		}
	}
}