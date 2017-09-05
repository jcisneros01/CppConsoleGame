/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: shipgateroom.cpp is the ShipGateRoom class implementation file.
 *********************************************************************/
#include "shipgateroom.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
ShipGateRoom::ShipGateRoom(Space* location1, Space* location2, Space* location3, Space* location4)
{
    left = location1;
    up = location2;
    right = location3;
    down = location4;
    roomName = "Destiny";
    enteredEarthWormhole = false;
}


/*********************************************************************
 ** Description: Menu for space
 ** Returns: void
 ***********************************************************c*********/
void ShipGateRoom::menu(Space* &l, int &h, int &e, int &o, vector<string> &i)
{
    // Print space info
    displayArt("destinyheading.txt");
    displayArt("base.txt");
    cout << "Gate Room" << endl;
    cout << "\nYou're on a space ship a billion lightyears from earth. The incoming wormhole drained the ships energy reserves and \ncritical systems are shutting down. The oxygen level is also dropping. You need to restore power \nto the ship  and fix any air leaks before you out of time. Once the ship is fixed, you need to use the gate to \nreturn to earth." << endl;
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    // Menu
    do
    {
        cout << "\nPlease make a selection" << endl;
        cout << "1: Go to Research Lab" << endl;
        cout << "2: Go to Engineering Room" << endl;
        cout << "3: Go to the Bridge" << endl;
        cout << "4: Go to Observation Deck " << endl;
        cout << "5: Dial the Earth gate" << endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 5);
        
        // Make selection based on input
        switch (choice)
        {
            case 1:
                l = left;
                flag = false;
                break;
            case 2:
                l = up;
                flag = false;
                break;
            case 3:
                l = right;
                flag = false;
                break;
            case 4:
                l = down;
                flag = false;
                break;
             case 5:
                
                // Check for sufficient energy levels for dial
                if (e < 80)
                {
                    cout << "\nNot enough energy to dial earth " << endl;
                }
                else
                {   int number;
                    cout << "The dial was successful " << endl;
                    cout << "1: Go through Stargate" << endl;
                    cout << "2: Stay in gate room" << endl;
                    cout << "\nEnter: ";
                    cin >> number;
                    validateInput(number, 1, 2);
                 
                    if (number == 1)
                    {
                        enteredEarthWormhole = true;
                    }
                }
                flag = false;
                break;
        }

        cin.get();
        
    } while (flag);
    
}




/*********************************************************************
 ** Description: Returns true if the earth worm hole has been entered
 ** Returns: bool
 ***********************************************************c*********/
bool ShipGateRoom::getEnteredEarthWormhole()
{
    return enteredEarthWormhole;
}
