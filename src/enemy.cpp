#include "enemy.h"
#include <iostream>

using namespace std;

vector<string> Enemy::names = {"Goblin, Harpy, Hobgoblin, Dreg, Vandal, Minotaur, Hydra, Thrall, Acolyte, Witch, Centurion "};

Enemy::Enemy(int level, int healthPoints, int attack)
    : level(level), healthPoints(healthPoints), attack(attack), name(getRandomName()) {}

    string Enemy::getRandomName(){
        srand(time(NULL));
        int index = rand() % names.size();  
        return names[index];
    }

    string Enemy::getName() const {
        return name;
    }

    int Enemy::getLevel() const {
        return level;
    }

    void Enemy::attack() const {
        cout << name << " attacks you for " << attack << " damage!" << endl;
    }
