/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: shipobservationroom.hpp is the ShipObservationRoom class interface file.
 *********************************************************************/

#ifndef SHIPOBSERVATIONROOM_HPP
#define SHIPOBSERVATIONROOM_HPP

#include "space.hpp"

// Defines the interface of the ShipObservationRoom class
class ShipObservationRoom: public Space
{
private:
    bool isDoorLocked;
public:
    ShipObservationRoom();
    void menu(Space* &l, int &h, int &e, int &o, vector<string> &i);
    void searchRoom(vector<string> &i);
    bool getIsDoorLocked();
};

#endif
