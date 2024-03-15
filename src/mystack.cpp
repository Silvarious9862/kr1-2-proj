#include "mystack.h"

template<typename T>
my::Stack<T>::Stack()
{
    size = 0;
    head = nullptr;
}

template <typename T>
my::Stack<T>::~Stack()
{
    clear();
}

template <typename T>
int my::Stack<T>::getsize()
{
    return size;
}

template <typename T>
void my::Stack<T>::push(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template <typename T>
void my::Stack<T>::pop()
{
    Node<T> *tmp = head;
    head = head->pNext;
    delete tmp;
    size--;
}

template <typename T>
T& my::Stack<T>::top()
{
    return head->data;
}

template <typename T>
void my::Stack<T>::clear()
{
    while(size) pop();
}
