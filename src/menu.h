#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Character.h"

class Menu {
public:
    void startMenu();
    void mainMenu();
    void showStartMenu();
    void showMainMenu();
    Character createChar();
    void saveGame(Character& character);
    void loadGame();
    void gameMenu();
    void showGameMenu(Character& character);
    void charInfo(const Character& character);
};

#endif