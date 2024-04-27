#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include <vector>
#include "enemy.h"

using namespace std;

class Character
{
    public:
        // Enums
        enum Gender {Male, Female};
        enum Race {Human, Elf, Dwarf, Orc, Undead};
        enum Orientation {Good, Neutral, Evil};
        enum CharacterClass {Warrior, Archer, Mage, Thief};

        // Constructors
        Character();
        Character(string name, Gender gender, Race race, Orientation orientation, CharacterClass charClass);

        int experience;
        int nextLevelExp;

        // Getters and setters

        string getName() const;
        Gender getGender() const;
        Race getRace() const;
        Orientation getOrientation() const;
        CharacterClass getCharClass() const;
        string getInitialWeapon() const;
        int getGold() const;
        int getSkillPoints() const;
        int getHealthPoints() const;
        int getManaPoints() const;
        int getIntellect() const;
        int getStrength() const;
        int getAgility() const;
        int getLevel() const;
        

        void setInitialWeapon(string weapon);
        void setGold(int gold);
        void setSkillPoints(int skillPoints);
        void setHealthPoints(int healthPoints);
        void setManaPoints(int manaPoints);
        void setIntellect(int intellect);
        void setStrength(int strength);
        void setAgility(int agility);
        void setLevel(int level);
        void addItem(const string& item);
        const vector<string>& getItems() const;

        void attack(Enemy& enemy) const;
        void useItem(const string& item);
        void useSkill(const string& skill);
        void levelUp();
        void gainExperience(int exp);
        bool checkLevelUp();
        void displayActions() const;
        void performAction(int action, Enemy& enemy);
        void gainGold(int gold);
        

        static string raceToString(Race race);
        static string orientationToString(Orientation orientation);
        static string classToString(CharacterClass charClass);

        friend istream& operator>>(istream& is, Character& character);
        friend ostream& operator<<(ostream& os, const Character& character);

        
    
    private:
        string name;
        Gender gender;
        Race race;
        Orientation orientation;
        CharacterClass charClass;
        string initialWeapon;

        int level;
        float gold;
        int skillPoints;
        int healthPoints;
        int manaPoints;
        int intellect;
        int strength;
        int agility;
        vector<string> items;

        static const int experienceThresholds[30];

    
};
#endif // CHARACTER_H
