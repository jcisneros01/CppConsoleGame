/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: basegateroom.cpp is the BaseGateRoom class interface file.
 *********************************************************************/

#ifndef BASEGATEROOM_HPP
#define BASEGATEROOM_HPP

#include <string>
#include "space.hpp"
#include "shipgateroom.hpp"

// Defines the interface of the BaseGateRoom class
class BaseGateRoom: public Space
{
public:
    BaseGateRoom(Space* &location);
    void menu(Space* &l, int &h, int &e, int &o, vector<string> &i);
    void searchRoom(vector<string> &i);

};

#endif
