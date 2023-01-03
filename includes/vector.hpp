/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:59 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/03 14:57:51 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "define.hpp"
#include <exception>
#include "iterator.hpp"
#include "utility.hpp"

namespace ft
{
	//Template : allocator<T> to allocate memory accordingly to the type of the vector
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference 					reference;
			typedef typename allocator_type::const_reference 			const_reference;
			typedef typename allocator_type::pointer 					pointer;
			typedef typename allocator_type::const_pointer 				const_pointer;
			typedef typename ft::random_access_iterator<value_type> 					iterator;
			typedef typename ft::random_access_iterator<const value_type>			const_iterator;
			typedef typename ft::reverse_random_access_iterator<value_type> 					reverse_iterator; //FIX
			typedef	typename ft::reverse_random_access_iterator<const value_type>			const_reverse_iterator; //FIX
			typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
			typedef size_t 												size_type;
		
		private:
			T				*_array;
			size_t			_currentSize; //current element in the vector
			size_t			_maxSize; //vector max capacity allocated actually
			allocator_type	_allocator;
			
		public:
			/* -------------------------------------------------------------------------- */
			/*                                 constructor                                */
			/* -------------------------------------------------------------------------- */
			/*
			@Default constructor
			Constructs an empty container, with no elements.
			*/
			explicit	vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _currentSize(0), _maxSize(0), _allocator(alloc) {}
			
