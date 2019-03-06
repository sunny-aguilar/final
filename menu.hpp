/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class also holds the
**                  user input validation function.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "player.hpp"
#include "space.hpp"
#include "myCubicle.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::string;
using std::setw;
using std::left;
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void startScreen();
    void startScreenArt();
    void gameIntro(int chance, Player *p);
    void sunIntro();
    void carArt();
    void startWorkDay();
    void officeArt();
    void myDeskArt();
    void mainMenu();
    void hud(Player *p, Space *s, double time);


    void exitGame();
    int validateNumber(int min, int max);
};

#endif // MENU_HPP
