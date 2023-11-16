#define NOMINMAX
#include <Windows.h>
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputManager.hpp"
#include "Cannon.hpp"

#include "Maths.hpp"

Cannon::Cannon(InputManager* inputManager, sf::RenderWindow* window) : GameObject(window, window->getSize().x / 2, window->getSize().y, 100, 50) {
	inputManager->moveMapping(std::bind(&Cannon::rotate, this)); // Mouvement de la souris pour la rotation du canon
	this->shape->setFillColor(sf::Color::White);
};

Cannon::~Cannon() {
	
};

void Cannon::rotate(){ // Rotation du canon avec le curseur de la souris
	sf::Vector2i v1 = sf::Mouse::getPosition();
	sf::Vector2f v2(0, 0);
	int xScreen = window->getSize().x;
	v2.x = v1.x - xScreen / 2;
	v2.y = window->getSize().y - v1.y;
	this->shape->setRotation(Maths::getAngle(&v2)); // Utilise le namespace Maths pour donner l'angle et faire la rotation
}

void Cannon::update(float deltaT, std::vector<GameObject*>* objectVector) { // Update collision 
}

