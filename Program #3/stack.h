/* stack.h
 *
 * Prototype of stack class implemented as a list
 */ 

#ifndef STACK_H
#define STACK_H

#include "list.h"

class Stack {
    public:
        Stack();
        void push(char);    // add element to top
        char pop();         // remove top element
        bool isEmpty();     // check if stack is empty
        void print();       // print stack from top to bottom
        char peek();        // return the top element of the stack 

    private:
        List top;           // top is an instance of a List class
};

#endif /* STACK_H */