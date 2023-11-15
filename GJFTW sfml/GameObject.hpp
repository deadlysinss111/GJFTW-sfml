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

	virtual void onHit(GameObject* target);
	virtual bool update(float deltaT, std::vector<GameObject*>* objectVector) { return 0; };

	void display(sf::RenderWindow* window);

	sf::Shape* shape;
	sf::RenderWindow* window;

	sf::Vector2f velocity;

	bool dead;

	float x;
	float y;
	float h;
	float w;
};