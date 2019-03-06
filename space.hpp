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

class Space {
protected:
    Space *up;
    Space *right;
    Space *down;
    Space *left;

public:
    Space();
    virtual ~Space();


};

#endif // SPACE_HPP
