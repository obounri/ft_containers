#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"
#include "Stack.hpp"
#include "fcts.hpp"

// int main()
// {

//     Vector<int> v(5, 5);

//     stack<int> s(v);
//     s.push(8);
//     std::cout << "is empty ? " << s.empty() << " size " << s.size() << " top " << s.top() << std::endl;
//     for (size_t i = 0; i < 6; i++)
//     {
//         s.pop();
//     }
//     std::cout << "is empty ? " << s.empty() << " size " << s.size() << " top " << s.top() << std::endl;
    

//     std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
//     return 0;
// }

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main () {
  char foo[]="Apple";
  char bar[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << lexicographical_compare(foo,foo+5,bar,bar+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  std::cout << '\n';

  return 0;
}