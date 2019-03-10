/*********************************************************************
** Author:          Sandro Aguilar
** Date:            March 4, 2019
** Description:     WaterCooler class is derived from the space class
**                  and it represents the space that is by the water
**                  cooler in the office.
*********************************************************************/
#ifndef WATERCOOLER_HPP
#define WATERCOOLER_HPP

#include "space.hpp"

class WaterCooler : public Space {
private:

public:
    WaterCooler();
    ~WaterCooler();
    void spaceInteractions() override;
    void officeChat();
    void moreChat();
};

#endif // WATERCOOLER_HPP
