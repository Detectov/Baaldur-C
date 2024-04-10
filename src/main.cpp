#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;


void gameMenu();
void newGame();
void loadGame();

void cleanConsole(){
    system("CLS");
}

void mainMenu() {
    int option = 0; 

    while (true) { 
        cleanConsole();
        cout << "=======================" << endl;
        cout << " Welcome to Baaldur-C!\n1. Enter Game\n2. Exit Game" << endl;
        cout << "=======================" << endl;
        cin >> option;

        switch (option) {
            case 1:
                gameMenu(); 
                break;
            case 2:
                cout << "Thanks for playing! :)" << endl;
                return; 
            default:
                cout << "Invalid option, please choose a valid one." << endl;
        }
    }
}

void newGame(){
    cleanConsole();
    cout << "Starting new game..." << endl;
}

void gameMenu() {
    int option = 0; 

    while (option != 3) { 
        cleanConsole();
        cout << "================" << endl;
        cout << "  Game Menu\n1. Start New Game\n2. Load Game\n3. Exit to Main Menu" << endl;
        cout << "================" << endl;
        cin >> option;

        switch (option) {
            case 1:
                newGame(); 
                break;
            case 2:
                //loadGame(); 
                break;
            case 3:
                return; 
            default:
                cout << "Invalid option, please choose a valid one." << endl;
        }
    }
}



int main() {
    mainMenu();
    return 0;
}
