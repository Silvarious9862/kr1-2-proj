#include <iostream>
#include "mystack.cpp"
#include <time.h>



int main()
{
    my::Stack<int> st;
    int sizeN;
    srand(time(NULL));
    std::cout << "How much push? : ";
    std::cin >> sizeN;
    for(int i = 0; i<sizeN;i++)
        st.push(rand()%100);
        
 
    while(st.getsize()) 
    {
        std::cout << "Top is: " << st.top() << std::endl;
        st.pop();
    }

    std::cout << "Exit with code 0";
    return 0;
}