/* fileToTree.h
 *
 * Holds the function prototypes to unpacking the data from the input file and 
 * putting that data into the binary search tree
 *  
 *---------------------------------------------------------------------
 */

#ifndef FILE_TO_TREE
#define FILE_TO_TREE

// System Includes
#include <string>

// User-Defined Includes
#include "binaryTree.h"

using namespace std;

// read the input file and parse the data, storing each
// TVShow in the binary tree databsae
void parseFile(BinaryTree&);

// gets the title of the TV show
void getTitle(string&, string&);

// get the years that a TV show aired from
void getYearsAired(string, string&, string&);

// get the index position of a char in a given string
int indexOf(string, char);

// get the substring based on index locations of original
// string
void getSubString(string, int, int, string&);

// removes every blank space in ENTIRE string
string removeBlankSpace(string);

// removes all blank space AFTER last char
string removeEndBlankSpace(string);

// Returns which string comes first in the alphabet
int alphabeticalCompare(string, string);

// returns true if an actor is in the array of actors or not
bool actorInShow(string[], string);


#endif /* FILE_TO_TREE */