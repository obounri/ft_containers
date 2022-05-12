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
    Vector<int>    v4(v3);

    Vector<int>::iterator f_iter;
    Vector<int>::iterator l_iter;

    f_iter = v3.begin();
    l_iter = v3.end();

    Vector<int>::reverse_iterator rf_iter;
    Vector<int>::reverse_iterator rl_iter;

    rf_iter = v3.rbegin();
    rl_iter = v3.rend();

    int i = 0;
    while (rf_iter != rl_iter)
    {
        std::cout << "iterator " << *rf_iter << std::endl;
        ++rf_iter;
        i++;
    }

    return 0;
}