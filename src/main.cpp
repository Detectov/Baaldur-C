#include "menu.h"
#include <iostream>



int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Menu menu;
    menu.showStartMenu();
    return 0;
}