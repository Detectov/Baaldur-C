#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include <vector>

using namespace std;

enum class Gender {Male, Female};
enum class Race {Human, Elf, Dwarf, Orc, Undead};
enum class Orientation {Good, Neutral, Evil};
enum class CharacterClass {Warrior, Archer, Mage,Thief};

class Character
{
    public:
        Character();
        Character(const string& name, Gender gender, Race race, Orientation orientation, CharacterClass charClass);


        void displayCharInfo() const;
        void levelUp();

        string getName() const;
    
    private:
        string name;
        Gender gender;
        Race race;
        Orientation orientation;
        CharacterClass charClass;

        int level;
        float gold;
        int skillPoints;
        int healthPoints;
        int manaPoints;
        int intellect;
        int strength;
        int agility;


        void initializeAttributes();
    
};
#endif // CHARACTER_H
