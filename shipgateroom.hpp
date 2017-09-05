/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: shipgateroom is the ShipGateRoom class interface file.
 *********************************************************************/

#ifndef SHIPGATEROOM_HPP
#define SHIPGATEROOM_HPP

#include <string>
#include "space.hpp"

// Defines the interface of the ShipGateRoom class
class ShipGateRoom: public Space
{
private:
    bool enteredEarthWormhole;
public:
    ShipGateRoom(Space* location1, Space* location2, Space* location3, Space* location4);
    void menu(Space* &l, int &h, int &e, int &o, vector<string> &i);
    bool getEnteredEarthWormhole();

};

#endif
