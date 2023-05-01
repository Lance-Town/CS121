/* queue.h
 *
 * Holds the Queue class prototypes
 */

#ifndef QUEUE_H
#define QUEUE_H

// User-Defined Includes
#include "list.h"

class Queue {
    public:
        Queue();                    // constructor 
        ~Queue();                   // destructor
        void enqueue(int, int);     // put element to end of queue
        void dequeue(int&, int&);   // pop the front element of the queue
        void print();               // print entire queue
    private:
        List front;
};

#endif /* QUEUE_H */