/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     FriendCubicle class is derived from the space clasa
**                  and it represents the space that is the player's
**                  friend at work.
*********************************************************************/
#include "friendCubicle.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
FriendCubicle::FriendCubicle() : Space("Friend's Cubicle", FRIENDCUBICLE) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
FriendCubicle::~FriendCubicle() {}

/*********************************************************************
** Description:     d
*********************************************************************/
void FriendCubicle::spaceInteractions() {
    if (player) {
        cout << "player is currently in Friend's Cubicle\n";
    }
    cout << "1. Put cell phone in your pocket\n";
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