			/*
			@fill constructor
			Constructs a container with n elements. Each element is a copy of val.
			*/
			explicit	vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			{
				_array = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&_array[i], val);
				_currentSize = n;
				_maxSize = n;
				_allocator = alloc;
			}

			/*
			@Range constructor
			Constructs a container with as many elements as the range [first,last), 
			with each element constructed from its corresponding element in that range, 
			in the same order.
			*/
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				difference_type	size = ft::distance(first, last);
				
				_currentSize = size;
				_maxSize = size;
				_allocator = alloc;
				_array = _allocator.allocate(size);
				for (int i = 0; first != last; i++, first++)
					_allocator.construct(&_array[i], *first);
			}

			/*
			@Copy constructor
			Constructs a container with a copy of each of the elements in x, in the same order.
			*/
			vector(const vector& x)
			{
				_array = _allocator.allocate(x._maxSize);
				_currentSize = x._currentSize;
				for (size_type i = 0; i < x._currentSize; i++)
					_allocator.construct(&_array[i], x._array[i]);
				_maxSize = x._maxSize;
			}

			vector	&operator=(const vector &x)
			{
				clear();
				_allocator.deallocate(_array, _maxSize);
				_array = _allocator.allocate(x._maxSize);
				for (size_type i = 0; i < x._currentSize; i++)
					_allocator.construct(&_array[i], x._array[i]);
				_currentSize = x._currentSize;
				_maxSize = x._maxSize;
				return (*this);
			}

			/* -------------------------------------------------------------------------- */
			/*                                 destructor                                 */
			/* -------------------------------------------------------------------------- */

			~vector()
			{
				
				clear();
				_allocator.deallocate(_array, _maxSize);
			}

			/* -------------------------------------------------------------------------- */
			/*                               element_access                               */
			/* -------------------------------------------------------------------------- */

			reference	operator[](size_type n)
			{
				return (*(_array + n));
			}

			const_reference	operator[](size_type n) const
			{
				return (_array[n]);
			}

			reference	at(size_type n)
			{
				if (n > _currentSize || n < 0)
					throw std::out_of_range("ArrayList<X>::at() : index is out of range");
				else
					return (*(_array + n));
			}

			const_reference	at(size_type n) const
			{
				if (n > _currentSize || n < 0)
					throw std::out_of_range("ArrayList<X>::at() : index is out of range");
				else
					return (*(_array + n));
			}

			reference	front()
			{
				return (*_array);
			}

			const_reference	front() const
			{
				return (*_array);
			}

			reference	back()
			{
				return (*(_array + _currentSize - 1));
			}

			const_reference	back() const
			{
				return (*(_array + _currentSize - 1));
			}

			allocator_type get_allocator() const
			{
				return (_allocator);
			}

			/* -------------------------------------------------------------------------- */
			/*                                  iterator                                  */
			/* -------------------------------------------------------------------------- */
			
			iterator	begin()
			{
				return (iterator(_array));
			}

			iterator	end()
			{
				return (iterator(&_array[_currentSize]));
			}

			const_iterator	begin() const
			{
				return (iterator(_array));
			}

			const_iterator	end() const
			{
				return (iterator(&_array[_currentSize]));
			}


			reverse_iterator	rbegin()
			{
				return (reverse_iterator(&_array[_currentSize - 1]));
			}

			reverse_iterator	rend()
			{
				return (reverse_iterator(_array - 1));
			}

			const_reverse_iterator	rbegin() const
			{
				return (reverse_iterator(&_array[_currentSize - 1]));
			}

			const_reverse_iterator	rend() const
			{
				return (reverse_iterator(_array - 1));
			}
			
			/* -------------------------------------------------------------------------- */
			/*                                   capacity                                 */
			/* -------------------------------------------------------------------------- */
			
			size_type	size() const
			{
				return (_currentSize);
			}

			size_type	max_size() const
			{
				return (_allocator.max_size());
			}

			size_type	capacity() const
			{
				return (_maxSize);
			}

			bool	empty() const
			{
				return (_currentSize <= 0);
			}

			void	reserve(size_type n) 
			{
				if (n > _maxSize)
				{
					size_type	save_size = _currentSize;
					value_type	*tmp = _allocator.allocate(n);

					for (size_type i = 0; i < _currentSize; i++)
						_allocator.construct(&tmp[i], _array[i]);
					clear();
					_allocator.deallocate(_array, _maxSize);
					_maxSize = n;
					_currentSize = save_size;
					_array = tmp;
				}
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n == _currentSize)
					return ;
				else if (n < _currentSize)
				{
					for (size_type i = n; i < _currentSize; i++)
						_allocator.destroy(&(_array[i++]));
				}
				else
				{
					reserve(n);
					for (size_type i = _currentSize; i < n; i++)
						_allocator.construct(&_array[i], val);
				}
				_currentSize = n;
			}
			/* -------------------------------------------------------------------------- */
			/*                                  Modifiers                                 */
			/* -------------------------------------------------------------------------- */

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				difference_type	size = ft::distance(first, last);
				
				reserve(size);
				clear();
				for (size_type i = 0; first != last; first++, i++)
					_allocator.construct(&_array[i], *first);
				_currentSize = size;
			}

			void	assign(size_type n, const value_type &val)
			{
				reserve(n);
				clear();
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&_array[i], value_type(val));
				_currentSize = n;
			}

			void	push_back(const value_type &val)
			{
				if (_currentSize + 1 > _maxSize)
				{
					if (_maxSize > 0)
						reserve(_maxSize * 2);
					else
						reserve(_maxSize + 1);
				}
				_allocator.construct(&_array[_currentSize], value_type(val));
				_currentSize = _currentSize + 1;
			}

			void	pop_back(void)
			{
				if (_currentSize == 0)
					return ; 
				resize(_currentSize - 1, 0);
			}

			void	clear()
			{
				for (size_type i = 0; i < _currentSize; i++)
				{
					_allocator.destroy(&(_array[i]));
				}
				_currentSize = 0;
			}

			iterator	insert(iterator position, const value_type &val)
			{
				difference_type	posIt = ft::distance(begin(), position);
				
				if (_currentSize + 1 > _maxSize)
					reserve((_maxSize) ? _maxSize * 2 : 1);
				for (difference_type i = _currentSize - 1; i > posIt - 1; i--)
				{
					_allocator.construct(&_array[i + 1], _array[i]);
					_allocator.destroy(&(_array[i]));
				}
				_allocator.construct(&_array[posIt], val);
				_currentSize += 1;
				return (iterator(&(_array[posIt])));
			}

			void	insert(iterator position, size_type n, const value_type &val)
			{
				difference_type	posIt = ft::distance(begin(), position);

				while (_currentSize + n > _maxSize)
					reserve((_maxSize) ? _maxSize * 2 : 1);
				for (difference_type i = _currentSize - 1; i > posIt - 1; i--)
				{
					_allocator.construct(&_array[i + n], _array[i]);
					_allocator.destroy(&(_array[i]));
				}
				for (size_type i = posIt; i < _currentSize + n; i++)
					_allocator.construct(&_array[i], val);
				_currentSize += n;
			}

			template<class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				difference_type	posIt = ft::distance(begin(), position);
				difference_type	size = ft::distance(first, last);
				
				while (_currentSize + size > _maxSize)
					reserve((_maxSize) ? _maxSize * 2 : 1);
				for (difference_type i = _currentSize - 1; i > posIt - 1; i--)
				{
					_allocator.construct(&_array[i + size], _array[i]);
					_allocator.destroy(&(_array[i]));
				}
				for (size_type i = posIt; first != last; i++, first++)
					_allocator.construct(&_array[i], *first);
				_currentSize += size;
			}

			iterator	erase(iterator first, iterator last)
			{
				difference_type	posIt = ft::distance(begin(), first);
				difference_type	size = ft::distance(first, last);
				
				for (size_type i = posIt; i < _currentSize; i++)
				{
					_allocator.destroy(&(_array[i]));
					if (i + size < _currentSize)
						_allocator.construct(&_array[i], _array[i + size]);
				}
				_currentSize -= size;
				return (_currentSize ? iterator(&(_array[posIt])) : end());
			}
			
			iterator	erase(iterator position)
			{
				difference_type	posIt = ft::distance(begin(), position);
				
				for (size_type i = posIt; i < _currentSize; i++)
				{
					_allocator.destroy(&(_array[i]));
					if (i + 1 < _currentSize)
					_allocator.construct(&_array[i], _array[i + 1]);
				}
				_currentSize -= 1;
				return (_currentSize ? iterator(&(_array[posIt])) : end());
			}

			void	swap(vector &x)
			{
				vector<value_type> tmp = x;
				
				x = *this;
				*this = tmp;
			}

			/* -------------------------- relationnal operator -------------------------- */
			template <class Type, class Allocator>
			friend bool operator== (const vector<Type,Allocator>& lhs, const vector<Type,Allocator>& rhs);
			template <class Type, class Allocator>
			friend bool operator!= (const vector<Type,Allocator>& lhs, const vector<Type,Allocator>& rhs);
			template <class Type, class Allocator>
			friend bool operator<  (const vector<Type,Allocator>& lhs, const vector<Type,Allocator>& rhs);
			template <class Type, class Allocator>
			friend bool operator<= (const vector<Type,Allocator>& lhs, const vector<Type,Allocator>& rhs);
			template <class Type, class Allocator>
			friend bool operator>  (const vector<Type,Allocator>& lhs, const vector<Type,Allocator>& rhs);
			template <class Type, class Allocator>
			friend bool operator>= (const vector<Type,Allocator>& lhs, const vector<Type,Allocator>& rhs);
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<const T,Alloc>::iterator it2 = rhs.begin();
		for (typename vector<const T,Alloc>::iterator it = lhs.begin(); it != lhs.end(); it++, it2++)
		{
			if ((*it) != (*it2))
				return (false);
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);
		typename vector<const T,Alloc>::iterator it2 = rhs.begin();
		for (typename vector<const T,Alloc>::iterator it = lhs.begin(); it != lhs.end(); it++, it2++)
		{
			if ((*it) != (*it2))
				return (true);
		}
		return (false);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexixographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!lexixographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexixographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!lexixographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
}
