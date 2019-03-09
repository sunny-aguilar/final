/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     MeetingRoom class is derived from the space class
**                  and it represents the space that is a meeting
**                  room in the office.
*********************************************************************/
#ifndef MEETINGROOM_HPP
#define MEETINGROOM_HPP

#include "space.hpp"

class MeetingRoom : public Space {
private:
public:
    MeetingRoom();
    ~MeetingRoom();
    void spaceInteractions() override;
};

#endif // MEETINGROOM_HPP
