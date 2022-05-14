#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

template <class Iter>
class vector_iterator : public iterator<std::random_access_iterator_tag,
                                typename iterator_traits<Iter>::value_type
                                >
{
public:
    typedef Iter	                                                   	iterator_type;
    typedef typename iterator_traits<Iter>::difference_type				difference_type;
    typedef typename iterator_traits<Iter>::pointer						pointer;
    typedef typename iterator_traits<Iter>::reference					reference;
private:
    iterator_type p;

public:
    vector_iterator(): p(0) {}
    vector_iterator(iterator_type x): p(x) {}
    vector_iterator operator=( const vector_iterator& rhs ) {
        if (*this == rhs)
            return *this;
        this->p = rhs.p;
        return *this;}
    vector_iterator( const vector_iterator& iter ) : p(iter.p) {}
    vector_iterator& operator++() {++p;return *this;}
    vector_iterator& operator--() {--p;return *this;}
    vector_iterator operator++( int ) { vector_iterator old(*this); ++p;return old; }
    vector_iterator operator--( int ) { vector_iterator old(*this); --p;return old; }
    pointer operator->() const { return &(operator*()); }
    bool operator==(const vector_iterator& rhs) const {return p==rhs.p;}
    bool operator!=(const vector_iterator& rhs) const {return p!=rhs.p;}
    vector_iterator operator+(difference_type _off) const { return vector_iterator(this->p + _off); }
    vector_iterator & operator+= (difference_type _off) { this->p += _off; return (*this); }
    vector_iterator operator-(difference_type _off) const { return vector_iterator(this->p - _off); }
    vector_iterator & operator-= (difference_type _off) { this->p -= _off; return (*this); }
    reference operator*() {return *p;}


	iterator_type base() const { return (this->p); }

};

template <class Iter>
bool operator==(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return _lhs.base() == _rhs.base();
}
template <class Iter>
bool operator!=(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return !(_lhs == _rhs);
}
template <class Iter>
vector_iterator<Iter> operator+(typename vector_iterator<Iter>::difference_type n, const vector_iterator<Iter>& _current)
{
    return vector_iterator<Iter>(_current + n);
}
template <class Iter>
typename vector_iterator<Iter>::difference_type operator-(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return _lhs.base() - _rhs.base();
}
template <class Iter>
bool operator<(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return _lhs.base() < _rhs.base();
}
template <class Iter>
bool operator>(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return _lhs.base() > _rhs.base();
}
template <class Iter>
bool operator<=(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return (_lhs < _rhs || _lhs == _rhs);
}
template <class Iter>
bool operator>=(const vector_iterator<Iter>& _lhs, const vector_iterator<Iter>& _rhs)
{
    return (_lhs > _rhs || _lhs == _rhs);
}

template <class Iter> 
class reverse_iter : public iterator<typename iterator_traits<Iter>::iterator_category,
                                            typename iterator_traits<Iter>::value_type,
                                            typename iterator_traits<Iter>::difference_type,
                                            typename iterator_traits<Iter>::pointer,
                                            typename iterator_traits<Iter>::reference
                                            >
{
public:
    typedef Iter	                                                     	iterator_type;
    typedef typename iterator_traits<Iter>::difference_type				difference_type;
    typedef typename iterator_traits<Iter>::pointer						pointer;
    typedef typename iterator_traits<Iter>::reference					reference;
private:
    iterator_type p;

public:
    reverse_iter(): p(0) {}
    reverse_iter(iterator_type x): p(x) {}
    reverse_iter operator=( const reverse_iter& rhs ) {
        if (*this == rhs)
            return *this;
        this->p = rhs.p;
        return *this;}
    reverse_iter( const reverse_iter& iter ) : p(iter.p) {}
    reverse_iter& operator++() {--p;return *this;}
    reverse_iter& operator--() {++p;return *this;}
    reverse_iter operator++( int ) { reverse_iter old(*this); --p;return old; }
    reverse_iter operator--( int ) { reverse_iter old(*this); ++p;return old; }
    pointer operator->() const { return &(operator*()); }
    bool operator==(const reverse_iter& rhs) const {return p==rhs.p;}
    bool operator!=(const reverse_iter& rhs) const {return p!=rhs.p;}
    reverse_iter operator+(difference_type _off) const { return reverse_iter(this->p - _off); }
    reverse_iter & operator+= (difference_type _off) { this->p -= _off; return (*this); }
    reverse_iter operator-(difference_type _off) const { return reverse_iter(this->p + _off); }
    reverse_iter & operator-= (difference_type _off) { this->p += _off; return (*this); }
    reference operator*() {return *p;}

    iterator_type base() const { return (this->p); }

};

template <class Iter>
bool operator==(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() == _rhs.base();
}
template <class Iter>
bool operator!=(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() != _rhs.base();
}
template <class Iter>
bool operator<(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() > _rhs.base();
}
template <class Iter>
bool operator<=(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() >= _rhs.base();
}
template <class Iter>
bool operator>(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() < _rhs.base();
}
template <class Iter>
bool operator>=(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() <= _rhs.base();
}
template <class Iter>
reverse_iter<Iter> operator+(typename reverse_iter<Iter>::difference_type _n,
        const reverse_iter<Iter>& rev_it)
{
    return reverse_iter<Iter>(rev_it - _n);
}
template <class Iter>
typename reverse_iter<Iter>::difference_type operator-(const reverse_iter<Iter>& _lhs,
        const reverse_iter<Iter>& _rhs)
{
    return _lhs.base() - _rhs.base();
}

#endif