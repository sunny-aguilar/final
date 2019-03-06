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
Game::Game() : time{9.0}, player{new Player()} {}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Game::~Game() {}

/*********************************************************************
** Description:     this function creates the spaces and links
**                  the pointers to each other
*********************************************************************/
void Game::createBoard() {
    myCubicle = new MyCubicle();



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
double Game::getTime() {
    return time;
}

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
    showMainMenu();


}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::morningRoutine() {
    menu.gameIntro();

    switch (generateRandom(3)) {
        case 1:
            menu.carArt();
            cout << "You decide to make yourself a cup of coffee however you spill\n";
            cout << "it all over your shirt as you get into your car ( -1 sanity points)\n\n";
            break;
        case 2:
            menu.carArt();
            cout << "Although you got up for work early with plenty of time to spare,\n";
            cout << "unforeseen traffic conditions have made you 15 minutes late for work\n";
            cout << "( -1 performance points, -1 sanity points)\n\n";
            break;
        case 3:
            menu.carArt();
            cout << "You get into your car and luckily make it to work on time\n\n";
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
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
    menu.hud(player, myCubicle, time);
    menu.mainMenu();
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
    cout << "Performance points: " << player->getPerfomancePoints() << endl;
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
void Game::exitGame() {
    menu.exitGame();
}
