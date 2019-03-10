/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     MeetingRoom class is derived from the space class
**                  and it represents the space that is a meeting
**                  room in the office.
*********************************************************************/
#include "meetingRoom.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
MeetingRoom::MeetingRoom() : Space("Meeting Room", MEETINGROOM) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
MeetingRoom::~MeetingRoom() {}

/*********************************************************************
** Description:     this functions determine which interactions a
**                  player will have with the space
*********************************************************************/
void MeetingRoom::spaceInteractions() {

}