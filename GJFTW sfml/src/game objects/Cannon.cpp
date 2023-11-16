#define NOMINMAX
#include <Windows.h>
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputManager.hpp"
#include "Cannon.hpp"

Cannon::Cannon(InputManager* inputManager, sf::RenderWindow* window) : GameObject(window, window->getSize().x / 2, window->getSize().y, 100, 50) {
	inputManager->moveMapping(std::bind(&Cannon::rotate, this));
	this->shape->setFillColor(sf::Color::White);
};

Cannon::~Cannon() {
	
};

void Cannon::rotate(){
	sf::Vector2i v1 = sf::Mouse::getPosition();
	sf::Vector2f v2(0, 0);
	int xScreen = window->getSize().x;
	v2.x = v1.x - xScreen / 2;
	v2.y = window->getSize().y - v1.y;
	this->shape->setRotation(Maths::getAngle(&v2));
	// on doit établir le projeté orthogonal de vect sur la droite qui passe par l'origine dirigée par le vecteur (1, 0)
	// de là on a un triangle rectangle dont on connait deux cotés => trigo pour trouver l'angle et c'est gagné
}

void Cannon::update(float deltaT, std::vector<GameObject*>* objectVector) {
}

