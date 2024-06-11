#include <cstddef>

#ifndef LIST_H
#define LIST_H

template<typename T>

struct List
{
    //adds an item to the end of the list
    virtual void add(const T&) = 0;

    //inserts an item at a given position and throws exception
    virtual void insert(const T&, const size_t) = 0;

    //removes first item in the list
    virtual void remove() = 0;

    //removes an item from a given position
    virtual void remove(const size_t) = 0;

    //true if empty, false otherwise
    virtual bool empty() const = 0;

    //returns number of elements in the list
    virtual size_t size() const = 0;

    //safely empties the list
    virtual void clear() = 0;

    //gets an item at a given position in the list
    virtual T get(const size_t) const = 0;

    //checks for containment/membership; returns the first position of the item if it exists; -1 if it doesn't
    virtual size_t contains(const T&) const = 0;

};



#endif /* LIST_H */
