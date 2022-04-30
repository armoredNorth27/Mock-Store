#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location{

    public:
        //* Constructors
        Location(char charCode, int number);

        //* Member functions
        // Getters
        string getId() const;
        string getProduct() const;
        int getQuantity() const;

        bool isEmpty() const;
        bool isAvailable() const;
        void print() const;

        // Virtual + Pure Virtual
        virtual int getCapacity() const = 0;
        virtual bool add(const string& name, int quantity) = 0;
        virtual bool remove(int quantity) = 0;

    protected:
        //* Member variables
        string id;
        string product;
        int quantity;
        static const string NONE;       

};

#endif