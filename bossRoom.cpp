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
** Description:     a player's job performance is reviewed by the boss
**                  and the player is rated accordingly. The player's
**                  boss is the type that is very rigid and by the
**                  book and does not like to see his subordinates
**                  with their cell phones or talking in the halls.
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
    else if (player->getPerformancePoints() < 10 && player->getPerformancePoints() > 6) {
        cout << ">> Your boss tells you that your work product is just average and\n";
        cout << "   tells you that average does not get you very far.\n";
        cout << ">> You have lost 2 sanity point\n";
        player->setSanityPoints(-2);
    }
    else {
        cout << ">> Your boss tells you that even though your performance is top notch,\n";
        cout << "   there is always room for improvement. No specific guidance is given.\n";
        cout << ">> You have lost 2 sanity point\n";
        player->setSanityPoints(-2);
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void BossRoom::timeOff() {
// check if player has cell phone in inventory and punish player
    vector<string> vect = player->getInventory();
    for (int index = 0; index < vect.size(); index++) {
        if (vect.at(index) == "Cell Phone") {
            cout << ">> Your boss sees you holding your cell phone. Since he has a strict\n";
            cout << "   anti-cell phone policy, you have lost 3 performance points.\n\n";
            player->setPerformancePoints(-3);
        }
    }

    if (player->getPerformancePoints() == 10) {
        int randomNum = generateRandom(2);
        switch (randomNum) {
            case 1:
                cout << ">> Your boss acknowledges your top performance rating of 10 however\n";
                cout << "   the days off you are asking for are a busy time at the office so\n";
                cout << "   your request has been denied.\n";
                cout << ">> Lose 2 sanity points\n\n";
                player->setSanityPoints(-2);
                break;
            case 2:
                cout << ">> Your boss states that your recent performance has been acceptable and\n";
                cout << "   grants you time off\n";
                cout << ">> Gain 1 sanity point\n\n";
                player->setSanityPoints(+1);
                break;
            default:
                cout << "Unable to determine boss's response\n";
        }
    }

    if (player->getPerformancePoints() < 9 && player->getPerformancePoints() > 5) {
        int randomNum = generateRandom(2);
        switch (randomNum) {
            case 1:
                cout << ">> Your boss cites your decrease in performance in the last year and\n";
                cout << "   denies your time off request.\n";
                cout << ">> Lose 2 sanity points\n\n";
                player->setSanityPoints(-2);
                break;
            case 2:
                cout << ">> Your boss gets irritated that you have the gal to even ask for time off\n";
                cout << "   and assigns you additional work.\n";
                cout << ">> Lose 1 sanity point\n";
                cout << ">> Lose 2 performance points\n\n";
                player->setSanityPoints(-1);
                player->setPerformancePoints(-2);
                break;
            default:
                cout << "Unable to determine boss's response\n\n";
        }
    }

    if (player->getPerformancePoints() < 6) {
        int randomNum = generateRandom(2);
        switch (randomNum) {
            case 1:
                cout << ">> Your boss thinks your joking and tells you to get back to work.\n";
                cout << ">> Lose 2 sanity points\n\n";
                player->setSanityPoints(-2);
                break;
            case 2:
                cout << ">> Your boss looks up at you and gives your the next topic to present at\n";
                cout << "   the next group meeting. He asks you to leave his office.\n";
                cout << ">> Lose 1 sanity point\n";
                cout << ">> Lose 2 performance points\n\n";
                player->setSanityPoints(-3);
                player->setPerformancePoints(-3);
                break;
            default:
                cout << "Unable to determine boss's response\n";
        }
    }
}