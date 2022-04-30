#include <iostream>
#include "Location.h"

//============================================//
//               Class Variables              //
//============================================//

const string Location::NONE = "Empty";

//============================================//
//                Constructors                //
//============================================//

Location::Location(char charCode, int number): product(NONE), quantity(0), id(charCode + to_string(number)){}

//============================================//
//               Member Functions             //
//============================================//

// Return the label of the location
string Location::getId() const{ return id; }

// Return the product type stored in the location
string Location::getProduct() const{ return product; }

// Return the number products in the location
int Location::getQuantity() const{ return quantity; }

// Return true if the location has no products
bool Location::isEmpty() const{ return quantity == 0; }

// Return true if there is no product set for the store
bool Location::isAvailable() const{ return product == NONE; }

// Prints out meta data of a general location object
void Location::print() const{
    cout << "Location: " << id << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Product: " << product << endl;
    cout << endl;
}