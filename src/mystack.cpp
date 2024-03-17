#include "mystack.h"
#include <iostream>
#define EMPTY -1

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
    try{
        if (size == 0) throw EMPTY;
        Node<T> *tmp = head;
        head = head->pNext;
        delete tmp;
        size--;
    }
    catch(int a)
    {
        std::cout << "Stack is empty!" << std::endl;
    }
}

template <typename T>
T& my::Stack<T>::top()
{
    try
    {
        if (size == 0) throw EMPTY;
        return head->data;
    }
    catch(int a)
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    
}

template <typename T>
void my::Stack<T>::clear()
{
    while(size) pop();
}
