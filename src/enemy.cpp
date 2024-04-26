#include "enemy.h"
#include <iostream>

using namespace std;

vector<string> Enemy::names = {"Goblin", "Harpy", "Hobgoblin", "Dreg", "Vandal", "Minotaur", "Hydra", "Thrall", "Acolyte", "Witch", "Centurion"};

Enemy::Enemy(int level, int healthPoints, int attack)
    : level(level), healthPoints(healthPoints), dmg(attack), name(getRandomName()) {}

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

    int Enemy::getAttack() const {
        return dmg;
    }

    void Enemy::attack() const {
        cout << name << " attacks for " << dmg << " damage!" << endl;
    }
