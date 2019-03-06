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
Game::Game() : time{9.0} {}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Game::~Game() {}

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
void Game::gameOperations() {
    // create the baord
    createBoard();



}

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
void Game::exitGame() {
    menu.exitGame();
}
