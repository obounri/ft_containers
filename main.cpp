#include <vector>
#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int>    v1;
    Vector<int>    v2(8, 3);
    // std::allocator<int> alloc;
    // std::vector<int>    v(8, 3);

    // int *n = alloc.allocate(3);
    // alloc.construct(n, 12);
    // alloc.deallocate(n, 100);

    // std::cout << "size " << v.size() << " capacity " << v.capacity() << "\n";
    // for (int i = 0; i < v.size(); i++)
    // {
    //     std::cout << v[i] << "\n";
    // }
    
    return 0;
}