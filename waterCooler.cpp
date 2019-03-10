/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     WaterCooler class is derived from the space class
**                  and it represents the space that is by the water
**                  cooler in the office.
*********************************************************************/
#include "waterCooler.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
WaterCooler::WaterCooler() : Space("Water Cooler", COOLER) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
WaterCooler::~WaterCooler() {}

/*********************************************************************
** Description:     this functions determine which interactions a
**                  player will have with the space
*********************************************************************/
void WaterCooler::spaceInteractions() {
    cout << "1. Spend 5 minutes getting updated on the latest office gossip\n";
    cout << "2. Spend another 5 minutes talking about the latest sports game\n";
    cout << ">> ";
    int selection = validateNumber(1,2);
    switch (selection) {
        case 1:
            officeChat();
            break;
        case 2:
            moreChat();
            break;
        default:
            cout << "Unable to determine selection!\n";
    }
}

/*********************************************************************
** Description:     this function allows you to chat with employees
**                  to gain sanity points at the cost of performance
**                  points
*********************************************************************/
void WaterCooler::officeChat() {

}

/*********************************************************************
** Description:     this function allows you to keep chatting with
**                  other co-workers about sports, etc.
*********************************************************************/
void WaterCooler::moreChat() {

}