#pragma once

#include <vector>
#include <map>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class InputManager; // utile ?
class GameObject; // 
namespace Maths {
    void normalized(sf::Vector2f* vect);
}

namespace sf
{
    class RenderWindow; // same
}

class GameManager {
public:

    GameManager(InputManager* inputManager, sf::RenderWindow* window);
    ~GameManager();

    InputManager* inputManager;
    sf::RenderWindow* window;
    static std::vector<GameObject*> objectVector;
    static std::map<std::string, sf::Font> fontMap;
    int maxBullets;
    int currentBullets;
    sf::Text scoreText;
    int scoreLogic;
    float bulletCooldown;
    float waveCooldown;

    bool manage(float deltaT);
    void insert(GameObject* object);
    void shoot();
    void wave();
    void setup();
    void addFont(std::string name, const char* path);
    void scoreSetup();
    void scoreUpdate(int value);

};
