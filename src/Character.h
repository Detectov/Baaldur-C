#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include <vector>

using namespace std;

class Character
{
    public:
        enum Gender {Male, Female};
        enum Race {Human, Elf, Dwarf, Orc, Undead};
        enum Orientation {Good, Neutral, Evil};
        enum CharacterClass {Warrior, Archer, Mage, Thief};

        Character();
        Character(string name, Gender gender, Race race, Orientation orientation, CharacterClass charClass);

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

    
};
#endif // CHARACTER_H
