/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     FriendCubicle class is derived from the space clasa
**                  and it represents the space that is the player's
**                  friend at work.
*********************************************************************/
#include "friendCubicle.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
FriendCubicle::FriendCubicle() : Space("Friend's Cubicle", FRIENDCUBICLE) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
FriendCubicle::~FriendCubicle() {}

/*********************************************************************
** Description:     d
*********************************************************************/
void FriendCubicle::spaceInteractions() {
    cout << "1. Have a pep talk with your friend\n";
    cout << "2. Have your friend help you with a project\n";
    cout << ">> ";
    int selection = validateNumber(1,2);

    switch (selection) {
        case 1:
            pepTalk();
            break;
        case 2:
            projectHelp();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void FriendCubicle::pepTalk() {
    cout << "You had a great pep talk with you friend. Your sanity\n";
    cout << "points have increased by +1\n";
    player->setSanityPoints(1);
}

/*********************************************************************
** Description:     d
*********************************************************************/
void FriendCubicle::projectHelp() {
    cout << "Your friend graciously helped you with your project. Your\n";
    cout << "performance points have increased by +1\n";
    player->setPerformancePoints(1);
}

/*********************************************************************
** Description:     d
*********************************************************************/

