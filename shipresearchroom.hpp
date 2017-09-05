/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: shipresearchroom.hpp is the ShipResearchRoom class interface file.
 *********************************************************************/

#ifndef SHIPRESEARCHROOM_HPP
#define SHIPRESEARCHROOM_HPP

#include "space.hpp"

// Defines the interface of the ShipResearchRoom class
class ShipResearchRoom: public Space
{
public:
    ShipResearchRoom();
    void menu(Space* &l, int &h, int &e, int &o, vector<string> &i);
    void searchRoom(vector<string> &i);
};

#endif
