/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class also holds the
**                  user input validation function.
*********************************************************************/
#include "menu.hpp"

/*********************************************************************
** Description:     intro art for the game title
*********************************************************************/
void Menu::startScreenArt() {
    cout << " _________  __                ___       ___    ___  _                 \n"
            "|  _   _  |[  |             .'   `.   .' ..] .' ..](_)                \n"
            "|_/ | | \\_| | |--.  .---.  /  .-.  \\ _| |_  _| |_  __   .---.  .---.  \n"
            "    | |     | .-. |/ /__\\\\ | |   | |'-| |-''-| |-'[  | / /'`\\]/ /__\\\\ \n"
            "   _| |_    | | | || \\__., \\  `-'  /  | |    | |   | | | \\__. | \\__., \n"
            "  |_____|  [___]|__]'.__.'  `.___.'  [___]  [___] [___]'.___.' '.__.'\n";
}

/*********************************************************************
** Description:     displays the start screen for the game
*********************************************************************/
void Menu::startScreen() {
    startScreenArt();
    cout << endl;

    cout << "The game were you try to survive the day to day office drudgery\n";
    cout << "of a job full of meaningless work, an out of touch boss and weird\n";
    cout << "co-workers. Your job is to make it through the day without getting\n";
    cout << "fired or losing your sanity. Luckily for you, one of your best\n";
    cout << "friends happens to be a co-worker that is ready to help you get\n";
    cout << "through the day.\n\n";
    cout << "OBJECTIVE: you start with 10 sanity points and 10 performance points\n";
    cout << "If your sanity or performance drops below 1 before the day is over,\n";
    cout << "the game will end.\n\n";
    cout << "TIME RULES: The day starts at 9AM and ends at 5PM. The time is adjusted in half\n";
    cout << "hour increments for each space visited.\n\n";
    cout << "GAME HINTS: throughout the game there are scattered items that will\n";
    cout << "help or hinder you as you make your way through the day. Hints will\n";
    cout << "scattered about the office that will help you out.\n\n";

    cout << "1. Start Game\n";
    cout << "2. Exit Game\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays the beginning of day activities. The
**                  function receives a player object and a randomly
**                  generated int value that is used to select a
**                  random event that will affect how your day starts
**                  off, just like in real life.
*********************************************************************/
void Menu::gameIntro(int chance, Player *p) {
    sunIntro();

    cout << "It is 7:30 AM and your alarm has just gone off. You quickly get\n";
    cout << "up and get ready for work with time to spare.\n\n";
    cout << "Sanity points " << p->getSanityPoints() << "   |   ";
    cout << "Performance points " << p->getPerformancePoints() << endl;
    cout << "\nHit [ENTER] to continue to next round\n";
    cin.ignore();

    switch (chance) {
        case 1:
            carArt();
            cout << "You decide to make yourself a cup of coffee however you spill\n";
            cout << "it all over your shirt as you get into your car ( -2 sanity points)\n\n";
            p->setSanityPoints(-2);
            break;
        case 2:
            carArt();
            cout << "Although you got up for work early with plenty of time to spare,\n";
            cout << "unforeseen traffic conditions have made you 15 minutes late for work\n";
            cout << "( -1 performance points, -2 sanity points)\n\n";
            p->setPerformancePoints(-1);
            p->setSanityPoints(-2);
            break;
        case 3:
            carArt();
            cout << "You get into your car and luckily make it to work on time\n\n";
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
    cout << "\nHit [ENTER] to continue to next round\n";
    cin.ignore();
}

/*********************************************************************
** Description:     displays ascii art of a morning sun
*********************************************************************/
void Menu::sunIntro() {
    cout << "                        |\n"
            "                    \\       /\n"
            "                      .-\"-.\n"
            "                 --  /     \\  --\n"
            "`~~^~^~^~^~^~^~^~^~^-=======-~^~^~^~~^~^~^~^~^~^~^~`\n"
            "`~^_~^~^~-~^_~^~^_~-=========- -~^~^~^-~^~^_~^~^~^~`\n"
            "`~^~-~~^~^~-^~^_~^~~ -=====- ~^~^~-~^~_~^~^~~^~-~^~`\n"
            "`~^~^~-~^~~^~-~^~~-~^~^~-~^~~^-~^~^~^-~^~^~^~^~~^~-`\n\n";
}

/*********************************************************************
** Description:     displays ascii art of a vehicle
*********************************************************************/
void Menu::carArt() {
    cout << "              _______\n"
            "             //  ||\\ \\ =\n"
            "       _____//___||_\\ \\___  =\n"
            "       )  _          _    \\\n"
            "       |_/ \\________/ \\___|  O o o .\n"
            "_________\\_/________\\_/_________________\n";
}

/*********************************************************************
** Description:     displays the desk art and lets a player know they
**                  have arrived to work
*********************************************************************/
void Menu::startWorkDay() {
    myDeskArt();
    cout << "You have arrived to work and are ready for the day\n\n";
}

/*********************************************************************
** Description:     displays ascii art of a desk
*********************************************************************/
void Menu::myDeskArt() {
    cout << "       ____\n"
            "      ||   |\n"
            "      ||___|\n"
            "      _)__<__  _     _\n"
            "      |____|__|:|___|:|_\n"
            "      |    |_.---._|___|\n"
            "    _ |   o| |   | |_o_|\n"
            "   | ||    |/|   |\\|   |\n"
            "   |_||____|`\\___/'|___|\n"
            "               V\n"
            "             _/-\\_\n\n";
}

/*********************************************************************
** Description:     displays the main menu to the user
*********************************************************************/
void Menu::mainMenu(string loc) {
    cout << "Choose something to do **************************\n";
    cout << "1. Show office map\n";
    cout << "2. Hang out at current location: " << loc << endl;
    cout << "3. Go to available spaces\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays player stats and inventory
*********************************************************************/
void Menu::hud(Player *p, string loc, string time) {
    cout << left;
    cout << "\n+-<<Heads Up Display>>----------------------------------------------------+\n";
    cout << "[  Sanity Points: " << setw(2) << p->getSanityPoints() << "                     |";
    cout << "   Performance Points: " << setw(2) << p->getPerformancePoints() <<"       ]\n";
    cout << "[  Current Location:  " << setw(16) << loc << "   |";
    cout << "   Current Time:  " << setw(8) << time << "      ]\n";
    cout << "   Inventory: "; p->displayInventory(); cout << endl;
    cout << "+-------------------------------------------------------------------------+\n\n";
}

/*********************************************************************
** Description:     displays office map
*********************************************************************/
void Menu::displayMap(Space *space) {
    string bl = "My Cubicle";
    string bm = "Water Cooler";
    string br = "Break Room";
    string tl = "Friend's Cubicle";
    string tm = "Boss's Office";
    string tr = "Meeting Room";

    // if player is in his cubicle, display that
    if (space->getLocationName() == "My Cubicle") {
        if (space->getPlayer() != nullptr) {
            bl = space->getLocationName() + " [*]";
        }
    }
    // if player is at his friend's cubicle, display that
    if (space->getLocationName() == "Friend's Cubicle") {
        if (space->getPlayer() != nullptr) {
            tl = space->getLocationName() + " [*]";
        }
    }
    // if player is at his boss's office, display that
    if (space->getLocationName() == "Boss's Office") {
        if (space->getPlayer() != nullptr) {
            tm = space->getLocationName() + " [*]";
        }
    }
    // if player is by the water cooler, display that
    if (space->getLocationName() == "Water Cooler") {
        if (space->getPlayer() != nullptr) {
            bm = space->getLocationName() + " [*]";
        }
    }
    // if player is by the meeting room, display that
    if (space->getLocationName() == "Meeting Room") {
        if (space->getPlayer() != nullptr) {
            tr = space->getLocationName() + " [*]";
        }
    }
    // if player is by the break room, display that
    if (space->getLocationName() == "Break Room") {
        if (space->getPlayer() != nullptr) {
            br = space->getLocationName() + " [*]";
        }
    }

    cout << "\n  ___   __  __ _        __  __           \n"
            " / _ \\ / _|/ _(_)__ ___|  \\/  |__ _ _ __ \n"
            "| (_) |  _|  _| / _/ -_) |\\/| / _` | '_ \\\n"
            " \\___/|_| |_| |_\\__\\___|_|  |_\\__,_| .__/\n"
            "                                   |_|";
    cout << "           [*] = CURRENT LOCATION\n";
    cout << left;
    cout << "+----------------------------------------------------------------------+\n";
    cout << "[ " << setw(20) << tl << "    | ";
    cout << setw(20) << tm << "| ";
    cout << setw(20) << tr << " ]\n";
    cout << "+----------------------------------------------------------------------+\n";
    cout << "[ "<< setw(20) << bl << "    | ";
    cout << setw(20) << bm << "| ";
    cout << setw(20) << br << " ]\n";
    cout << "+----------------------------------------------------------------------+\n";
    cout << "\nHit [ENTER] to continue\n";
    cin.ignore();
    cout << "\n\n\n\n";
}

/*********************************************************************
** Description:     displays available activities at the location that
**                  is received in the function parameter
*********************************************************************/
void Menu::displayRoomActivities(string loc) {
    cout << left;
    cout << "+------------------------------------------------------------------------+\n";
    cout << "[ Available Activities @ " << setw(16) << loc << "                                ]\n";
    cout << "+------------------------------------------------------------------------+\n";
}

/*********************************************************************
** Description:     displays the end game scenarios depending on the
**                  outcome of the game
*********************************************************************/
void Menu::endOfDay(int select, Player *p) {
    cout << left;
    cout << "\n+-<<Heads Up Display>>----------------------------------------------------+\n";
    cout << "[  Sanity Points: " << setw(2) << p->getSanityPoints() << "                     |";
    cout << "   Performance Points: " << setw(2) << p->getPerformancePoints() <<"       ]\n";
    cout << "+-------------------------------------------------------------------------+\n\n";

    switch (select) {
        case 0:
            cout << "Your job has literally driven you crazy and you are now checking\n";
            cout << "yourself in to the nearest mental institution for observation.\n";
            cout << "GAME OVER\n";
            break;
        case 1:
            cout << "Unfortunately, since your boss lacks patience and does not tolerate\n";
            cout << "mistakes, he has decided to fire you. Womp womp.\n";
            cout << "GAME OVER\n";
            break;
        case 2:
            cout << "\nCONGRATULATIONS!\n";
            cout << "You have made it through the day with your sanity intact and still have\n";
            cout << "your job! It is 5:00 PM and time to go home. You are relieved the day is\n";
            cout << "over and you look forward to getting home and continuing your computer science\n";
            cout << "studies. Until next time =)\n\n";
            cout << "GAME OVER\n";
            break;
        default:
            cout << "Unable to determine end of day message\n";
    }
}

/*********************************************************************
** Description:     displays exit message
*********************************************************************/
void Menu::exitGame() {
    cout << "Exiting game\n";
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}