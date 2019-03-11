/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     MeetingRoom class is derived from the space class
**                  and it represents the space that is a break room
**                  in the office.
*********************************************************************/
#ifndef BREAKROOM_HPP
#define BREAKROOM_HPP

#include "space.hpp"

class BreakRoom : public Space {
private:
public:
    BreakRoom();
    ~BreakRoom();
    void spaceInteractions() override;
    void getDoghnuts();
    void eatLeftovers();
};

#endif // BREAKROOM_HPP