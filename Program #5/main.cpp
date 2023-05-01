/* main.cpp
 *
 * Driver code for the program to take TV Show input from an external text file,
 * and organize that information into a database, implemented with binary 
 * search tree
 *---------------------------------------------------------------------
 */

// System Includes
#include <iostream>
#include <fstream>

// User-Defined Includes
#include "binaryTree.h"
#include "fileToTree.h"

using namespace std;

int main() {
    // declare a binary tree to hold the database
    BinaryTree TVShowDatabase;

    // initalize the binary tree with the input data
    parseFile(TVShowDatabase);

    // // print all titles in the database
    TVShowDatabase.printTitles();

    // print the actors of a given show
    TVShowDatabase.printActors("NCIS");
    TVShowDatabase.printActors("McHale's Navy");
    TVShowDatabase.printActors("The Prisoner");
    TVShowDatabase.printActors("The Office");
    TVShowDatabase.printActors("Futurama");
    TVShowDatabase.printActors("M*A*S*H");
    

    // print the shows a given actor stars in 
    TVShowDatabase.printShowsActorStars("Bill Daily");
    TVShowDatabase.printShowsActorStars("Dana Elcar");
    TVShowDatabase.printShowsActorStars("Andy Griffith");
    TVShowDatabase.printShowsActorStars("Tress MacNeille");
    TVShowDatabase.printShowsActorStars("Michael Dorn");
    TVShowDatabase.printShowsActorStars("Robin Williams");

    // print all shows released during the two decades
    TVShowDatabase.printShowsReleasedBetween(2005, 2015);
    TVShowDatabase.printShowsReleasedBetween(1990, 2000);

    return 0;
}