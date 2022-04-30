#include "Queue.h"
#include <iostream>

//===============================================//
//                 Constructors                  //
//===============================================//

Queue::Queue(): head(NULL), tail(NULL){}

Queue::~Queue(){
    Node* currNode = head;
    Node* nextNode = NULL;

    //? Removes all nodes in the queue
    while(currNode != NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    head = NULL;
    tail = NULL;
}

//===============================================//
//               Member Functions                //
//===============================================//

// Print out all students in the Queue
void Queue::print() const{
    if(this->isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }

    Node* currNode = head;
    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

// Return true if there are no nodes in the queue
// Return false otherwise
bool Queue::isEmpty() const{
    if(head == NULL && tail == NULL){
        return true;
    }

    return false;
}

// Store the WHLocation found at the head of the queue 
// in the output parameter
void Queue::peekFirst(WHLocation** loc) const{
    if(this->isEmpty()){
        *loc = NULL;
        return;
    }

    *loc = head->data;
}

// Store the WHLocation found at the head of the queue
// in the output parameter and then remove them from
// the queue as long as there's a WHLocation to remove
void Queue::popFirst(WHLocation** loc){
    Node* firstNode = head;

    if(this->isEmpty()){
        *loc = NULL;
        return;
    }
    //? One node left in the queue
    else if(head == tail){
        *loc = head->data;
        delete firstNode;
        head = NULL;
        tail = NULL;
    }
    else{
        *loc = head->data;
        head = head->next;
        delete firstNode;
    }

}

// Add a WHLocation onto the end of the queue
void Queue::addLast(WHLocation* loc){
    Node* newNode = new Node();
    newNode->data = loc;
    newNode->next = NULL;

    if(this->isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        Node* lastNode = tail;
        tail = newNode;
        lastNode->next = tail;
    }
}