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
#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "space.hpp"

class Game {
public:
    Game();
    ~Game();
    void start();

private:
    Menu menu;
    Space space;

};

#endif // GAME_HPP
