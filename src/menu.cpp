#include "menu.h"



using namespace std;

void cleanConsole(){
    system("CLS");
}

void Menu:: startMenu() {
    cout << "=======================" << endl;
    cout << " Welcome to Baaldur-C!\n1. Enter Game\n2. Exit Game" << endl;
    cout << "=======================" << endl;
}

void Menu:: mainMenu() {
    cout << "================" << endl;
    cout << "  Main Menu\n1. Start New Game\n2. Load Game\n3. Exit to Start Menu" << endl;
    cout << "================" << endl;
}

void Menu:: showStartMenu() {
    int option = 0; 

    while (true) { 
        cleanConsole();
        startMenu();
        cin >> option;

        switch (option) {
            case 1:
                showMainMenu(); 
                break;
            case 2:
                cout << "Thanks for playing! :)" << endl;
                return; 
            default:
                cout << "Invalid option, please choose a valid one." << endl;
        }
    }
}

void Menu:: showMainMenu() {
    int option = 0; 
    
    while (option != 3) { 
        cleanConsole();
        mainMenu();
        cin >> option;

        switch (option) {
            case 1: {
                Character character = createChar(); 
                cout << character.getInitialWeapon() << endl;
                break;
            }
            case 2:{
                loadGame(); 
                break;
            }
            case 3:{
                return;
            } 
            default:
                cout << "Invalid option, please choose a valid one." << endl;
        }
    }
}

Character Menu:: createChar() {
    cout << "============================" << endl;
    cout << "  Character Creation Menu" << endl;
    cout << "============================" << endl;

    string name;
    cout << "Enter your character's name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Choose your character's gender:\n1. Male\n2. Female" << endl;
    int genderOption;
    cin >> genderOption;
    Character::Gender gender;
    switch (genderOption) {
        case 1:
            gender = Character::Male;
            break;
        case 2:
            gender = Character::Female;
            break;
        default:
            cout << "Invalid option, please choose a valid one." << endl;
            return createChar();
    }
    cout << "Choose your character's race:\n1. Human\n2. Elf\n3. Dwarf\n4. Orc\n5. Undead" << endl;
    int raceOption;
    cin >> raceOption;
    Character::Race race;
    switch (raceOption) {
        case 1:
            race = Character::Human;
            break;
        case 2:
            race = Character::Elf;
            break;
        case 3:
            race = Character::Dwarf;
            break;
        case 4:
            race = Character::Orc;
            break;
        case 5:
            race = Character::Undead;
            break;
        default:
            cout << "Invalid option, please choose a valid one." << endl;
            return createChar();

    }
    cout << "Choose your character's orientation:\n1. Good\n2. Neutral\n3. Evil" << endl;
    int orientationOption;
    cin >> orientationOption;
    Character::Orientation orientation;
    switch (orientationOption) {
        case 1:
            orientation = Character::Good;
            break;
        case 2:
            orientation = Character::Neutral;
            break;
        case 3:
            orientation = Character::Evil;
            break;
        default:
            cout << "Invalid option, please choose a valid one." << endl;
            return createChar();
    }

    cout << "Choose your character's class:\n1. Warrior\n2. Archer\n3. Mage\n4. Thief" << endl;
    int classOption;
    cin >> classOption;
    Character::CharacterClass charClass;
    switch (classOption) {
        case 1:
            charClass = Character::Warrior;
            break;
        case 2:
            charClass = Character::Archer;
            break;
        case 3:
            charClass = Character::Mage;
            break;
        case 4:
            charClass = Character::Thief;
            break;
        default:
            cout << "Invalid option, please choose a valid one." << endl;
            return createChar();
    }

    Character newChar(name, gender, race, orientation, charClass);
    saveGame(newChar);
    return newChar;
}

void Menu::saveGame(Character& character) {
    ofstream file("savegame.txt", ios_base::app);
    if (file.is_open()){
        file << character.getName() << " "
            << character.getGender() << " "
            << character.getRace() << " "
            << character.getOrientation() << " "
            << character.getCharClass() << " "
            << character.getInitialWeapon() << " "
            << character.getGold() << " "
            << character.getSkillPoints() << " "
            << character.getHealthPoints() << " "
            << character.getManaPoints() << " "
            << character.getIntellect() << " "
            << character.getStrength() << " "
            << character.getAgility() << " "
            << character.getLevel() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    } 
}

