#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include "Bullet.hpp"
#include "Cannon.hpp"
#include "Brick.hpp"
#include "Collision.hpp"


Bullet::Bullet(sf::RenderWindow* window, int x, int y) : GameObject(window, x, y, 25) {
    this->shape->setFillColor(sf::Color::Green);
    this->sprite.setTexture(this->textureMap.find(4)->second);
};

Bullet::~Bullet() {
    delete this->shape;
};

void Bullet::move(float deltaT) {
    this->x += this->velocity.x * deltaT;
    this->y += this->velocity.y * deltaT;
    this->shape->setPosition(x, y);
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

void Bullet::update(float deltaT, std::vector<GameObject*>* objectVector){
    this->move(deltaT);
    for (int i = 0; i < objectVector->size(); i++) {
        auto target = objectVector->at(i);
        if (typeid(*target) == typeid(Brick)) {
            if(Collision::circleToRect(this, target)) {
                this->collideEffect(target);
            }
        }
        else if (typeid(*target) == typeid(Bullet)) {
            if(target != this)
            {
                if (Collision::circleToCircle(this, target)) {
                    this->collideEffect(target);
                }
            }
        }
    }
    this->adjustPosition();
    this->sprite.setPosition(this->shape->getPosition());
}

void Bullet::onHit(GameObject* target) {
    sf::Vector2f vect(-target->velocity.x, -target->velocity.y);
    this->setVelocity(&vect);
}

void Bullet::display(sf::RenderWindow* window) {
    window->draw(this->sprite);
}