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
WaterCooloer::WaterCooloer() : Space("Water Cooler", COOLER)
{
    // TODO - delete
    cout << "WaterCooler default constructor triggered\n";
}

/*********************************************************************
** Description:     destructor
*********************************************************************/
WaterCooloer::~WaterCooloer() {}