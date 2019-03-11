/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Game class
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/
#include "myCubicle.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
MyCubicle::MyCubicle(Player *&player) :
    napsTaken{0},
    Space("My Cubicle", MYCUBICLE, player) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
MyCubicle::~MyCubicle() {}

/*********************************************************************
** Description:     this functions determine which interactions a
**                  player will have with the space
*********************************************************************/
void MyCubicle::spaceInteractions() {
    cout << "1. Put cell phone in your pocket\n";
    cout << "2. Take a 15 minute siesta\n";
    cout << "3. Complete an overdue report\n";
    cout << ">> ";

    int selection = validateNumber(1,2);
    switch (selection) {
        case 1:
            takeCell();
            break;
        case 2:
            takeNap();
            break;
        case 3:
            doWork();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     adds cell phone to inventory
*********************************************************************/
void MyCubicle::takeCell() {
    vector<string> vect = player->getInventory();

    for (int index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Cell Phone") {
            cout << "Player already has the Cell Phone in their inventory!\n\n";
            return;
        }
    }

    // random chance (30%) that you get caught fidgeting with your phone
    if ( generateRandom(10) < 4 ) {
        cout << "Your boss has caught you looking at your phone and calls you\n";
        cout << "into his office where he writes you up.\n\n";
        player->setPerformancePoints(-2);
    }

    player->setInventory("Cell Phone");
}

/*********************************************************************
** Description:     allows a player to recover sanity points
*********************************************************************/
void MyCubicle::takeNap() {
    int napsMax = 1;

    if (napsTaken >= napsMax) {
        cout << ">> Sorry, your demanding schedule does not allow you\n";
        cout << "   to sneak in any more naps ( 0 _ 0 )\n\n";
        return;
    }

    cout << ">> You take a quick nap at your desk and luckily your boss did\n";
    cout << "   not notice. Sanity points have increased by +1\n\n";

    // random chance (30%) that you get caught napping
    if ( generateRandom(10) < 4 ) {
        cout << "Your boss has caught you taking a nap! He calls you into his\n";
        cout << "office where he writes you up.\n\n";
        player->setPerformancePoints(-3);
    }

    player->setSanityPoints(1);
    napsTaken++;
}

/*********************************************************************
** Description:     allows a player to complete overdue work
*********************************************************************/
void MyCubicle::doWork() {
    switch (generateRandom(3)) {
        case 1:

            break;
        case 2:

            break;
        case 3:
            
            break;
        default:
            cout << "Unable to determine work results\n\n";
    }
}
