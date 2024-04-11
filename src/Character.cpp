#include "Character.h"
#include <iostream>

using namespace std;

Character:: Character(const string& name, Gender gender, Race race, Orientation orientation, CharacterClass charClass):
                name(name), gender(gender), race(race), orientation(orientation), charClass(charClass) {
                    initializeAttributes();
                }

string genderToString(Gender gender){
    switch(gender){
        case Gender:: Male: return "Male";
        case Gender:: Female: return "Female";
        default: return "Unknown";
    }
}

string raceToString (Race race){
    switch(race){
        case Race:: Human: return "Human";
        case Race:: Elf: return "Elf";
        case Race:: Dwarf: return "Dwarf";
        case Race:: Orc: return "Orc";
        case Race:: Undead: return "Undead";
        default: return "Unknown";
    }
}

string orientationToString(Orientation orientation){
    switch(orientation){
        case Orientation:: Good: return "Good";
        case Orientation:: Neutral: return "Neutral";
        case Orientation:: Evil: return "Evil";
        default: return "Unknown";
    }
}

string charClassToString(CharacterClass charClass){
    switch(charClass){
        case CharacterClass:: Warrior: return "Warrior";
        case CharacterClass:: Archer: return "Archer";
        case CharacterClass:: Mage: return "Mage";
        case CharacterClass:: Thief: return "Thief";
        default: return "Unknown";
    }
}

void Character::displayCharInfo() const {
    cout << "Name: " << name << endl;
    cout << "Gender: " << genderToString(gender) << endl;
    cout << "Race: " << raceToString(race) << endl;
    cout << "Orientation: " << orientationToString(orientation) << endl;
    cout << "Class: " << charClassToString(charClass) << endl;
    cout << "Level: " << level << endl;
    cout << "Gold: " << gold << endl;
    cout << "Skill Points: " << skillPoints << endl;
    cout << "Health Points: " << healthPoints << endl;
    cout << "Mana Points: " << manaPoints << endl;
    cout << "Intellect: " << intellect << endl;
    cout << "Strength: " << strength << endl;
    cout << "Agility: " << agility << endl;
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

string Character::getName() const {
    return name;
}

void Character::levelUp() {
    level++;
    skillPoints += 1;
    healthPoints += 10;
    manaPoints += 5;
    intellect += 2;
    strength += 2;
    agility += 2;
}


    

