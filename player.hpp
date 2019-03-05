/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Player class creates a player object for the
**                  user. A player object is used to hold certain
**                  game stats. The player object also holds an
**                  inventory object which contains inventory items.
**                  d
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
private:
    int sanity;
    int performance;

public:
    Player();
    ~Player();
};

#endif // PLAYER_HPP
