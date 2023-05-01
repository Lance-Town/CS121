/* stack.cpp
 *
 * Method definitions from stack class
 */ 

// System Includes
#include <iostream>

// User-Defined Includes
#include "stack.h"

using namespace std;

// Stack class constructor
Stack::Stack() {
    // do nothing as List class already handles what is needed
}

// push character to top of stack
void Stack::push(char c) {
    top.appendFront(c);
    return;
}

// pop off top of stack and return the char
char Stack::pop() {
    char c = top.deleteFront();
    return c;
}

// check whether stack is empty or not
bool Stack::isEmpty() {
    return top.isEmpty();
}

// print out the entire stack from top down
void Stack::print() {
    top.print();
    return;
}

// return top character value of the stack
char Stack::peek() {
    char c = top.getFront();
    return c;
}
