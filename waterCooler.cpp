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
WaterCooler::WaterCooler() : chats{0}, Space("Water Cooler", COOLER) {}

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
    int maxChats = 2;

    if (chats >= maxChats) {
        cout << ">> Sorry, you only have two breaks available each day\n\n";
        cout << "   ( ; _ ; )\n\n";
        return;
    }

    cout << ">> You have caught up on the latest office rumors and are disgusted\n";
    cout << "   yet seemingly satisfied\n";
    cout << "   You have gained 1 sanity point\n\n";
    player->setSanityPoints(1);
    chats++;
}

/*********************************************************************
** Description:     this function allows you to keep chatting with
**                  other co-workers about sports, etc. however too
**                  much chatting will affect your performance and
**                  sanity points.
*********************************************************************/
void WaterCooler::moreChat() {
    cout << ">> You continue to chat with co-workers however your boss\n";
    cout << "   has been keeping track of time and writes you up for\n";
    cout << "   exceeding your break time!\n";
    cout << "   You have lost 3 performance points\n";
    cout << "   You have lost 3 sanity points\n";
    cout << "  ヽ(。_°)ノ\n\n";
    player->setPerformancePoints(-3);
    player->setSanityPoints(-3);
}