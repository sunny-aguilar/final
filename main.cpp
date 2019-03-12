/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     This final project implements a one-player
**                  text-based game where a player can move through
**                  spaces to get items and accomplish goals. The
**                  theme of this game resembles the movie "Office
**                  Space" where a player is just trying to survive
**                  the day to day drudgery of office life. The
**                  objective of the game is to survive a full work day
**                  with your sanity intact or without getting fired.
*********************************************************************/
#include "game.hpp"
#include <iostream>
#include <ctime>

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);        // create random number generator
    Game game;
    game.start();
    return 0;
}