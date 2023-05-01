/* list.cpp
 *
 * Holds the method definitions for the linked list class
 */ 

// System Includes
#include <iostream>

// User-Defined Includes
#include "list.h"

using namespace std;

List::List() {
    head = NULL;
    return;
}

// append character to front of list
void List::appendFront(char c) {
    // allocate 
    node* n = new node;

    // initialize
    n->info = c;
    n->next = NULL;

    // place
    if (head == NULL) {
        head = n;
    } else  {
        n->next = head;
        head = n;
    }

    return;
}

// append character to back of list
void List::appendBack(char c) {
    // allocate
    node* n = new node;

    // initialize
    n->info = c;
    n->next = NULL;

    // place
    if (head == NULL) {
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

// delete character from front of list
char List::deleteFront() {
    char c = 'Z';

    // if stack empty, return space character
    if (head == NULL) {
        // stack is empty
        // cout << "Stack is empty\n";
        return c;
    }

    node* del = head;

    head = head->next;
    c = del->info;

    del->next = NULL;
    del->info = 'Z';
    del = NULL;

    delete del;
    return c;
}

// get the front element of the list and return it
char List::getFront() {
    if (head == NULL) {
        return 'Z';
    } else {
        return head->info;
    }
}

// return if the list is empty or not
bool List::isEmpty() {
    return (head == NULL);
}

// print the entire list from front to back
void List::print() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* n = head;

    while (n != NULL) {
        cout << n->info << '\n';
        n = n->next;
    }

    return;
}