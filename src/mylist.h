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

    class Iterator
    {
    public:
        
    };

    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    List();
    ~List();
    int getsize();
    T& front();
    T& back();
    void push_front(T data);
    void pop_front();
    void push_back(T data);
    void pop_back(T data);
    void insert(T data);
    void erase();
    void clear();
    Iterator begin();
    Iterator end();
    bool empty();

};
}

#endif