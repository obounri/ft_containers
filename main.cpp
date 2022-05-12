#include <vector>
#include <iostream>
#include <algorithm>
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

    // Vector<int>::iterator f_iter;
    // Vector<int>::iterator l_iter;

    // f_iter = v5.begin();
    // l_iter = v5.end();

    std::vector<int> c;
    
    std::cout << "max size " << c.max_size() << " ulimit for int " << std::numeric_limits<int>::max() << "\n";

    // Vector<int>::reverse_iterator rf_iter;
    // Vector<int>::reverse_iterator rl_iter;

    // rf_iter = v3.rbegin();
    // rl_iter = v3.rend();

    // while (f_iter != l_iter)
    // {
    //     std::cout << "iterator " << *f_iter << std::endl;
    //     ++f_iter;
    // }

    return 0;
}