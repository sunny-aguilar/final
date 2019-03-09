/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     MeetingRoom class is derived from the space class
**                  and it represents the space that is a break room
**                  in the office.
*********************************************************************/
#include "breakRoom.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
BreakRoom::BreakRoom() : Space("Break Room", BREAKROOM)
{
    // TODO - delete
    cout << "BreakRoom default constructor triggered\n";
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
BreakRoom::~BreakRoom() {}