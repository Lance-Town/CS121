/* list.h
 *
 * Holds the linked list prototypes for the stack class to use 
 */
 
#ifndef LIST_H
#define LIST_H

class List {
    public:
        List();                     // constructor
        void appendFront(char);     // add char to front of linked list
        void appendBack(char);      // add char to back of linked list
        char deleteFront();         // delete first node in list
        char getFront();            // get front element in list
        bool isEmpty();             // see if list is empty or not
        void print();               // print entire list
        
    private:
        struct node {
            node* next;
            char info;
        };
        
        node* head;
        int length;
};

#endif