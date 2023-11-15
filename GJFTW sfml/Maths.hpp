#pragma once

#include <SFML/System/Vector2.hpp>

namespace Maths {
    float normalizing(sf::Vector2f* vect);
    void normalized(sf::Vector2f* vect);
    void bounceVectH(sf::Vector2f* vect);
    void bounceVectV(sf::Vector2f* vect);

}
