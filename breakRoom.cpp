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
BreakRoom::BreakRoom() : Space("Break Room", BREAKROOM) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
BreakRoom::~BreakRoom() {}

/*********************************************************************
** Description:     d
*********************************************************************/
void BreakRoom::spaceInteractions() {
    cout << "1. Pick up some doughnuts\n";
    cout << "2. Eat your leftovers from yesterday\n";
    cout << ">> ";
    int selection = validateNumber(1,2);

    switch (selection) {
        case 1:
            getDoghnuts();
            break;
        case 2:
            eatLeftovers();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     allows a player to pick up a doughnut and add it
**                  to their inventory for later use
*********************************************************************/
void BreakRoom::getDoghnuts() {
    vector<string> vect = player->getInventory();

    for (int index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Doughnut") {
            cout << "Player already has Doughnuts in their inventory!\n\n";
            return;
        }
    }

    player->setInventory("Doughnut");
}

/*********************************************************************
** Description:     this function makes a player eat their prior day
**                  leftovers for lunch
*********************************************************************/
void BreakRoom::eatLeftovers() {

}