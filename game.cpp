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
Game::~Game() {
    if (myCubicle != nullptr) {
        if (myCubicle->getPlayer() != nullptr) {
            delete myCubicle->getPlayer();
        }
    }
    delete myCubicle;

    if (friendCubicle != nullptr) {
        if (friendCubicle->getPlayer() != nullptr) {
            delete friendCubicle->getPlayer();
        }
    }
    delete friendCubicle;

    if (bossRoom != nullptr) {
        if (bossRoom->getPlayer() != nullptr) {
            delete bossRoom->getPlayer();
        }
    }
    delete bossRoom;

    if (waterCooler != nullptr) {
        if (waterCooler->getPlayer() != nullptr) {
            delete waterCooler->getPlayer();
        }
    }
    delete waterCooler;

    if (meetingRoom != nullptr) {
        if (meetingRoom->getPlayer() != nullptr) {
            delete meetingRoom->getPlayer();
        }
    }
    delete meetingRoom;

    if (breakRoom != nullptr) {
        if (breakRoom->getPlayer() != nullptr) {
            delete breakRoom->getPlayer();
        }
    }
    delete breakRoom;
}

/*********************************************************************
** Description:     this function creates the spaces and links
**                  the pointers to each other
*********************************************************************/
void Game::createBoard() {
    // create spaces
    myCubicle = new MyCubicle( player );
    friendCubicle = new FriendCubicle();
    bossRoom = new BossRoom();
    waterCooler = new WaterCooler();
    meetingRoom = new MeetingRoom();
    breakRoom = new BreakRoom();

    // link spaces to each other
    myCubicle->setUp(friendCubicle);    // link myCubicle
    myCubicle->setRight(waterCooler);
    friendCubicle->setDown(myCubicle);  // link friendCubicle
    friendCubicle->setRight(bossRoom);
    bossRoom->setLeft(friendCubicle);   // link bossRoom
    bossRoom->setRight(meetingRoom);
    bossRoom->setDown(waterCooler);
    waterCooler->setLeft(myCubicle);    // link waterCooler
    waterCooler->setUp(bossRoom);
    waterCooler->setRight(breakRoom);
    meetingRoom->setLeft(bossRoom);     // link meetingRoom
    meetingRoom->setDown(breakRoom);
    breakRoom->setLeft(waterCooler);    // link breakRoom
    breakRoom->setUp(meetingRoom);
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
** Description:     this function controls the game operations from
**                  start to finish
*********************************************************************/
void Game::gameOperations() {
    // create the board
    createBoard();

    // game intro
    morningRoutine();

    // arrive to work
    arriveToWork();

    // start day steps
    playDay();

    // end of day results
    endDay();
}

/*********************************************************************
** Description:     this function calls a menu prompt that is
**                  randomly picked and it will determine how your
**                  day will start
*********************************************************************/
void Game::morningRoutine() {
    menu.gameIntro(generateRandom(3), player);
}

/*********************************************************************
** Description:     this function displays a menu prompt to alert a
**                  user they have arrived to work
*********************************************************************/
void Game::arriveToWork() {
    menu.startWorkDay();
}

/*********************************************************************
** Description:     this function plays the day and allows the game
**                  to continue until the player has lost all of their
**                  sanity points, performance points, or it is time
**                  to go home
*********************************************************************/
void Game::playDay() {
    while (loopControl()) {
        // lose sanity points as day wears on
        loseSanity();

        // show main menu
        showMainMenu();
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::showMainMenu() {
    menu.hud(player, playerLocation(), calculateTime(time));
    menu.mainMenu(playerLocation());

    switch(menu.validateNumber(1,3)) {
        case 1:
            menu.displayMap(getSpaceAddress());
            break;
        case 2:
            roomActivities();
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
** Description:     this function returns true or false and is used
**                  to control the steps in the game and whether the
**                  game ends once a condition is met.
**                  Conditions that stop the day:
**                      - player loses sanity
**                      - player gets fired
**                      - player quits job
**                      - 5:00 PM end of day, player wins
*********************************************************************/
bool Game::loopControl() {
    bool insane = false;
    bool fired = false;
    bool shiftOver = false;

    // quit game if any of these conditions become true
    if (player->getSanityPoints() < 1) {
        insane = true;
    }
    if (player->getPerformancePoints() < 1) {
        fired = true;
    }
    if (calculateTime(time) == "5:00 PM") {
        shiftOver = true;
    }

    return ( !insane > 0 &&
             !fired &&
             !shiftOver );
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
    else if (waterCooler->getPlayer() != nullptr) {
        return waterCooler->getLocationName();
    }
    else if (meetingRoom->getPlayer() != nullptr) {
        return meetingRoom->getLocationName();
    }
    else if (breakRoom->getPlayer() != nullptr) {
        return breakRoom->getLocationName();
    }
    return "unknown room";
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
    else if (bossRoom->getPlayer() != nullptr) {
        return bossRoom;
    }
    else if (waterCooler->getPlayer() != nullptr) {
        return waterCooler;
    }
    else if (meetingRoom->getPlayer() != nullptr) {
        return meetingRoom;
    }
    else if (breakRoom->getPlayer() != nullptr) {
        return breakRoom;
    }
    return 0;
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
    int selection = menu.validateNumber(0, movesAvailable);
    int location = places.at(selection - 1);

    switch (location) {
        case MYCUBICLE:
            // move player to my cubicle
            movePlayer(myCubicle);
            break;
        case FRIENDCUBICLE:
            // move player to friend's cubicle
            movePlayer(friendCubicle);
            break;
        case BOSSROOM:
            movePlayer(bossRoom);
            break;
        case COOLER:
            movePlayer(waterCooler);
            break;
        case BREAKROOM:
            movePlayer(breakRoom);
            break;
        case MEETINGROOM:
            movePlayer(meetingRoom);
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

    // increase time for each step taken
    time++;
}

/*********************************************************************
** Description:     the player loses 1 sanity point for every hour
**                  elapsed
*********************************************************************/
void Game::loseSanity() {

    if (time % 3 == 1) {
        cout << ">> Another hour has passed, lose 1 sanity point\n\n";
        player->setSanityPoints(-1);
    }
}

/*********************************************************************
** Description:     this functions calls the virtual function in the
**                  space class that allows a player to interact with
**                  different rooms. Activities that a player can
**                  carry out depend on the room they are in.
*********************************************************************/
void Game::roomActivities() {
    menu.displayRoomActivities(playerLocation());
    getSpaceAddress()->spaceInteractions();
}

/*********************************************************************
** Description:     display end of day message
*********************************************************************/
void Game::endDay() {
    bool wentInsane = false;
    bool gotFired = false;
    bool dayOver = false;

    // determine how game ended
    if (player->getSanityPoints() < 1) {
        wentInsane = true;
    }
    if (player->getPerformancePoints() < 1) {
        gotFired = true;
    }
    if (calculateTime(time) ==  "5:00 PM") {
        dayOver = true;
    }

    // display end of game message depending on how it ended
    if (wentInsane) {
        menu.endOfDay(0);
    }
    else if (gotFired) {
        menu.endOfDay(1);
    }
    else if (dayOver) {
        menu.endOfDay(2);
    }
}

/*********************************************************************
** Description:     takes an integer that it will use to generate a
**                  random number from 1 to max
*********************************************************************/
int Game::generateRandom(int max) {
    int randomNum = 0;
    randomNum = rand() % max + 1;
    return randomNum;
}

/*********************************************************************
** Description:     this function takes an int parameter to calculate
**                  the time elapsed. Each step a player makes into a
**                  different space, time passes by half an hour.
*********************************************************************/
string Game::calculateTime(int time) {
    if (time > 17) {
        return "OVERTIME";
    }

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
    return "00:00 AM";
}

/*********************************************************************
** Description:     this function displays exit message upon exiting
**                  program
*********************************************************************/
void Game::exitGame() {
    menu.exitGame();
}