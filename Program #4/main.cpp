/* main.cpp
 *
 * Holds the driver code for the maze traversal program
 */

// System Includes
#include <iostream>
#include <fstream>

// User-Defined Includes
#include "queue.h"
#include "mazeTraversal.h"

using namespace std;

int main() {
    Queue positions;

    // input file stream on maze.txt
    ifstream inFile("maze.txt");

    // 2D character array to store the maze
    char** arr;
    
    // row and column of the 2D character array
    int row = 0, col = 0;
    int currentRow = 0, currentCol = 0;

    // counter to see how often the array should print
    int printCount = 0, mazeCount = 1;

    bool foundGoal = false;

    // while input file is open, keep looping and getting all the mazes
    if (inFile.is_open()) {
        printPrologue();
        while (!inFile.eof()) {
            // reset the print count to 0
            printCount = 0;
            
            cout << "\nSolving Maze " << mazeCount << "...\n";

            // get the maze into 2D array
            arr = getMaze(inFile, row, col);

            // find starting position
            findStart(arr, row, col, currentRow, currentCol);

            // loop to solve the maze
            do {
                foundGoal = addSurroundingPositions(arr, positions, currentRow, currentCol, row, col);
                getNextPosition(positions, currentRow, currentCol);
                if ((printCount++ % ((5*row)/2)) == 0){
                    printArr(arr, row, col);
                    // cout << "\n-------------------------------------------------------------------------------\n\n";
                    cout << "\n----------------------------------------\n\n";
                }
            } while (!foundGoal);

            cout << "Solved Maze " << mazeCount << ".\n\n";
            printArr(arr, row, col);
            cout << "\n\n----------------------------------------\n\n";
            mazeCount++;
        }
    }

    inFile.close();

    return 0;
}