/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Space class provides a player spaces for
**                  which they can move through. The space class is
**                  an abstract class from which other classes are
**                  derived from. Space class contains virtual
**                  functions. Each space has 4 space pointers are
**                  used to point to other spaces and allow a player
**                  to move about.
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "player.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

enum Location{MYCUBICLE, FRIENDCUBICLE, BOSSROOM, COOLER, BREAKROOM, MEETINGROOM};

class Space {
protected:
    Space *up;
    Space *right;
    Space *down;
    Space *left;

    Location location;
    string locationName;
    Player *player;

public:
    Space();
    Space(string locName, Location loc);
    Space(string locName, Location loc, Player *player);
    virtual ~Space();
    string getLocationName();
    Location getLocation();

    // space pointer setters
    void setUp(Space *up);
    void setRight(Space *right);
    void setDown(Space *down);
    void setLeft(Space *left);

    // space pointer getters
    Space *getUp();
    Space *getRight();
    Space *getDown();
    Space *getLeft();

    // player setter/getter
    void setPlayer(Player *&player);
    Player *getPlayer();

    // virtual function(s)
    virtual void spaceInteractions() = 0;

    //friend class Game;
};

#endif // SPACE_HPP
