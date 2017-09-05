/******************************************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/5/2017
 ** Description: A function that validates user input, and if invalid it prompts the user
 ** again.
 ** 3 parameters: A reference variable to input, and lower and upper variable bounds.
 ******************************************************************************************/
#include "validateInput.hpp"

// Helper function that validates type
void checkInputType(int &input)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input!" << endl;
        cout << "Enter again: ";
        cin >> input;
    }
}

// ValidateInput function definition
void validateInput(int &input, int parameter1, int parameter2)
{
    checkInputType(input);
    
    // Validate input is within range
    while (input < parameter1 || input > parameter2)
    {
        cout << "Input out of range!" << endl;
        cout << "Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> input;
        
        checkInputType(input);
    }
}

// ValidateCharInput function definition
void validateCharInput(char &input)
{
    input = toupper(input);
    
   while (input != 'Y' && input != 'N')
    {
        cout << "Invalid input!" << endl;
        cout << "Enter again: ";

        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cin >> input;
        input = toupper(input);
    }
}
