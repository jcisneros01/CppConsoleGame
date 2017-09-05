/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: shipengineeringroom.hpp is the ShipEngineeringRoom class interface file.
 *********************************************************************/

#ifndef SHIPENGINEERINGROOM_HPP
#define SHIPENGINEERINGROOM_HPP

#include "space.hpp"

// Defines the interface of the shipEngineeringRoom class
class ShipEngineeringRoom: public Space
{
public:
    ShipEngineeringRoom();
    void menu(Space* &l, int &h, int &e, int &o, vector<string> &i);
    void searchRoom(vector<string> &i);
};

#endif

