#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Enemy{
    public:
        Enemy(int level, int healthPoints, int attack);

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
        int attack;
        static vector<string> names;
        static string getRandomName();

};

#endif