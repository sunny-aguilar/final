/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Game class controls all of the game operations
**                  required to control the game.
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "space.hpp"
#include "myCubicle.hpp"

class Game {
public:
    Game();
    ~Game();
    void start();
    void createBoard();
    void gameOperations();
    void morningRoutine();
    int generateRandom();
    void exitGame();

private:
    Menu menu;
    double time;
    Space *myCubicle;
    Space *BM;
    Space *BR;
    Space *ML;
    Space *MM;
    Space *MR;
    Space *TL;
    Space *TM;
    Space *TR;

};

#endif // GAME_HPP
