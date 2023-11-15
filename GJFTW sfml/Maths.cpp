#include "Maths.hpp"
#include<iostream>


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
