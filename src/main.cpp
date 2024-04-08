#include <iostream>
#include "mystack.cpp"
#include "mylist.cpp"
#include <time.h>
#include <list>



int main()
{
    my::Stack<int> stack;
    
    std::cout << "start\n";
    stack.push(5);
    std::cout << "push 5\n";
    stack.push(7);
    std::cout << "push 7\n";
    stack.push(10);
    std::cout << "push 10\n";
    std::cout << "top:" << stack.top() << "\n";
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    system("pause");

    my::List<int> list;
    if(list.empty()) std::cout << "empty list\n";
    else std::cout << "NONempty list\n";
    list.push_back(13);
    list.push_back(15);
    list.push_back(17);
    list.push_back(20);

    for (auto i : list) std::cout << i.data << std::endl;

    my::List<int>::Iterator it(list.begin()); 
    ++it; ++it;
    list.insert(55, it);
    std::cout << "----\n";
    for (auto i : list) std::cout << i.data << std::endl;
    --it; --it;
    list.erase(it);
    std::cout << "----\n";


    for (auto i : list) std::cout << i.data << std::endl;

    return 0;
}