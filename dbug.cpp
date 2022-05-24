#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"
#include "Stack.hpp"
#include "fcts.hpp"
#include "pair.hpp"

int main()
{

    // Vector<int> v(5, 5);

    // stack<int> s(v);
    // s.push(8);
    // std::cout << "is empty ? " << s.empty() << " size " << s.size() << " top " << s.top() << std::endl;
    // for (size_t i = 0; i < 6; i++)
    // {
    //     s.pop();
    // }
    // std::cout << "is empty ? " << s.empty() << " size " << s.size() << " top " << s.top() << std::endl;
  
    pair<std::string, int> o("key", 1);
    pair<std::string, int> l(o);
    pair<std::string, int> p;

    p = l;

    if (p == l)
        std::cout << "equal" << "\n";

    p.first = "dd";

    if (p == l)
        std::cout << "equal" << "\n";
    else
        std::cout << "not equal" << "\n";
    
    std::cout << p.first << " " << p.second << std::endl;

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}