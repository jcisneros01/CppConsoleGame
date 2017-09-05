/*********************************************************************
 ** Author: Jose Cisneros
 ** Date: 3/21/2017
 ** Description: game.hpp is the Game class interface file.
 *********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "space.hpp"
#include "shipgateroom.hpp"
#include "basegateroom.hpp"
#include "shipresearchroom.hpp"
#include "shipbridge.hpp"
#include "shipengineeringroom.hpp"
#include "shipobservationroom.hpp"

// Defines the interface of the Game class
class Game
{
private:
    // Player values
    int playerHealth;
    vector<string> inventory;
    Space* currentLocation;
    
    // Ship values
    int energy;
    int oxygenLevel;
    
    // Spaces
    Space* baseGateRoom;
    Space* shipGateRoom;
    Space* shipResearchRoom;
    Space* shipEngineeringRoom;
    Space* shipObservationRoom;
    Space* shipBridge;
    
    // Helper functions
    bool gameOver;
    void updateGameState();
    void getInventory();
public:
    Game();
    ~Game();
    void menu();
    void runGame();
};

#endif


