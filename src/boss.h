#ifndef BOSS_H
#define BOSS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Boss{
    public:
        Boss(int level, int healthPoints, int attack);

        string getName() const;
        int getLevel() const;
        int getHealthPoints() const;
        int getAttack() const;

        void setHealthPoints(int healthPoints);
        void attack() const;
        
    private:
        string name;
        int level;
        int healthPoints;
        int dmg = 0;
        static vector<string> names;
        static string getRandomName();

};



#endif