#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Character.h"

class Menu {
public:
    void mainMenu();
    void gameMenu();
    void showMenuInicio();
    void showMenuPrincipal();
    Character crearPersonaje();
    void saveGame(Character& character);
    void loadGame();
    void mostrarMenuJuego();
    void showGameMenu(Character& character);
    void charInfo(const Character& character);
};

#endif