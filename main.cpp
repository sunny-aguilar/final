/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     This final project implements a one-player
**                  text-based game where a player can move through
**                  spaces to get items and accomplish goals.
**                  s
**                  i
**                  s
**                  s
**                  a
**                  f
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