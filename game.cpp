/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Game class
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/
#include "game.hpp"
#include "space.hpp"
#include "menu.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Game::Game() : time{1}, player{new Player()} {}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Game::~Game() {}

/*********************************************************************
** Description:     this function creates the spaces and links
**                  the pointers to each other
*********************************************************************/
void Game::createBoard() {
    // create spaces
    myCubicle = new MyCubicle( player );
    friendCubicle = new FriendCubicle();
    // TODO - remove this cout after debugged
    cout << "Player address " << player << endl;
    cout << "Friend Cubicle address " << friendCubicle << endl;

    // link spaces to each other
    myCubicle->setUp(friendCubicle);
    friendCubicle->setDown(myCubicle);




}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::start() {
    menu.startScreen();
    switch (menu.validateNumber(1,2)) {
        case 1:
            gameOperations();
            break;
        case 2:
            exitGame();
            break;
        default:
            cout << "Cannot determine selection made\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/
void Game::gameOperations() {
    // create the board
    createBoard();

    // game intro
    morningRoutine();

    // arrive to work
    arriveToWork();

    // show main menu

    while (player->getSanityPoints() > 0 && player->getPerformancePoints()) {
        showMainMenu();
    }


}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::morningRoutine() {
    menu.gameIntro(generateRandom(3), player);
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::arriveToWork() {
    menu.startWorkDay();
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::showMainMenu() {
    menu.hud(player, playerLocation(), calculateTime(time));
    menu.mainMenu(playerLocation());

    switch(menu.validateNumber(1,3)) {
        case 1:
            menu.displayMap(myCubicle);
            break;
        case 2:
            break;
        case 3:
            availableMoves( getSpaceAddress() );
            break;
        default:
            cout << "Unable to determine selection\n";
    }
}

/*********************************************************************
** Description:     this function plays the day and allows the game
**                  to continue until the player has lost all of their
**                  sanity points, performance points, or it is time
**                  to go home
*********************************************************************/
void Game::playDay() {
//    while () {
//
//    }
}

/*********************************************************************
** Description:     this function returns the name of the space the
**                  space the player is currently in
*********************************************************************/
string Game::playerLocation() {
    if (myCubicle->getPlayer() != nullptr) {
        return myCubicle->getLocationName();
    }
    else if (friendCubicle->getPlayer() != nullptr) {
        return friendCubicle->getLocationName();
    }
}

/*********************************************************************
** Description:     this function returns the pointer to the space
**                  a player currently resides in
*********************************************************************/
Space *Game::getSpaceAddress() {
    if (myCubicle->getPlayer() != nullptr) {
        return myCubicle;
    }
    else if (friendCubicle->getPlayer() != nullptr) {
        return friendCubicle;
    }
}

/*********************************************************************
** Description:     this function receives a space parameter to
**                  determine the spaces around it available to
**                  move to. A space is considered available if it is
**                  adjacent to the space.
*********************************************************************/
void Game::availableMoves(Space *space) {
    int count = 0;
    cout << "\nAvailable Locations To Move To:\n";
    if (space->getUp() != nullptr) {
        cout << ++count << ". " << space->getUp()->getLocationName() << endl;
    }
    if (space->getRight() != nullptr) {
        cout << ++count << ". " << space->getRight()->getLocationName() << endl;
    }
    if (space->getDown() != nullptr) {
        cout <<++count << ". " << space->getDown()->getLocationName() << endl;
    }
    if (space->getLeft() != nullptr) {
        cout << ++count << ". " << space->getLeft()->getLocationName() << endl;
    }
    cout << ++count << ". Back to main menu\n";
    cout << ">> ";
    int selection = menu.validateNumber(1, count);
    movePlayer(selection);
    cout << endl;
}

/*********************************************************************
** Description:     this function moves the player around from space
**                  to space
*********************************************************************/
void Game::movePlayer(int selection) {
    switch (selection) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout << "Unable to determine location to move player\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
int Game::generateRandom(int max) {
    int randomNum = 0;
    randomNum = rand() % max + 1;
    return randomNum;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::showPlayerStats() {
    cout << "Sanity points: " << player->getSanityPoints() << endl;
    cout << "Performance points: " << player->getPerformancePoints() << endl;
}

/*********************************************************************
** Description:     d
*********************************************************************/
string Game::calculateTime(int time) {
    switch (time) {
        case 1: return "9:00 AM";
        case 2: return "9:30 AM";
        case 3: return "10:00 AM";
        case 4: return "10:30 AM";
        case 5: return "11:00 AM";
        case 6: return "11:30 AM";
        case 7: return "12:00 PM";
        case 8: return "12:30 PM";
        case 9: return "1:00 PM";
        case 10: return "1:30 PM";
        case 11: return "2:00 PM";
        case 12: return "2:30 PM";
        case 13: return "3:00 PM";
        case 14: return "3:30 PM";
        case 15: return "4:00 PM";
        case 16: return "4:30 PM";
        case 17: return "5:00 PM";
        default:
            cout << "Unable to return time!\n";
    }
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
void Game::exitGame() {
    menu.exitGame();
}
