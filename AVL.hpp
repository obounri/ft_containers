#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include "pair.hpp"
#include "Vector.hpp"


template <class P>
struct Node {
    P data; // holds the key
    Node *parent; // pointer to the parent
    Node *left; // pointer to left child
    Node *right; // pointer to right child
    int bf; // balance factor of the node
};

// tree iterator class
template <class Iter, class T>
class tree_iterator : public iterator<std::bidirectional_iterator_tag,
                        typename iterator_traits<T>::value_type>
{
    public:
        typedef Iter iterator_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef std::bidirectional_iterator_tag 	iterator_category;
        typedef std::ptrdiff_t difference_type;

    private:
        iterator_type _current;

    public:
        tree_iterator() : _current()
        {
        }

        tree_iterator(iterator_type _x) : _current(_x)
        {
        }
        
        template <class OthIter, class U>
        tree_iterator(const tree_iterator<OthIter, U>& _other) : _current(_other.base())
        {
        }

        template <class OthIter, class U>
        tree_iterator& operator=(const tree_iterator<OthIter, U>& _other)
        {
            this->_current = _other.base();
            return (*this);
        }

        ~tree_iterator()
        {
        }

        reference operator*() const
        {
            return _current->_data;
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        tree_iterator & operator++()
        {
            this->_current = successor(this->_current);
            return (*this);
        }

        tree_iterator operator++(int)
        {
            tree_iterator _tmp(*this);
            this->_current = successor(this->_current);
            return (_tmp);
        }

        tree_iterator & operator--()
        {
            this->_current = predecessor(this->_current);
            return (*this);
        }

        tree_iterator operator--(int)
        {
            tree_iterator _tmp(*this);
            this->_current = predecessor(this->_current);
            return (_tmp);
        }

        iterator_type base() const
        {
            return (this->_current);
        }

    private:
        iterator_type minimum(iterator_type _x) const
        {
            while (_x->_left != nullptr)
                _x = _x->_left;
            return (_x);
        }
        
        iterator_type maximum(iterator_type _x) const
        {
            while (_x->_right != nullptr)
                _x = _x->_right;
            return (_x);
        }
        
        iterator_type successor(iterator_type _x)
        {
            if (_x->_right != nullptr)
                return (minimum(_x->_right));
            iterator_type _node_y = _x->_parent;
            while (_node_y != nullptr && _x == _node_y->_right)
            {
                _x = _node_y;
                _node_y = _node_y->_parent;
            }
            return (_node_y);
        }
        
        iterator_type predecessor(iterator_type _x)
        {
            if (_x->_left != nullptr)
                return (maximum(_x->_left));
            iterator_type _node_y = _x->_parent;
            while (_node_y != nullptr && _x == _node_y->_left)
            {
                _x = _node_y;
                _node_y = _node_y->_parent;
            }
            return (_node_y);
        }
    public:
        template <class Iter1, class T1>
        bool operator==(const tree_iterator<T1, Iter1>& _iter)
        {
            return this->_current == _iter.base();
        }
        template <class Iter1, class T1>
        bool operator!=(const tree_iterator<T1, Iter1>& _iter)
        {
            return this->_current != _iter.base();
        }
};

// class AVL implements the operations in AVL tree
template <class T1, class T2, class Compare, class Alloc>
class AVL {
    public:
        typedef pair<T1, T2> _pair;
        typedef T1  first_type;
        typedef T2  second_type;
		typedef Compare 						                            key_compare;
		typedef Alloc 							                            allocator_type;
        typedef typename allocator_type::template rebind<Node<_pair> >::other    node_allocator;
        typedef Node<_pair> *NodePtr;

    private:
        NodePtr root;
        node_allocator   _node_alloc;
        key_compare     _comp;

        // initializes the nodes with appropirate values
        // all the pointers are set to point to the null pointer
        void initializeNode(NodePtr &node, _pair p) {
            node->data.first = p.first;
            node->data.second = p.second;
            node->parent = nullptr;
            node->left = nullptr;
            node->right = nullptr;
            node->bf = 0;
        }

        void inOrderHelper(NodePtr node) {
            if (node != nullptr) {
                inOrderHelper(node->left);
                std::cout << node->data.first << "\n";
                inOrderHelper(node->right);
            } 
        }

        NodePtr searchTreeHelper(NodePtr node, first_type key) {
            if (node == nullptr || key == node->data.first) {
                return node;
            }

            if (key < node->data.first) {
                return searchTreeHelper(node->left, key);
            } 
            return searchTreeHelper(node->right, key);
        }

        // NodePtr deleteNodeHelper(NodePtr node, first_type key) {
        //     // search the key
        //     if (node == nullptr) return node;
        //     else if (key < node->data.first) node->left = deleteNodeHelper(node->left, key);
        //     else if (key > node->data.first) node->right = deleteNodeHelper(node->right, key);
        //     else {
        //         // the key has been found, now delete it

        //         // case 1: node is a leaf node
        //         if (node->left == nullptr && node->right == nullptr) {
        //             delete node;
        //             node = nullptr;
        //         }

        //         // case 2: node has only one child
        //         else if (node->left == nullptr) {
        //             NodePtr temp = node;
        //             node = node->right;
        //             delete temp;
        //         }

        //         else if (node->right == nullptr) {
        //             NodePtr temp = node;
        //             node = node->left;
        //             delete temp;
        //         }

        //         // case 3: has both children
        //         else {
        //             NodePtr temp = minimum(node->right);
        //             node->data.first = temp->data.first;
        //             node->right = deleteNodeHelper(node->right, temp->data.first);
        //         }

        //     } 

        //     // Write the update balance logic here 
        //     // YOUR CODE HERE

        //     return node;
        // }

        


        // update the balance factor the node
        void updateBalance(NodePtr node) {
            if (node->bf < -1 || node->bf > 1) {
                rebalance(node);
                return;
            }

            if (node->parent != nullptr) {
                if (node == node->parent->left) {
                    node->parent->bf -= 1;
                } 

                if (node == node->parent->right) {
                    node->parent->bf += 1;
                }

                if (node->parent->bf != 0) {
                    updateBalance(node->parent);
                }
            }
        }

        // rebalance the tree
        void rebalance(NodePtr node) {
            if (node->bf > 0) {
                if (node->right->bf < 0) {
                    rightRotate(node->right);
                    leftRotate(node);
                } else {
                    leftRotate(node);
                }
            } else if (node->bf < 0) {
                if (node->left->bf > 0) {
                    leftRotate(node->left);
                    rightRotate(node);
                } else {
                    rightRotate(node);
                }
            }
        }

        void printHelper(NodePtr root, std::string indent, bool last) {
            // print the tree structure on the screen
            if (root != nullptr) {
            std::cout<<indent;
            if (last) {
                std::cout<<"R----";
                indent += "     ";
            } else {
                std::cout<<"L----";
                indent += "|    ";
            }

            std::cout<<root->data.first<<"( BF = "<<root->bf<<")"<< std::endl;

            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
            }
        }

    public:
        AVL( const key_compare& comp = key_compare(), 
        const node_allocator& alloc = node_allocator() ): root(nullptr), _comp(comp), _node_alloc(alloc) {}

        // Pre-Order traversal
        // Node->Left Subtree->Right Subtree
        void preorder() {
            preOrderHelper(this->root);
        }

        // In-Order traversal
        // Left Subtree -> Node -> Right Subtree
        void inorder() {
            inOrderHelper(this->root);
        }

        // Post-Order traversal
        // Left Subtree -> Right Subtree -> Node
        void postorder() {
            postOrderHelper(this->root);
        }

        // search the tree for the key k
        // and return the corresponding node
        NodePtr searchTree(int k) {
            return searchTreeHelper(this->root, k);
        }

        // // find the node with the minimum key
        // NodePtr minimum(NodePtr node) {
        //     while (node->left != nullptr) {
        //         node = node->left;
        //     }
        //     return node;
        // }

        // // find the node with the maximum key
        // NodePtr maximum(NodePtr node) {
        //     while (node->right != nullptr) {
        //         node = node->right;
        //     }
        //     return node;
        // }

        // // find the successor of a given node
        // NodePtr successor(NodePtr x) {
        //     // if the right subtree is not null,
        //     // the successor is the leftmost node in the
        //     // right subtree
        //     if (x->right != nullptr) {
        //         return minimum(x->right);
        //     }

        //     // else it is the lowest ancestor of x whose
        //     // left child is also an ancestor of x.
        //     NodePtr y = x->parent;
        //     while (y != nullptr && x == y->right) {
        //         x = y;
        //         y = y->parent;
        //     }
        //     return y;
        // }

        // // find the predecessor of a given node
        // NodePtr predecessor(NodePtr x) {
        //     // if the left subtree is not null,
        //     // the predecessor is the rightmost node in the 
        //     // left subtree
        //     if (x->left != nullptr) {
        //         return maximum(x->left);
        //     }

        //     NodePtr y = x->parent;
        //     while (y != nullptr && x == y->left) {
        //         x = y;
        //         y = y->parent;
        //     }

        //     return y;
        // }

        // rotate left at node x
        void leftRotate(NodePtr x) {
            NodePtr y = x->right;
            x->right = y->left;
            if (y->left != nullptr) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                this->root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;

            // update the balance factor
            x->bf = x->bf - 1 - std::max(0, y->bf);
            y->bf = y->bf - 1 + std::min(0, x->bf);
        }

        // rotate right at node x
        void rightRotate(NodePtr x) {
            NodePtr y = x->left;
            x->left = y->right;
            if (y->right != nullptr) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                this->root = y;
            } else if (x == x->parent->right) {
                x->parent->right = y;
            } else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;

            // update the balance factor
            x->bf = x->bf + 1 - std::min(0, y->bf);
            y->bf = y->bf + 1 + std::max(0, x->bf);
        }

        // insert the key to the tree in its appropriate position
        // here 
        void insert(_pair p) {
            // PART 1: Ordinary BST insert
            NodePtr node;
            node = _node_alloc.allocate(1);
            _node_alloc.construct(node, Node<_pair>());
            initializeNode(node, p);
            NodePtr y = nullptr;
            NodePtr x = this->root;

            while (x != nullptr) {
                y = x;
                if (_comp(node->data.first, x->data.first)) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }

            // y is parent of x
            node->parent = y;
            if (y == nullptr) {
                root = node;
            } else if (_comp(node->data.first, y->data.first)) {

                y->left = node;
            } else {
                y->right = node;
            }

            // PART 2: re-balance the node if necessary
            updateBalance(node);

        }

        NodePtr getRoot(){
            return this->root;
        }

        // delete the node from the tree
        NodePtr deleteNode(first_type data) {
            NodePtr deletedNode =  deleteNodeHelper(this->root, data);
            return deletedNode;
        }

        // print the tree structure on the screen
        void prettyPrint() {
            printHelper(this->root, "", true);
        }

};