
#include "Store.h"

//===============================================//
//                 Constructors                  //
//===============================================//

Store::Store(const string& name): name(name){
    products = new List();
}

Store::~Store(){
    delete products;
}

//===============================================//
//               Member Functions                //
//===============================================//

// Stores the first available StoreLocation in the input parameter
void Store::findAvailableSLoc(StoreLocation** sloc){
    for(int i=0; i<SLOCS; i++){
        if(SLarray[i].isAvailable()){
            *sloc = &SLarray[i];
            break;
        }
    }
}

// Stores the first available WHLocation in the input parameter
void Store::findAvailableWHLoc(WHLocation** wloc){
    for(int i=0; i<WHLOCS; i++){
        if(WHLarray[i].isAvailable()){
            *wloc = &WHLarray[i];
            break;
        }
    }
}

// Print all StoreLocation objects in the store
void Store::printStoreStock() const{
    for(int i=0; i<SLOCS; i++){
        if(SLarray[i].getProduct() != "Empty"){
            SLarray[i].print();
        }
    }
}

// Print all WHLocation objects in the store
void Store::printWareHouseStock() const{
    for(int i=0; i<WHLOCS; i++){
        if(!WHLarray[i].isEmpty()){
            WHLarray[i].print();
        }
    }
}

// Print all products in the products list
void Store::printProducts() const{ products->print(); }

// Finds the product with the given name and stores
// it in the input parameter
void Store::findProduct(const string& name, Product** prod){
    products->findProduct(name, prod);
}

// First search for the product. If there
// is no such product, make a new Product 
// object and add it to the List of products. 
// Then find available WHLocations to store 
// all of the product
void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);
    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();
}

// Remove amount of the product from all locations
// starting with the StoreLocation. Return the 
// amount of the order that you could not fill.
void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}

// Print out the name of the store
void Store::print() const{
    cout<<"Store: "<<name<<endl;
}