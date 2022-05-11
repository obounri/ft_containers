#ifndef Vector_HPP
#define Vector_HPP

#include <string>
#include <exception>
#include <iostream>
#include <memory>
#include <iterator>

// class IndexOutOfRange: public std::exception {
// private:
//     const char * exception;
// public:
//     IndexOutOfRange(): exception("Index out of range !") {};
//    const char * what () const throw () {
//       return exception;
//    }
// };

// template <class T>
// class iterator: public std::iterator<std::random_access_iterator_tag, T>
// {
//         T* p;
//     public:
//         iterator(): p(0) {}
//         iterator(T* x): p(x) {}
//         iterator(const iterator& mit) : p(mit.p) {}
//         iterator& operator++() {++p;return *this;}
//         iterator& operator--() {--p;return *this;}
//         bool operator==(const iterator& rhs) const {return p==rhs.p;}
//         bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
//         int& operator*() {return *p;}
// };

// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>
//   struct iterator {
//     typedef T         value_type;
//     typedef Distance  difference_type;
//     typedef Pointer   pointer;
//     typedef Reference reference;
//     typedef Category  iterator_category;
//   };

template <class T>
class Vector
{
private:
    T* data;
    T* _begin;
    T* _end;
    T* _capacity;
    std::allocator<T> alloc;

public:
    Vector();
    Vector( int n, T val );
    Vector( T* first, T* last );
    Vector(const Vector& arr);
    Vector&  operator=(const Vector& arr);
    T&      operator[] (int index) const ;
    ~Vector();

    int size() const ;
    int capacity() const ;

    class iterator
    {
            T* p;
        public:
            iterator(): p(0) {}
            iterator(T* x): p(x) {}
            iterator operator=(const iterator& rhs) const { iterator iter(rhs.p);
                return iter;} 
            // iterator(const iterator& mit) : p(mit.p) {}
            iterator& operator++() {++p;return *this;}
            iterator& operator--() {--p;return *this;}
            bool operator==(const iterator& rhs) const {return p==rhs.p;}
            bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
            T& operator*() {return *p;}
    };

    iterator begin() { iterator iter(data);
        return iter; };
    iterator end() {return iterator(data + this->size()); } ;

    // void  deepCopy(const Vector& arr);
    // IndexOutOfRange _ioor;
    
};

template<class T>
Vector<T>::Vector() {
    std::cout << "Empty container constructor called" << std::endl;
    this->_begin = data;
    this->_end = data;
    this->_capacity = data;
}

template<class T>
Vector<T>::Vector( int n, T val ) {
    std::cout << "Fill constructor called" << std::endl;
    this->data = alloc.allocate(n);
    for (int i = 0; i < n; i++)
        alloc.construct(data+i, val);
    this->_begin = data;
    this->_end = data + n;
    this->_capacity = data + n;
}

template<class T>
Vector<T>::Vector( T* first, T* last ) {
    int size = last - first;
    std::cout << "Range constructor called " << size << std::endl;
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

template<class T>
Vector<T>::~Vector() {
    std::cout << "Destructor called" << std::endl;
    if (this->capacity() > 0)
        alloc.deallocate(this->data, this->capacity());
}

template<class T>
int  Vector<T>::size() const {
    return this->_end - this->_begin;
}

template<class T>
int  Vector<T>::capacity() const {
    return this->_capacity - this->_begin;
}

// template<class T>
// void Vector<T>::deepCopy(const Vector& arr) {
//     if (this->size != 0)
//         delete [] this->data;
//     this->size = arr.size();
//     if (arr.data != 0)
//     {
//         this->data = new T[this->size];
//         for (int i = 0; i < this->size; i++)
//         {
//             this->data[i] = arr[i];
//         }
//     }
//     else
//         this->data = 0;
// }

// template<class T>
// Vector<T>::Vector(const Vector& arr):
// {
//     deepCopy(arr);
// }

// template<class T>
// Vector<T>&  Vector<T>::operator=(const Vector& arr) {
//     deepCopy(arr);
//     return *this;
// }

template<class T>
T&      Vector<T>::operator[] (int index) const {
    // if (index >= this->size()) {
    //     throw _ioor;
    // }
    return this->data[index];
}

// template<class T>
// std::ostream&   operator<<(std::ostream& out, Vector<T>& arr) {
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         out << arr[i] << std::endl;
//     }
//     return out;
// }

#endif