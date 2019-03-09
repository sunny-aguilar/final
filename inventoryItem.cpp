/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     The Inventory item class is used to create
**                  inventory items that a player can use in the game.
*********************************************************************/
#include "inventoryItem.hpp"

/*********************************************************************
** Description:     default constructor
*********************************************************************/
InventoryItem::InventoryItem(string name, Inventory itemType) :
    name{name}, itemType{itemType} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
InventoryItem::~InventoryItem() {}

/*********************************************************************
** Description:     returns the enum item type
*********************************************************************/
Inventory InventoryItem::getItemType() {
    return itemType;
}


