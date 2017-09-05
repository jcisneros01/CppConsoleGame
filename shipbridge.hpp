/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: shipbridge.hpp is the ShipBridge class interface file.
 *********************************************************************/

#ifndef ShipBridge_HPP
#define ShipBridge_HPP

#include "space.hpp"

// Defines the interface of the ShipBridge class
class ShipBridge: public Space
{
public:
    ShipBridge();
    void menu(Space* &l, int &h, int &e, int &o, vector<string> &i);
};

#endif
