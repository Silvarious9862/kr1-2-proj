#include "mystack.h"

template<typename T>
Stack<T>::Stack()
{
    size = 0;
    head = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

template <typename T>
int Stack<T>::getSize()
{
    return size;
}

template <typename T>
void Stack<T>::push(T data)
{
    head = new Node(data, head);
    size++;
}

template <typename T>
void Stack<T>::pop()
{
    Node<T> *tmp = head;
    head = head->pNext;
    delete tmp;
    size--;
}

template <typename T>
T& Stack<T>::top()
{
    return head->data;
}

template <typename T>
void Stack<T>::clear()
{
    while(size) pop();
}
