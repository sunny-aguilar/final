/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Inventory item class is used to create
**                  inventory items that a player can use in the game.
*********************************************************************/
#ifndef INVENTORYITEM_HPP
#define INVENTORYITEM_HPP

#include <string>
using std::string;

enum Inventory{CELLPHONE, DOUGHNUTS, STAPLER};

class InventoryItem {
private:
    string name;
    Inventory itemType;
public:
    InventoryItem(string name, Inventory itemType);
    ~InventoryItem();
    Inventory getItemType();
};

#endif INVENTORYITEM_HPP
