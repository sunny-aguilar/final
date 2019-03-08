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
Game::Game() : time{1}, movesAvailable{0}, player{new Player()} {}

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
        showMainMenu(); // TODO - need to change this so that it displays location of any player
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
            menu.displayMap(myCubicle); // TODO - myCubicle should be any space
            break;
        case 2:
            break;
        case 3:
            availableMoves( getSpaceAddress() );
            selectSpaceToMovePlayer();
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
        places.push_back( space->getUp()->getLocation() );
    }
    if (space->getRight() != nullptr) {
        cout << ++count << ". " << space->getRight()->getLocationName() << endl;
        places.push_back( space->getRight()->getLocation() );
    }
    if (space->getDown() != nullptr) {
        cout <<++count << ". " << space->getDown()->getLocationName() << endl;
        places.push_back( space->getDown()->getLocation() );
    }
    if (space->getLeft() != nullptr) {
        cout << ++count << ". " << space->getLeft()->getLocationName() << endl;
        places.push_back( space->getLeft()->getLocation() );
    }
    cout << ++count << ". Back to main menu\n";
    cout << ">> ";
    movesAvailable = count;

    cout << endl;
}

/*********************************************************************
** Description:     this function moves the player around from space
**                  to space
*********************************************************************/
void Game::selectSpaceToMovePlayer() {
    int selection = menu.validateNumber(1, movesAvailable);

    cout << "Size: " << places.size() << endl;
    cout << places.front() << endl;

    switch (selection) {
        case 0:
            // move player to my cubicle
            movePlayer(myCubicle);
            break;
        case 1:
            // move player to friend's cubicle
            movePlayer(friendCubicle);
            break;
        case 2:
            //movePlayer();
            break;
        case 3:
            //movePlayer();
            break;
        case 4:
            //movePlayer();
            break;
        case 5:
            //movePlayer();
            break;
        default:
            cout << "Unable to determine location to move player\n";
    }
}

/*********************************************************************
** Description:     this function receives the space a space
 *                  parameter for which the player will move to
*********************************************************************/
void Game::movePlayer(Space *space) {
    cout << "Player address: " << space->getPlayer() << endl;
//    if (space->getPlayer() == nullptr) {
        Player *tempPlayer = getSpaceAddress()->getPlayer();
        space->setPlayer( tempPlayer );
//    }
//    else {
//        cout << "Space is already occupied!\n";
//    }

cout << "Address of player in friend's cubicle " << tempPlayer << endl << endl;
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
