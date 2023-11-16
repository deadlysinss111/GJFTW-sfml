#pragma once

#include <SFML/System/Vector2.hpp>

namespace sf {
    class Shape;
    class RenderWindow;
}
namespace Maths {
    void normalized(sf::Vector2f* vect);
    void bounceVectH(sf::Vector2f* vect);
    void bounceVectV(sf::Vector2f* vect);

    float normalizing(sf::Vector2f* vect);

    int getAngle(sf::Vector2f* target);

}
