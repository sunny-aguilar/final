/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     MyCubicle class is derived from the space clasa
**                  and it represents the space that is the players
**                  own work area.
**                  derived from. Space class contains virtual
**                  functions. Each space has 4 space pointers are
**                  used to point to other spaces and allow a player
**                  to move about.
*********************************************************************/
#ifndef MYCUBICLE_HPP
#define MYCUBICLE_HPP

#include "space.hpp"

class MyCubicle : public Space {
private:

public:
    MyCubicle();
    ~MyCubicle();

};

#endif // MYCUBICLE_HPP
