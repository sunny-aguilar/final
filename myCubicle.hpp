/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     MyCubicle class is derived from the space class
**                  and it represents the space that is the players
**                  own work area. This is the space where a player
**                  starts the game.
*********************************************************************/
#ifndef MYCUBICLE_HPP
#define MYCUBICLE_HPP

#include "space.hpp"

class MyCubicle : public Space {
private:
    int napsTaken;
public:
    MyCubicle(Player *&player);
    ~MyCubicle();
    void spaceInteractions() override;
    void takeCell();
    void takeNap();
    void doWork();
};

#endif // MYCUBICLE_HPP