/* main.cpp
 *
 * Program to read and dynamically allocate a 2-D array for a robot to traverse through.
 * Program will take in input such as grid size, starting position for robot, max iterations allowed
 * and more and will output a grid showing the amount of times the robot has visited each cell
 * in the 2-D array, along with some other data such as rows in which the robot visited the max
 * allowable times, and total iteration count plus more. 
 *---------------------------------------------------------------------
 */

// "System" Includes
#include <iostream>
#include <random>
#include <ctime>

// "User-Defined" Includes
#include "gridClass.h"

using namespace std;

int main() {
    // set random seed
    srand(time(nullptr));

    // variable to hold amount of times the robot looped throught the array
    int iterations = 0;

    // create the grid
    Grid grid;

    cout << "\nPrinting Grid before robot starts moving:\n";
    grid.printGrid();

    iterations = grid.startMoving();

    cout << "\nPrinting the grid after robot completion\n";
    grid.printGrid();
    grid.printMaxCells();
    grid.printOutput(iterations);
}