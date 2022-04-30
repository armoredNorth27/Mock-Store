#include <iostream>
#include <string>
using namespace std;

#include "List.h"

//===============================================//
//                 Constructors                  //
//===============================================//

List::List(): head(NULL){}

List::~List(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }

}

//===============================================//
//               Member Functions                //
//===============================================//

// Add a product in sorted order by name.
void List::add(Product* product){
    Node* newNode = new Node();
    newNode->data = product;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->getName() < currNode->data->getName()){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}

// Remove a product from the list if it exists and store
// the removed product in the product output parameter.
// Store NULL if product not found.
void List::remove(const string& name, Product** goner){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *goner = NULL;
        return;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *goner = currNode->data;
    delete currNode;
}

// Find the product with the matching name and store it
// in the product output parameter. Store NULL if product
// is not found.
void List::get(const string& name, Product** product){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *product = NULL;
        return;
    }
    //currNode is not NULL
    *product = currNode->data;
}

// Remove all products up to the specified name(inclusive).
void List::removeUpTo(const string& name){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (name < currNode->data->getName()){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode->data;
        delete prevNode;
    }

    head = currNode;
}

// Print out all products in the list.
void List::print() const{
    Node* currNode = head;

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}


//* Newly added member functions

// Return true if the List is empty.
// Return false otherwise.
bool List::isEmpty() const{ return head == NULL; }

// Find and store the product with the matching name in
// the prod output parameter. Store NULL in the output
// parameter if the specified product isn't found
void List::findProduct(const string& name, Product** prod) const{
    Node* currNode = head;
    
    while(currNode != NULL){
        if(currNode->data->getName() == name){
            *prod = currNode->data;
            return;
        }

        currNode = currNode->next;
    }

    *prod = NULL;
}
