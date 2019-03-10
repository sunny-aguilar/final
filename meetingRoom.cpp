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
    cout << "1. Attend your group meeting\n";
    cout << "2. Add something here\n";
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
    vector<string> vect = player->getInventory();

    for (int index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Doughnut") {
            // remove doughnuts from inventory
            //player->getInventory().at(index) = "";
            vect.at(index) = "";
            player->getInventory() = vect;

            for (int index = 0; index < vect.size(); index++) {
                cout << "Inventory: " << vect.at(index) << " ";
            }
            cout << endl;

            // display message
            cout << ">> Your group meetings are generally long and could have been\n";
            cout << "   stated in an email. Luckily, you have doughnuts and saved the\n";
            cout << "   day!\n";
            cout << ">> Gain 1 sanity point +1\n\n";
            player->setSanityPoints(1);
            return;
        }
        else {
            cout << "Sorry, you do not have Doughnuts in your inventory\n\n";
        }
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void MeetingRoom::useCellPhone() {

}