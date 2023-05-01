/* list.cpp
 *
 * Holds the definitions to List class and methods
 */

// System Includes
#include <iostream>

// User-Defined Includes
#include "list.h"

using namespace std;

// constructor
List::List() {
    head = NULL;
}

// Deletes all elements from list
List::~List() {
    if (head == NULL) {
        // cout << "List::~List: List is empty\n";
        return;
    }
    node* curr = head;
    node* del = NULL;

    while (curr != NULL) {
        del = curr;
        // cout << "Deleting " << del->info << '\n';
        curr = curr->next;
        delete del;
    }

    delete curr;
    head = NULL;
    return;
}

// Prints the entire list
void List::print() {
    if (head == NULL) {
        cout << "List::print: List is empty\n";
        return;
    }

    node* curr = head;

    while (curr != NULL) {
        cout << "(" << curr->row << ", " << curr->col << ")\n";
        curr = curr->next;
    }

    return;
}

// Appends element to the end of the list
void List::appendLast(int row, int col) {
    node* n = new node;
    n->row = row;
    n->col = col;
    n->next = NULL;

    if (head == NULL) {
        n->next = head;
        head = n;
    } else {
        node* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = n;
    }

    return;
}

// Deletes element from front of list and stores result in the arguments
void List::deleteFront(int& row, int& col) {
    if (head == NULL) {
        cout << "List::deleteFront: List is empty\n";
        row = 0;
        col = 0;
        return;
    }

    node* curr = head;
    head = head->next;

    // copy contents into row and col
    row = curr->row;
    col = curr->col;

    curr = NULL;
    delete curr;
    return;
}

// check if list is empty
bool List::isEmpty() {
    return (head == NULL);
}