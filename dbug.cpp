#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"

int main()
{
    std::vector<int>    v2(10, 3);
    v2.resize(15, 4);
    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    Vector<int>    v3(10, 3);
    v3.resize(15, 4);
    std::cout << v3.size() << " " << v3.capacity() << std::endl;
    // std::cout << l.front() << " " << l.back() << std::endl;
    for (size_t i = 0; i < v2.size(); i++)
    {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < v3.size(); i++)
    {
        std::cout << v3[i] << " ";
    }
    

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}