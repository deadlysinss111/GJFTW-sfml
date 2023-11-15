#pragma once
#include <SFML/Graphics.hpp>

namespace Maths {
    float normalizing(sf::Vector2f* vect);
    void normalized(sf::Vector2f* vect);
    void bounceVectH(sf::Vector2f* vect);
    void bounceVectV(sf::Vector2f* vect);

}
