#include "Maths.hpp"
#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <functional>

#include <SFML/Graphics.hpp>

float Maths::normalizing(sf::Vector2f* vect) {
	float norm = std::sqrt(vect->x * vect->x + vect->y * vect->y);
	return norm;
}

void Maths::normalized(sf::Vector2f* vect) {
	float norm = normalizing(vect);
	vect->x /= norm;
	vect->y /= norm;
}

void Maths::bounceVectH(sf::Vector2f* vect){
	vect->x = -vect->x;
	std::cout<< "yo";
}
void Maths::bounceVectV(sf::Vector2f* vect) {
	vect->y = -vect->y;
}

int Maths::getAngle(sf::Vector2f* target) {
	sf::Vector2f v2(target->x, 0);
	float signe = (target->x > 0) ? -1.f : 1.f;
	return (90 + signe * 180.f * cos(normalizing(&v2) / normalizing(target)));
}
