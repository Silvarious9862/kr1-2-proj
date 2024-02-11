#pragma once


template<typename T>
class Stack
{
private:
    template<typename T1>
    class Node
    {
    public:
        T1 data;
        Node *pNext;

        Node(T1 data = T1(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }

    };    
    Node<T> *head;
    int size;

public:
    Stack();
    ~Stack();
    int getSize();
    void push(T data);
    void pop();
    T& top();
    void clear();
};