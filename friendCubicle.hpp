/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     FriendCubicle class is derived from the space class
**                  and it represents the space that is the player's
**                  friend at work.
*********************************************************************/
#ifndef FRIENDCUBICLE_HPP
#define FRIENDCUBICLE_HPP

#include "space.hpp"

class FriendCubicle : public Space {
private:
    int pepTalks = 0;
    int projectHelps = 0;
public:
    FriendCubicle();
    ~FriendCubicle();
    void spaceInteractions() override;
    void pepTalk();
    void projectHelp();
};

#endif // FRIENDCUBICLE_HPP
