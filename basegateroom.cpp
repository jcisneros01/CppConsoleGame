/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: basegateroom.cpp is the BaseGateRoom class implementation file.
 *********************************************************************/
#include "basegateroom.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
BaseGateRoom::BaseGateRoom(Space* &location)
{
    up = location;
    roomName = "Icarus Base Gate Room";
    roomInventory.push_back("ZPM");
}


/*********************************************************************
 ** Description: Menu for space
 ** Returns: void
 ***********************************************************c*********/
void BaseGateRoom::menu(Space* &l, int &h, int &e, int &o, vector<string> &i)
{
    // Print space info
    displayArt("baseheading.txt");
    displayArt("base.txt");
    cout << "Gate Room" << endl;
    cout << "\nYou're off world at a base that is several light years from earth. The planet is experiencing strange seismic activity \nand is on the verge of blowing up. Your only chance is to escape through the stargate and transport off the planet. The only \nproblem is that you don't know where it goes. Make sure to take any supplies you might need. " << endl;
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    // Menu
    do
    {
        cout << "\nPlease make a selection" << endl;
        cout << "1: Go through Stargate" << endl;
        cout << "2: Search the room" << endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 2);
        
        // Make selection based on input
        switch (choice)
        {
            case 1:
            {   // Set new location
                l = up;
                flag = false;
            }
                break;
            case 2:
            {
                searchRoom(i);
                break;
            }
        }
        cin.get();
    } while (flag);

}

/*********************************************************************
 ** Description: search room and add to inventory
 ** Returns: void
 ***********************************************************c*********/
void BaseGateRoom::searchRoom(vector<string> &i)
{
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input

    cout << "Items found in room" << endl;
    // Menu
    do
    {
        cout << "\nPlease make a selection to add to bag" << endl;
        cout << "1: ZPM energy module" << endl;
        cout << "2: Back to room menu"<< endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 2);
        
        // Limit bag size
        if (i.size() == 3)
        {
            cout << "There's no more room-" << endl;
            return;
        }
        // Make selection based on input
        switch (choice)
        {
            case 1:
                
                // Add item to bag
                if (!(roomInventory[0] == "empty"))
                {
                    i.push_back(roomInventory[0]);
                    cout << roomInventory[0] << " was added to the inventory" << endl;
                    roomInventory[0] = "empty";
                }
                else
                {
                    cout << "The item was already added!" << endl;
                }
                
                break;
            case 2:
                flag = false;
                break;
        }
        
    } while (flag);
}
