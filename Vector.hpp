#ifndef Vector_HPP
#define Vector_HPP

#include <string>
#include <exception>
#include <iostream>
#include <memory>
// #include <iterator>

template < class T, class Alloc = std::allocator<T> >
class Vector
{
private:
    T* data;
    T* _begin;
    T* _end;
    T* _capacity;
    Alloc alloc;

public:
    Vector();
    Vector( int n, T val );
    Vector( T* first, T* last );
    Vector( Vector& v );
    Vector&  operator=(const Vector& arr);
    T&      operator[] (int index) const ;
    ~Vector();

    int size() const ;
    int capacity() const ;

    class iterator: std::iterator<std::random_access_iterator_tag, T>
    {
            T* p;
        public:
            iterator(): p(0) {}
            iterator(T* x): p(x) {}
            iterator operator=(const iterator& rhs) {
                if (*this == rhs)
                    return *this;
                this->p = rhs.p;
                return *this;}
            iterator(const iterator& iter) : p(iter.p) {}
            iterator& operator++() {++p;return *this;}
            iterator& operator--() {--p;return *this;}
            iterator operator++( int ) { iterator old(*this); ++p;return old; }
            iterator operator--( int ) { iterator old(*this); --p;return old; }
            bool operator==(const iterator& rhs) const {return p==rhs.p;}
            bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
            T& operator*() {return *p;}
    };

    class reverse_iterator
    {
            T* p;
        public:
            reverse_iterator(): p(0) {}
            reverse_iterator(T* x): p(x) {}
            reverse_iterator operator=(const reverse_iterator& rhs) {
                if (*this == rhs)
                    return *this;
                this->p = rhs.p;
                return *this;}
            reverse_iterator(const reverse_iterator& iter) : p(iter.p) {}
            reverse_iterator& operator++() {--p;return *this;}
            reverse_iterator& operator--() {++p;return *this;}
            reverse_iterator operator++( int ) { reverse_iterator old(*this); --p;return old; }
            reverse_iterator operator--( int ) { reverse_iterator old(*this); ++p;return old; }
            bool operator==(const reverse_iterator& rhs) const {return p==rhs.p;}
            bool operator!=(const reverse_iterator& rhs) const {return p!=rhs.p;}
            T& operator*() {return *p;}
    };

    iterator begin() { return iterator(data); };
    iterator end() { return iterator(data + this->size()); };
    reverse_iterator rbegin() { return reverse_iterator(data + this->size() - 1); };
    reverse_iterator rend() { return reverse_iterator(data-1); };
    
};

template<class T, class Alloc>
Vector<T, Alloc>::Vector() {
    this->_begin = data;
    this->_end = data;
    this->_capacity = data;
}

template<class T, class Alloc>
Vector<T, Alloc>::Vector( int n, T val ) {
    this->data = alloc.allocate(n);
    for (int i = 0; i < n; i++)
        alloc.construct(data+i, val);
    this->_begin = data;
    this->_end = data + n;
    this->_capacity = data + n;
}

template<class T, class Alloc>
Vector<T, Alloc>::Vector( T* first, T* last ) {
    int size = last - first;
    this->data = alloc.allocate(size);
    int i = 0;
    while (first != last) {
        alloc.construct(data+i, *first);
        i++;
        first++;
    }
    this->_begin = data;
    this->_end = data + size;
    this->_capacity = data + size;
}

template<class T, class Alloc>
Vector<T, Alloc>::Vector( Vector& v ) {
    int size = v.size();
    Vector<T, Alloc>::iterator first = v.begin();
    Vector<T, Alloc>::iterator last = v.end();
    this->data = alloc.allocate(size);
    int i = 0;
    while (first != last) {
        alloc.construct(data+i, *first);
        i++;
        first++;
    }
    this->_begin = data;
    this->_end = data + size;
    this->_capacity = data + size;
}

template<class T, class Alloc>
Vector<T, Alloc>::~Vector() {
    if (this->capacity() > 0)
        alloc.deallocate(this->data, this->capacity());
}

template<class T, class Alloc>
int  Vector<T, Alloc>::size() const {
    return this->_end - this->_begin;
}

template<class T, class Alloc>
int  Vector<T, Alloc>::capacity() const {
    return this->_capacity - this->_begin;
}

template<class T, class Alloc>
T&      Vector<T, Alloc>::operator[] (int index) const {
    return this->data[index];
}

#endif