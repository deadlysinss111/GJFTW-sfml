#include "GameManager.hpp"
#include "InputManager.hpp"
#include "GameObject.hpp"

#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <SFML/Graphics.hpp>


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "SFML");
    //sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    InputManager inputManager(&window); // demander a Peter si c'est une bonne pratique de tout link des le départ plutot que de repasser tout en argument a chaque appels
    sf::Clock clock;
    GameManager gameManager(&inputManager, &window);

    bool isPlaying = true;

    while (isPlaying)
    {
        window.clear();

        sf::Event event;

        sf::Time elapsed = clock.restart();

        isPlaying = gameManager.manage(elapsed.asSeconds());

        inputManager.manage();

        window.display();
    }

    return 0;
}

