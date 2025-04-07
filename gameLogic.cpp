#include "gameLogic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Initialize the grids with empty cells
void initializeGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            playerGrid[i][j] = '_';
            computerGrid[i][j] = '_';
        }
    }
}

// Display the current state of the grids
void displayGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]) {
    cout << "You:                Computer:\n\n";
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << playerGrid[i][j] << " ";
        }
        cout << "    " << (char)('A' + i) << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << computerGrid[i][j] << " ";
        }
        cout << endl;
    }
}

// Validate and place the player's boat
bool placePlayerBoat(char playerGrid[GRID_SIZE][GRID_SIZE]) {
    string input;
    int row, col;

    cout << "Where would you like to hide your boat? (e.g., A1, B2, C3, D4): ";
    cin >> input;

    // Validate the input (row A-D, column 1-4)
    if (input.length() != 2 || input[0] < 'A' || input[0] > 'D' || input[1] < '1' || input[1] > '4') {
        cout << "Invalid input!" << endl;
        return false;
    }

    row = input[0] - 'A';
    col = input[1] - '1';

    // Place the boat
    playerGrid[row][col] = '\__/';
    return true;
}

// Place the computer's boat randomly
void placeComputerBoat(char computerGrid[GRID_SIZE][GRID_SIZE]) {
    srand(time(0));
    int row = rand() % GRID_SIZE;
    int col = rand() % GRID_SIZE;
    computerGrid[row][col] = '*';
}

// Get a valid shot from the player
bool getPlayerShot(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]) {
    string input;
    int row, col;

    cout << "Pick a spot: ";
    cin >> input;

    // Validate the input (row A-D, column 1-4)
    if (input.length() != 2 || input[0] < 'A' || input[0] > 'D' || input[1] < '1' || input[1] > '4') {
        cout << "That is invalid!" << endl;
        return false;
    }

    row = input[0] - 'A';
    col = input[1] - '1';

    if (computerGrid[row][col] == '*') {
        cout << "You win the game! Great job!" << endl;
        return true;
    }
    else {
        computerGrid[row][col] = 'X';  // Miss
        cout << "You missed!" << endl;
        return false;
    }
}

// Make the computer's shot
void computerShot(char playerGrid[GRID_SIZE][GRID_SIZE]) {
    srand(time(0));
    int row = rand() % GRID_SIZE;
    int col = rand() % GRID_SIZE;

    if (playerGrid[row][col] == '\__/') {
        cout << "The computer hits your boat at " << (char)('A' + row) << col + 1 << "!" << endl;
    }
    else {
        playerGrid[row][col] = 'X';  // Miss
        cout << "The computer missed!" << endl;
    }
}

// Check if the player has won
bool checkWin(char computerGrid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (computerGrid[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

// Check if the computer has won
bool checkComputerWin(char playerGrid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (playerGrid[i][j] == '\__/') {
                return false;
            }
        }
    }
    return true;
}