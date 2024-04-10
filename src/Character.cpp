#include "Character.h"
#include <iostream>

using namespace std;

Character:: Character(const string& name, Gender gender, Race race, Orientation orientation, CharacterClass charClass):
                name(name), gender(gender), race(race), orientation(orientation), charClass(charClass) {
                    initializeAttributes();
                }

void Character::displayCharInfo() const {
    cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Race: " << race << endl;
}

void Character::initializeAttributes() {
        level = 1;
        gold = 0;
        skillPoints = 0;
        healthPoints = 100;
        manaPoints = 50;
        intellect = 10;
        strength = 10;
        agility = 10;
}

    

