#ifndef BST_HPP
# define BST_HPP

#include <iostream>
#include "pair.hpp"

template <class T1, class T2>
class BST {
    public:
        typedef pair<T1, T2> _pair;
        typedef T1  first_type;
        typedef T2  second_type;
    
    private:
        _pair   data;
        BST     *left, *right;
 
public:
    BST(): data(), left(NULL), right(NULL) {} ;
 
    BST(first_type f , second_type s) { data.first = f; data.second = s; left = NULL; right = NULL; } ;
    BST(_pair p) { data.first = p.first; data.second = p.second; left = NULL; right = NULL; } ;
 
    BST* insert(BST* root, first_type f, second_type s) {
        if (!root)
            return new BST(f, s);

        if (f > root->data.first)
            root->right = insert(root->right, f, s);
        else
            root->left = insert(root->left, f, s);

        return root;
    };

    BST* insert(BST* root, _pair p) {
        if (!root)
            return new BST(p);

        if (p.first > root->data.first)
            root->right = insert(root->right, p);
        else
            root->left = insert(root->left, p);

        return root;
    };

    void traversal(BST* root) {
        if (!root)
            return ;
        traversal(root->left);
        std::cout << root->data.first << "=" << root->data.second << std::endl;
        traversal(root->right);
    };
};

#endif