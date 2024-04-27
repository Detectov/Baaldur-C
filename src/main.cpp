#include "menu.h"
#include <iostream>



int main() {
    // Seed the random number generator with the current time to get different results each time the program is run
    srand(static_cast<unsigned int>(time(nullptr)));
    Menu menu;
    menu.showStartMenu();
    return 0;
}