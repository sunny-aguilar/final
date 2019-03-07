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
#include "player.hpp"
#include "space.hpp"
#include "myCubicle.hpp"
#include "friendCubicle.hpp"

class Game {
public:
    Game();
    ~Game();
    void start();
    void createBoard();

    // getters/setters
    double getTime();

    void gameOperations();
    void morningRoutine();
    void arriveToWork();
    void showMainMenu();
    void playDay();


    int generateRandom(int max);
    void showPlayerStats();
    void exitGame();

private:
    Menu menu;
    double time;
    Player *player;
    Space *myCubicle;
    Space *friendCubicle;
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
