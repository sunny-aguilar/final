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

#include "inventoryItem.hpp"
#include <vector>
using std::vector;

class Player {
private:
    int sanity;
    int performance;
    vector<InventoryItem> inventory;

public:
    Player();
    ~Player();
    int getSanityPoints();
    void setSanityPoints(int points);
    int getPerformancePoints();
    void setPerformancePoints(int points);
};

#endif // PLAYER_HPP
