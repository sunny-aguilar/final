/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class also holds the
**                  user input validation function.
*********************************************************************/
#include "menu.hpp"


/*********************************************************************
** Description:     d
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
** Description:     d
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
            cout << "it all over your shirt as you get into your car ( -1 sanity points)\n\n";
            p->setSanityPoints(-1);
            break;
        case 2:
            carArt();
            cout << "Although you got up for work early with plenty of time to spare,\n";
            cout << "unforeseen traffic conditions have made you 15 minutes late for work\n";
            cout << "( -1 performance points, -1 sanity points)\n\n";
            p->setPerformancePoints(-1);
            p->setSanityPoints(-1);
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
** Description:     d
*********************************************************************/
void Menu::carArt() {
    cout << "        _______\n"
            "       //  ||\\ \\\n"
            " _____//___||_\\ \\___\n"
            " )  _          _    \\\n"
            " |_/ \\________/ \\___|\n"
            "___\\_/________\\_/______\n";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::officeArt() {
    cout << "(╯°□°）╯︵ ┻━┻\n";
    cout << "┬─┬ノ( º _ ºノ)\n";


}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::startWorkDay() {
    myDeskArt();
    cout << "You have arrived to work and are ready for the day\n\n";
}

/*********************************************************************
** Description:     d
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
** Description:     d
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
    cout << "<< heads up display >>\n";
    cout << "+--------------------------------------------------------------------+\n";
    cout << "[  Sanity Points: " << setw(2) << p->getSanityPoints() << "               |";
    cout << "   Performance Points: " << setw(2) << p->getPerformancePoints() <<"        ]\n";
    cout << "[  Current Location:  " << setw(8) << loc << "   |";
    cout << "   Current Time:  " << time << "        ]\n";
    cout << "[  Inventory: " << "                                                       ]\n";
    cout << "+--------------------------------------------------------------------+\n\n";
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
    if (space->getLocationName() == "My Cubicle") {
        if (space->getPlayer() != nullptr) {
            bl = space->getLocationName() + " [*]";
        }
    }




    cout << "  ___   __  __ _        __  __           \n"
            " / _ \\ / _|/ _(_)__ ___|  \\/  |__ _ _ __ \n"
            "| (_) |  _|  _| / _/ -_) |\\/| / _` | '_ \\\n"
            " \\___/|_| |_| |_\\__\\___|_|  |_\\__,_| .__/\n"
            "                                   |_|\n";
    cout << left;
    cout << "+----------------------------------------------------------------------+\n";
    cout << "[ " << setw(16) << tl << "     | ";
    cout << setw(16) << tm << "      | ";
    cout << setw(16) << tr << "      ]\n";
    cout << "+----------------------------------------------------------------------+\n";
    cout << "[ "<< setw(16) << bl << "     | ";
    cout << setw(16) << bm << "      | ";
    cout << setw(16) << br << "      ]\n";
    cout << "+----------------------------------------------------------------------+\n";
    cout << "\nHit [ENTER] to continue\n";
    cin.ignore();
    cout << "\n\n\n\n";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::displayAvailableSpaces() {

}

/*********************************************************************
** Description:     d
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