/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: shipbridge.cpp is the ShipBridge class implementation file.
 *********************************************************************/
#include "shipbridge.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
ShipBridge::ShipBridge()
{
    roomName = "Bridge";
}

/*********************************************************************
 ** Description: Menu for space
 ** Returns: void
 ***********************************************************c*********/
void ShipBridge::menu(Space* &l, int &h, int &e, int &o, vector<string> &i)
{
    // Print space info
    cout << endl;
    displayArt("console.txt");
    cout << "Bridge" << endl;
    cout << "\nYou're on the ship's bridge. There's a console in the middle of the room." << endl;
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    // Menu
    do
    {
        cout << "\nPlease make a selection" << endl;
        cout << "1: Go back to the Gate Room" << endl;
        cout << "2: Interact with console" << endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 2);
        
        // Make selection based on input
        switch (choice)
        {
            case 1:
                l = left;
                flag = false;
                break;
            case 2:
                {
                    int choice = 0;  // user choice input
                    
                    // Get item position
                    int itemPosition = searchBag(i, "Kino");
                    
                    // If item found, use item and remove form inventory
                    if (itemPosition == -1)
                    {
                        cout << "\nALERT! You need the kino in order to operate the console." << endl;
                        break;
                    }
                    
                    // Check if energy levels
                    if (e >= 80)
                    {
                        cout << "\nThe ship is fully operational and on autopiliot." << endl;
                        break;

                    }
                    
                    // Menu
                    cout << "\nALERT! LOW ON ENERGY." << endl;
                    cout << "\nPlease make a selection" << endl;
                    cout << "1: Locate a star and recharge" << endl;
                    cout << "\nEnter: ";
                    cin >> choice;
                    validateInput(choice, 1, 2);
                    
                    // Recharge ship
                    if (choice == 1)
                    {
                        cout << "The ship entered the nearest star and has begun recharging." << endl;
                        
                        // If energy is sufficient, recharge e level, else ship blows up.
                        if (e >= 30)
                        {
                            cout << "The ship has recharged and all systems are operational." << endl;
                            e = 100;
                        }
                        else
                        {
                            e = 0;
                            flag = false;
                        }
                        
                    }
                
                }
                break;
        }
        cin.get();

    } while (flag);
}
