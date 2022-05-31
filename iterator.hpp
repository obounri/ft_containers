#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
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
        vector_iterator( const vector_iterator& iter ) : p(iter.p) {}

        vector_iterator operator=( const vector_iterator& rhs ) {
            if (*this == rhs)
                return *this;
            this->p = rhs.p;
            return *this;}

        iterator_type base() const { return (this->p); }
        
        pointer operator->() const { return &(operator*()); }
        reference operator*() {return *p;}
        
        reference operator[]( difference_type n ) const { return (this->base())[n]; }

        vector_iterator& operator++() {++p;return *this;}
        vector_iterator& operator--() {--p;return *this;}
        vector_iterator operator++( int ) { vector_iterator old(*this); ++p;return old; }
        vector_iterator operator--( int ) { vector_iterator old(*this); --p;return old; }
        vector_iterator operator+(difference_type _off) const { return vector_iterator(this->p + _off); }
        vector_iterator & operator+= (difference_type _off) { this->p += _off; return (*this); }
        vector_iterator operator-(difference_type _off) const { return vector_iterator(this->p - _off); }
        vector_iterator & operator-= (difference_type _off) { this->p -= _off; return (*this); }

        bool operator==(const vector_iterator& _rhs) { return this->base() == _rhs.base(); }
        bool operator!=(const vector_iterator& _rhs) { return this->base() != _rhs.base(); }
        bool operator<(const vector_iterator& _rhs) { return this->base() < _rhs.base(); }
        bool operator<=(const vector_iterator& _rhs) { return this->base() <= _rhs.base(); }
        bool operator>(const vector_iterator& _rhs) { return this->base() > _rhs.base(); }
        bool operator>=(const vector_iterator& _rhs) { return this->base() >= _rhs.base(); }

        difference_type operator-(const vector_iterator& _rhs) { return _rhs.base() - this->base(); }


    };

    template <class Iter> 
    vector_iterator<Iter> operator+(typename vector_iterator<Iter>::difference_type n, const vector_iterator<Iter>& _rhs) { return vector_iterator<Iter>(_rhs.base() + n); }

    namespace ft {
        template <class Iter> 
        class reverse_iterator : public iterator<typename iterator_traits<Iter>::iterator_category,
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
            reverse_iterator(): p(0) {}
            reverse_iterator(iterator_type x): p(x) {}
            reverse_iterator( const reverse_iterator& iter ) : p(iter.p) {}

            reverse_iterator operator=( const reverse_iterator& rhs ) {
                if (*this == rhs)
                    return *this;
                this->p = rhs.p;
                return *this;}

            iterator_type base() const { return (this->p); }
            
            pointer operator->() const { return &(operator*()); }
            reference operator*() {return *p;}
            
            reference operator[]( difference_type n ) const { return (this->base())[-n - 1]; }

            reverse_iterator& operator++() {--p;return *this;}
            reverse_iterator& operator--() {++p;return *this;}
            reverse_iterator operator++( int ) { reverse_iterator old(*this); --p;return old; }
            reverse_iterator operator--( int ) { reverse_iterator old(*this); ++p;return old; }
            reverse_iterator operator+(difference_type _off) const { return reverse_iterator(this->p - _off); }
            reverse_iterator & operator+= (difference_type _off) { this->p -= _off; return (*this); }
            reverse_iterator operator-(difference_type _off) const { return reverse_iterator(this->p + _off); }
            reverse_iterator & operator-= (difference_type _off) { this->p += _off; return (*this); }

            bool operator==(const reverse_iterator& _rhs) { return this->base() == _rhs.base(); }
            bool operator!=(const reverse_iterator& _rhs) { return this->base() != _rhs.base(); }
            bool operator<(const reverse_iterator& _rhs) { return this->base() > _rhs.base(); }
            bool operator<=(const reverse_iterator& _rhs) { return this->base() >= _rhs.base(); }
            bool operator>(const reverse_iterator& _rhs) { return this->base() < _rhs.base(); }
            bool operator>=(const reverse_iterator& _rhs) { return this->base() <= _rhs.base(); }

            difference_type operator-(const reverse_iterator& _rhs) { return _rhs.base() - this->base(); }

        };

        template <class Iter> 
        reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& _rhs) { return reverse_iterator<Iter>(_rhs.base() - n); }
    }

}

#endif