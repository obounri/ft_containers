#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"

int main()
{
    Vector<int>    v1;
    Vector<int>    v2(8, 3);

    int p [] = {16, 2, 77, 40, 12071};
    Vector<int>    v3(p, p+5);

    Vector<int>    v4;
    v4 = v3;

    Vector<int> v5(v4);

    Vector<int>::iterator f_iter;
    Vector<int>::iterator l_iter;

    f_iter = v5.begin();
    l_iter = v5.end();


    std::vector<std::size_t> c;
    Vector<std::size_t> d;
    
    std::cout << "std::vector alloc max size " << c.max_size() << " ft::vector max size " << d.max_size() << "\n";

    // Vector<int>::reverse_iterator rf_iter;
    // Vector<int>::reverse_iterator rl_iter;

    // rf_iter = v5.rbegin();
    // rl_iter = v5.rend();

    std::cout << "size " << v5.size() << " capacity " << v5.capacity() << " min " << *(std::min_element(f_iter, l_iter)) << " max " << *(std::max_element(f_iter, l_iter)) << std::endl;
    try
    {
        v5.reserve(10); // invalidates iterators
        f_iter = v5.begin();
        l_iter = v5.end();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "size " << v5.size() << " capacity " << v5.capacity() << " min " << *(std::min_element(f_iter, l_iter)) << " max " << *(std::max_element(f_iter, l_iter)) << std::endl;
    
    // std::sort(f_iter, l_iter);

    while (f_iter != l_iter)
    {
        std::cout << "iterator " << *f_iter << std::endl;
        ++f_iter;
    }

    std::cout << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}