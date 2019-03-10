/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Player class creates a player object for the
**                  user. A player object is used to hold certain
**                  game stats. The player object also holds an
**                  inventory object which contains inventory items.
*********************************************************************/
#include "player.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Player::Player() : sanity{10}, performance{10} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Player::~Player() {}

/*********************************************************************
** Description:     getter that returns player sanity points
*********************************************************************/
int Player::getSanityPoints() {
    return sanity;
}

/*********************************************************************
** Description:     setter that sets the player's sanity points. A
**                  player's sanity points cannot exceed 10.
*********************************************************************/
void Player::setSanityPoints(int points) {
    if (sanity + points > 10) { return; }
    sanity += points;
}

/*********************************************************************
** Description:     getter that returns player performance points
*********************************************************************/
int Player::getPerformancePoints() {
    return performance;
}

/*********************************************************************
** Description:     setter that sets the player's performance points.
**                  A player's performance points cannot exceed 10.
*********************************************************************/
void Player::setPerformancePoints(int points) {
    if (performance + points > 10) { return; }
    performance += points;
}

/*********************************************************************
** Description:     setter that adds inventory to player's pockets.
**                  The player's inventory cannot exceed 3 items.
*********************************************************************/
void Player::setInventory(string name) {
    // check if player is already carrying the max items allowed
    if (item.size() >= 3) {
        cout << "You can only carry 3 items at a time\n\n";
        return;
    }

    // check if player already has that item in their inventory
    for (int index = 0; index < item.size(); index++) {
        if (item[index] == "Cell Phone") {
            cout << "You already have the cell phone in your pocket\n\n";
            return;
        }
    }

    // add item to player's inventory
    item.push_back(name);
    cout << "You have placed the cell phone in your pocket\n";
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Player::getInventory() {
    int index = -1;
//    while (!item.empty()) {
//        index++;
//        return item.at(index) + " ";
//    }

    for (index = 0; index < item.size(); index++) {
        cout << item.at(index) + " ";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/

