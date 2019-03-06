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
#include "space.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Space::Space() :
    up{nullptr}, right{nullptr}, down{nullptr}, left{nullptr} {}

/*********************************************************************
** Description:     default constructor
*********************************************************************/
Space::Space(string locName) :
    locationName{locName} {}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Space::~Space() {}

/*********************************************************************
** Description:     d
*********************************************************************/
string Space::getLocationName() {
    return locationName;
}

/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/


/*********************************************************************
** Description:     d
*********************************************************************/

