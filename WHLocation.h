#ifndef WHLOCATION_H
#define WHLOCATION_H

#include "Location.h"

class WHLocation: public Location{

    public:
        //* Constructors
        WHLocation();

        //* Member functions
        virtual int getCapacity() const;
        virtual bool add(const string& product, int amount);
        virtual bool remove(int amount);

    private:
        //* Member variables
        static const char code;
        static const int capacity;
        static int nextId;

};

#endif