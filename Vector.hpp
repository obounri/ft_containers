#ifndef Vector_HPP
#define Vector_HPP

#include <string>
#include <exception>
#include <iostream>
#include <memory>
#include "iterator.hpp"

template <class T, class Alloc = std::allocator<T> >
class Vector
{
public:
	typedef T			value_type;
	typedef Alloc		allocator_type;
	typedef typename Alloc::reference	reference;
	typedef typename Alloc::const_reference	const_reference;
	typedef typename Alloc::pointer	pointer;
	typedef typename Alloc::const_pointer	const_pointer;
	typedef vector_iterator<pointer>	iterator;
	typedef vector_iterator<const_pointer>	const_iterator;
	typedef reverse_iter<iterator>	reverse_iterator;
	typedef reverse_iter<const_iterator>	const_reverse_iterator;
	typedef std::ptrdiff_t	difference_type;
	typedef std::size_t	size_type;

private:
	pointer _data;
	size_type _size;
	size_type _capacity;
	allocator_type _alloc;

public:
    Vector();
    Vector( int n, T val );
    Vector( T* first, T* last );
    Vector( const Vector& v );
    Vector&  operator=( const Vector& rhs );
    reference      operator[] ( int index ) const ;
    ~Vector();

    int size() const ;
    int capacity() const ;

    iterator begin() const { return iterator(_data); };
    iterator end() const { return iterator(_data + this->size()); };
    reverse_iterator rbegin() const { return reverse_iterator(_data + this->size() - 1); };
    reverse_iterator rend() const { return reverse_iterator(_data-1); };

};

template<class T, class Alloc>
Vector<T, Alloc>::Vector() {
    this->_data = 0;
    this->_size = 0;
    this->_capacity = 0;
}

template<class T, class Alloc>
Vector<T, Alloc>::Vector( int n, T val ) {
    this->_data = _alloc.allocate(n);
    for (int i = 0; i < n; i++)
        _alloc.construct(_data+i, val);
    this->_size = n;
    this->_capacity = n;
}

template<class T, class Alloc>
Vector<T, Alloc>::Vector( T* first, T* last ) {
    int size = last - first;
    this->_data = _alloc.allocate(size);
    int i = 0;
    while (first != last) {
        _alloc.construct(_data+i, *first);
        i++;
        first++;
    }
    this->_size = size;
    this->_capacity = size;
}

template<class T, class Alloc>
Vector<T, Alloc>::Vector( const Vector& v ) {
    int size = v.size();
    int capacity = v.capacity();
    this->_data = _alloc.allocate(capacity);
    int i = 0;
    while (i < size) {
        _alloc.construct(_data+i, v[i]);
        i++;
    }
    this->_size = size;
    this->_capacity = capacity;
}

template<class T, class Alloc>
Vector<T, Alloc>::~Vector() {
    if (this->capacity() > 0)
        _alloc.deallocate(this->_data, this->capacity());
}

template<class T, class Alloc>
Vector<T, Alloc>&  Vector<T, Alloc>::operator=( const Vector& rhs ) {
    if (this == &rhs)
        return *this;

    int size = rhs.size();
    int capacity = rhs.capacity();
    if (capacity > 0)
        _alloc.deallocate(this->_data, capacity);
    this->_data = _alloc.allocate(capacity);
    int i = 0;
    while (i < size) {
        _alloc.construct(_data+i, rhs[i]);
        i++;
    }
    this->_size = size;
    this->_capacity = capacity;
    
    return *this;
}

template<class T, class Alloc>
int  Vector<T, Alloc>::size() const {
    return this->_size;
}

template<class T, class Alloc>
int  Vector<T, Alloc>::capacity() const {
    return this->_capacity;
}

template<class T, class Alloc>
typename Vector<T, Alloc>::reference      Vector<T, Alloc>::operator[] ( int index ) const {
    return *(this->_data + index);
}

#endif