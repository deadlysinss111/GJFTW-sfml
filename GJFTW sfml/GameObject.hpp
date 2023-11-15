#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
	class RenderWindow;
	class Shape;
}


class GameObject {
public:
	GameObject(sf::RenderWindow* window, int x, int y, float width, float height);
	GameObject(sf::RenderWindow* window, int x, int y, float radius);
	GameObject();
	~GameObject();

	
	sf::RenderWindow* window;
	sf::Shape* shape;
	virtual void update(float deltaT, std::vector<GameObject*>* objectVector);
	void display(sf::RenderWindow* window);
	virtual void onHit(GameObject* target);

	float x;
	float y;
	float h;
	float w;
	bool dead;
	
	sf::Vector2f velocity;
	
};