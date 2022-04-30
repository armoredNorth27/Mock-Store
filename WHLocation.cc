#include "WHLocation.h"
#include "defs.h"

//============================================//
//               Class Variables              //
//============================================//

const char WHLocation::code = 'B';
const int WHLocation::capacity = WHLOC_CAPACITY;
int WHLocation::nextId = 0;

//============================================//
//                Constructors                //
//============================================//

WHLocation::WHLocation(): Location(code, ++nextId){}

//============================================//
//               Member Functions             //
//============================================//

// Return the capacity of the warehouse location
int WHLocation::getCapacity() const{ return capacity; }

// Add the product with the specified amount only
// if the WHLocation doesn't have any products added
// to it before and it has enough room. Then return true
// Return false otherwise
bool WHLocation::add(const string& product, int amount){

    if(this->isAvailable() && amount <= capacity){
        this->product = product;
        this->quantity += amount;
        return true;
    }

    return false;
}

// Remove the specified amount from the WHLocation.
// If the quantity reaches 0, set its product type
// to NONE.
// Return true if amount was removed
// Return false otherwise
bool WHLocation::remove(int amount){
    if(amount > this->quantity || amount < 0){
        return false;
    }

    this->quantity -= amount;

    // Reset product when warehouse is empty
    if(this->quantity == 0){
        this->product = NONE;
    }

    return true;
}