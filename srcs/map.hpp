#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "pair.hpp"
# include "Tree.hpp"
# include "Type_traits.hpp"

namespace ft {
	template < class Key,
				class T,
				class Compare = std::less<Key>,
				class Alloc = std::allocator< ft::pair<const Key,T> >
				>
	class map
	{
	public:
		typedef Key 								key_type;
		typedef T 									mapped_type;
		typedef pair<const key_type, mapped_type> 	value_type;
		typedef Compare 							key_compare;
		class value_compare
		{
			friend class map;
		protected:
			Compare _comp;
			value_compare(Compare _c) : _comp(_c) {}
		public:
			typedef bool result_type;
			typedef value_type first_type;
			typedef value_type second_type;
			result_type operator()(const value_type& _x,  const value_type& _y) const
			{
				return (_comp(_x.first, _y.first));
			}
		};
		typedef Alloc 															allocator_type;
		typedef typename allocator_type::reference 								reference;
		typedef typename allocator_type::const_reference 						const_reference;
		typedef typename allocator_type::pointer 								pointer;
		typedef typename allocator_type::const_pointer 							const_pointer;
		typedef typename ft::tree<value_type, value_compare, allocator_type> 	tree;
		typedef typename ft::node<value_type> 									node;
		typedef node* 															node_pointer;
		typedef tree_iterator<node_pointer, pointer> 							iterator;
		typedef tree_iterator<node_pointer, const_pointer> 						const_iterator;
		typedef typename ft::reverse_iterator<iterator> 						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type 			difference_type;
		typedef size_t															size_type;

	private:
		tree 			_tree;
		allocator_type	_alloc;
		key_compare		_comp;

	public:
		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc), _alloc(alloc), _comp(comp)
		{
		}
		template <class InputIterator>
  		map (InputIterator first, InputIterator last,
       		const key_compare& comp = key_compare(),
       		const allocator_type& alloc = allocator_type()): _tree(value_compare(comp), alloc),  _alloc(alloc), _comp(comp)
		{
			this->insert(first, last);
		}
		
		map (const map& _m) : _tree(value_compare(_m._comp), _m._alloc),  _alloc(_m._alloc), _comp(_m._comp)
		{
			*this = _m;
		}

		map& operator=(const map& _m)
		{
			if (this != &_m)
			{
				this->clear();
				this->_alloc = _m._alloc;
				this->_comp = _m._comp;
				this->insert(_m.begin(), _m.end());
			}
			return *this;
		}

		~map()
		{
		}

		/* begin */
		iterator begin()
		{
			return iterator(_tree.begin());
		}
		const_iterator begin() const
		{
			return const_iterator(_tree.begin());
		}

		iterator end()
		{
			return iterator(_tree.end());
		}

		const_iterator end() const
		{
			return const_iterator(_tree.end());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(this->end());
		}
		
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		bool empty() const
		{
			return this->size() == 0;
		}

		size_type size() const
		{
			return _tree.size();
		}

		size_type max_size() const
		{
			return (std::min<size_type>(this->_alloc.max_size(), std::numeric_limits<difference_type>::max()));
		}

		mapped_type& operator[] (const key_type& _k)
		{
			iterator _f = this->find(_k);
			if (_f != this->end())
				return ((*_f).second);
			return (*((this->insert(ft::make_pair(_k, mapped_type()))).first)).second;
		}

		void clear()
		{
			this->_tree.clear();
		}

		pair<iterator,bool> insert (const value_type& val)
		{
			iterator _f = this->find(val.first);
			if (_f == this->end())
			{
				this->_tree.insert(val);
				_f = this->find(val.first);
				return pair<iterator,bool>(_f, true);
			}
			return pair<iterator,bool>(_f, false);
		}

		iterator insert (iterator position, const value_type& val)
		{
			position = this->find(val.first);
			if (position != this->end())
				return (position);
			this->insert(val);
			return (this->find(val.first));
		}
		
		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				this->insert(*first);
		}

		void erase (iterator position)
		{
			if (this->find((*position).first) != this->end())
				this->_tree.erase(*position);
		}

		size_type erase (const key_type& _k)
		{
			iterator _f = this->find(_k);
			if (_f != this->end())
			{
				this->erase(_f);
				return (1);
			}
			return (0);
		}

		void erase (iterator first, iterator last)
		{
			while (first != last)
				this->erase(first++);
		}

		iterator find (const key_type& _k)
		{
			node_pointer _y = this->_tree.find(ft::make_pair(_k, mapped_type()));
			if (_y == nullptr)
				return this->end();
			return iterator(_y);
		}

		const_iterator find (const key_type& _k) const
		{
			node_pointer _y = this->_tree.find(ft::make_pair(_k, mapped_type()));
			if (_y == nullptr)
				return this->end();
			return const_iterator(_y);
		}

		void swap (map& _x)
		{
			_tree.swap(_x._tree);
			std::swap(this->_comp, _x._comp);
			std::swap(this->_alloc, _x._alloc);
		}

		key_compare key_comp() const
		{
			return this->_comp;
		}

		value_compare value_comp() const
		{
			return value_compare(this->_comp);
		}

		size_type count (const key_type& _k) const
		{
			return (this->find(_k) != this->end());
		}

		iterator lower_bound (const key_type& _k)
		{
			return _tree.lower_bound(make_pair(_k, mapped_type()));
		}

		const_iterator lower_bound (const key_type& _k) const
		{
			return _tree.lower_bound(make_pair(_k, mapped_type()));
		}

		iterator upper_bound (const key_type& _k)
		{
			return _tree.upper_bound(make_pair(_k, mapped_type()));
		}

		const_iterator upper_bound (const key_type& _k) const
		{
			return _tree.upper_bound(make_pair(_k, mapped_type()));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& _k) const
		{
			return pair<const_iterator,const_iterator>(lower_bound(_k), upper_bound(_k));
		}

		pair<iterator,iterator> equal_range (const key_type& _k)
		{
			return pair<iterator,iterator>(lower_bound(_k), upper_bound(_k));
		}

		allocator_type get_allocator() const
		{
			return  this->_alloc;
		}
	};
} // end namespace ft
#endif