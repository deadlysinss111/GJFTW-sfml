#define NOMINMAX
#include <Windows.h>
#include <functional>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputManager.hpp"
#include "Cannon.hpp"

Cannon::Cannon(InputManager* inputManager, sf::RenderWindow* window) : GameObject(window, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN), 100, 50){
	inputManager->moveMapping(std::bind(&Cannon::rotate, this));
	this->shape->setFillColor(sf::Color::White);
};

Cannon::~Cannon() {
	
};

void Cannon::rotate(){
	sf::Vector2i v1 = sf::Mouse::getPosition();
	sf::Vector2f hyp(0, 0);
	hyp.x = v1.x - GetSystemMetrics(SM_CXSCREEN) / 2;
	hyp.y = GetSystemMetrics(SM_CYSCREEN) - v1.y;
	sf::Vector2f v2(hyp.x, 0);
	float signe = (hyp.x > 0) ? -1.f : 1.f;
	this->shape->setRotation(90 + signe * 180.f * cos(Maths::normalizing(&v2) / Maths::normalizing(&hyp)));
	// on doit établir le projeté orthogonal de vect sur la droite qui passe par l'origine dirigée par le vecteur (1, 0)
	// de là on a un triangle rectangle dont on connait deux cotés => trigo pour trouver l'angle et c'est gagné
}

bool Cannon::update(float deltaT, std::vector<GameObject*>* objectVector) {
	return 0;
}

