#pragma once
#include <unordered_map>
#include <functional>
#include <vector>
#include "SFML/Graphics.hpp"


class InputManager {
public:
	InputManager(sf::RenderWindow* window);
	~InputManager();

	void mouseMapping(sf::Mouse::Button, std::function<void()> function);
	void moveMapping(std::function<void()>);
	void manage();
private:

	void keyMapping(sf::Keyboard::Key, std::function<void()> function);

	std::unordered_map<sf::Keyboard::Key, std::function<void()>> keyMap;
	std::unordered_map<sf::Mouse::Button, std::function<void()>> mouseMap;
	std::vector<std::function<void()>> moveEffect;

	sf::RenderWindow* window;
};
