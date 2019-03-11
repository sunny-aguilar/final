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
** Description:     this functions determine which interactions a
**                  player will have with boss's office
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
** Description:
*********************************************************************/
void BossRoom::performanceReview() {
    // check if player has cell phone in inventory and punish player
    vector<string> vect = player->getInventory();
    for (int index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Cell Phone") {
            cout << ">> Your boss sees you holding your cell phone. Since he has a strict\n";
            cout << "   anti-cell phone policy, you have lost 3 performance points.\n";
            player->setPerformancePoints(-3);
        }
    }

    if (player->getPerformancePoints() < 7) {
        cout << ">> Your boss goes over your performance during your annual review. Since\n";
        cout << "   your performance is at a " << player->getPerformancePoints() << ", you\n";
        cout << "   are directed to get your act together or else face further repercussions\n";
        cout << ">> You have lost 3 sanity points\n";
        cout << ">> You have lost 1 performance point\n";
        player->setSanityPoints(-3);
        player->setPerformancePoints(-1);
    }
    else {
        
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void BossRoom::timeOff() {

}