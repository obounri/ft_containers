#ifndef BST_HPP
# define BST_HPP

#include <iostream>
#include "pair.hpp"

template <class T1, class T2, class Compare, class Alloc>
class BST {
    public:
        typedef pair<T1, T2> _pair;
        typedef T1  first_type;
        typedef T2  second_type;
		typedef Compare 						                        key_compare;
		typedef Alloc 							                        allocator_type;
        typedef typename allocator_type::template rebind<BST>::other    bst_allocator;
    
    private:
        _pair           data;
        BST             *left, *right;
        bst_allocator   _bst_alloc;
        key_compare     _comp;
 
public:
    BST( const key_compare& comp = key_compare(), 
        const bst_allocator& bst_alloc = bst_allocator() 
            ): left(NULL), right(NULL), _bst_alloc(bst_alloc), _comp(comp) {} ;
 
    BST( first_type f, second_type s, const key_compare& comp = key_compare(), 
        const bst_allocator& alloc = bst_allocator() ) { 
            data.first = f;
            data.second = s;
            left = NULL;
            right = NULL;
            _bst_alloc = alloc;
            _comp = comp;
        } ;

    BST* insert(BST* root, const first_type f, const second_type s) {
        if (!root) {
            root = _bst_alloc.allocate(1);
            _bst_alloc.construct(root, BST(f, s));
            return root;
        }

        if (_comp(f, root->data.first))
            root->left = insert(root->left, f, s);
        else
            root->right = insert(root->right, f, s);

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