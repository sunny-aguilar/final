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
#include <vector>
using std::vector;


class Game {
public:
    Game();
    ~Game();
    void start();
    void createBoard();

    // getters/setters
    string calculateTime(int time);

    void gameOperations();
    void morningRoutine();
    void arriveToWork();
    void showMainMenu();
    void playDay();
    string playerLocation();
    Space *getSpaceAddress();
    void availableMoves(Space *space);
    void selectSpaceToMovePlayer();
    void movePlayer();

    // utilities
    int generateRandom(int max);
    void showPlayerStats();

    void exitGame();

private:
    Menu menu;
    int time;
    int movesAvailable;
    vector <Location> places;
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
