#include "Character.h"
#include <iostream>

using namespace std;

Character:: Character(string name, Gender gender, Race race, Orientation orientation, CharacterClass charClass) 
    : name(name), gender (gender), race (race), orientation (orientation), charClass (charClass), gold (0), skillPoints (1), healthPoints (100), manaPoints (50), intellect (5), strength (5), agility (5), level (1) {

    switch (charClass) {
        case Mage:
            initialWeapon = "Mage Staff";
            break;
        case Thief:
            initialWeapon = "Dagger";
            break;
        case Archer:
            initialWeapon = "Apprentice Bow";
            break;
        case Warrior:
            initialWeapon = "Sword";
            break;
    }
}

string Character::getName() const {
    return name;
}

Character:: Gender Character::getGender() const {
    return gender;
}

Character:: Race Character::getRace() const {
    return race;
}

Character:: Orientation Character::getOrientation() const {
    return orientation;
}

Character:: CharacterClass Character::getCharClass() const {
    return charClass;
}

string Character::getInitialWeapon() const {
    return initialWeapon;
}

int Character::getGold() const {
    return gold;
}

int Character::getSkillPoints() const {
    return skillPoints;
}

int Character::getHealthPoints() const {
    return healthPoints;
}

int Character::getManaPoints() const {
    return manaPoints;
}

int Character::getIntellect() const {
    return intellect;
}

int Character::getStrength() const {
    return strength;
}

int Character::getAgility() const {
    return agility;
}

int Character::getLevel() const {
    return level;
}

void Character::setInitialWeapon(string weapon) {
    initialWeapon = weapon;
}

void Character::setGold(int gold) {
    this->gold = gold;
}

void Character::setSkillPoints(int skillPoints) {
    this->skillPoints = skillPoints;
}

void Character::setHealthPoints(int healthPoints) {
    this->healthPoints = healthPoints;
}

void Character::setManaPoints(int manaPoints) {
    this->manaPoints = manaPoints;
}

void Character::setIntellect(int intellect) {
    this->intellect = intellect;
}

void Character::setStrength(int strength) {
    this->strength = strength;
}

void Character::setAgility(int agility) {
    this->agility = agility;
}

void Character::setLevel(int level) {
    this->level = level;
}

void Character::addItem(const string& item) {
    items.push_back(item);
}

const vector<string>& Character::getItems() const {
    return items;
}
    

