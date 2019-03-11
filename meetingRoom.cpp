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
**                  player will have with the meeting room
*********************************************************************/
void MeetingRoom::spaceInteractions() {
    cout << "1. Attend your group meeting\n";
    cout << "2. Play on your cell phone\n";
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
** Description:     if a player has doughnuts in their inventory, then
**                  they are not penalized for attending a brutal
**                  meeting. Otherwise, a player loses sanity and
**                  performance points.
*********************************************************************/
void MeetingRoom::bringDoghnuts() {
    vector<string> vect = player->getInventory();

    for (unsigned index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Doughnut") {
            vect.at(index) = "";
            player->deleteInventoryItem(index, "");
            cout << endl;

            // display message
            cout << ">> Good thing you had doughnuts with you otherwise these long\n";
            cout << "   and unproductive meeting would have been a nightmare!\n";
            cout << ">> Gain 1 sanity point +1\n\n";
            player->setSanityPoints(1);
            return;
        }
    }
    cout << ">> Unfortunately you came to the meeting empty handed and now you\n";
    cout << "   have to endure a long and unproductive meeting.\n";
    cout << ">> Lose -2 sanity points\n";
    cout << ">> Lose -2 productivity points\n\n";
    player->setSanityPoints(-2);
    player->setPerformancePoints(-2);
}

/*********************************************************************
** Description:     if a player is carrying their cell phone in their
**                  inventory, then the player can pass time at the
**                  meeting. Otherwise the player will have a long
**                  unproductive meeting and be penalized by losing
**                  sanity and performance points.
*********************************************************************/
void MeetingRoom::useCellPhone() {
    vector<string> vect = player->getInventory();

    for (unsigned index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Cell Phone") {
            vect.at(index) = "";
            player->deleteInventoryItem(index, "");
            cout << endl;

            // display message
            cout << ">> Good thing you brought your cell phone with you because\n";
            cout << "   now you can pass time checking out the latest Instagram posts.\n";
            cout << ">> Gain 1 sanity point +1\n\n";
            player->setSanityPoints(1);
            return;
        }
    }
    cout << ">> Unfortunately you came to the meeting and forgot your cellphone at your desk\n";
    cout << "   and now you have to endure a long and unproductive meeting.\n";
    cout << ">> Lose -3 sanity points\n";
    cout << ">> Lose -2 productivity points\n\n";
    player->setSanityPoints(-3);
    player->setPerformancePoints(-2);
}