/* gridClass.cpp
 *
 * Stores the method definitions for the methods that main.cpp calls
 *---------------------------------------------------------------------
 */

// "System" Includes
#include <iostream>
#include <random>

// "User-Defined" Includes
#include "gridClass.h"

using namespace std;

// get input from user and return it
int Grid::getIntInput(string outputString) {
    cout << outputString;
    int iVal;
    cin >> iVal;
    return iVal;
}

// check the input from the user to make sure it is within bounds of the program
void Grid::checkInput() {
    // check input to be within the grid dimensions of 1x1 to 50x50
    if ((nRow < MIN_GRID_SIZE || nRow > MAX_GRID_SIZE) || (nCol < MIN_GRID_SIZE || nCol > MAX_GRID_SIZE)) {
        cout << "\nInvalid grid dimensions: Must be between [1, 50]\n";
        nRow = getIntInput("Row size: ");
        nCol = getIntInput("Col size: ");
        checkInput();
    }

    // check robot starting position to be inside the grid and not outside the bounds
    if ((robotRowPosition < MIN_POSITION || robotRowPosition >= nRow) || (robotColPosition < MIN_POSITION || robotColPosition >= nCol)) {
        cout << "\nInvalid starting position: Must be between 0 and gridSize-1\n";
        robotRowPosition = getIntInput("Enter Robot Starting Row: ");
        robotColPosition = getIntInput("Enter Robot Starting Column: ");
        checkInput();
    }

    // check max iterations to be positive
    if (maxIterations < 0) {
        cout << "\nInvalid maximum iterations: Must be a positive number\n";
        maxIterations = getIntInput("Enter Max Number of Iterations Robot Can Make: ");
        checkInput();
    }

    // check max cell visits to be a positive number 
    if (maxCellVisits < 0) {
        cout << "\nInvalid maximum cell visits: Must be a positive number\n";
        maxCellVisits = getIntInput("Enter Max Cell Visits Robot Can Make at Each Point: ");
        checkInput();
    }
    return;
}

// grid constructor to get necessary inputs and initialize the 2-D grid array
Grid::Grid() {
    // get the necessary inputs from user
    nRow = getIntInput("Enter Number of Rows in Grid: ");
    nCol = getIntInput("Enter Number of Columns in Grid: ");
    cout << '\n';

    robotRowPosition = getIntInput("Enter Robot Starting Row: ");
    robotColPosition = getIntInput("Enter Robot Starting Column: ");
    cout << '\n';
    
    maxIterations = getIntInput("Enter Max Number of Iterations Robot Can Make: ");
    maxCellVisits = getIntInput("Enter Max Cell Visits Robot Can Make at Each Point: ");

    // check the input to make sure it is in bounds
    checkInput();

    // allocate and initialize the 2-D grid array to all be 0
    grid = new int*[nRow];
    for (int i = 0; i < nRow; i++) {
        grid[i] = new int[nCol];

        for (int j = 0; j < nCol; j++) {
            grid[i][j] = 0;
        }
    }

    // place the robot by iterating its starting position by one
    grid[robotRowPosition][robotColPosition]++;
    return;
}

// Loop through 2-D array and print each element
void Grid::printGrid() {
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            cout << grid[i][j] << "  ";
        }

        cout << '\n';
    }
    return;
}

// check to make sure potential robot move is valid and not out of bounds or in an invalid cell. 
// use integers to denote error cases.
int Grid::checkValidRobotMove(int rowMove, int colMove) {
    if (((robotRowPosition + rowMove) < MIN_POSITION || (robotRowPosition+rowMove) > (nRow-1))) {
        // check if the move would put the robot out of bounds of the grid
        return 1;
    } else if (((robotColPosition + colMove) < MIN_POSITION || (robotColPosition+colMove) > (nCol-1))) {
        // check if the move would put the robot out of bounds of the grid
        return 1;
    } else if (rowMove == 0 && colMove == 0) {
        // check if move makes robot stay still, which is invalid
        return 1;
    } else if (grid[robotRowPosition+rowMove][robotColPosition+colMove] >= maxCellVisits) {
        // check if the position to move to has already reached maximum cell visits
        return 2;
    } else {
        // position is valid
        return 0;
    }
}

