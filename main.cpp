#include <vector>
#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int>    v1;
    Vector<int>    v2(8, 3);

    int p [] = {16, 2, 77, 40, 12071};
    Vector<int>    v3(p, p+5);

    Vector<int>::iterator f_iter(v3.begin());
    Vector<int>::iterator l_iter(v3.end());

    // f_iter = v3.begin();
    // l_iter = v3.end();

        // problem in assignement op

    int i = 0;
    while (f_iter != l_iter)
    {
        std::cout << "iterator " << *f_iter << std::endl;
        std::cout << "index [] " << v3[i] << std::endl << std::endl;
        ++f_iter;
        i++;
    }
    
    return 0;
}