/*********************************************************************
 ** Author: Jose Cisneros
 ** Date:  3/21/2017
 ** Description: game.cpp is the Game class implementation file.
 *********************************************************************/
#include "game.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Game::Game()
{
    //Init Game values
    playerHealth = 100;
    energy = 30;
    oxygenLevel = 50;
    gameOver = false;
    
    // Init rooms
    shipResearchRoom = new ShipResearchRoom();
    shipEngineeringRoom = new ShipEngineeringRoom();
    shipObservationRoom = new ShipObservationRoom();
    shipBridge = new ShipBridge();
    
    // Init ship
    shipGateRoom = new ShipGateRoom(shipResearchRoom, shipEngineeringRoom, shipBridge, shipObservationRoom);
    
    // Init base and set location
    baseGateRoom = new BaseGateRoom(shipGateRoom);
    currentLocation = baseGateRoom;
    
    // Connect rooms to gate
    shipResearchRoom->setLocation(shipGateRoom, 'R');
    shipEngineeringRoom->setLocation(shipGateRoom, 'D');
    shipBridge->setLocation(shipGateRoom, 'L');
    shipObservationRoom->setLocation(shipGateRoom, 'U');
}

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Game::~Game()
{
    // Dealloc memory
    delete shipEngineeringRoom;
    delete shipResearchRoom;
    delete shipObservationRoom;
    delete shipBridge;
    delete shipGateRoom;
    delete baseGateRoom;
    
    shipEngineeringRoom = nullptr;
    shipResearchRoom = nullptr;
    shipObservationRoom = nullptr;
    shipBridge = nullptr;
    shipGateRoom = nullptr;
    baseGateRoom = nullptr;
}

/*********************************************************************
 ** Description: check and update game status
 ** Returns: void
 *********************************************************************/
void Game::updateGameState()
{
    // Check ship energy levels
    if (energy <= 0)
    {
        gameOver = true;
        playerHealth = 0;
        cout << "The shields failed and the ship was destroyed. " << endl;
    }
    
    // Check ship oxygen levels
    if (oxygenLevel <= 0)
    {
        gameOver = true;
        cout << "You ran out of air." << endl;
        playerHealth = 0;
    }
    
    // Check player health levels
    if (playerHealth <= 0)
    {
        gameOver = true;
        cout << "The player died." << endl;
    }
    
    bool gatedToEarth = false;  // Bool store for earth transport status
    
    // Get transport status from shipGateRoom
    gatedToEarth = static_cast<ShipGateRoom*>(shipGateRoom)->getEnteredEarthWormhole();
    
    // If transported to earth, end game and print notif.
    if (gatedToEarth)
    {
        gameOver = true;
        cout << "You're back on earth! You won." << endl;
    }
}

/*********************************************************************
 ** Description: Starts game and runs logic
 ** Returns: void
 *********************************************************************/
void Game::runGame()
{

    while(!gameOver)
    {
        // Print Stats
        cout << "Player stats" << endl;
        cout << "--------------" << endl;
        cout << "Health: " << playerHealth << endl;
        cout << "Inventory:" << endl;
        getInventory();
        
        // If on ship, print ship stats
        if (currentLocation->getRoomName() != "Icarus Base Gate Room")
        {
            cout << "\nShip stats" << endl;
            cout << "--------------" << endl;
            cout << "Power Level: " << energy << endl;
        }
        
        if (currentLocation->getRoomName() != "Icarus Base Gate Room")
        {
            cout << "Oxygen Level: " << oxygenLevel << endl;
        }
        
        // Call current space's menu function and pass vars
        currentLocation->menu(currentLocation, playerHealth, energy, oxygenLevel, inventory);
        
        // Reduce ship stats after each location switch
        energy-=5;
        
        // Reduce ship stat after each location switch until door is locked
        if (!(static_cast<ShipObservationRoom*>(shipObservationRoom)->getIsDoorLocked()))
        {
            oxygenLevel-=10;
        }
        
        // Chech if game lost/won
        updateGameState();
        
        // Clear screen after space switch
        cout << "\nPRESS ENTER TO CONTINUE" << endl;
        cin.get();
        system("clear");
    }
}


/*********************************************************************
 ** Description: print inventory
 ** Returns: void
 ***********************************************************c*********/
void Game::getInventory()
{
    // Cycle through vector and display
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << i+1 << ":" << inventory[i] << ' ' << endl;
    }
}

