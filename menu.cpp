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
    cout << "GAME NITS: throughout the game there are scattered items that will\n";
    cout << "help or hinder you as you make your way through the day. Hints will\n";
    cout << "scattered about the office that will help you out.\n\n";

    cout << "1. Start Game\n";
    cout << "2. Exit Game\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Menu::gameIntro() {
    cout << ""
}

/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


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


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


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