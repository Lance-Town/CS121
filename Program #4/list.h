/* list.h
 *
 * Holds the definitions to List class
 */

#ifndef LIST_H
#define LIST_H

class List {
    public:
        List();                         // constructor
        ~List();                        // delete all elements in list
        void print();                   // print entire list
        void appendLast(int, int);      // append to last element of list
        void deleteFront(int&, int&);   // delete first element of list
        bool isEmpty();                 // check if list is empty
    private:
        struct node {
            int row;
            int col;
            node* next;
        };

        node* head;
};

#endif /* LIST_H */