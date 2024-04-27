#include "adventure.h"
#include "Character.h"
#include "enemy.h"
#include "boss.h"
#include "menu.h"
#include <cstdlib>
#include <ctime>

using namespace std;
Adventure::Adventure() : difficulty(Difficulty::Easy){
    srand(static_cast<unsigned int>(time(nullptr)));
}


Adventure::Adventure(Difficulty difficulty) : difficulty(difficulty) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Adventure:: chooseDifficulty() {
    int choice;
    cout << "Choose difficulty: " << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            difficulty = Difficulty::Easy;
            break;
        case 2:
            difficulty = Difficulty::Medium;
            break;
        case 3:
            difficulty = Difficulty::Hard;
            break;
        default:
            cout << "Invalid choice! Setting difficulty to Easy!" << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            difficulty = Difficulty::Easy;
    }
}




void Adventure::startAdventure(Character& character) {
    chooseDifficulty();
    displayAdventureDetails();
    resetCharacterStats(character); 
    int enemiesCount = calculateEnemiesCount();
    int enemyLevel = calculateEnemyLevel(character);
    cout << "You are about to face " << enemiesCount << " enemies!" << endl;



    for (int i = 0; i < enemiesCount; i++) {
        Enemy enemy(enemyLevel, 100 * enemyLevel, 10 * enemyLevel);
        enemies.push_back(enemy);
        combat(character, enemy);
    }

    if (character.getHealthPoints() <= 0) {
        cout << "You have been defeated!" << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    else {
        cout << "You have defeated all enemies!" << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

void Adventure::combat(Character& character, Enemy& enemy){
    cout << "You are facing a " << enemy.getName() << "!" << endl;
    cout << "Press any key to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    int enemyChoice = 0;

    while (character.getHealthPoints() > 0 && !enemies.empty()) {
        cout << "Your health: " << character.getHealthPoints() <<  endl;
        character.displayActions();
        int action;
        cin >> action;
        
        switch (action){
            case 1: {
                cout << "Choose an enemy to attack:" << endl;
                for (size_t i = 0; i < enemies.size(); i++){
                    cout << i + 1 << ". " << enemies[i].getName() << "(HP: " << enemies[i].getHealthPoints() << ")" << endl;
                }
                cin >> enemyChoice;
                if (enemyChoice > 0 && enemyChoice <= enemies.size()){
                    character.attack(enemies[enemyChoice - 1]);
                    if (enemies[enemyChoice - 1].getHealthPoints() <= 0){
                        cout << "You have defeated " << enemies[enemyChoice- 1].getName() << "!" << endl;
                        character.gainExperience(10);
                        character.gainGold(50);
                        enemies.erase(enemies.begin() + enemyChoice - 1);
                    }
                } else {
                    cout << "Invalid choice! Please try again!" << endl;
                }
                break;
            }
            case 2:
                character.useSkill("Herbs");
                break;
            case 3:
                character.useItem("Elixir");
                break;
            default:
                cout << "Invalid action! Please try again!" << endl;
                continue;
        }
        for (auto &enemy : enemies){
            enemy.attack();
            character.setHealthPoints(character.getHealthPoints() - enemy.getAttack());
            cout << enemy.getName() << " attacks, and deals " << enemy.getAttack() << " damage!" << endl;
            if (character.getHealthPoints() <= 0){
                cout << "You have been defeated!" << endl;
                break;
            }
            
        }
    }
    if (character.getHealthPoints() <= 0){
        cout << "You have been defeated!" << endl;
        character.setGold(character.getGold() / 2);
    } else {
        cout << "You have defeated all the enemies"  << "!" << endl;

    }
}

Menu menu; 
Character character; 

void Adventure::returnToMenu() const {
    cout << "Press any key to return to the main menu..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    menu.showGameMenu(character);
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

int Adventure::calculateEnemyLevel(const Character& character) const {
    switch (difficulty) {
        case Difficulty::Easy:
            return character.getLevel() - 1;
        case Difficulty::Medium:
            return character.getLevel();
        case Difficulty::Hard:
            return character.getLevel() + 1;
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