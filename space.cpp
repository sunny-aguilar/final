/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Space class provides a player spaces for
**                  which they can move through. The space class is
**                  an abstract class from which other classes are
**                  derived from. Space class contains virtual
**                  functions. Each space has 4 space pointers are
**                  used to point to other spaces and allow a player
**                  to move about.
*********************************************************************/
#include "space.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Space::Space() :
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr} {}

/*********************************************************************
** Description:     2-arg constructor
*********************************************************************/
Space::Space(string locName, Location loc) :
    location{loc},
    locationName{locName},
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr},
    player{nullptr} {}

/*********************************************************************
** Description:     3-arg constructor
*********************************************************************/
Space::Space(string locName, Location loc, Player *player) :
    location{loc},
    locationName{locName},
    player{player},
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr} {}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Space::~Space() {}

/*********************************************************************
** Description:     returns a string showing the space name
*********************************************************************/
string Space::getLocationName() {
    return locationName;
}

/*********************************************************************
** Description:     sets the space pointer going up
*********************************************************************/
void Space::setUp(Space *up) {
    this->up = up;
}

/*********************************************************************
** Description:     sets the space pointer going right
*********************************************************************/
void Space::setRight(Space *right) {
    this->right = right;
}

/*********************************************************************
** Description:     sets the space pointer down
*********************************************************************/
void Space::setDown(Space *down) {
    this->down = down;
}

/*********************************************************************
** Description:     sets the space pointer on the left
*********************************************************************/
void Space::setLeft(Space *left) {
    this->left = left;
}

/*********************************************************************
** Description:     returns the pointer of the space going up
*********************************************************************/
Space *Space::getUp() {
    return up;
}

/*********************************************************************
** Description:     returns the pointer of the space on the right
*********************************************************************/
Space *Space::getRight() {
    return right;
}

/*********************************************************************
** Description:     returns the pointer of the space going down
*********************************************************************/
Space *Space::getDown() {
    return down;
}

/*********************************************************************
** Description:     returns the pointer of the space on the left
*********************************************************************/
Space *Space::getLeft() {
    return left;
}

/*********************************************************************
** Description:     returns the player pointer
*********************************************************************/
void Space::setPlayer(Player *&player) {
    this->player = player;
}

/*********************************************************************
** Description:     returns the player pointer
*********************************************************************/
Player *Space::getPlayer() {
    return player;
}

/*********************************************************************
** Description:     returns the enum location of the player
*********************************************************************/
Location Space::getLocation() {
    return location;
}

/*********************************************************************
** Description:     takes an integer that it will use to generate a
**                  random number from 1 to max
*********************************************************************/
int Space::generateRandom(int max) {
    int randomNum = 0;
    randomNum = rand() % max + 1;
    return randomNum;
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Space::validateNumber(int min, int max) {
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