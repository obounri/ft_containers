#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "pair.hpp"

class PrettyTree
{
    private:
        typedef ft::tree<ft::pair<const int, int> > 	tree;
        tree _tree;

    public:
        template <class InputIterator>
        PrettyTree(InputIterator first, InputIterator last):_tree( tree::value_compare(), tree::allocator_type()) {
            for (; first != last; first++) {
                _tree.insert(*first);
            }
        };

        ~PrettyTree() {} ;
        
        void prettyPrint() {
            _tree.prettyPrint(_tree.root_base(), "", 1);
        }
};

int main()
{
    ft::vector<int>    v1;
    ft::vector<int>    v2(8, 3);

    int p [] = {16, 2, 77, 40, 12071};
    std::cout << "Range constructing v3 from int p [] = {16, 2, 77, 40, 12071} "; 
    std::cout << ", assigning v3 to v4, copy constructing v5 from v4" << "\n\n";

    ft::vector<int>    v3(p, p+5);


    ft::vector<int>    v4;
    v4 = v3;

    ft::vector<int> v5(v4);

    ft::vector<int>::iterator f_iter;
    ft::vector<int>::iterator l_iter;

    f_iter = v5.begin();
    l_iter = v5.end();


    std::vector<std::size_t> c;
    ft::vector<std::size_t> d;
    
    std::cout << "std::vector<std::size_t> alloc max size " << c.max_size() << " ft::vector<std::size_t> max size " << d.max_size() << "\n\n";

    ft::vector<int>::reverse_iterator rf_iter;
    ft::vector<int>::reverse_iterator rl_iter;

    rf_iter = v5.rbegin();
    rl_iter = v5.rend();

    std::cout << "iterating using reverse_iterators, deferencing them to get value >>" << '\n';
    while (rf_iter != rl_iter)
    {
        std::cout << *rf_iter << " ";
        ++rf_iter;
    }
    std::cout << std::endl << std::endl;

    std::cout << "v5.size() " << v5.size() << " v5.capacity() " << v5.capacity() << " v5.min() " << *(std::min_element(f_iter, l_iter)) << " v5.max() " << *(std::max_element(f_iter, l_iter)) << std::endl;
    try
    {
        std::cout << "v5.reserve(10), v5.at(...) = x, std::cout << v5.at(...) >> " << '\n';
        v5.reserve(10); // invalidates iterators
        v5.at(1) = -1;
        v5.at(2) = 69;
        v5.at(4) = 420;
        std::cout << v5.at(0) << " / " << v5.at(1) << " / " << v5.at(2) << " / " << v5.at(3) << " / " << v5.at(4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    f_iter = v5.begin();
    l_iter = v5.end();
    std::cout << "v5.size() " << v5.size() << " v5.capacity() " << v5.capacity() << " v5.min() " << *(std::min_element(f_iter, l_iter)) << " v5.max() " << *(std::max_element(f_iter, l_iter)) << std::endl << std::endl;

    std::cout << "iterating using iterators, deferencing them to get value >>" << '\n';
    while (f_iter != l_iter)
    {
        std::cout << *f_iter << " ";
        ++f_iter;
    }
    std::cout << std::endl << std::endl;
    
    std::cout << "v5.resize(10, 9), accessing through operator[] >>" << '\n';
    v5.resize(10, 9);
    for (size_t i = 0; i < v5.size(); i++)
    {
        std::cout << v5[i] << " ";
    }
    std::cout << std::endl;
    f_iter = v5.begin();
    l_iter = v5.end();
    std::cout << "v5.size() " << v5.size() << " v5.capacity() " << v5.capacity() << " v5.min() " << *(std::min_element(f_iter, l_iter)) << " v5.max() " << *(std::max_element(f_iter, l_iter)) << std::endl << std::endl;

    // map
    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;

    const char *strs[58] = { "wording", "far", "original", "crouch", "revive", "mainstream", "waiter", "sunshine", "motivation", 
        "quarter", "zero", "noble", "module", "lump", "incredible", "visual", "ranch", "default", "admiration", "chase", 
        "pedestrian", "evening", "concert", "environmental", "alarm", "injury", "disaster", "theft", "bill", "fax", "trainer", 
        "display", "looting", "crystal", "fill", "prisoner", "war", "breakfast", "camera", "coup", "gravity", "lay", "hit", 
        "straight", "rate", "band", "helpless", "sex", "eject", "dash", "contrast", "rehearsal", "golf", "poem", "desire", "waist", 
        "nonremittal", "indulge" };

    ft::vector< ft::pair<std::string, int> > v;
    for (size_t i = 0; i < 58; i++) {
        ft::pair<std::string, int> vtmp(strs[i], i);
        v.push_back(vtmp);
    }

    ft::vector< ft::pair<std::string, int> >::iterator vb = v.begin();
    ft::vector< ft::pair<std::string, int> >::iterator ve = v.end();

    ft::map<std::string, int> str_map(vb, ve);
    ft::map<std::string, int>::iterator first = str_map.begin();
    ft::map<std::string, int>::iterator last = str_map.end();
    
    for (; first != last; first++) {
        std::cout << (*first).first << ", " << (*first).second << std::endl; 
    }
    
    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;

    ft::vector< ft::pair<int, int> > vPretty;

    for (size_t i = 0; i < 10; i++) {
        ft::pair<int, int> tmp(i, i);
        vPretty.push_back(tmp);
    }

    ft::vector< ft::pair<int, int> >::iterator ib = vPretty.begin();
    ft::vector< ft::pair<int, int> >::iterator ie = vPretty.end();

    PrettyTree m(ib, ie);
    m.prettyPrint();
    // visualization https://www.cs.usfca.edu/~galles/visualization/RedBlack.html


    std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
    
    return 0;
}