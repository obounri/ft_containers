#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"
#include "Stack.hpp"

int main()
{

    Vector<int> v(5, 5);

    stack<int> s(v);
    s.push(8);
    std::cout << "is empty ? " << s.empty() << " size " << s.size() << " top " << s.top() << std::endl;
    for (size_t i = 0; i < 6; i++)
    {
        s.pop();
    }
    std::cout << "is empty ? " << s.empty() << " size " << s.size() << " top " << s.top() << std::endl;
    

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}