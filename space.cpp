/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: space.cpp is the Space class implementation file.
 *********************************************************************/
#include "space.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Space::Space()
{
    right = left = up = down = nullptr;
}

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Space::~Space()
{
}

/*********************************************************************
 ** Description: retrieve room
 ** Returns: Space*
 *********************************************************************/
Space* Space::getRight()
{
    return right;
}

/*********************************************************************
 ** Description: retrieve room
 ** Returns: Space*
 *********************************************************************/
Space* Space::getLeft()
{
    return left;
}

/*********************************************************************
 ** Description: retrieve room
 ** Returns: Space*
 *********************************************************************/
Space* Space::getUp()
{
    return up;
}

/*********************************************************************
 ** Description: retrieve room
 ** Returns: Space*
 *********************************************************************/
Space* Space::getdown()
{
    return down;
}

/*********************************************************************
 ** Description: retrieve room
 ** Returns: Space*
 *********************************************************************/
void Space::displayArt(string fileName)
{
    
    ifstream inputFile;     // Create input file stream object
    string lines = "";
    
    //Open the input file
    inputFile.open(fileName);
    
    // Read input and store into Vector
    if (inputFile)
    {
        
        // Read and add the numbers in file
        while (inputFile)
        {
            string tempLine;
            getline(inputFile, tempLine);
            tempLine += "\n";
            lines += tempLine;
        }
        cout << lines << endl;
    }
    else
    {
        // Display error message
        cout << "could not access file" << endl;
    }
    
    // Close file
    inputFile.close();
}

/*********************************************************************
 ** Description: retrieve room name
 ** Returns: string
 ***********************************************************c*********/
string Space::getRoomName()
{
    return roomName;
}


/*********************************************************************
 ** Description: set location
 ** Returns: void
 ***********************************************************c*********/
void Space::setLocation(Space* location, char direction)
{
    // Based on char input, set pointer
    switch (direction)
    {
        case 'U':
            up = location;
            break;
        case 'D':
            down = location;
            break;
        case 'L':
            left = location;
            break;
        case 'R':
            right = location;
            break;
        default:
            break;
    }
}

/*********************************************************************
 ** Description: set location
 ** Returns: void
 ***********************************************************c*********/
int Space::searchBag(vector<string> &inv, string name)
{
    int position = -1;        // Position of search string
    bool searchDone = false;  // flag
    int i = 0;                // Starting position
    
    // If empty, return
    if (inv.size() == 0)
    {
        return position;
    }
    
    while (!searchDone)
    {
        // If element is equal to search string, set position and update flag
        if (inv[i] == name)
        {
            position = i;
            searchDone = true;
        }
        
        // If back is reached update flag
        if (inv[i] == inv.back())
        {
            searchDone = true;
        }
    
        i++;
    }
    
    return position;
}
