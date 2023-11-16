//#include "SpecialBrick.hpp"
//
//
//SpecialBrick::SpecialBrick(sf::RenderWindow* window, int x, int y, int hp) : Brick(window,  x,  y, hp) {
//}
//
//
//SpecialBrick::~SpecialBrick() {};
//
//void SpecialBrick::collideEffect(GameObject* target) { // Collisions avec les briques
//    int random = rand() % 300;
//    float targetXMax = target->x + target->w;
//    float targetYMax = target->y + target->h;
//
//    if (target->y < this->y) {
//        this->velocity.y = -this->velocity.y + random;
//    }
//    else if (target->y < this->y + this->h) {
//        this->velocity.y = -this->velocity.y + random;
//
//    }
//    else if (target->x < this->x) {
//        this->velocity.x = -this->velocity.x + random;
//
//    }
//    else if (target->x < this->x + this->w) {
//        this->velocity.x = -this->velocity.x + random;
//    }
//    target->onHit(this);
//}