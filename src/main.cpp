#include <iostream>
#include <stdlib.h>


using namespace std;


int mainMenu(){
    int option;
    while(option =! 3){
        cout << "Main Menu\n1. Start Game\n2. Load Game\n3. Exit to menu" << endl;
        switch (option){
            case 1:
                //startGame();
                system("cls");
                break;
            case 2:
                //loadGame();
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "Exiting to menu" << endl;
                break;
            default:
                cout << "Invalid option, please choose a valid one" << endl;
                system("cls");
                break;
        }
    }
}

int main(){
    int option;
    while (option =! 2){
        system("cls");
        cout << "Welcome to Baaldur-C\n1. Enter\n2. Exit Game"<< endl;
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
}