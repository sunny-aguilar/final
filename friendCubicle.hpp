/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     FriendCubicle class is derived from the space clasa
**                  and it represents the space that is the player's
**                  friend at work.
*********************************************************************/
#ifndef FRIENDCUBICLE_HPP
#define FRIENDCUBICLE_HPP

#include "space.hpp"

class FriendCubicle : public Space {
private:

public:
    FriendCubicle();
    ~FriendCubicle();
    void setPlayer(Player *player);
};

#endif // FRIENDCUBICLE_HPP
