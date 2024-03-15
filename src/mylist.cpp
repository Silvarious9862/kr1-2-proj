#include "mylist.h"


template<typename T>
my::List<T>::List()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
my::List<T>::~List()
{
    clear();
}

template <typename T>
int my::List<T>::getsize()
{
    return size;
}

template <typename T>
void my::List<T>::push_front(T data)
{
    Node<T> *tmp = head;
    head = new Node<T>(data, head);
    if(head->pNext == nullptr) tail = head;
    if(tmp != nullptr) tmp->pPrev = head;
    size++;
}

template <typename T>
void my::List<T>::pop_front()
{
    try
    {
        if (this->empty()) throw EMPTY;
        Node<T> *tmp = head;
        if(head == tail) tail = nullptr;
        head = head->pNext;
        delete tmp;
        size--;
    }
    catch(EMPTY) { std::cout << "List is empty!" << '\n'; }
    
}

template <typename T>
void my::List<T>::push_back(T data)
{
    Node<T> *tmp = tail;
    Node<T> *tmp2 = nullptr;
    tail = new Node<T>(data, tmp2, tail);
    if(tail->pPrev == nullptr) head = tail;
    if(tmp!=nullptr) tmp->pNext = tail;
    size++;
}

template <typename T>
void my::List<T>::pop_back()
{
    try
    {
        if (this->empty()) throw EMPTY;
        Node<T> *tmp = tail;
        if(head == tail) head = nullptr;
        tail = tail->pPrev;
        delete tmp;
        size--;
    }
    catch(EMPTY) { std::cout << "List is empty!" << '\n'; }
}

template <typename T>
void my::List<T>::insert(T data, Iterator &it)
{
    try 
    { 
        Node<T> *current = &(*it); 
        if (current == nullptr) throw OUT_OF_RANGE; 

        Node<T> *before = current->pPrev;
        Node<T> *tmp = new Node<T>(data, current, before);
        current->pPrev = tmp;
        before->pNext = tmp;
        size++; 
    }
    catch(OUT_OF_RANGE)  { std::cout << "Insert position is out of range of list!\n"; }
}

template <typename T>
void my::List<T>::erase(Iterator &it)
{
    try 
    { 
        Node<T> *tmp = &(*it);
        if (tmp == nullptr) throw OUT_OF_RANGE;

        Node<T> *next = tmp->pNext;
        Node<T> *prev = tmp->pPrev;
        if(tmp == head) head = next;
        if(tmp == tail) tail = prev;
        prev->pNext = next;
        next->pPrev = prev;
        delete tmp;
        size--;
    }
    catch(OUT_OF_RANGE)  { std::cout << "Erase position is out of range of list!\n"; }
}

template <typename T>
T& my::List<T>::front()
{
    try
    {
        if (this->empty()) throw EMPTY;
        return head->data;
    }
    catch(EMPTY) { std::cout << "List is empty!" << endl; }
}

template <typename T>
T& my::List<T>::back()
{
    try
    {
        if (this->empty()) throw EMPTY;
        return tail->data;
    }
    catch(EMPTY) { std::cout << "List is empty!" << endl; }
}

template <typename T>
void my::List<T>::clear()
{
    while(size) pop_front();
}

template <typename T>
bool my::List<T>::empty()
{
    if (!this->getsize())  return true;
    return false;
}