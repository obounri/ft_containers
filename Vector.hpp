#ifndef Vector_HPP
#define Vector_HPP

#include <string>
#include <exception>
#include <iostream>
#include <memory>

class IndexOutOfRange: public std::exception {
private:
    const char * exception;
public:
    IndexOutOfRange(): exception("Index out of range !") {};
   const char * what () const throw () {
      return exception;
   }
};

template <class T>
class Vector
{
private:
    T* data;
    int size;
    std::allocator<T> alloc;

public:
    Vector();
    Vector( int n, T val );
    Vector( int n, T val );
    Vector(const Vector& arr);
    Vector&  operator=(const Vector& arr);
    T&      operator[] (int index) const ;
    ~Vector();

    int size() const ;

    void  deepCopy(const Vector& arr);
    IndexOutOfRange _ioor;
    
};

template<class T>
Vector<T>::Vector() {
    size = 0;
    data = alloc.allocate(3);
}

template<class T>
Vector<T>::Vector( int n ) {
    this->data = new T[n];
    this->size = n;
}

template<class T>
Vector<T>::~Vector() {
    if (this->size != 0)
        delete [] this->data;
}

template<class T>
int  Vector<T>::size() const {
    return this->size;
}

template<class T>
void Vector<T>::deepCopy(const Vector& arr) {
    if (this->size != 0)
        delete [] this->data;
    this->size = arr.size();
    if (arr.data != 0)
    {
        this->data = new T[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = arr[i];
        }
    }
    else
        this->data = 0;
}

template<class T>
Vector<T>::Vector(const Vector& arr):
size(0)
{
    deepCopy(arr);
}

template<class T>
Vector<T>&  Vector<T>::operator=(const Vector& arr) {
    deepCopy(arr);
    return *this;
}

template<class T>
T&      Vector<T>::operator[] (int index) const {
    if (index >= this->size()) {
        throw _ioor;
    }
    return this->data[index];
}

template<class T>
std::ostream&   operator<<(std::ostream& out, Vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        out << arr[i] << std::endl;
    }
    return out;
}

#endif