// check if all squares have been met at least once
bool Grid::checkEachCell() {
    // loop through entire grid, and return false if any cell is found to have 0
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (grid[i][j] < 1) {
                // a grid has not been visited yet, return false
                return false;
            }
        }
    }

    // each grid has been visited once, so return true
    return true;
}

// Check the surrouding squares of the robot to see if there are available squares to move to
bool Grid::checkSurroundingSquares() {
    // bounds for the loop to make sure it doesn't access an illegal cell
    int rowLoopStart = robotRowPosition-1;
    int rowLoopEnd = robotRowPosition+1;
    int colLoopStart = robotColPosition-1;
    int colLoopEnd = robotColPosition + 1;
    // keep track of total cells check
    int totalLoops = 0;
    // keep track of amount of cells that have been visited the maximum number of times
    int totalMaxVisits = 0;

    if (robotRowPosition == 0) {
        // robot is on first row
        rowLoopStart += 1;
    } else if (robotRowPosition == nRow-1) {
        // robot is on the last row
        rowLoopEnd -= 1;
    }

    if (robotColPosition == 0) {
        // robot is on the first column
        colLoopStart += 1;
    } else if (robotColPosition == nCol-1) {
        // robot is on the last column
        colLoopEnd -= 1;
    }

    // loop through the surrounding squares, and update the total loops and max visits
    for (int i = rowLoopStart; i <= rowLoopEnd; i++ ) {
        for (int j = colLoopStart; j <= colLoopEnd; j++) {
            if (grid[i][j] >= maxCellVisits) {
                // cell has been visited the max amount of times, so increment max visits
                totalMaxVisits++;
            }
            if (i != 0 && j != 0) {
                // don't count the cell the robot is already sitting in
                totalLoops++;
            }
        }
    }

    // return true if every position has been visited max times, false otherwise
    return (totalLoops == totalMaxVisits);
}

// move the robot, and return true if robot has moves available to make or false if all squares are not available to move to
bool Grid::moveRobot() {
    // integers to hold the random row and column moves
    int randRowMove;
    int randColMove;

    // if the surrounding squares are all taken up, then return false as this is a terminal case
    if (checkSurroundingSquares() == true) {
        return false;
    }

    // keep picking a random position to move to until a valid one is found
    do {
        // pick between [-1, 1] for the robot to move
        randRowMove = (rand() % 3) - 1;
        randColMove = (rand() % 3) - 1;
    } while (checkValidRobotMove(randRowMove, randColMove) != 0);

    // move the robot
    robotRowPosition += randRowMove;
    robotColPosition += randColMove;

    // increment that cell
    grid[robotRowPosition][robotColPosition]++;

    // robot is still able to move
    return true;
}

// start moving the robot until one of the terminating cases is met. Return the amount of times iterations robot took
int Grid::startMoving() {
    // iterator
    int i = 0;

    // boolean to see if robot has surrounding squares available to move to that haven't met max cell visits
    bool eligibleToMove = true; 
    
    // boolean to check if each square has been visited or not, and if all squares are, then program terminates
    bool eachSquareHasBeenVisited = false;

    // loop until max iterations are met, each cell has been visited once, or robot can no longer move
    while (((i < maxIterations) && (eachSquareHasBeenVisited == false)) && (eligibleToMove == true)) {
        eligibleToMove = moveRobot();
        eachSquareHasBeenVisited = checkEachCell();
        i++; // increment iterator
    }
    return i;
}

// print the board but leave all cells blank unless they have been visited the max number of times
void Grid::printMaxCells() {
    cout << "Printing out all cells that were visited the maximum number of times allowed, " << maxCellVisits << ":\n";

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (grid[i][j] >= maxCellVisits) {
                cout << grid[i][j] << " |";
            } else {
                cout << "   |";
            }
        }
        cout << '\n';
    }
}

// print the output of the program
void Grid::printOutput(int iterations) {
    cout << "\nNumber of Rows: " << nRow << endl;
    cout << "Number of Columns: " << nCol << endl;
    cout << "Robot's Ending Position: (" << robotRowPosition << ", " << robotColPosition << ")\n";
    cout << "Max Iterations: " << maxIterations << endl;
    cout << "Max Cell Visits: " << maxCellVisits << endl;
    cout << "The robot made " << iterations << " iterations\n";
}