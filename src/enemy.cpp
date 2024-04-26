#include "enemy.h"
#include <iostream>

using namespace std;

vector<string> Enemy::names = {"Goblin", "Harpy", "Hobgoblin", "Dreg", "Vandal", "Minotaur", "Hydra", "Thrall", "Acolyte", "Witch", "Centurion"};

Enemy::Enemy(int level, int healthPoints, int attack)
    : level(level), healthPoints(75), dmg(attack), name(getRandomName()) {}

    string Enemy::getRandomName(){
        int index = rand() % names.size();  
        return names[index];
    }

    string Enemy::getName() const {
        return name;
    }

    int Enemy::getLevel() const {
        return level;
    }

    int Enemy::getHealthPoints() const {
        return healthPoints;
    }

    int Enemy::getAttack() const {
        int dmg = rand() % 10 + 1;
        return dmg;
    }

    void Enemy::attack() const {
        int damage = getAttack();
        cout << name << " attacks, and deals " << damage << " damage!" << endl;
    }

    void Enemy::setHealthPoints(int healthPoints){
        this->healthPoints = healthPoints;
    }
    
