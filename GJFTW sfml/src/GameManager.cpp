#define NOMINMAX

#include "GameManager.hpp"

#include "InputManager.hpp"

#include "Bullet.hpp"
#include "Brick.hpp"
#include "Cannon.hpp"
#include "ShockWave.hpp"
#include "Houreglass.hpp"

#include <typeinfo>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <functional> 

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
	while(deltaT > 0) // on force les tours de boucle en cas de délai trop long entre deux appels de manage
	{
		this->bulletCooldown -= deltaT;
		this->waveCooldown -= deltaT;
		for (int i = 0; i < this->objectVector.size(); i++) {
			this->objectVector.at(i)->update(deltaT, &objectVector);
			this->objectVector.at(i)->display(this->window); // a bouger
			if (this->objectVector.at(i)->dead) { // on purge la liste de ses objets morts et on active un effet ou non a la mort d'un objet selon son type
				if (typeid(*objectVector.at(i)) == typeid(Bullet)) {
					this->currentBullets -= 1;
					this->scoreUpdate(-20);
				}
				else if (typeid(*objectVector.at(i)) == typeid(Brick)) {
					this->scoreUpdate(50);
				}
				objectVector.erase(objectVector.begin() + i);
				if (this->objectVector.size() <= 1) { // terrifiant, a changer asap
					this->window->draw(this->scoreText);
					return false;
				}
			}
		}
		this->window->draw(this->scoreText);
		deltaT -= 0.1;
	}
	return true;
}

void GameManager::insert(GameObject* object){
	this->objectVector.push_back(object);
}

void GameManager::shoot() {
	if(this->currentBullets < this->maxBullets && this->bulletCooldown <= 0)
	{
		Bullet* bullet = new Bullet(this->window, this->window->getSize().x / 2, this->window->getSize().y);
		sf::Vector2f mouseVect(sf::Vector2f(sf::Mouse::getPosition().x - bullet->x, sf::Mouse::getPosition().y - bullet->y));
		Maths::normalized(&mouseVect);
		mouseVect.x *= 500;
		mouseVect.y *= 500;
		bullet->setVelocity(&mouseVect);
		this->objectVector.push_back(bullet);
		this->currentBullets++;
		this->bulletCooldown = 1;
	}
}

void GameManager::wave() {
	if(this->waveCooldown <= 0){
		sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		ShockWave* wave = new ShockWave(this->window, &mousePosition, 0.55);
		this->objectVector.push_back(wave);
		Houreglass* houreglass = new Houreglass(this->window, 0, window->getSize().y, 50, 200, 2.5);
		this->objectVector.push_back(houreglass);
		waveCooldown = 2.5;
	}
}

void GameManager::setup() { // setup du niveau selon un fichier texte
	std::ifstream level;
	level.open("src/assets/level files/test.txt");
	if (level.is_open()) {
		std::string strLvl;
		level >> strLvl;

		Cannon* cannon = new Cannon(this->inputManager, this->window);
		this->objectVector.push_back(cannon);

		for (int i = 0; i < strLvl.size(); i++) {
			if (strLvl[i] != '0' ) {
				int j = strLvl[i] - '0';
				Brick* brick = new Brick(this->window, i%15, i / 15, j);
				this->objectVector.push_back(brick);
			}
		}
	}
	
}

void GameManager::addFont(std::string name, const char* path) {
	sf::Font font;
	font.loadFromFile(path);
	this->fontMap.insert({ name, font });
}

void GameManager::scoreSetup() {
	this->addFont(std::string("score"), "src/assets/fonts/arial.ttf");
	this->scoreLogic = 0;
	this->scoreText.setFont(this->fontMap.find("score")->second);
	this->scoreText.setCharacterSize(50);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(sf::Vector2f(window->getSize().x - 100, 15));
	this->scoreText.setString(std::to_string(this->scoreLogic));
}

void GameManager::scoreUpdate(int value){
	this->scoreLogic += value;
	this->scoreText.setString(std::to_string(this->scoreLogic));
}