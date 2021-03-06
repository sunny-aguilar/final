/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Player class creates a player object for the
**                  user. A player object is used to hold certain
**                  game stats. The player object also holds an
**                  inventory object which contains inventory items.
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Player {
private:
    int sanity;
    int performance;
    vector<string> item;

public:
    Player();
    ~Player();
    int getSanityPoints();
    void setSanityPoints(int points);
    int getPerformancePoints();
    void setPerformancePoints(int points);
    void setInventory(string item);
    void displayInventory();
    vector<string> getInventory();
    void deleteInventoryItem(int index, string eraseItem);
};

#endif // PLAYER_HPP
