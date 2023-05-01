/* queue.cpp
 *
 * Holds the definitions to Queue class and methods
 */

// System Includes
#include <iostream>

// User-Defined Includes
#include "queue.h"

using namespace std;

Queue::Queue() {
    // handled by List class
}

Queue::~Queue() {
    // handled by List classs
}

// enqueue element to end of queue
void Queue::enqueue(int row, int col) {
    front.appendLast(row, col);
    return;
}

// pop the front element of the queue and return it
void Queue::dequeue(int& row, int& col) {
    
    if (front.isEmpty()) {
        cout << "Queue::dequeue: Queue is empty\n";
        
        // set row and col to 0
        row = 0;
        col = 0;
        return;
    }
    
    front.deleteFront(row, col);
    return;
}

// print the entire queue
void Queue::print() {
    if (front.isEmpty()) {
        cout << "Queue::print: Queue is Empty\n";
        return;
    }
    front.print();
    return;
}