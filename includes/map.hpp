/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:52:15 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 19:00:47 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utility.hpp"
#include "iterator.hpp"
#include <iostream>
#include <memory>
#include "RBtree.hpp"

#define MAP_MAX_SIZE 230584300921369395

namespace ft {
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > 
	>
	class map {
		public:
			typedef	Key																key_type;
			typedef	T																mapped_type;
			typedef ft::pair<const key_type, mapped_type>							value_type;
			typedef Compare															key_compare;

			class ValComp : std::binary_function<value_type, value_type, bool>
			{
				protected:
					Compare comp;
					ValComp(Compare c) : comp(c) {};
				
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool	operator()(const value_type &x, const value_type &y) const
					{
						return (comp(x.first, y.first));
					}
			};
			
			typedef ValComp																value_compare;
			typedef Allocator															allocator_type;
			typedef typename allocator_type::reference 									reference;
			typedef typename allocator_type::const_reference 							const_reference;
			typedef typename allocator_type::pointer 									pointer;
			typedef typename allocator_type::const_pointer 								const_pointer;
			typedef typename ft::RBtree<value_type>::iterator							iterator;
			typedef typename ft::RBtree<value_type>::const_iterator						const_iterator;
			typedef typename ft::RBtree<value_type>::reverse_iterator 					reverse_iterator;
			typedef typename ft::RBtree<value_type>::const_reverse_iterator				const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
			typedef size_t 																size_type;
			
		private:
			RBtree<value_type>	_data;
			key_compare			_comp;
			allocator_type		_alloc;
			
		public:
			/* -------------------------------------------------------------------------- */
			/*                          constructor / destructor                          */
			/* -------------------------------------------------------------------------- */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc) {}
			
			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) 
			{
				_comp = comp;
				_alloc = alloc;
				for (; first != last; first++)
					_data.addNode(*first);
			}

			map(const map &x)
			{
				_data.clear(_data.getRoot());
				_alloc = x._alloc;
				_comp = x._comp;
				insert(x.begin(), x.end());
			}

			~map(void) {
				_data.clear(_data.getRoot());
			}

			map	&operator=(const map &x)
			{
				_data.clear(_data.getRoot());
				_comp = x._comp;
				insert(x.begin(), x.end());
				return (*this);
			}
			
			/* -------------------------------------------------------------------------- */
			/*                                  iterator                                  */
			/* -------------------------------------------------------------------------- */
			iterator begin(void)
			{
				return (_data.begin());
			}

			const_iterator begin(void) const
			{
				return (_data.begin());
			}

			iterator end(void)
			{
				return (_data.end());
			}

			const_iterator end(void) const
			{
				return (_data.end());
			}

			reverse_iterator rbegin(void)
			{
				return (_data.rbegin());
			}

			const_reverse_iterator rbegin(void) const
			{
				return (_data.rbegin());
			}

			reverse_iterator rend(void)
			{
				return (_data.rend());
			}

			const_reverse_iterator rend(void) const
			{
				return (_data.rend());
			}

			/* -------------------------------------------------------------------------- */
			/*                                  capacity                                  */
			/* -------------------------------------------------------------------------- */
			bool	empty() const
			{
				return (_data.getSize() == 0 ? true : false);
			}

			size_type	size() const
			{
				return (_data.getSize());
			}

			size_type	max_size() const
			{
				return (MAP_MAX_SIZE);
			}

			/* -------------------------------------------------------------------------- */
			/*                               element_access                               */
			/* -------------------------------------------------------------------------- */
			mapped_type &operator[](const key_type &k)
			{
				value_type	pair = ft::make_pair(k, mapped_type());

				typename ft::RBtree<value_type>::NodePtr node = _data.search(pair);
				if (!node)
				{
					_data.addNode(pair);
					return (_data.search(pair)->_pair.second);
				}
				return (node->_pair.second);
			}

			/* -------------------------------------------------------------------------- */
			/*                                  modifiers                                 */
			/* -------------------------------------------------------------------------- */
			pair<iterator, bool> insert(const value_type &val)
			{
				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(val);
				if (nodeFound)
					return (ft::make_pair(iterator(nodeFound), false));
				_data.addNode(val);
				return (ft::make_pair(iterator(_data.search(val)), true));
			}

			iterator	insert(iterator position, const value_type &val)
			{
				(void)position;
				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(val);
				if (nodeFound)
					return (iterator(nodeFound));
				_data.addNode(val);
				return (iterator(_data.search(val)));
			}

			template<class InputIterator>
			void	insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* =0)
			{
				for (; first != last; first++)
				{
					if (!_data.search(*first))
						_data.addNode(*first);
				}
			}

			void	erase(iterator position)
			{
				_data.deleteNode(position->first);
			}

			void	erase(iterator first, iterator last)
			{
				iterator tmp;
				
				while (first != last)
				{
					tmp = first;
					first++;
					_data.deleteNode(tmp->first);
				}
			}

			size_type	erase(const key_type &key)
			{
				value_type	pair = ft::make_pair(key, mapped_type());

				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(pair);
				if (!nodeFound)
					return (0);
				_data.deleteNode(nodeFound->_pair.first);
				return (1);
			}

			void	clear(void)
			{
				_data.clear(_data.getRoot());
			}

			// /* -------------------------------------------------------------------------- */
			// /*                                  observer                                  */
			// /* -------------------------------------------------------------------------- */
			key_compare key_comp(void) const
			{
				return (_comp);
			}

			value_compare value_comp(void) const
			{
				return (value_compare::comp);
			}

			// /* -------------------------------------------------------------------------- */
			// /*                                  operation                                 */
			// /* -------------------------------------------------------------------------- */
			iterator find(const key_type &k)
			{
				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(ft::make_pair(k, mapped_type()));
				if (!nodeFound)
					return (end());
				return (iterator(nodeFound));
			}

			const_iterator find(const key_type& k) const
			{
				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(ft::make_pair(k, mapped_type()));
				if (!nodeFound)
					return (end());
				return (iterator(nodeFound));
			}

			size_type count(const key_type& k) const
			{
				return (_data.search(ft::make_pair(k, mapped_type())) ? 1 : 0);
			}

			iterator lower_bound(const key_type& k)
			{
				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(ft::make_pair(k, mapped_type()));
				if (!nodeFound)
				{
					for (iterator it = begin(); it != end(); it++)
					{
						if ((_comp(k, it->first)))
							return (it);
					}
					return (end());
				}
				return (iterator(nodeFound));
			}

			const_iterator lower_bound(const key_type& k) const
			{
				typename ft::RBtree<value_type>::NodePtr nodeFound = _data.search(ft::make_pair(k, mapped_type()));
				if (!nodeFound)
				{
					for (const_iterator it = begin(); it != end(); it++)
					{
						if ((_comp(k, it->first)))
							return (it);
					}
					return (end());
				}
				return (const_iterator(nodeFound));
			}

			iterator upper_bound(const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if ((_comp(it->first, k)))
						return (it);
				}
				return (end());
			}

			const_iterator upper_bound(const key_type& k) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if ((_comp(it->first, k)))
						return (it);
				}
				return (end());
			}

			pair<iterator,iterator> equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

			void	swap (map &x)
			{
				ft::swapT(this->_alloc, x._alloc);
				ft::swapT(this->_comp, x._comp);
				_data.swap(x._data);
			}
	};
}