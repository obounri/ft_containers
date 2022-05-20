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
	typedef T                                   value_type;
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

    // std::bad_alloc                              _bad_alloc;
    // std::length_error                           _length_error;

private:
	pointer         _data;
	size_type       _size;
	size_type       _capacity;
	allocator_type  _alloc;

public:
    Vector();
    Vector( int n, T val );

    template <class InputIterator>
    Vector( InputIterator first, InputIterator last ) {
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

    Vector( const Vector& v );
    Vector&     operator=( const Vector& rhs );
    ~Vector();

    // iterators
    iterator begin() const { return iterator(_data); };
    iterator end() const { return iterator(_data + this->size()); };
    reverse_iterator rbegin() const { return reverse_iterator(_data + this->size() - 1); };
    reverse_iterator rend() const { return reverse_iterator(_data-1); };

    // capacity
    size_type size() const ;
    size_type max_size() const;
    void resize (size_type n, value_type val = value_type());
    size_type capacity() const ;
    bool empty() const;
    void reserve ( size_type n );

    // element access
    reference   operator[] ( size_type index ) const ;
    reference at (size_type n);
    // const_reference at (size_type n) const; // how to know if vector object is const qualified
    reference front();
    // const_reference front() const;
    reference back();
    // const_reference back() const;

    void assign(size_type n, const value_type &val)
    {
        if (n <= 0)
            return ;
        this->reserve(n);
        this->_size = n;
        for (size_type i = 0; i < n; ++i)
            this->_alloc.construct(&this->_data[i], val);
    }

    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last,
    //             typename enable_if<!is_integral<InputIterator>::value, bool>::type = true)
    // {
    //     difference_type len = last - first;
    //     if (len <= 0)
    //         return ;
    //     this->reserve(len);
    //     this->_size = len;
    //     size_type i = 0;
    //     for (InputIterator it = first; it != last; ++it)
    //         this->_alloc.construct(&this->_data[i++], *it);
    // }

    void push_back(const value_type &val)
    {
        this->reserve(this->_size + 1);
        this->_alloc.construct(&this->_data[this->_size++], val);
    }

    void pop_back()
    {
        this->_alloc.destroy(&this->_data[this->_size - 1]);
        this->_size--;
    }

    iterator insert(iterator position, const value_type &val)
    {
        // std::cout << "normal insert" << std::endl;
        difference_type index = position - begin();
        if (index < 0)
            throw std::out_of_range("out_of_range");
        this->reserve(this->_size + 1);
        this->_size += 1;
        difference_type i = size();
        while (--i >= 0)
        {
            if (i == index)
            {
                this->_alloc.construct(&this->_data[i], val);
                break;
            }
            this->_alloc.construct(&this->_data[i], this->_data[i - 1]);
        }
        return (iterator(this->_data + index));
    }

    void insert(iterator position, size_type n, const value_type &val)
    {
        if (n <= 0)
            return;
        difference_type index = position - begin();
        if (index < 0)
            return;
        this->reserve(size() + n);
        this->_size += n;
        difference_type i = size();
        while (--i >= 0)
        {
            if (i == (index + (difference_type)n) - 1)
            {
                _alloc.construct(&this->_data[i], val);
                n--;
            }
            else
                _alloc.construct(&this->_data[i], this->_data[i - n]);
            if (i == index)
                break;
        }
    }

    // template <class InputIterator>
    // void insert(iterator position, InputIterator first, InputIterator last,
    //             typename enable_if<!is_integral<InputIterator>::value, bool>::type = true)
    // {
    //     difference_type index = position - begin();
    //     difference_type len = last - first;
    //     if (len <= 0)
    //         return;
    //     this->reserve(size() + len);
    //     this->_size += len;
    //     difference_type i = size();
    //     while (--i >= 0)
    //     {
    //         if (i == index + len - 1)
    //         {
    //             _alloc.construct(&_data[i], *--last);
    //             len--;
    //         }
    //         else
    //             _alloc.construct(&_data[i], _data[i - len]);
    //         if (i == index)
    //             break;
    //     }
    // }

    iterator erase(iterator position)
    {
        difference_type index = position - begin();
        if (index < 0)
            throw std::out_of_range("out_of_range");
        size_type i = 0, _j = 0;
        while (i < size())
        {
            if (i == (size_type)index)
                _alloc.destroy(&_data[i++]);
            _alloc.construct(&_data[_j++], _data[i]);
            i++;
        }
        _size--;
        return (iterator(this->_data + index));
    }

    iterator erase(iterator first, iterator last)
    {
        difference_type index = first - begin();
        if ((last - first) <= 0)
            throw std::out_of_range("out_of_range");
        size_type len = 0;
        size_type i = 0, _j = 0;
        while (i < size())
        {
            if (i == (size_type)index)
            {
                for (; first != last; first++)
                {
                    this->_alloc.destroy(&this->_data[i++]);
                    len++;
                }
            }
            this->_alloc.construct(&this->_data[_j++], this->_data[i++]);
        }
        this->_size -= len;
        return (iterator(this->_data + index));
    }

    void swap(Vector &v)
    {
        std::swap(this->_data, v._data);
        std::swap(this->_size, v._size);
        std::swap(this->_capacity, v._capacity);
        std::swap(this->_alloc, v._alloc);
    }

    void clear()
    {
        if (!this->empty())
        {
            for (size_type i = 0; i < this->size(); i++)
                this->_alloc.destroy(&this->_data[i]);
            this->_size = 0;
        }
    }

    allocator_type get_allocator() const {
        return (this->_alloc);
    }
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
    if (this->_size > 0)
        for (Vector<T, Alloc>::size_type i = 0; i < this->_size; i++)
            _alloc.destroy(this->_data+i);
    if (this->_capacity > 0)
        _alloc.deallocate(this->_data, this->_capacity);
}

