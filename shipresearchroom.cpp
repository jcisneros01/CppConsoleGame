/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: shipresearchroom.cpp is the ShipResearchRoom class implementation file.
 *********************************************************************/
#include "shipresearchroom.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
ShipResearchRoom::ShipResearchRoom()
{
    roomName = "Control Room";
    roomInventory.push_back("Kino");
}


/*********************************************************************
 ** Description: Menu for space
 ** Returns: void
 ***********************************************************c*********/
void ShipResearchRoom::menu(Space* &l, int &h, int &e, int &o, vector<string> &i)
{
    // Print space info
    cout << endl;
    displayArt("console.txt");
    cout << "Research Lab" << endl;
    cout << "\nYou're in the research lab. There's a computer in the center of the room." << endl;
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    // Menu
    do
    {
        cout << "\nPlease make a selection" << endl;
        cout << "1: Go back to the Gate Room" << endl;
        cout << "2: Interact with Computer" << endl;
        cout << "3: Search the room" << endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 4);
        
        // Make selection based on input
        switch (choice)
        {
            case 1:
                
                // Change location
                l = right;
                flag = false;
                break;
            case 2:
                {
                    bool isTrue = true;  // Flag
                    int number;          // User input
                    
                    // Menu
                    do {
                            cout << "\nComputer file menu-" << endl;
                            cout << "Please make a selection to open file" << endl;
                            cout << "1: kino.txt" << endl;
                            cout << "2: ship.txt" << endl;
                            cout << "3: shipEnergySystems.txt" << endl;
                            cout << "4: Log off computer"<< endl;
                            cout << "\nEnter: ";
                            cin >> number;
                            validateInput(number, 1, 4);
                        
                            switch (number)
                            {
                                case 1:
                                    cout << "\nA kino is a digital device needed to control the ship." << endl;
                                    break;
                                    
                                case 2:
                                    cout << "\nThe ship Destiny is an automated ship sent into space millions of years ago by the 1st people. Its mission is to reach the \ncenter of the universe and research the big bang." << endl;
                                    break;
                                case 3:
                                    cout << "\nThe ship is fueld by solar power. Literally. Periodically, the ship flys into the sun to replenish its energy reserves. \nThe energy level  must be at least 30% for the shield to hold." << endl;
                                    break;
                                case 4:
                                    isTrue = false;
                                    break;
                            }
                        
                    } while (isTrue);
                }
                    break;
            case 3:
                searchRoom(i);
                break;
        }
        cin.get();

    } while (flag);
}

/*********************************************************************
 ** Description: search room and add to inventory
 ** Returns: void
 ***********************************************************c*********/
void ShipResearchRoom::searchRoom(vector<string> &i)
{
    
    bool flag = true;             // flag
    int choice = 0;               // user choice input
    
    
    cout << "Items found in room" << endl;
    // Menu
    do
    {
        cout << "\nPlease make a selection to add to bag" << endl;
        cout << "1: Kino" << endl;
        cout << "2: Back to room menu"<< endl;
        cout << "\nEnter: ";
        cin >> choice;
        validateInput(choice, 1, 2);
        
        // Limit bag size
        if (i.size() == 4)
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
