#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include "Bullet.hpp"
#include "Cannon.hpp"
#include "Brick.hpp"


Bullet::Bullet(sf::RenderWindow* window, int x, int y) : GameObject(window, x, y, 25) {
    this->shape->setFillColor(sf::Color::Green);
};

Bullet::~Bullet() {
    delete this->shape;
};

void Bullet::move(float deltaT) {
    this->x += this->velocity.x * deltaT;
    this->y += this->velocity.y * deltaT;
    this->shape->setPosition(x, y);
}

bool Bullet::checkCollideRect(GameObject* target) {
    if(target != this){
        if (this->x + this->w > 0 && this->x < this->window->getSize().x && this->y + this->h > 0 && this->y < this->window->getSize().y) {
            if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y) {
                return true;
            }
        }
    }
    return false;
}

bool Bullet::checkCollideCircleRect(GameObject* target) {
    if (typeid(*target) == typeid(Bullet) || typeid(*target) == typeid(Cannon)) { return false; }
    float disatanceX = std::abs(this->x - target->x);
    float disatanceY = std::abs(this->y - target->y);
    if (disatanceX > (target->w / 2 + this->h)) { return false; }
    if (disatanceY > (target->h / 2 + this->h)) { return false; }
    if (disatanceX <= (target->w / 2)) { return true; }
    if (disatanceY <= (target->h / 2)) { return true; }
    auto cornerDistance_sq = (disatanceX - target->w / 2) * (disatanceX - target->w / 2) + (disatanceY - target->h / 2) * (disatanceY - target->h / 2);

    return (cornerDistance_sq <= (this->h * this->h));
}

bool Bullet::checkCollideCircle(GameObject* target) {
    float distanceX = std::abs(this->x - target->x);
    float distanceY = std::abs(this->y - target->y);
    float distance = sqrt(distanceX*distanceX + distanceY * distanceY);
    if ((this->w + target->w) >= distance) { return true; }
    return false;
}

void Bullet::collideEffect(GameObject* target) {
    float targetXMax = target->x + target->w;
    float targetYMax = target->y + target->h;

    if (target->y < this->y) {
        this->velocity.y = -this->velocity.y;
    }
    else if (target->y < this->y + this->h) {
        this->velocity.y = -this->velocity.y;

    }
    else if (target->x < this->x) {
        this->velocity.x = -this->velocity.x;

    }
    else if (target->x < this->x + this->w) {
        this->velocity.x = -this->velocity.x;
    }
    target->onHit(this);
}


void Bullet::adjustPosition() {
    if (this->x < 0) {
        this->x = 0;
        this->velocity.x = -this->velocity.x;
    }

    if (this->x + this->w > this->window->getSize().x) {
        this->x = this->window->getSize().x - this->w;
        this->velocity.x = -this->velocity.x;
    }

    if (this->y < 0) {
        this->y = 0;
        this->velocity.y = -this->velocity.y;
    }

    if (this->y + this->h > this->window->getSize().y + 100) {
        this->dead = 1;
    }
}

void Bullet::setVelocity(sf::Vector2f* v1) {
    this->velocity = *v1;
}

bool Bullet::update(float deltaT, std::vector<GameObject*>* objectVector){
    this->move(deltaT);
    for (int i = 0; i < objectVector->size(); i++) {
        auto target = objectVector->at(i);
        if (typeid(*target) == typeid(Brick)) {
            if(this->checkCollideCircleRect(target)) {
                this->collideEffect(target);
            }
        }
        else if (typeid(*target) == typeid(Bullet)) {
            if(target != this)
            {
                if (this->checkCollideCircle(target)) {
                    this->collideEffect(target);
                }
            }
        }
    }
    this->adjustPosition();
    return 1;
}

void Bullet::onHit(GameObject* target) {
    sf::Vector2f vect(-target->velocity.x, -target->velocity.y);
    this->setVelocity(&vect);
}