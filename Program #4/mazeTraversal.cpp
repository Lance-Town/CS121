/* mazeTraversal.cpp
 *
 * Holds the definitions to the functions that will traverse the maze, handle retrieving input, 
 * output etc.
 */

// System Includes
#include <fstream>
#include <iostream>

// User-Defined Includes
#include "mazeTraversal.h"
#include "queue.h"

using namespace std;

// get the next maze in the text file, and return a 2D character array containting the array
char** getMaze(ifstream& inFile, int& row, int& col) {
    inFile >> row;
    inFile >> col;
    string tempLine;

    char **arr = new char*[row];

    for (int i = 0; i < row; i++) {
        arr[i] = new char[col];
    }

    int i = 0;

    getline(inFile, tempLine);      // throw out trash line?

    while (i < row && getline(inFile, tempLine)) {
        for (int j = 0; j < tempLine.length(); j++) {
            arr[i][j] = tempLine[j];
        }
        i++;
    }

    return arr;
}

// prints out the 2D character array
void printArr(char**& arr, int row, int col) {
    // cout << "PRINTING ARRAY\n";
    for (int i = 0; i < row; i++) {
        // cout << "IN I LOOP" << '\n';
        for (int j = 0; j < col; j++) {
            // cout << "IN J LOOP" << '\n';
            cout << arr[i][j];
        }
        cout << '\n';
    }
}

// find starting position
void findStart(char**& arr, int row, int col, int& startRow, int& startCol) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            // check if position is the starting one
            if (arr[r][c] == 'S') {
                startRow = r;
                startCol = c;
                return;
            }
        }
    }

    return;
}

// position is valid or not
bool isValid(char** arr, int r, int c) {
    return (arr[r][c] == '.' || arr[r][c] == 'G');
}

// check surrounding cells, adding valid ones to the queue
bool addSurroundingPositions(char**&arr, Queue& positions, int currRow, int currCol, int maxRowSize, int maxColSize) {
    // North
    if ( (currRow - 1) >= 0 && isValid(arr, currRow-1, currCol)) {
        // currRow - 1 is valid
        
        // check if next to Goal
        if (arr[currRow-1][currCol] == 'G'){
            return true;
        }
        
        // cout << "Position " << currRow-1 << ", " << currCol << " is valid\n";
        positions.enqueue(currRow-1, currCol);
        arr[currRow-1][currCol] = '^';
    }

    // East
    if ( (currCol+1) < maxColSize && isValid(arr, currRow, currCol+1)) {
        // currCol + 1 is valid

        // check if next to Goal
        if (arr[currRow][currCol+1] == 'G'){
            return true;
        }

        // cout << "Position " << currRow << ", " << currCol+1 << " is valid\n";
        positions.enqueue(currRow, currCol+1);
        arr[currRow][currCol+1] = '>';
    }
    
    // South
    if ( (currRow+1) < maxRowSize && isValid(arr, currRow+1, currCol)) {
        // currRow + 1 is valid

        // check if next to Goal
        if (arr[currRow+1][currCol] == 'G'){
            return true;
        }

        // cout << "Position " << currRow+1 << ", " << currCol << " is valid\n";
        positions.enqueue(currRow+1, currCol);
        arr[currRow+1][currCol] = 'v';
    }
    
    // West
    if ( (currCol-1) >= 0 && isValid(arr, currRow, currCol-1)) {
        // currCol - 1 is valid

        // check if next to Goal
        if (arr[currRow][currCol-1] == 'G'){
            return true;
        }
        
        // cout << "Position " << currRow << ", " << currCol-1 << " is valid\n";
        positions.enqueue(currRow, currCol-1);
        arr[currRow][currCol-1] = '<';
    }

    return false;
}

// pop off queue and go to next position
void getNextPosition(Queue& positions, int& currRow, int& currCol) {
    positions.dequeue(currRow, currCol);
    return;
}

void printPrologue() {
    cout << "This program solves any mazes implemented in the maze.txt file.\n" <<
    "-------------------------------------------------------------------------------\n";
    return;
}