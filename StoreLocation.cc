#include "StoreLocation.h"
#include "defs.h"

//============================================//
//               Class Variables              //
//============================================//

const char StoreLocation::code = 'A';
const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 0;

//============================================//
//                Constructors                //
//============================================//

StoreLocation::StoreLocation(): Location(code, ++nextId){}

//============================================//
//               Member Functions             //
//============================================//

// Set the product of the StoreLocation to the input parameter
void StoreLocation::setProduct(const string& product){ this->product = product; }

// Return the amount of free space left in the StoreLocation
int StoreLocation::getFreeSpace() const{ return capacity - quantity; }

// Return the capacity of the StoreLocation
int StoreLocation::getCapacity() const{ return capacity; }

// Adds the amount of the specified product if possible
// If the product is empty and amount <= capcity, product of this
// location is set equal to the product type being passed in
// Return false if location has different product or cannot fit specified amount
// Return true otherwise
bool StoreLocation::add(const string& name, int amount){
    // First time we add to the store, so we have 
    // the full capacity of the store available
    if(this->product == NONE && amount <= capacity){
        this->product = name;
        this->quantity += amount;
    }
    // If we're adding a different product or we're adding more products
    // than what we have room for, then don't do anything and exit method
    else if(this->product != name || amount > this->getFreeSpace()){
        return false;
    }
    else{
        this->quantity += amount;
    }
    
    return true;
}

// Attempts to remove the specified amount.
// Return false If the amount to remove is greater than the 
// amount of items in the store and don't do anything
// Return true otherwise
bool StoreLocation::remove(int amount){
    if(amount > this->quantity || amount < 0){
        return false;
    }

    this->quantity -= amount;
    return true;
}