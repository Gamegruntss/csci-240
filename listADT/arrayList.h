#include "list_interface.h"
#include <stdexcept>
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define DEFAULT_SIZE 128

template <typename T>

class ArrayList : public List<T>
{
    public:

    ArrayList() : array{new T[DEFAULT_SIZE]}, count{}, currentSize{DEFAULT_SIZE} { }
    ~ArrayList() { delete[] array; }

    void add(const T& item) override
    {
        if(count >= currentSize) resize();
        array[count++] = item;
    }

    void insert(const T& item, const size_t pos)
    {
        size_t posIdx{pos - 1};
        T tmp;

        if(pos < 1 || pos > count) throw std::range_error("Position is out of bounds.");
        if(count >= currentSize) resize();
        
        for(int i = count - 1; i >= posIdx && i > 0; --i)
            array[i + 1] = array[i];
        array[posIdx] = item;
        ++count;            
    }

    void remove() override { remove(1); }

    void remove(const size_t pos) override
    {
        size_t posIdx{pos - 1};
        for (size_t i = posIdx; i < count - 1; ++i)
            array[i] = array[i + 1];
        --count;
    }

    bool empty() const override { return count == 0; }

    size_t size() const override { return count; }

    void clear() override { while(!empty()) {remove();} }

    T get(const size_t pos) const override { return array[pos - 1]; }

    size_t contains(const T& item) const override
    {
        for (size_t i = 0; i < count; ++i)
            if(array[i] == item) return (i + 1);


        return -1;
    }

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

#endif /* ARRAYLIST_H */
