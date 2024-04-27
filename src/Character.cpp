#include "Character.h"
#include <iostream>

using namespace std;

const int Character::experienceThresholds[30] = {0,7, 23, 47, 110, 220, 450, 800, 1300, 2000, 2900, 400, 5500, 7500, 10000, 13000, 
                                    17000, 21000, 25000, 29000, 33000, 37000, 41000, 45000, 49000, 53000, 57000, 61000, 65000, 70000};

Character::Character()
    : name ("Kuzon"), gender(Male), race(Human), orientation (Good), charClass(Mage), initialWeapon("MageStaff"),
        gold(10000), skillPoints(90), healthPoints(500), manaPoints(250),intellect(30), strength(10), agility(10), level(30) {}

Character::Character(string name, Gender gender, Race race, Orientation orientation, CharacterClass charClass)
    : name(name), gender(gender), race(race), orientation(orientation), charClass(charClass), gold(0),
      skillPoints(1), healthPoints(200), manaPoints(50), intellect(5), strength(5), agility(5), level(1) {

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

// Getters

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

// Setters

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

// Other methods

void Character::gainExperience(int exp) {
    exp = rand() % 5 + 2;
    experience += exp;

    cout << "You have gained " << exp << " experience points!" << endl;
    if (checkLevelUp()) {
        levelUp();
    }
}

void Character :: gainGold(int gold) {
    gold = rand() % 41 + 30;
    int money = rand() % 41 + 30;
    money += gold;
    cout << "You have gained " << gold << " gold!" << endl;
}

bool Character::checkLevelUp(){
    if (level >= 30){
        return false;
    }
    return experience >= experienceThresholds[level];
}

void Character::levelUp(){
    if (level >= 30){
        return;
    }
    level++;
    experience -= experienceThresholds[level - 1];
    skillPoints += 5;

    intellect += 2;
    strength += 2;
    agility += 2;

    cout << "You have leveled up! You are now level " << level << "!" << endl;
}

void Character::attack(Enemy& enemy) const {
    cout << name << " attacks " << enemy.getName() << " for " << strength << " damage!" << endl;
    enemy.setHealthPoints(enemy.getHealthPoints() - strength);
}

void Character::useItem(const string& item){
    if (item == "Herbs"){
        int restore = 25;
        this -> healthPoints += restore;
    } else if (item == "Elixir"){
        int restore = 50;
        this -> healthPoints += restore;
    }
}

void Character:: useSkill(const string& skill){}

void Character :: displayActions() const {
    cout << "1. Attack" << endl;
    cout << "2. Use Item" << endl;
    cout << "3. Use Skill" << endl;
}

void Character::performAction(int action, Enemy& enemy) {}

// Static methods

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

// Overloaded operators

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


