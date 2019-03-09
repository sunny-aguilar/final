/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     BossRoom class is derived from the space class
**                  and it represents the space that is the player's
**                  boss office at work.
*********************************************************************/
#include "bossRoom.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
BossRoom::BossRoom() : Space("Boss's Office", BOSSROOM)
{
    // TODO - delete cout
    cout << "BossRoom default constructor triggered\n";
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
BossRoom::~BossRoom() {}

