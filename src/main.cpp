#include <iostream>
#include <stdlib.h>


using namespace std;


int mainMenu(){
    int option;
    while(option != 3){
        cout << "Main Menu\n1. Start Game\n2. Load Game\n3. Exit to menu" << endl;
        cin >> option;
        switch (option){
            case 1:
                //startGame();
                break;
            case 2:
                //loadGame();
                break;
            case 3:
                cout << "Exiting to menu" << endl;
                break;
            default:
                cout << "Invalid option, please choose a valid one" << endl;
                break;
        }
    }
}

int main(){
    int option;
    while (option != 2){
        cout << "=======================" << endl;
        cout << " Welcome to Baaldur-C!\n1. Enter\n2. Exit Game"<< endl;
        cout << "=======================" << endl;
        cin >> option;
        switch (option){
            case 1:
                mainMenu();
                break;
            case 2:
                cout << "Thanks for playing! :)" << endl;
                break;
            default:
                cout << "Invalid option, please choose a valid one" << endl;
                break;

        }


    }
    return 0;
}