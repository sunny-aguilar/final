/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     BossRoom class is derived from the space class
**                  and it represents the space that is the player's
**                  boss office at work.
*********************************************************************/
#ifndef BOSSROOM_HPP
#define BOSSROOM_HPP

#include "space.hpp"

class BossRoom : public Space {
private:
public:
    BossRoom();
    ~BossRoom();
};

#endif // BOSSROOM_HPP
