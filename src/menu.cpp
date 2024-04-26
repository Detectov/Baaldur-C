#include <filesystem>
#include "menu.h"



using namespace std;

namespace fs = std::filesystem;

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu :: charInfo(const Character &character){
    cout << "================" << endl;
    cout << "  Character Info" << endl;
    cout << "================" << endl;
    cout << "Name: " << character.getName() << endl;
    cout << "Level: " << character.getLevel() << endl;
    cout << "Class: " << Character::classToString(character.getCharClass()) << endl;
    cout << "Race: " << Character::raceToString(character.getRace()) << endl;
    cout << "Orientation: " << Character::orientationToString(character.getOrientation()) << endl;
    cout << "Gold: " << character.getGold() << "G" << endl;
    cout << "Skill Points: " << character.getSkillPoints() << endl;
    cout << "Initial Weapon: " << character.getInitialWeapon() << endl;
    cout << "Health Points: " << character.getHealthPoints() << endl;
    cout << "Mana Points: " << character.getManaPoints() << endl;
    cout << "Intellect: " << character.getIntellect() << endl;
    cout << "Strength: " << character.getStrength() << endl;
    cout << "Agility: " << character.getAgility() << endl;

    cout << "Press any key to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    
}

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
    string path = fs::current_path().string();

    map<string, Character> characterMap;
    ifstream inFile(path + "./savegame.txt");
    string line;
    
    if (inFile.is_open()){
        while (getline(inFile, line)){
            istringstream lineStream(line);
            Character readChar;
            lineStream >> readChar;
            characterMap[readChar.getName()] = readChar;
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    characterMap[character.getName()] = character;

    ofstream outFile("savegame.txt", ios::trunc);
    if (outFile.is_open()){
        for (const auto& pair : characterMap){
            outFile << pair.second;
        }
        outFile.close();
        cout << "Game saved successfully!" << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
    else {
        cout << "Unable to open file" << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
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

        cleanConsole();
        cout << "================" << endl;
        cout << "  Load Game" << endl;
        cout << "================" << endl;
        for (int i = 0; i < games.size(); i++){
            istringstream ss(games[i]);
            string name, item;
            int gender, race, orientation, charClass, gold, skillPoints, healthPoints, manaPoints, intellect, strength, agility, level;
            ss >> name >> gender >> race >> orientation >> charClass >> item >> gold >> skillPoints >> healthPoints >> manaPoints >> intellect >> strength >> agility >> level;
            cout << i + 1 << ". " << name << " - Level " << level << endl; 
        }

        int option;
        cout << "Choose a game to load: ";
        cin >> option;

        if (option > 0 && option <= games.size()){
            string selectedGame = games[option - 1];
            istringstream ss(selectedGame);
            string name, item;
            int gender, race, orientation, charClass, gold, skillPoints, healthPoints, manaPoints, intellect, strength, agility, level;
            ss >> name >> gender >> race >> orientation >> charClass >> item >> gold >> skillPoints >> healthPoints >> manaPoints >> intellect >> strength >> agility >> level;

            Character::Gender charGender = static_cast<Character::Gender>(gender);
            Character::Race charRace = static_cast<Character::Race>(race);
            Character::Orientation charOrientation = static_cast<Character::Orientation>(orientation);
            Character::CharacterClass charCharClass = static_cast<Character::CharacterClass>(charClass);

            Character loadedChar(name, charGender, charRace, charOrientation, charCharClass);
            loadedChar.setInitialWeapon(item);
            loadedChar.setGold(gold);
            loadedChar.setSkillPoints(skillPoints);
            loadedChar.setHealthPoints(healthPoints);
            loadedChar.setManaPoints(manaPoints);
            loadedChar.setIntellect(intellect);
            loadedChar.setStrength(strength);
            loadedChar.setAgility(agility);
            loadedChar.setLevel(level);

            cout << "Game loaded successfully!" << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            showGameMenu(loadedChar);
        }
        else {
            cout << "Invalid option, please choose a valid one." << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            loadGame();
        }
    }
    else {
        cout << "Unable to open file" << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}


void Menu::gameMenu() {
    cout << "================" << endl;
    cout << "  Game Menu\n1. Show Character Info\n2. Buy equipment\n3. Skill Tree\n4. Go on an adventure!\n5. Save Game\n6. Exit to main menu" << endl;
    cout << "================" << endl;
}

void Menu::showGameMenu(Character& character) {
    int option = 0; 

    while (option != 6) { 
        cleanConsole();
        gameMenu();
        cin >> option;

        switch (option) {
            case 1:{
                charInfo(character); 
                break;
            }
            case 2:{
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
                        cout << "9. Herbs - 25G" << endl;
                        cout << "10. Elixir - 35G" << endl;
                        cout << "11. Exit" << endl;

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
                                case 9:
                                    price = 25;
                                    item = "Herbs";
                                    break;
                                case 10:
                                    price =35;
                                    item = "Elixir";
                                    break;
                            }

                            if (character.getGold() >= price){
                                character.addItem(item);
                                character.setGold(character.getGold() - price);
                                cout << "Item bought successfully!" << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                            else {
                                cout << "You don't have enough gold to buy this item." << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                        }
                        else if (shopOption == 11){
                            break;
                        }
                        else {
                            cout << "Invalid option, please choose a valid one." << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                        }
                        break;
                    }
                    
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
                        cout << "9. Herbs - 25G" << endl;
                        cout << "10. Elixir - 35G" << endl;
                        cout << "11. Exit" << endl;

                        int shopOption;
                        cin >> shopOption;

                        if (shopOption >= 1 && shopOption <= 8){
                            int price;
                            string item;
                            switch (shopOption){
                                case 1:
                                    price = 500;
                                    item = "LongBow";
                                    break;
                                case 2:
                                    price = 550;
                                    item = "HawkEyeHood";
                                    break;
                                case 3:
                                    price = 600;
                                    item = "LeatherArmor";
                                    break;
                                case 4:
                                    price = 450;
                                    item = "SilentBoots";
                                    break;
                                case 5:
                                    price = 750;
                                    item = "ForestHood";
                                    break;
                                case 6:
                                    price = 550;
                                    item = "ReinforcedGloves";
                                    break;
                                case 7:
                                    price = 650;
                                    item = "PowerBandana";
                                    break;
                                case 8:
                                    price = 800;
                                    item = "PrecisionCrossbow";
                                    break;
                                case 9:
                                    price = 25;
                                    item = "Herbs";
                                    break;
                                case 10:
                                    price =35;
                                    item = "Elixir";
                                    break;
                            }

                            if (character.getGold() >= price){
                                character.addItem(item);
                                character.setGold(character.getGold() - price);
                                cout << "Item bought successfully!" << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                            else {
                                cout << "You don't have enough gold to buy this item." << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                        }
                        else if (shopOption == 11){
                            break;
                        }
                        else {
                            cout << " Invalid option, please choose a valid one." << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                    }
                    break;
                }
                
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
                    cout << "9. Herbs - 25G" << endl;
                    cout << "10. Elixir - 35G" << endl;
                    cout << "11. Exit" << endl;

                    int shopOption;
                    cin >> shopOption;

                    if (shopOption >= 1 && shopOption <= 8){
                        int price;
                        string item;
                        switch (shopOption){
                            case 1:
                                price = 500;
                                item = "MysticTunic";
                                break;
                            case 2:
                                price = 600;
                                item = "Mage'sRing";
                                break;
                            case 3:
                                price = 550;
                                item = "EnchantedHat";
                                break;
                            case 4:
                                price = 450;
                                item = "MagicBoots";
                                break;
                            case 5:
                                price = 800;
                                item = "Sage'sCape";
                                break;
                            case 6:
                                price = 750;
                                item = "MagicAmulet";
                                break;
                            case 7:
                                price = 650;
                                item = "MagicBandana";
                                break;
                            case 8:
                                price = 900;
                                item = "MagicWand";
                                break;
                            case 9:
                                price = 25;
                                item = "Herbs";
                                break;
                            case 10:
                                price =35;
                                item = "Elixir";
                                break;
                        }

                        if (character.getGold() >= price){
                            character.addItem(item);
                            character.setGold(character.getGold() - price);
                            cout << "Item bought successfully!" << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                        }
                        else {
                            cout << "You don't have enough gold to buy this item." << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                        }
                    }
                    else if (shopOption == 11){
                        break;
                    }
                    else {
                        cout << "Invalid option, please choose a valid one." << endl;
                        cout << "Press any key to continue..." << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                    }
                    break;
                }
                
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
                    cout << "9. Herbs - 25G" << endl;
                    cout << "10. Elixir - 35G" << endl;
                    cout << "11. Exit" << endl;

                    int shopOption;
                    cin >> shopOption;

                    if (shopOption >= 1 && shopOption <= 8){
                        int price;
                        string item;
                        switch (shopOption){
                            case 1:
                                price = 500;
                                item = "TwinDaggers";
                                break;
                            case 2:
                                price = 600;
                                item = "DarkCape";
                                break;
                            case 3:
                                price = 550;
                                item = "ClimbingHook";
                                break;
                            case 4:
                                price = 450;
                                item = "ThiefBoots";
                                break;
                            case 5:
                                price = 750;
                                item = "Boss'Boots";
                                break;
                            case 6:
                                price = 800;
                                item = "StealthTunic";
                                break;
                            case 7:
                                price = 650;
                                item = "Scimitar";
                                break;
                            case 8:
                                price = 550;
                                item = "Bandit'sMask";
                                break;
                            case 9:
                                price = 25;
                                item = "Herbs";
                                break;
                            case 10:
                                price =35;
                                item = "Elixir";
                                break;
                        }

                        if (character.getGold() >= price){
                            character.addItem(item);
                            character.setGold(character.getGold() - price);
                            cout << "Item bought successfully!" << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                        }
                        else {
                            cout << "You don't have enough gold to buy this item." << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                        }
                    }
                    else if (shopOption == 11){
                        break;
                    }
                    else {
                        cout << "Invalid option, please choose a valid one." << endl;
                        cout << "Press any key to continue..." << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                    }
                    break;
                }
                
                }
                break;
            }
            case 3:{
                int skillPoints = character.getSkillPoints();
                if (skillPoints >= 5){
                    cout << "================" << endl;
                    cout << "  Skill Tree" << endl;
                    cout << "================" << endl;
                    cout << "Total Skill Points: " << skillPoints << endl;

                    switch(character.getCharClass()){
                        case Character::Warrior:{
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
                                    if (skillPoints >= 5){                              
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Power Strike unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 2:
                                    if (skillPoints >= 12){
                                        character.setSkillPoints(skillPoints - 12);
                                        cout << "Iron Defense unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 3:
                                    if (skillPoints >= 25){
                                        character.setSkillPoints(skillPoints - 25);
                                        cout << "War Cry unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }

                            break;
                        }
                        case Character::Archer:{
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
                                    if (skillPoints >= 5){
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Quick Shot unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 2:
                                    if (skillPoints >= 18){
                                        character.setSkillPoints(skillPoints - 18);
                                        cout << "Eagle Eye unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
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
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }

                            break;
                        }
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
                                    if (skillPoints >= 5){
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Fireball unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 2: 
                                    if (skillPoints >= 15){
                                        character.setSkillPoints(skillPoints - 15);
                                        cout << "Ice Beam unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 3:
                                    if (skillPoints >= 24){
                                        character.setSkillPoints(skillPoints - 24);
                                        cout << "Radiant unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                            break;
                        }
                        case Character::Thief:{
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
                                    if (skillPoints >= 5){
                                        character.setSkillPoints(skillPoints - 5);
                                        cout << "Backstab unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 2:
                                    if (skillPoints >= 14){
                                        character.setSkillPoints(skillPoints - 14);
                                        cout << "Focus unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                    case 3:
                                    if (skillPoints >= 25){
                                        character.setSkillPoints(skillPoints - 25);
                                        cout << "Lethal Stab unlocked!" << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                    else {
                                        cout << "You don't have enough skill points to unlock this skill." << endl;
                                        cout << "Press any key to continue..." << endl;
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin.get();
                                    }
                                        break;
                                }
                            }
                            else if (skillOption == 4){
                                break;
                            }
                            else {
                                cout << "Invalid option, please choose a valid one." << endl;
                                cout << "Press any key to continue..." << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                            }
                            break;
                        }
                        default:{
                            cout << "Invalid option, please choose a valid one." << endl;
                            cout << "Press any key to continue..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                            break;

                        }
                        



                    }
                    
                } 
                else {
                    cout << "You don't have enough skill points to unlock a new skill." << endl;
                    cout << "Press any key to continue..." << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                }
                break;
            }
            
            case 4:{
                //goOnAdventure(character); 
                cout << "Adventure not implemented yet" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            }
            case 5: {
                if (true) {
                    saveGame(character);
                }
                break;
            }
            case 6:{
                cout << "Exiting to main menu" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            } 
            default:{
                cout << "Invalid option, please choose a valid one." << endl; 
                cout << "Press any key to continue..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();  
                break;
            }

        }
        
    }
}
