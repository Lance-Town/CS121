/* gridClass.h
 *
 * Stores the class and methods for the methods defined in gridClass.cpp
 *---------------------------------------------------------------------
 */

#ifndef GRID_CLASS_H
#define GRID_CLASS_H

// constant global variables
const int MAX_GRID_SIZE = 50;           // maximum grid size
const int MIN_GRID_SIZE = 1;            // minimum grid size
const int MIN_POSITION = 0;             // minimum position allowed to access the 2-D array
const int NUM_SURROUNDING_SQUARES = 8;  // maximum number of surrounding squares around one cell

class Grid {
    public:
        int** grid;
        int nRow, nCol;                             // size of grid
        int robotRowPosition, robotColPosition;     // position of robot on the grid
        int maxIterations, maxCellVisits;           // max iterations robot can make and max times robot can visit a cell

        Grid();                                     // constructor
        int getIntInput(std::string);
        void checkInput();
        void printGrid();                           // print the entire grid
        void printOutput(int);                      // print the output at end of program   
        void printMaxCells();                       // print only the cells that have been visited max number of times
        bool moveRobot();
        int checkValidRobotMove(int, int);
        int startMoving();
        bool checkEachCell();
        bool checkSurroundingSquares();
};

#endif /* GRID_CLASS_H */