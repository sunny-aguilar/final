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
BossRoom::BossRoom() : Space("Boss's Office", BOSSROOM) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
BossRoom::~BossRoom() {}

/*********************************************************************
** Description:     d
*********************************************************************/
void BossRoom::spaceInteractions() {
    cout << "1. Performance Review\n";
    cout << "2. Ask For Time Off\n";
    cout << ">> ";
    int selection = validateNumber(1,2);

    switch (selection) {
        case 1:
            performanceReview();
            break;
        case 2:
            timeOff();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void BossRoom::performanceReview() {

}

/*********************************************************************
** Description:     d
*********************************************************************/
void BossRoom::timeOff() {

}