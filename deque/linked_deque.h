#include "deque_interface.h"
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

template <typename T>
class LinkedDeque : public Deque<T>
{
    public:

    LinkedDeque() : head{nullptr}, tail{nullptr}  { }
    ~LinkedDeque() { while(!empty()) {dequeueBack();} }
    
    void enqueueBack(const T& item)
    {
        tail = (head == nullptr ? head : tail->next) = new Node{item, tail, nullptr};
    }
    
    void enqueueFront(const T& item)
    {
        if(head == nullptr)
        {
            enqueueBack(item);
            return;
        }

        head = head->previous = new Node{item, nullptr, head};
    }
    
    void dequeueFront()
    {
        Node* tmp{head};
        head = tmp->next;
        head->previous = nullptr;
        delete tmp;        
    }
    
    void dequeueBack()
    {
        Node* tmp{tail};
        tail = tail->previous;
        tail->next = nullptr;
        delete tmp;
    }
    
    T front() const { return head->item; }
    
    T back() const { return tail->item; }
    
    bool empty() const { return head == nullptr; }
    
    private:

    struct Node
    {
        T item;
        Node* previous;
        Node* next;  
    };

    Node* head;
    Node* tail;

};


#endif /* LINKED_DEQUE_H */
