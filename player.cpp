/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Player class creates a player object for the
**                  user. A player object is used to hold certain
**                  game stats. The player object also holds an
**                  inventory object which contains inventory items.
**                  d
*********************************************************************/
#include "player.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Player::Player() : sanity{10}, performance{10} {}

/*********************************************************************
** Description:     d
*********************************************************************/
Player::~Player() {}

/*********************************************************************
** Description:     d
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
** Description:     d
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
** Description:     setter that adds inventory to player's pockets
*********************************************************************/
void Player::setInventory(string name, int type) {
    inventory.push_back( //add inventory object here );
}

/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/

