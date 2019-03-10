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
    cout << "1. Pick up some doughnuts\n";
    cout << "2. Eat your leftovers from yesterday\n";
    cout << ">> ";
    int selection = validateNumber(1,2);

    switch (selection) {
        case 1:
            bringDoghnuts();
            break;
        case 2:
            useCellPhone();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void MeetingRoom::bringDoghnuts() {

}

/*********************************************************************
** Description:     d
*********************************************************************/
void MeetingRoom::useCellPhone() {

}