template<class T, class Alloc>
Vector<T, Alloc>&  Vector<T, Alloc>::operator=( const Vector& rhs ) {
    if (this == &rhs)
        return *this;

    if (this->_size > 0)
        for (Vector<T, Alloc>::size_type i = 0; i < this->_size; i++)
            _alloc.destroy(this->_data+i);
    if (this->_capacity > 0)
        _alloc.deallocate(this->_data, this->_capacity);
    this->_data = _alloc.allocate(rhs.capacity());
    size_type i = 0;
    while (i < rhs.size()) {
        _alloc.construct(_data+i, rhs[i]);
        i++;
    }
    this->_size = rhs.size();
    this->_capacity = rhs.capacity();
    
    return *this;
}

template<class T, class Alloc>
typename Vector<T, Alloc>::size_type  Vector<T, Alloc>::size() const {
    return this->_size;
}

template<class T, class Alloc>
typename Vector<T, Alloc>::size_type  Vector<T, Alloc>::capacity() const {
    return this->_capacity;
}

template<class T, class Alloc>
bool Vector<T, Alloc>::empty() const {
    if (this->_size == 0)
        return true;
    return false;
}

template<class T, class Alloc>
typename Vector<T, Alloc>::size_type Vector<T, Alloc>::max_size() const {
    return (this->_alloc).max_size();
}

template<class T, class Alloc>
void Vector<T, Alloc>::reserve( size_type n )  {
    if (n > this->max_size())
        throw std::length_error("length_error");
    if (n > this->_capacity) {
        Vector tmp(*this);
        if (this->_size > 0)
            for (Vector<T, Alloc>::size_type i = 0; i < this->_size; i++)
                _alloc.destroy(this->_data+i);
        _alloc.deallocate(this->_data, this->_capacity);
        try {
            this->_data = _alloc.allocate(n);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            *this = tmp;
            throw std::bad_alloc();
        }
        for (size_type i = 0; i < this->_size; i++) {
            _alloc.construct(_data+i, tmp[i]);
        }
        this->_capacity = n;
    }
}

template<class T, class Alloc>
typename Vector<T, Alloc>::reference      Vector<T, Alloc>::operator[] ( size_type index ) const {
    return *(this->_data + index);
}

template<class T, class Alloc>
typename Vector<T, Alloc>::reference      Vector<T, Alloc>::at (size_type n) {
    if (n >= this->_size)
        throw std::out_of_range("out_of_range");
    return *(this->_data + n);
}

template<class T, class Alloc>
typename Vector<T, Alloc>::reference      Vector<T, Alloc>::front () {
    return *(this->_data);
}

template<class T, class Alloc>
typename Vector<T, Alloc>::reference      Vector<T, Alloc>::back () {
    return *(this->_data + this->_size - 1);
}

template<class T, class Alloc>
void Vector<T, Alloc>::resize (size_type n, value_type val) {
    if (n < this->_size) {
        for (size_type i = n; i < this->_size; i++) {
            _alloc.destroy(this->_data + i);
        }
        this->_size = n;
    }
    else if (n > this->_size) {
        this->reserve(n);
        for (; this->_size < n; this->_size++)
            _alloc.construct(this->_data+this->_size, val);
    }
}

// template <class T, class Alloc>
// bool operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs) {
//     return rhs.size() == lhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
// }

template <class T, class Alloc>
bool operator!=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs) {
    return !(lhs == rhs);
}

// template <class T, class Alloc>
// bool operator<(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs) {
//     return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
// }

template <class T, class Alloc>
bool operator>(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs) {
    return (rhs < lhs);
}

template <class T, class Alloc>
bool operator<=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs) {
    return  (lhs < rhs || lhs == rhs);
}

template <class T, class Alloc>
bool operator>=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
    return (lhs > rhs || lhs == rhs);
}

template <class T, class Alloc>
void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y)
{
    x.swap(y);
}

#endif