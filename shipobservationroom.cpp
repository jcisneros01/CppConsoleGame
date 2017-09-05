/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: ShipObservationroom.cpp is the ShipObservationRoom class implementation file.
 *********************************************************************/
#include "shipobservationroom.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
ShipObservationRoom::ShipObservationRoom()
{
    roomName = "Observation Room";
    roomInventory.push_back("Key");
    isDoorLocked = false;
}

/*********************************************************************
 ** Description: Menu for space
 ** Returns: void
 ***********************************************************c*********/
void ShipObservationRoom::menu(Space* &l, int &h, int &e, int &o, vector<string> &i)
{

    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    //Check if door si locked
    if (isDoorLocked)
    {
        cout << "\nThe door is locked " << endl;
        l = up;

        return;
    }
    cout << endl;
    // Print space info
    displayArt("observation.txt");
    cout << "Observation Deck" << endl;
    cout << "\nThis room is leaking air." << endl;
    
    // Menu
    do
    {
        cout << "\nPlease make a selection" << endl;
        cout << "1: Go back to the Gate Room" << endl;
        cout << "2: Lock the door" << endl;
        cout << "3: Search the room" << endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 3);
        
        // Make selection based on input
        switch (choice)
        {
            case 1:
            {
                l = up;
                flag = false;
            }
                break;
            case 2:
            {
                // Check if user has picked up key
                if (!(roomInventory[0] == "empty"))
                {
                    cout << "You don't have a key " << endl;
                }
                // Check if door is locked. If not, lock.
                else if (!isDoorLocked)
                {
                    cout << "The door was locked and the leak has been sealed" << endl << endl;
                    isDoorLocked = true;
                    flag = false;
                    l = up;
                }
                else
                {
                    cout << "The door is already locked" << endl;
                }
            }
                break;
            case 3:
            {
                searchRoom(i);
            }
                break;
    
        }
  
        cin.get();

       } while (flag);

}

/*********************************************************************
 ** Description: search room and add to inventory
 ** Returns: void
 ***********************************************************c*********/
void ShipObservationRoom::searchRoom(vector<string> &i)
{
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    cout << "Items found in room" << endl;
    // Menu
    do
    {
        cout << "\nPlease make a selection to add to bag" << endl;
        cout << "1: Key" << endl;
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
                
                // Check if user has picked up key. If not, add to inventory.
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

/*********************************************************************
 ** Description: returns whether door is locked or not
 ** Returns: Bool
 ***********************************************************c*********/
bool ShipObservationRoom::getIsDoorLocked()
{
    return isDoorLocked;
}
