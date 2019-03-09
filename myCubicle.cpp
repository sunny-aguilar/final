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
MyCubicle::MyCubicle(Player *&player) : Space("My Cubicle", MYCUBICLE, player) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
MyCubicle::~MyCubicle() {}

/*********************************************************************
** Description:     d
*********************************************************************/
void MyCubicle::spaceInteractions() {
    cout << "1. Put cell phone in your pocket\n";
    cout << "2. Take a 15 minute siesta\n";
    cout << ">> ";

    int selection = validateNumber(1,2);
    switch (selection) {
        case 1:
            takeCell();
            break;
        case 2:
            takeNap();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     adds cell phone to inventory
*********************************************************************/
void MyCubicle::takeCell() {

}

/*********************************************************************
** Description:     allows a player to recover sanity points
*********************************************************************/
void MyCubicle::takeNap() {

}