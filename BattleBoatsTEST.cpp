// BattleBoatsTEST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "gameLogic.h"

using namespace std;

int main()
{
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];

    // Test initialization
    initializeGrids(playerGrid, computerGrid);
    cout << "Testing grid initialization:" << endl;
    displayGrids(playerGrid, computerGrid);

    // Test boat placement
    placePlayerBoat(playerGrid);
    placeComputerBoat(computerGrid);
    displayGrids(playerGrid, computerGrid);

    return 0;

}

