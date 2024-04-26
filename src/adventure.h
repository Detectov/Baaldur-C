#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "Character.h"
#include "enemy.h"
#include "boss.h"
#include <vector>
#include <string>

enum class Difficulty {Easy, Medium, Hard};

class Adventure {
    public:
        Adventure();
        void chooseDifficulty();
        Adventure(Difficulty difficulty);
        void startAdventure(Character& character);
        void resetCharacterStats(Character& character);
        bool checkForBossEncounter();
        void displayAdventureDetails() const;
        void returnToMenu() const;
    
    private:
        Difficulty difficulty;
        vector<Enemy> enemies;
        void combat(Character& character, Enemy& enemy);
        int calculateEnemiesCount() const;
        int calculateEnemyLevel(const Character& character) const;
        double bossEncounterChance() const;
};
#endif
