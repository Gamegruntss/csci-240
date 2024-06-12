#include "deque_interface.h"

#ifndef ARRAY_DEQUE_H
#define ARRAY_DEQUE_H

#define INITIAL_SIZE 128

template <typename T>

class ArrayDeque : public Deque<T>
{
    public: 
    ArrayDeque() : count{0}, array{new T[INITIAL_SIZE]}, currentSize{INITIAL_SIZE} { }
    ~ArrayDeque () { delete[] array; }

    //add an item to the back of the deque
    void enqueueBack(const T& item)
    {
        if(count >= currentSize) resize();
        array[count++] = item;
    }
    
    //add item to the front of the deque
    void enqueueFront(const T& item)
    {
        for (size_t i = count; i > 0; --i)
            array[i + 1] = array[i];
        array[0] = item;
        ++count;
    }
    
    //removes item from the front
    void dequeueFront()
    {
        for (size_t i = 0; i < count - 1; ++i)
            array[i] = array[i + 1];
        --count;
         
    }
    
    //removes item from the back
    void dequeueBack() { --count; }
    
    //returns the front of the deque, does not remove
    T front() const { return array[0]; }
    
    //returns the back fo the deque, does not remove
    T back() const { return array[count - 1]; }
    
    //returns true if empty, false otherwise
    bool empty() const { return count == 0; }

    private:
    
    T* array;
    size_t count;
    size_t currentSize;

    void resize()
    {
        size_t newSize{currentSize << 1};
        T newArray[newSize];

        for (size_t i = 0; i < currentSize; ++i)
            newArray[i] = array[i];
        
        delete[] array;
        array = newArray;
        currentSize = newSize;
    }

};

#endif /* ARRAY_DEQUE_H */
