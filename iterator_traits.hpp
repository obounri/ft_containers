#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>

template <
				class Category,
				class T,
				class Distance = std::ptrdiff_t,
				class Pointer = T*,
				class Reference = T&
				>
class iterator
{
public:
    typedef Category	iterator_category;
    typedef T			value_type;
    typedef Pointer		pointer;
    typedef Reference	reference;
    typedef Distance	difference_type;
};

/* iterator_traits */
template <class Iter>
class iterator_traits
{
public:
    typedef typename Iter::value_type			value_type;
    typedef typename Iter::pointer				pointer;
    typedef typename Iter::reference			reference;
    typedef typename Iter::difference_type		difference_type;
    typedef typename Iter::iterator_category	iterator_category;
};

template <class T>
class iterator_traits<T*>
{
public:
    typedef T								value_type;
    typedef T*								pointer;
    typedef T&								reference;
    typedef std::ptrdiff_t					difference_type;
    typedef std::random_access_iterator_tag	iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
public:
    typedef T								value_type;
    typedef const T*						pointer;
    typedef const T&						reference;
    typedef std::ptrdiff_t					difference_type;
    typedef std::random_access_iterator_tag	iterator_category;
};

#endif