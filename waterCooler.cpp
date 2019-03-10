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
WaterCooloer::WaterCooloer() : Space("Water Cooler", COOLER) {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
WaterCooloer::~WaterCooloer() {}

/*********************************************************************
** Description:     this functions determine which interactions a
**                  player will have with the space
*********************************************************************/
void WaterCooloer::spaceInteractions() {

}