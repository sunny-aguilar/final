/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Space class provides a player spaces for
**                  which they can move through. The space class is
**                  an abstract class from which other classes are
**                  derived from. Space class contains virtual
**                  functions. Each space has 4 space pointers are
**                  used to point to other spaces and allow a player
**                  to move about.
*********************************************************************/
#include "space.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Space::Space() :
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr} {}

/*********************************************************************
** Description:     1-arg constructor
*********************************************************************/
Space::Space(string locName, Location loc) :
    locationName{locName},
    location{loc},
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr} {}

/*********************************************************************
** Description:     2-arg constructor
*********************************************************************/
Space::Space(string locName, Player *player) :
    locationName{locName},
    player{player},
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr} {}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Space::~Space() {}

/*********************************************************************
** Description:     d
*********************************************************************/
string Space::getLocationName() {
    return locationName;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Space::setUp(Space *up) {
    this->up = up;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Space::setRight(Space *right) {
    this->right = right;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Space::setDown(Space *down) {
    this->down = down;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Space::setLeft(Space *left) {
    this->left = left;
}

/*********************************************************************
** Description:     d
*********************************************************************/
Space *Space::getUp() {
    return up;
}

/*********************************************************************
** Description:     d
*********************************************************************/
Space *Space::getRight() {
    return right;
}

/*********************************************************************
** Description:     d
*********************************************************************/
Space *Space::getDown() {
    return down;
}

/*********************************************************************
** Description:     d
*********************************************************************/
Space *Space::getLeft() {
    return left;
}

/*********************************************************************
** Description:     returns the player pointer
*********************************************************************/
Player *Space::getPlayer() {
    return player;
}

/*********************************************************************
** Description:     sets the player pointer
*********************************************************************/
void Space::getPlayer(Player *player) {
    this->player = player;
}

/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/

