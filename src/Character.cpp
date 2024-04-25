#include "Character.h"
#include <iostream>

using namespace std;

Character::Character()
    : name ("Kuzon"), gender(Male), race(Human), orientation (Good), charClass(Mage), initialWeapon("MageStaff"),
        gold(10000), skillPoints(90), healthPoints(500), manaPoints(250),intellect(30), strength(10), agility(10), level(30) {}

Character::Character(string name, Gender gender, Race race, Orientation orientation, CharacterClass charClass)
    : name(name), gender(gender), race(race), orientation(orientation), charClass(charClass), gold(0),
      skillPoints(1), healthPoints(100), manaPoints(50), intellect(5), strength(5), agility(5), level(1) {

    switch (charClass) {
        case Mage:
            initialWeapon = "MageStaff";
            break;
        case Thief:
            initialWeapon = "Dagger";
            break;
        case Archer:
            initialWeapon = "ApprenticeBow";
            break;
        case Warrior:
            initialWeapon = "Sword";
            break;
    }
}


string Character::getName() const {
    return name;
}

Character::Gender Character::getGender() const {
    return gender;
}

Character::Race Character::getRace() const {
    return race;
}

Character::Orientation Character::getOrientation() const {
    return orientation;
}

Character::CharacterClass Character::getCharClass() const {
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


string Character::raceToString(Race race) {
    switch (race) {
        case Human: return "Human";
        case Elf: return "Elf";
        case Dwarf: return "Dwarf";
        case Orc: return "Orc";
        case Undead: return "Undead";
        
    }
}

string Character::orientationToString(Orientation orientation) {
    switch (orientation) {
        case Good: return "Good";
        case Neutral: return "Neutral";
        case Evil: return "Evil";
        
    }
}

string Character::classToString(CharacterClass charClass) {
    switch (charClass) {
        case Warrior: return "Warrior";
        case Archer: return "Archer";
        case Mage: return "Mage";
        case Thief: return "Thief";
        
    }
}

istream& operator>>(istream& is, Character& character) {
    int gender, race, orientation, charClass;
    is >> character.name
       >> gender
       >> race
       >> orientation
       >> charClass
       >> character.initialWeapon
       >> character.gold
       >> character.skillPoints
       >> character.healthPoints
       >> character.manaPoints
       >> character.intellect
       >> character.strength
       >> character.agility
       >> character.level;

    character.gender = static_cast<Character::Gender>(gender);
    character.race = static_cast<Character::Race>(race);
    character.orientation = static_cast<Character::Orientation>(orientation);
    character.charClass = static_cast<Character::CharacterClass>(charClass);

    return is;
}

ostream& operator<<(ostream& os, const Character& character) {
    os << character.name << " "
       << static_cast<int>(character.gender) << " "
       << static_cast<int>(character.race) << " "
       << static_cast<int>(character.orientation) << " "
       << static_cast<int>(character.charClass) << " "
       << character.initialWeapon << " "
       << character.gold << " "
       << character.skillPoints << " "
       << character.healthPoints << " "
       << character.manaPoints << " "
       << character.intellect << " "
       << character.strength << " "
       << character.agility << " "
       << character.level << endl;
    return os;
}


