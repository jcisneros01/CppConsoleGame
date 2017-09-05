/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: shipengineeringroom.cpp is the shipEngineeringRoom class implementation file.
 *********************************************************************/
#include "shipengineeringroom.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
ShipEngineeringRoom::ShipEngineeringRoom()
{
    roomName = "Engineering Room";

}

/*********************************************************************
 ** Description: Menu for space
 ** Returns: void
 ***********************************************************c*********/
void ShipEngineeringRoom::menu(Space* &l, int &h, int &e, int &o, vector<string> &i)
{
    // Print space info
    cout << endl;
    displayArt("reactor.txt");
    cout << "Engineering Room" << endl;
    cout << "\nYou're in the Engineering room. There's a reactor in the middle of the room." << endl;
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    // Menu
    do
    {
        cout << "\nPlease make a selection" << endl;
        cout << "1: Go back to the Gate Room" << endl;
        cout << "2: Install ZPM energy module" << endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 2);
        
        // Make selection based on input
        switch (choice)
        {
            case 1:
            {
                l = down;
                flag = false;
            }
                break;
            case 2:
            {
                // Get item position
                int itemPosition = searchBag(i, "ZPM");
                
                // If item found, use item and remove form inventory
                if (!(itemPosition == -1))
                {
                    roomInventory.push_back(i[itemPosition]);
                    cout << "Installed ZPM" << endl;
                    i[itemPosition] = "empty";
                    e = 50;
                    cout << "\nThe energy levels are now adequate enough for systems to be operational, but you are still losing power." << endl;
                }
                else
                {
                    cout << " You don't have a ZPM" << endl;
                }
            }
                break;
        }
        cin.get();

    } while (flag);

}

