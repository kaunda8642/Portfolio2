#include <iostream>
#include "gameLogic.h"

using namespace std;

int main() {
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];
    bool gameOver = false;

    cout << "Welcome to Battle Boats!" << endl;

    // Initialize grids
    initializeGrids(playerGrid, computerGrid);

    // Place boats
    while (!placePlayerBoat(playerGrid)) {}
    placeComputerBoat(computerGrid);

    // Game loop
    while (!gameOver) {
        // Display grids
        displayGrids(playerGrid, computerGrid);

        // Player's turn
        if (getPlayerShot(playerGrid, computerGrid)) {
            gameOver = true;
            continue;
        }

        // Computer's turn
        computerShot(playerGrid);

        // Check if the computer wins
        if (checkComputerWin(playerGrid)) {
            cout << "The computer has destroyed your boat! You lose." << endl;
            gameOver = true;
        }

        // Check if the player wins
        if (checkWin(computerGrid)) {
            gameOver = true;
        }
    }

    return 0;
}
