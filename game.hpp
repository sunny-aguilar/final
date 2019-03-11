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
#include "bossRoom.hpp"
#include "waterCooler.hpp"
#include "meetingRoom.hpp"
#include "breakRoom.hpp"
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
    bool loopControl();
    string playerLocation();
    Space *getSpaceAddress();
    void availableMoves(Space *space);
    void selectSpaceToMovePlayer();
    void movePlayer(Space *space);
    void roomActivities();
    void endDay();

    // utilities
    int generateRandom(int max);

    void exitGame();

private:
    Menu menu;
    int time;
    int movesAvailable;
    vector <Location> places;
    Player *player;             // player object
    Space *myCubicle;           // space 1
    Space *friendCubicle;       // space 2
    Space *bossRoom;            // space 3
    Space *waterCooler;         // space 4
    Space *meetingRoom;         // space 5
    Space *breakRoom;           // space 5

};

#endif // GAME_HPP
