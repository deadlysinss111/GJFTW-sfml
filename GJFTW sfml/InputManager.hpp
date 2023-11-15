#pragma once
#include <unordered_map>
#include <functional>
#include "SFML/Graphics.hpp"
#include <vector>

class InputManager {
public:
	InputManager(sf::RenderWindow* window);
	~InputManager();

	sf::RenderWindow* window;

	void keyMapping(sf::Keyboard::Key, std::function<void()> function);
	void mouseMapping(sf::Mouse::Button, std::function<void()> function);
	void moveMapping(std::function<void()>);

	void manage();
private:
	std::unordered_map<sf::Keyboard::Key, std::function<void()>> keyMap;
	std::unordered_map<sf::Mouse::Button, std::function<void()>> mouseMap;
	std::vector<std::function<void()>> moveEffect;
};
