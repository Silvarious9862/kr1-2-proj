#pragma once
#ifndef _MYLIST
#define _MYLIST

namespace my
{

template<typename T>
class List
{
private:
    template<typename T1>
    class Node
    {
    public:
        T1 data;
        Node *pNext;
        Node *pPrev;

        Node(T1 data = T1(), Node *pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };   
    Node<T> *head;
    Node<T> *tail;
    int size;

public:


    struct Iterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Node<T>;
        using pointer           = Node<T>*;
        using reference         = Node<T>&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->()        { return m_ptr;  }
        Iterator& operator++()      { m_ptr = m_ptr->pNext; return *this; }
        Iterator operator++(int)    { Iterator tmp = *this; *this = tmp->pNext; return tmp; }
        Iterator& operator--()      { m_ptr = m_ptr->pPrev; return *this; }
        Iterator operator--(int)    { Iterator tmp = *this; *this = tmp->pPrev; return tmp; }
        friend bool operator==(const Iterator& a, const Iterator& b) 
            { return a.m_ptr == b.m_ptr; } 
        friend bool operator!=(const Iterator& a, const Iterator& b) 
            { return a.m_ptr != b.m_ptr; } 
    private:  
        pointer m_ptr;        
    };
    
    List();
    ~List();
    int getsize();
    T& front();
    T& back();
    void push_front(T data);
    void pop_front();
    void push_back(T data);
    void pop_back();
    void insert(T data, Iterator &it);
    void erase(Iterator &it);
    void clear();
    bool empty();
    Iterator begin() { return Iterator(head) ;}
    Iterator end() { return Iterator(tail->pNext) ;} 

};
}

#endif