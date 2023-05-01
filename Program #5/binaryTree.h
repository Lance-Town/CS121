/* binaryTree.h
 *
 * Holds the class prototype for the BinaryTree class
 *---------------------------------------------------------------------
 */

#ifndef BINARY_TREE
#define BINARY_TREE

// System Includes
#include <string>

using namespace std;

// set the maximum size of the actor array
const int MAX_ACTOR_COUNT = 25;

// binary tree class
class BinaryTree {
    private:
        // binary tree node struct
        struct BinaryTreeNode {
            BinaryTreeNode* left;
            BinaryTreeNode* right;

            // information that database will store
            string title;
            string yearStart;
            string yearEnd;
            string genre;
            string url;
            string actors[MAX_ACTOR_COUNT];
        };

        // typedef to associate a new name for the tree nodes
        typedef BinaryTreeNode node;

        // root of tree
        node* root;

        // recursively print the titles in the tree with an 
        // in-order traversal
        int printTitles(node*& t);

        // insert new data into the tree
        void insertData(node*&, string, string[], int, string, string, string, string);

        // recursively print all actors in a specific show
        int printActors(node*&, string);

        // recursively print all of the shows an actor is involved with
        int printShowsActorStars(node*&, string);  

        // recursively print all shows released in a specific date range
        void printShowsReleasedBetween(node*&, int, int);

        // recursively delete the entire tree. 
        void deleteTree(node*& t);
    public:
        // constructor
        BinaryTree();
        
        // destructor
        ~BinaryTree();

        // print the TV Show titles in an in-order traversal
        void printTitles();

        // add all input information to a node in the tree
        void insertData(string, string[], int, string, string, string, string); 

        // print all actors in a specific TV Show
        void printActors(string);

        // print all of the shows an actor is involved with
        void printShowsActorStars(string);

        // print all shows that had at least one season aired between the
        // two specified dates
        void printShowsReleasedBetween(int, int);
};

#endif /* BINARY_TREE */