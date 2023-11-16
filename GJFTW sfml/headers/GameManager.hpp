#pragma once

#include <vector>
#include <map>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>

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

    bool manage(float deltaT);

private:

    void insert(GameObject* object);
    void shoot();
    void wave();
    void setup();
    void addFont(std::string name, const char* path);
    void scoreSetup();
    void scoreUpdate(int value);

    InputManager* inputManager;
    sf::RenderWindow* window;

    static std::vector<GameObject*> objectVector;
    static std::map<std::string, sf::Font> fontMap;
    static std::map<int, sf::Texture> textureMap;

    sf::Text scoreText;

    float bulletCooldown;
    float waveCooldown;

    int scoreLogic;
    int maxBullets;
    int currentBullets;
};
