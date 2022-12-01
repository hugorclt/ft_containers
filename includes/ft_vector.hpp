/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/11/29 23:55:52 by hrecolet         ###   ########.fr       */
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

namespace ft {
	//Template : allocator<T> to allocate memory accordingly to the type of the vector
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:
			typedef	T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference 					reference;
			typedef typename allocator_type::const_reference 			const_reference;
			typedef typename allocator_type::pointer 					pointer;
			typedef typename allocator_type::const_pointer 				const_pointer;
			typedef random_access_iterator<value_type> 					iterator;
			typedef random_access_iterator<const value_type>			const_iterator;
			typedef random_access_iterator<value_type> 					reverse_iterator; //FIX
			typedef	random_access_iterator<const value_type>			const_reverse_iterator; //FIX
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
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
			explicit	vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {
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
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				difference_type	size = distance(first, last);
				
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
			vector(const vector& x) {
				_array = _allocator.allocate(x._maxSize);
				_currentSize = x._currentSize;
				*(_array) = *(x._array);
				_maxSize = x._maxSize;
			}

			vector	&operator=(const vector &x) {
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

			~vector() {
				clear();
				_allocator.deallocate(_array, _maxSize);
			}

			/* -------------------------------------------------------------------------- */
			/*                               element_access                               */
			/* -------------------------------------------------------------------------- */

			reference	operator[](size_type n) {
				return (*(_array + n));
			}

			const_reference	operator[](size_type n) const {
				return (*(_array) + n);
			}

			reference	at(size_type n) {
				if (n > _currentSize || n < 0)
					throw std::out_of_range("ArrayList<X>::at() : index is out of range");
				else
					return (*(_array + n));
			}

			const_reference	at(size_type n) const {
				if (n > _currentSize || n < 0)
					throw std::out_of_range("ArrayList<X>::at() : index is out of range");
				else
					return (*(_array + n));
			}

			reference	front() {
				return (*_array);
			}

			const_reference	front() const {
				return (*_array);
			}

			reference	back() {
				return (*(_array + _currentSize - 1));
			}

			const_reference	back() const {
				return (*(_array + _currentSize - 1));
			}

			/* -------------------------------------------------------------------------- */
			/*                                  iterator                                  */
			/* -------------------------------------------------------------------------- */
			
			iterator	begin() {
				return (iterator(_array));
			}

			iterator	end() {
				return (iterator(&_array[_currentSize]));
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(_array));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(&_array[_currentSize]));
			}
			
			/* -------------------------------------------------------------------------- */
			/*                                   capacity                                 */
			/* -------------------------------------------------------------------------- */
			
			size_type	size() const {
				return (_currentSize);
			}

			size_type	max_size() const {
				return (_allocator.max_size());
			}

			size_type	capacity() const {
				return (_maxSize);
			}

			bool	empty() const {
				return (_currentSize <= 0);
			}

			/* -------------------------------------------------------------------------- */
			/*                                  Modifiers                                 */
			/* -------------------------------------------------------------------------- */

			void	reserve(size_type n) {
				if (n >= _maxSize)
				{
					_allocator.allocate(n);
					_maxSize = n;
				}
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n == _currentSize)
					return ;
			}

			void	clear() {
				_allocator.destroy(_array);
			}
	};
}
