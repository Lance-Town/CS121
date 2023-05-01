/* binaryTree.cpp
 *
 * Holds the definition of the BinaryTree class
 *
 *---------------------------------------------------------------------
 */

// System Includes
#include <iostream>
#include <string>

// User-Defined Includes
#include "binaryTree.h"
#include "fileToTree.h"

using namespace std;

// Constructor for BinaryTree
BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    deleteTree(root);
    root = NULL;
}

// PRIVATE : Print the tree with an inorder traversal
int BinaryTree::printTitles(node*& t) {
    static int i = 1;
    if (t != NULL) {
        int left = printTitles(t->left);
        cout << i++ << ": " <<  t->title << '\n';
        int right = printTitles(t->right);
        return 1 + left + right;
    }
    return 0;
}

// PUBLIC : Print the tree
void BinaryTree::printTitles() {
    cout << "Printing All TV Shows in Database:\n";
    cout << "----------------------------------\n";
    int numTitles = printTitles(root);

    if (numTitles == 0) 
        cout << "ERROR: There are no shows in the database\n";
    else
        cout << "Total Shows in Database: " << numTitles << '\n';
    cout << "----------------------------------\n\n";
    return;
}

// PRIVATE: Insert data into the database
void BinaryTree::insertData(node*& t, string title, string actors[], 
                            int SIZE, string yearStart,string yearEnd, 
                            string genre, string url)
{
    if (t != NULL) {
        int checkVal = alphabeticalCompare(title, t->title);
        if (checkVal == 0) {
            // title < t->title ; so go to the left
            insertData(t->left, title, actors, SIZE, yearStart, yearEnd, genre, url);
        } else if (checkVal == 1) {
            // title > t->title ; so go to the right
            insertData(t->right, title, actors, SIZE, yearStart, yearEnd, genre, url);
        } else {
            // title == t->title ; this is a duplicate, do nothing
        }
    } else {
        // insert the node at this point in the tree
        // allocate
        node* p = new node;

        // initialize
        // cout << "INSERT_NODE::TITLE: |" << title << "|\n";
        p->title = title;
        // cout << "INSERT_NODE::p->TITLE: |" << p->title << "|\n";
        for (int i = 0; i < SIZE; i++) {
            p->actors[i] = actors[i];
        }
        p->yearStart = yearStart;
        p->yearEnd = yearEnd;
        p->genre = genre;
        p->url = url;

        // place
        t = p;
    }

    return;
}

// PUBLIC: Insert data into the database
void BinaryTree::insertData(string title, string actors[], int SIZE, 
                            string yearStart, string yearEnd, string genre, 
                            string url)
{
    return insertData(root, title, actors, SIZE, yearStart, yearEnd, genre, url);
}

// PRIVATE: Print all actors in a specific show
int BinaryTree::printActors(node*& t, string show) {
    // nothing at node, return
    if (t == NULL)
        return 0;

    // check if we have found the show yet or not
    if (show == t->title) {
        // found the correct node
        cout << "Printing Actors in " << show << '\n';

        // loop through and print each actor
        for (int i = 0; i < MAX_ACTOR_COUNT; i++) {
            if (t->actors[i] == "")
                break;
            
            cout << "Actor: " << t->actors[i] << '\n';
        }

        // return true to show we found the node
        return 1;
    } 
    else if (alphabeticalCompare(show, t->title)) 
        return 0 + printActors(t->right, show);
    else 
        return 0 + printActors(t->left, show);

    // no show was found in the database, so return 0
    return 0;
}

// PUBLIC: Print all actors in a specific show
void BinaryTree::printActors (string show) {
    cout << "Printing All Actors Who Star in: " << show << '\n';
    cout << "----------------------------------\n";
    if (printActors(root, show) == 0)
        cout << "Error: " << show << " not in database.\n";
    cout << "----------------------------------\n\n";
    return;
}

// PRIVATE: Print all shows an actor stars in
int BinaryTree::printShowsActorStars(node*& t, string actor) {
    if (t == NULL)
        return 0;

    // set a return value that signifies how many shows the actor is in
    int retVal = 0;
    if (actorInShow(t->actors, actor)) {
        // actor is in show
        cout << "Stars In: " << t->title << '\n';
        retVal++;
    }

    // check the left and the right
    return retVal + printShowsActorStars(t->left, actor) + printShowsActorStars(t->right, actor);
}

// PUBLIC: Print all shows an actor stars in
void BinaryTree::printShowsActorStars(string actor) {
    cout << "Printing All Shows That " << actor << " Stars In...\n";
    cout << "----------------------------------\n";
    
    // if 0 is returned, then the actor was not found to star in any shows
    if (printShowsActorStars(root, actor) == 0) 
        cout << "Error: " << actor <<  " stars in 0 shows\n";

    cout << "----------------------------------\n\n";
    return;
}   

// PRIVATE: Prints all shows released between the two specified dates (inclusive)
void BinaryTree::printShowsReleasedBetween(node*& t, int yearStart, int yearEnd) {
    if (t == NULL)
        return;

    // year start and end of the tree value at the current node
    int yStartTreeVal = stoi(t->yearStart);
    int yEndTreeVal = stoi(t->yearEnd);

    bool airsWithinRange = false;

    // check if in range from the arguments given
    if (yearStart <= yStartTreeVal && yStartTreeVal <= yearEnd) {
        // the show first season aired at or after the check value
        airsWithinRange = true;
    } else if (yearStart <= yEndTreeVal && yEndTreeVal <= yearEnd) {
        // the show last season aired before at at the check value
        airsWithinRange = true;
    } else if (yStartTreeVal <= yearStart && yearStart <= yEndTreeVal) {
        // to check if the show first aired before the check value,
        // but continued to air in the range we are checking
        airsWithinRange = true;
    } else if (yStartTreeVal <= yearEnd && yearEnd <= yEndTreeVal) {
        // also to check if the show first aired before the check value,
        // but continued to air in the range we are checking
        airsWithinRange = true;
    }

    // if the show aired within the range, output the show
    if (airsWithinRange){
        cout << "Show: " << t->title << "\nAired: (" << yStartTreeVal << "-" << yEndTreeVal << ")\n\n";
    }

    // check left and right nodes
    printShowsReleasedBetween(t->left, yearStart, yearEnd);
    printShowsReleasedBetween(t->right, yearStart, yearEnd);

    return;
}

// PUBLIC: Prints all shows released between the two specified dates (inclusive)
void BinaryTree::printShowsReleasedBetween(int yearStart, int yearEnd) {
    cout << "Printing All Shows Released Between: (" << yearStart << "-" << yearEnd << ")\n";
    cout << "----------------------------------\n";
    printShowsReleasedBetween(root, yearStart, yearEnd);
    cout << "----------------------------------\n\n";
    return;
}

// PRIVATE: Deletes the entire binary tree
void BinaryTree::deleteTree(node*& t) {
    if (t == NULL)
        return;
    
    deleteTree(t->left);
    deleteTree(t->right);

    t->left = NULL;
    t->right = NULL;
    delete t;
    t = NULL;
}