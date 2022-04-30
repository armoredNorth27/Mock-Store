#ifndef STORELOCATION_H
#define STORELOCATION_H

#include "Location.h"

class StoreLocation: public Location{

    public:
        //* Constructors
        StoreLocation();

        //* Member functions
        void setProduct(const string& product);
        int getFreeSpace() const;
        virtual int getCapacity() const;
        virtual bool add(const string& name, int amount);
        virtual bool remove(int amount);

    private:
        //* Member variables
        static const char code;
        static const int capacity;
        static int nextId;

};

#endif