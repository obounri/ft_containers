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
  
    pair<std::string, int> a("oth", 0);
    pair<std::string, int> b("ism", 3);
    pair<std::string, int> c("kha", 2);
    pair<std::string, int> d("raq", 1);
    pair<std::string, int> e("rao", 1);

    BST<std::string, int> *root = NULL, tree;

    root = tree.insert(root, a);
    tree.insert(root, b);
    tree.insert(root, c);
    tree.insert(root, d);
    tree.insert(root, e);

    tree.traversal(root);

    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}