void Menu::loadGame(){
    ifstream file("savegame.txt");
    if (file.is_open()){
        string line;
        vector<string> games;
        while (getline(file, line)){
            games.push_back(line);
        }
        file.close();

        cout << "================" << endl;
        cout << "  Load Game" << endl;
        cout << "================" << endl;
        for (int i = 0; i < games.size(); i++){
            istringstream ss(games[i]);
            string name;
            int level;
            ss >> name >> level;
            cout << i + 1 << ". " << name << " - Level " << level << endl; 
        }

        int option;
        cout << "Choose a game to load: ";
        cin >> option;

        if (option > 0 && option <= games.size()){
            string selectedGame = games[option - 1];
            istringstream ss(selectedGame);
            string name, item;
            int gender, race, orientation, charClass, level, gold, skillPoints, healthPoints, manaPoints, intellect, strength, agility;
            ss >> name >> gender >> race >> orientation >> charClass >> item >> gold >> skillPoints >> healthPoints >> manaPoints >> intellect >> strength >> agility >> level;

            Character::Gender charGender = static_cast<Character::Gender>(gender);
            Character::Race charRace = static_cast<Character::Race>(race);
            Character::Orientation charOrientation = static_cast<Character::Orientation>(orientation);
            Character::CharacterClass charCharClass = static_cast<Character::CharacterClass>(charClass);

            Character loadedChar(name, charGender, charRace, charOrientation, charCharClass);
            loadedChar.setGold(gold);
            loadedChar.setSkillPoints(skillPoints);
            loadedChar.setHealthPoints(healthPoints);
            loadedChar.setManaPoints(manaPoints);
            loadedChar.setIntellect(intellect);
            loadedChar.setStrength(strength);
            loadedChar.setAgility(agility);
            loadedChar.setLevel(level);

            cout << "Game loaded successfully!" << endl;
            showGameMenu(loadedChar);
        }
        else {
            cout << "Invalid option, please choose a valid one." << endl;
            loadGame();
        }
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void Menu::gameMenu() {
    cout << "================" << endl;
    cout << "  Game Menu\n1. Show Character Info\n2. Buy equipment\n3. Skill Tree\n4. Go on an adventure!\n5. Save Game\n6. Exit to main menu" << endl;
}

void Menu::showGameMenu(Character& character) {
    int option = 0; 

    while (option != 6) { 
        cleanConsole();
        gameMenu();
        cin >> option;

        switch (option) {
            case 1:
                charInfo(character); 
                break;
            case 2:
                switch (character.getCharClass()){
                    case Character:: Warrior:{
                        cout << "================" << endl;
                        cout << " Shop " << endl;
                        cout << "================" << endl;
                        cout << "Your Gold: " << character.getGold() << "G" << endl;
                        cout << "1. Battle Axe - 800G" << endl;
                        cout << "2. Warrior's Helmet - 600G" << endl;
                        cout << "3. Reinforced Armor - 1000G" << endl;
                        cout << "4. Spike Boots - 550G" << endl;
                        cout << "5. Battle Shield - 750G" << endl;
                        cout << "6. War Boots - 650G" << endl;
                        cout << "7. Warrior's Crown - 700G" << endl;
                        cout << "8. Gladiators Sword - 850G" << endl;
                        cout << "9. Exit" << endl;

                        int shopOption;
                        cin >> shopOption;

                        if (shopOption >= 1 && shopOption <= 8){
                            int price;
                            string item;
                            switch (shopOption){
                                case 1:
                                    price = 800;
                                    item = "Battle Axe";
                                    break;
                                case 2:
                                    price = 600;
                                    item = "Warrior's Helmet";
                                    break;
                                case 3:
                                    price = 1000;
                                    item = "Reinforced Armor";
                                    break;
                                case 4:
                                    price = 550;
                                    item = "Spike Boots";
                                    break;
                                case 5:
                                    price = 750;
                                    item = "Battle Shield";
                                    break;
                                case 6:
                                    price = 650;
                                    item = "War Boots";
                                    break;
                                case 7:
                                    price = 700;
                                    item = "Warrior's Crown";
                                    break;
                                case 8:
                                    price = 850;
                                    item = "Gladiators Sword";
                                    break;
                            }

                            if (character.getGold() >= price){
                                character.addItem(item);
                                character.setGold(character.getGold() - price);
                                cout << "Item bought successfully!" << endl;
                            }
                            else {
                                cout << "You don't have enough gold to buy this item." << endl;
                            }
                        }
                        else if (shopOption == 9){
                            break;
                        }
                        else {
                            cout << "Invalid option, please choose a valid one." << endl;
                        }
                    }
                    break;
                    case Character::Archer:{
                        cout << "================" << endl;
                        cout << " Shop " << endl;
                        cout << "================" << endl;
                        cout << "Your Gold: " << character.getGold() << "G" << endl;
                        cout << "1. Long Bow - 500G" << endl;
                        cout << "2. Hawk Eye Hood - 550G" << endl;
                        cout << "3. Leather Armor - 600G" << endl;
                        cout << "4. Silent Boots - 450G" << endl;
                        cout << "5. Forest Hood - 750G" << endl;
                        cout << "6. Reinforced Gloves - 550G" << endl;
                        cout << "7. Power Bandana - 650G" << endl;
                        cout << "8. Precision Crossbow - 800G" << endl;
                        cout << "9. Exit" << endl;

                        int shopOption;
                        cin >> shopOption;

                        if (shopOption >= 1 && shopOption <= 8){
                            int price;
                            string item;
                            switch (shopOption){
                                case 1:
                                    price = 500;
                                    item = "Long Bow";
                                    break;
                                case 2:
                                    price = 550;
                                    item = "Hawk Eye Hood";
                                    break;
                                case 3:
                                    price = 600;
                                    item = "Leather Armor";
                                    break;
                                case 4:
                                    price = 450;
                                    item = "Silent Boots";
                                    break;
                                case 5:
                                    price = 750;
                                    item = "Forest Hood";
                                    break;
                                case 6:
                                    price = 550;
                                    item = "Reinforced Gloves";
                                    break;
                                case 7:
                                    price = 650;
                                    item = "Power Bandana";
                                    break;
                                case 8:
                                    price = 800;
                                    item = "Precision Crossbow";
                                    break;
                            }

                            if (character.getGold() >= price){
                                character.addItem(item);
                                character.setGold(character.getGold() - price);
                                cout << "Item bought successfully!" << endl;
                            }
                            else {
                                cout << "You don't have enough gold to buy this item." << endl;
                            }
                        }
                        else if (shopOption == 9){
                            break;
                        }
                        else {
                            cout << " Invalid option, please choose a valid one." << endl;
                    }
                }
                break;
                case Character::Mage:{
                    cout << "================" << endl;
                    cout << " Shop " << endl;
                    cout << "================" << endl;
                    cout << "Your Gold: " << character.getGold() << "G" << endl;
                    cout << "1. Mystic Tunic - 500G" << endl;
                    cout << "2. Mage's Ring - 600G" << endl;
                    cout << "3. Enchanted Hat - 550G" << endl;
                    cout << "4. Magic Boots - 450G" << endl;
                    cout << "5. Sage's Cape - 800G" << endl;
                    cout << "6. Magic Amulet - 750G" << endl;
                    cout << "7. Arcane Staff - 650G" << endl;
                    cout << "8. Master's Tiara - 900G" << endl;
                    cout << "9. Exit" << endl;

                    int shopOption;
                    cin >> shopOption;

                    if (shopOption >= 1 && shopOption <= 8){
                        int price;
                        string item;
                        switch (shopOption){
                            case 1:
                                price = 500;
                                item = "Mystic Tunic";
                                break;
                            case 2:
                                price = 600;
                                item = "Mage's Ring";
                                break;
                            case 3:
                                price = 550;
                                item = "Enchanted Hat";
                                break;
                            case 4:
                                price = 450;
                                item = "Magic Boots";
                                break;
                            case 5:
                                price = 800;
                                item = "Sage's Cape";
                                break;
                            case 6:
                                price = 750;
                                item = "Magic Amulet";
                                break;
                            case 7:
                                price = 650;
                                item = "Magic Bandana";
                                break;
                            case 8:
                                price = 900;
                                item = "Magic Wand";
                                break;
                        }

                        if (character.getGold() >= price){
                            character.addItem(item);
                            character.setGold(character.getGold() - price);
                            cout << "Item bought successfully!" << endl;
                        }
                        else {
                            cout << "You don't have enough gold to buy this item." << endl;
                        }
                    }
                    else if (shopOption == 9){
                        break;
                    }
                    else {
                        cout << "Invalid option, please choose a valid one." << endl;
                    }
                }
                break;
                case Character::Thief:{
                    cout << "================" << endl;
                    cout << " Shop " << endl;
                    cout << "================" << endl;
                    cout << "Your Gold: " << character.getGold() << "G" << endl;
                    cout << "1. Twin Daggers - 500G" << endl;
                    cout << "2. Thief's Mask - 600G" << endl;
                    cout << "3. Climbing Hook - 550G" << endl;
                    cout << "4. Thief Boots - 450G" << endl;
                    cout << "5. Boss' Boots - 750G" << endl;
                    cout << "6. Stealth Tunic - 800G" << endl;
                    cout << "7. Scimitar - 650G" << endl;
                    cout << "8. Bandit's Mask - 550G" << endl;
                    cout << "11. Exit" << endl;

                    int shopOption;
                    cin >> shopOption;

                    if (shopOption >= 1 && shopOption <= 8){
                        int price;
                        string item;
                        switch (shopOption){
                            case 1:
                                price = 500;
                                item = "Twin Daggers";
                                break;
                            case 2:
                                price = 600;
                                item = "Dark Cape";
                                break;
                            case 3:
                                price = 550;
                                item = "Climbing Hook";
                                break;
                            case 4:
                                price = 450;
                                item = "Thief Boots";
                                break;
                            case 5:
                                price = 750;
                                item = "Boss' Boots";
                                break;
                            case 6:
                                price = 800;
                                item = "Stealth Tunic";
                                break;
                            case 7:
                                price = 650;
                                item = "Scimitar";
                                break;
                            case 8:
                                price = 550;
                                item = "Bandit's Mask";
                                break;
                        }

                        if (character.getGold() >= price){
                            character.addItem(item);
                            character.setGold(character.getGold() - price);
                            cout << "Item bought successfully!" << endl;
                        }
                        else {
                            cout << "You don't have enough gold to buy this item." << endl;
                        }
                    }
                    else if (shopOption == 9){
                        break;
                    }
                    else {
                        cout << "Invalid option, please choose a valid one." << endl;
                    }
                }
                break;
            }
            case 3:
                int skillPoints = character.getSkillPoints();
                if (skillPoints >= 5){
                    cout << "================" << endl;
                    cout << "  Skill Tree" << endl;
                    cout << "================" << endl;
                    cout << "Total Skill Points: " << skillPoints << endl;
                    cout << "Choose a skill to unlock: " << endl;

                    switch(character.getCharClass()){
                        case Character::Warrior:
                            cout << "1. Power Strike - 5 Points" << endl;
                            cout << "2. Iron Defense - 12 Points" << endl;
                            cout << "3. War Cry - 2S Points" << endl;
                            cout << "4. Exit" << endl;

                            int skillOption;
                            cin.ignore();
                            cin >> skillOption;


                            if (skillOption >= 1 && skillOption <= 3){
                                switch (skillOption){
                                    case 1:                                
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Power Strike unlocked!" << endl;
                                        break;
                                    case 2:
                                        character.setSkillPoints(skillPoints - 12);
                                        cout << "Iron Defense unlocked!" << endl;
                                        break;
                                    case 3:
                                        character.setSkillPoints(skillPoints - 25);
                                        cout << "War Cry unlocked!" << endl;
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                            }

                            break;
                        case Character::Archer:
                            cout << "1. Quick Shot - 5 Points" << endl;
                            cout << "2. Eagle Eye - 18 Points" << endl;
                            cout << "3. Arrow Burst - 27 Points" << endl;
                            cout << "4. Exit" << endl;

                            int skillOption;
                            cin.ignore();
                            cin >> skillOption;

                            if (skillOption >= 1 && skillOption <= 3){
                                switch (skillOption){
                                    case 1:
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Quick Shot unlocked!" << endl;
                                        break;
                                    case 2:
                                        character.setSkillPoints(skillPoints - 18);
                                        cout << "Eagle Eye unlocked!" << endl;
                                        break;
                                    case 3:
                                        character.setSkillPoints(skillPoints - 27);
                                        cout << "Arrow Burst unlocked!" << endl;
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                            }

                            break;
                        case Character::Mage:{
                            cout << "1. Fireball - 5 Points" << endl;
                            cout << "2. Ice Beam - 15 Points" << endl;
                            cout << "3. Radiant - 24 Points" << endl;
                            cout << "4. Exit" << endl;

                            int skillOption;
                            cin.ignore();
                            cin >> skillOption;

                            if (skillOption >= 1 && skillOption <= 3){
                                switch (skillOption){
                                    case 1:
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Fireball unlocked!" << endl;
                                        break;
                                    case 2: 
                                        character.setSkillPoints(skillPoints - 15);
                                        cout << "Ice Beam unlocked!" << endl;
                                        break;
                                    case 3:
                                        character.setSkillPoints(skillPoints - 24);
                                        cout << "Radiant unlocked!" << endl;
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                            }
                            break;
                        case Character::Thief:
                            cout << "1. Backstab - 5 Points" << endl;
                            cout << "2. Focus - 14 Points" << endl;
                            cout << "3. Lethal Stab - 25 Points" << endl;
                            cout << "4. Exit" << endl;

                            int skillOption;
                            cin.ignore();
                            cin >> skillOption;

                            if (skillOption >= 1 && skillOption <= 3){
                                switch (skillOption){
                                    case 1:
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Backstab unlocked!" << endl;
                                        break;
                                    case 2:
                                        character.setSkillPoints(skillPoints - 14);
                                        cout << "Focus unlocked!" << endl;
                                        break;
                                    case 3:
                                        character.setSkillPoints(skillPoints - 25);
                                        cout << "Lethal Stab unlocked!" << endl;
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                            }
                            break;
                        default:
                            cout << "Invalid option, please choose a valid one." << endl;
                            break;
                        }
                        



                    }
                } 
                break;
            case 4:
                //goOnAdventure(character); 
                break;
            case 5:
                saveGame(character);
                break;
            case 6:
                return; 
            default:
                cout << "Invalid option, please choose a valid one." << endl;
        }
    }
}