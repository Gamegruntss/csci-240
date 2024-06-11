#include <stdexcept>
#include "list_interface.h"

#ifndef LINKED_LIST_ADT_H
#define LINKED_LIST_ADT_H

template<typename T>

class LinkedList : public List<T>
{
    public:
    
    LinkedList() : head{nullptr}, tail{nullptr} { }
    ~LinkedList() { clear(); }

    void add(const T& item) override
    {
        tail = (empty() ? head : tail->next) = new Node{item, nullptr};
        ++count;
    }

    void insert(const T& item, const size_t pos)
    {
        if(pos < 1 || pos > count) throw std::range_error("Position is out of bounds.");
        Node* it{head};
        for (size_t i = 1; i < pos; ++i)
            it = it->next;
        it->next = new Node{item,it->next};
        ++count;
        
    }

    void remove() override
    {
        Node* tmp{head};
        head = head->next;
        delete tmp;
        if(empty()) tail = nullptr;
        --count;
    }

    void remove(const size_t pos) override
    {
        Node* it{head};
        for (size_t i = 1; i < pos - 1; ++i)
            it = it->next;
        Node* tmp{it->next};
        it->next = it->next->next;
        delete tmp;
        --count;
    }

    bool empty() const override { return head == nullptr; }

    size_t size() const override { return count; }

    void clear() override { while(!empty()) {remove();} }

    T get(const size_t pos) const override
    {
        Node* it{head};
        for (size_t i = 1; i <= pos; ++i)
            it = it->next;
        return it->item;
    }

    
    size_t contains(const T& item) const override
    {
        Node* it{head};
        for(size_t i = 1; i <= count; ++i)
        {
            if(it->item == item) return i;
            it = it->next;
        }

        return -1;
    }

    private:

    int count{0};

    struct Node
    {
        T item;
        Node* next;
    };

    Node* head; //front of the list
    Node* tail; //back of the list

};

#endif /* LINKED_LIST_ADT_H */
