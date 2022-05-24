#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include "pair.hpp"

#include <functional>
#include <memory>

template < class Key,                                 
           class T,                                   
           class Compare = std::less<Key>,                 
           class Alloc = std::allocator<pair<const Key,T> >
           >
class map
{
    public:
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef pair<const key_type, mapped_type>   value_type;
        typedef Compare                             key_compare;
        // value_compare
        typedef Alloc                               allocator_type;
        typedef typename Alloc::reference           reference;
        typedef typename Alloc::const_reference     const_reference;
        typedef typename Alloc::pointer             pointer;
        typedef typename Alloc::const_pointer       const_pointer;
        typedef vector_iterator<pointer>            iterator;
        typedef vector_iterator<const_pointer>      const_iterator;
        typedef reverse_iter<iterator>              reverse_iterator;
        typedef reverse_iter<const_iterator>        const_reverse_iterator;
        typedef std::ptrdiff_t                      difference_type;
	    typedef std::size_t                         size_type;
        typedef class                               value_compare;
};

template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare
{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  friend class map;
protected:
  Compare comp;
  value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
  typedef bool result_type;
  typedef value_type first_argument_type;
  typedef value_type second_argument_type;
  bool operator() (const value_type& x, const value_type& y) const
  {
    return comp(x.first, y.first);
  }
};

#endif

// value_compare	Nested function class to compare elements	see value_comp