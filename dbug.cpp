#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Vector.hpp"
#include "Stack.hpp"
#include "fcts.hpp"
#include "pair.hpp"
#include "BST.hpp"

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
  
    pair<int, int> a(0, 0);
    pair<int, int> b(3, 3);
    pair<int, int> c(2, 2);
    pair<int, int> d(1, 1);

    BST<int, int> *root = NULL, tree;

    root = tree.insert(root, a);
    tree.insert(root, b);
    tree.insert(root, c);
    tree.insert(root, d);

    tree.traversal(root);

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}