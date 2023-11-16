#define NOMINMAX
#include <Windows.h>
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"
#include "Cannon.hpp"



GameObject::GameObject(sf::RenderWindow* window, int x, int y, float width, float height){
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->x = x; this->y = y;
	this->w = width; this->h = height;
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	this->shape->setOrigin(sf::Vector2f(w / 2, h / 2));
	this->shape->setPosition(sf::Vector2f(this->x, this->y));
	this->dead = false;
	this->window = window;
}


GameObject::GameObject(sf::RenderWindow* window, int x, int y, float radius){
	this->shape = new sf::CircleShape(radius);
	this->x = x; this->y = y;
	this->h = radius; this->w = radius;
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	this->window = window;
	this->shape->setOrigin(sf::Vector2f(w / 2, h / 2));
}

GameObject::GameObject() {};

GameObject::~GameObject() {
	delete this->shape;
};

void GameObject::display(sf::RenderWindow* window) {
	window->draw(*this->shape);
}

void GameObject::onHit(GameObject* target) {
}