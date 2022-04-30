#ifndef QUEUE_H
#define QUEUE_H

#include "WHLocation.h"

class Queue{

    class Node{
        public:
            WHLocation* data;
            Node* next;
    };

    public:
        //* Constructors & Destructors
        Queue();
        ~Queue();

        //* Member functions
        void print() const;
        bool isEmpty() const;
        void peekFirst(WHLocation**) const;
        void popFirst(WHLocation**);
        void addLast(WHLocation*);

    private:
        //* Member variables
        Node* head;
        Node* tail;

};

#endif