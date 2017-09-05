/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: space.hpp is the Space class interface file.
 *********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "validateInput.hpp"

using namespace std;

// Defines the interface of the Space class
class Space
{
protected:
    Space* right;
    Space* left;
    Space* up;
    Space* down;
    string roomName;
    vector<string> roomInventory;
public:
    Space();
    virtual ~Space();
    virtual void menu(Space* &l, int &h, int &e, int &o, vector<string> &i)=0;
    Space* getRight();
    Space* getLeft();
    Space* getUp();
    Space* getdown();
    void displayArt(string fileName);
    string getRoomName();
    void setLocation(Space* location, char direction);
    int searchBag(vector<string> &inv, string name);
    
};

#endif
