#include "boss.h"
#include <iostream>

using namespace std;

vector<string> Boss::names = {"Atheon", "Oryx", "Crota", "Aksis", "Skolas"};

Boss::Boss(int level, int healthPoints, int attack)
    : level(level), healthPoints(300), dmg(attack), name(getRandomName()) {}

    string Boss::getRandomName(){
        int index = rand() % names.size();  
        return names[index];
    }

    string Boss::getName() const {
        return name;
    }

    int Boss::getLevel() const {
        return level;
    }

    int Boss::getHealthPoints() const {
        return healthPoints;
    }

    int Boss::getAttack() const {
        int dmg = rand() % 20 + 1;
        return dmg;
    }

    void Boss::attack() const {
        int damage = getAttack();
        cout << name << " attacks, and deals " << damage << " damage!" << endl;
    }

    void Boss::setHealthPoints(int healthPoints){
        this->healthPoints = healthPoints;
    }