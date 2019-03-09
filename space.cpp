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
** Description:     2-arg constructor
*********************************************************************/
Space::Space(string locName, Location loc) :
    location{loc},
    locationName{locName},
    up{nullptr},
    right{nullptr},
    down{nullptr},
    left{nullptr},
    player{nullptr} {}

/*********************************************************************
** Description:     2-arg constructor
*********************************************************************/
Space::Space(string locName, Location loc, Player *player) :
    location{loc},
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
** Description:     returns the pointer of the space going up
*********************************************************************/
Space *Space::getUp() {
    return up;
}

/*********************************************************************
** Description:     returns the pointer of the space on the right
*********************************************************************/
Space *Space::getRight() {
    return right;
}

/*********************************************************************
** Description:     returns the pointer of the space going down
*********************************************************************/
Space *Space::getDown() {
    return down;
}

/*********************************************************************
** Description:     returns the pointer of the space on the left
*********************************************************************/
Space *Space::getLeft() {
    return left;
}

/*********************************************************************
** Description:     returns the player pointer
*********************************************************************/
void Space::setPlayer(Player *&player) {
    this->player = player;
}

/*********************************************************************
** Description:     returns the player pointer
*********************************************************************/
Player *Space::getPlayer() {
    return player;
}

/*********************************************************************
** Description:     returns the enum location of the player
*********************************************************************/
Location Space::getLocation() {
    return location;
}

/*********************************************************************
** Description:     d
*********************************************************************/

