Contents:

    README.txt
        Contains information on the assignment

    Makefile
        Compiles all .cc files and produces an executable

    main.cc
        Starts the code in Control.cc in order to test
        the code made for the assignment

    defs.h
        Contains a bunch of constants that are used to
        help define array sizes

    Control.cc
        Defines all the functions in Control.h
    Control.h
        Has functions that test the code of the assignment

    View.cc
        Defines all the functions in View.h
    View.h
        Code a menu in the terminal that the user
        can look at in order to know how to interact
        with the assignment code

    Store.cc
        Defines all the functions in Store.h
    Store.h
        Provides an interface for interacting with
        the inventory system created for the assignment

    StoreLocation.cc
        Defines all the functions in StoreLocation.h
    StoreLocation.h
        Concrete implementation for in-store product
        locations

    WHLocation.cc
        Defines all the functions in WHLocation.h
    WHLocation.h
        Concrete implementation for the warehouse
        product locations

    Location.cc
        Defines all the functions in Location.h
    Location.h
        A virtual base class for the StoreLocation
        and WHLocation classes(Contains common code
        that both those classes use via inheritance)

    List.cc
        Defines all the functions in List.h
    List.h
        Contains methods that define a LinkedList
        implementation. This is meant to store a
        list of Products that can arbitrarily grow

    Queue.cc
        Defines all the functions in Queue.h
    Queue.h
        Implements a first-in-first-out(FIFO) data
        structure for storing WHLocations. Functions
        are implemented in such a way that it ensures
        that we use older stock first
