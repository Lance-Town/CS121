/* mazeTraversal.h
 *
 * Holds the prototypes to the functions that will be used to traverse the maze.
 */

#ifndef MAZE_TRAVERSAL_H
#define MAZE_TRAVERSAL_H

// System Includes
#include <fstream>

// User-Defined Includes
#include "queue.h"

using namespace std;

// get the next maze in the text file, and return a 2D character array containing the maze
char** getMaze(ifstream&, int&, int&);

// print out 2D array
void printArr(char**&, int, int);

// find starting position
void findStart(char**&, int, int, int&, int&);

// check surrounding cubes, adding valid ones to the queue
bool addSurroundingPositions(char**&, Queue&, int, int, int, int);

// pop off queue and go to next position
void getNextPosition(Queue&, int&, int&);

// prints the introduction to the maze traversal algorithm
void printPrologue();

#endif /* MAZE_TRAVERSAL_H */