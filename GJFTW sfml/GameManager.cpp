#define NOMINMAX
#include <typeinfo>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "GameManager.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"
#include "Cannon.hpp"
#include "InputManager.hpp"
#include "Maths.hpp"
#include "ShockWave.hpp"

std::vector<GameObject*> GameManager::objectVector;

std::map<std::string, sf::Font> GameManager::fontMap = {};

GameManager::GameManager(InputManager* inputManager, sf::RenderWindow* window) {
	this->inputManager = inputManager;
	this->window = window;
	this->inputManager->mouseMapping(sf::Mouse::Left, std::bind(&GameManager::shoot, this));
	this->inputManager->mouseMapping(sf::Mouse::Right, std::bind(&GameManager::wave, this));
	this->maxBullets = 2;
	this->currentBullets = 0;
	this->setup();
	this->scoreSetup();
};

GameManager::~GameManager() {};

bool GameManager::manage(float deltaT) {
	for (int i = 0; i < this->objectVector.size(); i++) {
		this->objectVector.at(i)->update(deltaT, &objectVector);
		this->objectVector.at(i)->display(this->window);
		if (this->objectVector.at(i)->dead) {
			if (typeid(*objectVector.at(i)) == typeid(Bullet)) {
				this->currentBullets -= 1;
			}
			else if (typeid(*objectVector.at(i)) == typeid(Brick)){ 
				this->scoreUpdate(50); 
			}
			objectVector.erase(objectVector.begin()+i);
			if (this->objectVector.size() <= 1) {
				this->window->draw(this->scoreText);
				return false;
			}
		}
	}
	this->window->draw(this->scoreText);
	return true;
}

void GameManager::insert(GameObject* object){
	this->objectVector.push_back(object);
}

void GameManager::shoot() {
	if(this->currentBullets < this->maxBullets)
	{
		Bullet* bullet = new Bullet(this->window, this->window->getSize().x / 2, this->window->getSize().y);
		//Bullet* bullet = new Bullet(this->inputManager, this->window, 200, 200);
		sf::Vector2f mouseVect(sf::Vector2f(sf::Mouse::getPosition().x - bullet->x, sf::Mouse::getPosition().y - bullet->y));
		Maths::normalized(&mouseVect);
		mouseVect.x *= 500;
		mouseVect.y *= 500;
		bullet->setVelocity(&mouseVect);
		this->objectVector.push_back(bullet);
		this->currentBullets++;
	}
}

void GameManager::wave() {
	sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	ShockWave* wave = new ShockWave(this->window, &mousePosition);
	this->objectVector.push_back(wave);
}

void GameManager::setup() {
	std::ifstream level;
	level.open("assets/level files/test.txt");
	if (level.is_open()) {
		std::string polf;
		level >> polf;

		Cannon* cannon = new Cannon(this->inputManager, this->window);
		this->objectVector.push_back(cannon);

		for (int i = 0; i < polf.size(); i++) {
			if (polf[i] != '0' ) {
				int j = polf[i] - '0';
				Brick* brick = new Brick(this->window, i%15, i / 15, j);
				this->objectVector.push_back(brick);
			}
		}

		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 15; k++) {

					Brick* brick = new Brick(this->window, k, j + 5 * i, 3 - i);
					this->objectVector.push_back(brick);
				}
			}
		}*/
	}
	else { std::cout << "flop"; }
	
}

void GameManager::addFont(std::string name, const char* path) {
	sf::Font font;
	font.loadFromFile(path);
	this->fontMap.insert({ name, font });
}

void GameManager::scoreSetup() {
	this->addFont(std::string("score"), "assets/fonts/arial.ttf");
	this->scoreLogic = 0;
	this->scoreText.setFont(this->fontMap.find("score")->second);
	this->scoreText.setCharacterSize(50);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(sf::Vector2f(GetSystemMetrics(SM_CXSCREEN) - 100, 15));
	this->scoreText.setString(std::to_string(this->scoreLogic));
}

void GameManager::scoreUpdate(int value){
	this->scoreLogic += value;
	this->scoreText.setString(std::to_string(this->scoreLogic));
}