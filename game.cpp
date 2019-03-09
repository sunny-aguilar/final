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
    bossRoom = new BossRoom();
    // TODO - remove this cout after debugged
    cout << "myCubicle address " << myCubicle << endl;
    cout << "Player address " << player << endl;
    cout << "Friend Cubicle address " << friendCubicle << endl;
    cout << "Friend player address " << friendCubicle->getPlayer() << endl;
    cout << "bossRoom address " << bossRoom << endl;
    cout << "bossRoom player address " << bossRoom->getPlayer() << endl << endl;

    // link spaces to each other
    myCubicle->setUp(friendCubicle);
    friendCubicle->setDown(myCubicle);
    friendCubicle->setRight(bossRoom);
    bossRoom->setLeft(friendCubicle);




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
            menu.displayMap(getSpaceAddress()); // TODO - myCubicle should be any space
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
    else if (bossRoom->getPlayer() != nullptr) {
        return bossRoom->getLocationName();
    }
}

/*********************************************************************
** Description:     this function returns the pointer to the space
**                  a player currently resides in. The function
**                  automatically detects where in the board a player
**                  is by seeing if the player pointer in the space
**                  class is not null
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
        cout << "pushed back in vector getup(): " << space->getUp()->getLocation() << endl;
        places.push_back( space->getUp()->getLocation() );
    }
    if (space->getRight() != nullptr) {
        cout << ++count << ". " << space->getRight()->getLocationName() << endl;
        cout << "pushed back in vector getRight(): " << space->getRight()->getLocation() << endl;
        places.push_back( space->getRight()->getLocation() );
    }
    if (space->getDown() != nullptr) {
        cout <<++count << ". " << space->getDown()->getLocationName() << endl;
        cout << "pushed back in vector getDown(): " << space->getDown()->getLocation() << endl;
        places.push_back( space->getDown()->getLocation() );
    }
    if (space->getLeft() != nullptr) {
        cout << ++count << ". " << space->getLeft()->getLocationName() << endl;
        cout << "pushed back in vector getLeft(): " << space->getLeft()->getLocation() << endl;
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
    int selection = menu.validateNumber(0, movesAvailable);
    cout << "selection: " << selection << endl;
    int location = places.at(selection - 1);
    cout << "Location selected: " << location << endl;
    cout << "Size: " << places.size() << endl;
    cout << "Vector @ 0: " << places.front() << endl;
    cout << "Vector @ 0: " << places[0] << endl;

    switch (location) {
        case MYCUBICLE:
            // move player to my cubicle
            cout << "Move to my cubicle\n";
            movePlayer(myCubicle);
            break;
        case FRIENDCUBICLE:
            // move player to friend's cubicle
            cout << "Move to friend's cubicle\n";
            movePlayer(friendCubicle);
            break;
        case BOSSROOM:
            cout << "Move to boss's office\n";
            movePlayer(bossRoom);
            break;
        case COOLER:
            //movePlayer();
            break;
        case BREAKROOM:
            //movePlayer();
            break;
        case MEETINGROOM:
            //movePlayer();
            break;
        default:
            cout << "Unable to determine location to move player\n";
    }

    // clear vector holding available move locations
    places.clear();
}

/*********************************************************************
** Description:     this function receives a space parameter for which
**                  for which the player will move to
*********************************************************************/
void Game::movePlayer(Space *space) {
    if (space->getPlayer() == nullptr) {
        // transfer player object to new space
        Space *tempPlayer1 = getSpaceAddress();                 // get current space
        Player *tempPlayer = getSpaceAddress()->getPlayer();    // get current player object
        space->setPlayer( tempPlayer );                         // set player object to new space

        // set player object in prior space to null
        Player *nullPlayer = nullptr;
        tempPlayer1->setPlayer(nullPlayer);
    }
    else {
        cout << "Space is already occupied!\n";
    }


    // TODO - increase time by half hour
    time++;
//    switch () {
//        case MYCUBICLE:
//            // move player to my cubicle
//
//            break;
//        case FRIENDCUBICLE:
//            // move player to friend's cubicle
//
//            break;
//        case BOSSROOM:
//            //movePlayer();
//            break;
//        case COOLER:
//            //movePlayer();
//            break;
//        case BREAKROOM:
//            //movePlayer();
//            break;
//        case MEETINGROOM:
//            //movePlayer();
//            break;
//        default:
//            cout << "Unable to determine location to move player\n";
//    }


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
