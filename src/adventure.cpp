#include "adventure.h"
#include <cstdlib>
#include <ctime>

Adventure::Adventure(Difficulty difficulty) : difficulty(difficulty) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Adventure::startAdventure(Character& character) {
    resetCharacterStats(character); 
    int enemiesCount = calculateEnemiesCount();
    int enemyLevel = calculateEnemyLevel(character);
    cout << "You are about to face " << enemiesCount << " enemies!" << endl;

    for (int i = 0; i < enemiesCount; i++) {
        Enemy enemy(enemyLevel, 100, 10);
        enemies.push_back(enemy);
    }

    for (auto& enemy: enemies){
        cout << enemy.getName() << " appears!" << endl;
        while (enemy.getHealthPoints() > 0 && character.getHealthPoints() > 0) {
            enemy.attack();
            character.setHealthPoints(character.getHealthPoints() - enemy.getAttack());
            cout << "You have " << character.getHealthPoints() << " health points left!" << endl;
        }
    }


    
}

void Adventure::resetCharacterStats(Character& character) {
    character.setHealthPoints(100);
    character.setManaPoints(50);
}

int Adventure::calculateEnemiesCount() const {
    switch (difficulty) {
        case Difficulty::Easy:
            return rand() % 3 + 1;
        case Difficulty::Medium:
            return rand() % 5 + 1;
        case Difficulty::Hard:
            return rand() % 7 + 1;
    }
}

bool Adventure::checkForBossEncounter(){
    double chance = bossEncounterChance();
    double roll = (double)rand() / RAND_MAX;
    return roll < chance;
}

void Adventure::displayAdventureDetails() const {
    string diff;
    switch (difficulty) {
        case Difficulty::Easy:
            diff = "Easy";
            break;
        case Difficulty::Medium:
            diff = "Medium";
            break;
        case Difficulty::Hard:
            diff = "Hard";
            break;
    }
    cout << "You are about to embark on an adventure with difficulty: " << diff << endl;
}

double Adventure::bossEncounterChance() const {
    switch (difficulty) {
        case Difficulty::Easy:
            return 0.1;
        case Difficulty::Medium:
            return 0.25;
        case Difficulty::Hard:
            return 0.5;
    }
}