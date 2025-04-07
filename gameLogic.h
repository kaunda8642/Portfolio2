#pragma once

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string>

// Define the size of the grid
const int GRID_SIZE = 4;

// Function to initialize the grids
void initializeGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]);

// Function to display the current state of both grids
void displayGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]);

// Function to place the boat on the player's grid
bool placePlayerBoat(char playerGrid[GRID_SIZE][GRID_SIZE]);

// Function for the computer to randomly place its boat
void placeComputerBoat(char computerGrid[GRID_SIZE][GRID_SIZE]);

// Function to get a valid shot from the player
bool getPlayerShot(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGrid[GRID_SIZE][GRID_SIZE]);

// Function to process the computer's shot
void computerShot(char playerGrid[GRID_SIZE][GRID_SIZE]);

// Function to check if the player has won
bool checkWin(char computerGrid[GRID_SIZE][GRID_SIZE]);

// Function to check if the computer has won
bool checkComputerWin(char playerGrid[GRID_SIZE][GRID_SIZE]);

#endif
