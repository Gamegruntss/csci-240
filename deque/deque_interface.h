#include <cstddef>

#ifndef DEQUE_INTERFACE_H
#define DEQUE_INTERFACE_H

template <typename T>
struct Deque
{
    //add an item to the back of the deque
    virtual void enqueueBack(const T&) = 0;
    
    //add item to the front of the deque
    virtual void enqueueFront(const T&) = 0;
    
    //removes item from the front
    virtual void dequeueFront() = 0;
    
    //removes item from the back
    virtual void dequeueBack() = 0;
    
    //returns the front of the deque, does not remove
    virtual T front() const = 0;
    
    //returns the back fo the deque, does not remove
    virtual T back() const = 0;
    
    //returns true if empty, false otherwise
    virtual bool empty() const = 0;
    
};

#endif /* DEQUE_INTERFACE_H */
