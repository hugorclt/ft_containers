/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/09/17 17:28:03 by hrecolet         ###   ########.fr       */
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
			T				*array;
			size_t			currentSize; //current element in the vector
			size_t			maxSize; //vector max capacity allocated actually
			allocator_type	allocator;
			
		public:
			/* -------------------------------------------------------------------------- */
			/*                                 constructor                                */
			/* -------------------------------------------------------------------------- */
			/*
			@Default constructor
			Constructs an empty container, with no elements.
			*/
			explicit	vector(const allocator_type& alloc = allocator_type()) : array(NULL), currentSize(0), maxSize(0), allocator(alloc) {}
			
			/*
			@fill constructor
			Constructs a container with n elements. Each element is a copy of val.
			*/
			explicit	vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {
				this->array = this->allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->allocator.construct(&this->array[i], val);
				this->currentSize = n;
				this->maxSize = n;
				this->allocator = alloc;
			}

			/*
			@Range constructor
			Constructs a container with as many elements as the range [first,last), 
			with each element constructed from its corresponding element in that range, 
			in the same order.
			*/
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				difference_type	size = distance(first, last) + 1;
				
				this->array = this->allocator.allocate(size);
				for (int i = 0; first != last; i++, first++)
					this->allocator.construct(&this->array[i], *first);
				this->currentSize = size;
				this->maxSize = size;
				this->allocator = alloc;
			}

			/*
			@Copy constructor
			Constructs a container with a copy of each of the elements in x, in the same order.
			*/
			vector(const vector& x) {
				this->array = this->allocator.allocate(x.maxSize);
				this->currentSize = x.currentSize;
				*(this->array) = *(x.array);
				this->maxSize = x.maxSize;
			}

			/* -------------------------------------------------------------------------- */
			/*                                 destructor                                 */
			/* -------------------------------------------------------------------------- */

			~vector() {
				this->clear();
				this->allocator.deallocate(this->array, this->maxSize);
			}

			/* -------------------------------------------------------------------------- */
			/*                                  operator                                  */
			/* -------------------------------------------------------------------------- */
			vector	&operator=(const vector &x) {
				this->clear();
				this->allocator.deallocate(this->array, this->maxSize);
				this->array = this->allocator.allocate(x.maxSize);
				for (size_type i = 0; i < x.currentSize; i++)
					this->allocator.construct(&this->array[i], x.array[i]);
				this->currentSize = x.currentSize;
				this->maxSize = x.maxSize;
				return (*this);
			}

			reference	operator[](size_type n) {
				return (*(this->array + n));
			}

			const_reference	operator[](size_type n) const {
				return (*(this->array) + n);
			}

			/* -------------------------------------------------------------------------- */
			/*                                  iterator                                  */
			/* -------------------------------------------------------------------------- */
			
			iterator	begin() {
				return (iterator(this->array));
			}

			iterator	end() {
				return (iterator(&this->array[this->currentSize - 1]));
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(this->array));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(&this->array[this->currentSize - 1]));
			}
			
			/* -------------------------------------------------------------------------- */
			/*                                    size                                    */
			/* -------------------------------------------------------------------------- */
			
			size_type	size() const {
				return (this->currentSize);
			}

			size_type	max_size() const {
				return (this->allocator.max_size());
			}

			size_type	capacity() const {
				return (this->maxSize);
			}

			void	resize(size_type n, value_type val = value_type()) {
				if (n > this->allocator.max_size())
					throw std::out_of_range("ArrayList<X>::resize() : n is out of range");
				else if (n < this->currentSize) {
					value_type	*newArray = this->allocator.allocate(this->maxSize);
					for (size_type i = 0; i < n; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
					this->clear();
					this->allocator.deallocate(this->array, this->maxSize);
					this->array = newArray;
				}
				else if (n > this->currentSize && n < this->maxSize) {
					for (size_type i = this->currentSize; i < n; i++)
						this->allocator.construct(&this->array[i], val);

				}
				else if (n > this->currentSize && n > this->maxSize) {
					value_type	*newArray = this->allocator.allocate(n);
					for (size_type i = 0; i < this->currentSize; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
					for (size_type i = this->currentSize; i < n; i++)
						this->allocator.construct(&newArray[i], val);
					this->clear();
					this->allocator.deallocate(this->array, this->maxSize);
					this->maxSize = n;
					this->array = newArray;
				}
				this->currentSize = n;
			}

			bool	empty() const {
				if (this->currentSize == 0)
					return (true);
				else
					return (false);
			}

			void	reserve(size_type n) {
				if (n > this->allocator.max_size())
					std::out_of_range("ArrayList<X>::reserve() : n is out of range");
				if (n > this->maxSize) {
					value_type	*newArray = this->allocator.allocate(n);
					for (size_type i = 0; i < this->currentSize; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
					this->clear();
					this->allocator.deallocate(this->array, this->maxSize);
					this->maxSize = n;
					this->array = newArray;
				}
			}

			/* -------------------------------------------------------------------------- */
			/*                               element_access                               */
			/* -------------------------------------------------------------------------- */
			reference	at(size_type n) {
				if (n > this->currentSize || n < 0)
					throw std::out_of_range("ArrayList<X>::at() : index is out of range");
				else
					return (*(this->array + n));
			}

			const_reference	at(size_type n) const {
				if (n > this->currentSize || n < 0)
					throw std::out_of_range("ArrayList<X>::at() : index is out of range");
				else
					return (*(this->array + n));
			}

			reference	front() {
				return (*this->array);
			}

			const_reference	front() const {
				return (*this->array);
			}

			reference	back() {
				return (*(this->array + this->currentSize - 1));
			}

			const_reference	back() const {
				return (*(this->array + this->currentSize - 1));
			}

			/* -------------------------------------------------------------------------- */
			/*                                  Modifiers                                 */
			/* -------------------------------------------------------------------------- */
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
				difference_type	size = distance(first, last) + 1;
				
				if (size > static_cast<long>(this->maxSize)) {
					value_type	*newArray = this->allocator.allocate(size);
					for (size_type i = 0; first != last; i++, first++)
						this->allocator.construct(&newArray[i], *first);
					this->clear();
					this->allocator.deallocate(this->array, this->maxSize);
					this->maxSize = size;
					this->array = newArray;
				}
				else {
					for (difference_type i = 0; i < size; i++, first++)
					{
						this->allocator.construct(&this->array[i], *first);
					}
				}
				this->currentSize = size;
			}

			void	assign(size_type n, const value_type &val) {
				if (n > this->maxSize) {
					value_type	*newArray = this->allocator.allocate(n);
					for (size_type i = 0; i < n; i++)
						this->allocator.construct(&newArray[i], val);
					this->clear();
					this->allocator.deallocate(this->array, this->maxSize);
					this->maxSize = n;
					this->array = newArray;
				}
				else {
					for (size_type i =0; i < n; i++)
						this->allocator.construct(&this->array[i], val);
				}
				this->currentSize = n;
			}

			void	push_back(const value_type& val) {
				size_type	saveCurrent = this->currentSize;
				
				if (this->currentSize + 1 > this->maxSize) {
					value_type	*newArray = this->allocator.allocate(this->maxSize + 1);
					for (size_type i = 0; i < this->currentSize; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
					this->allocator.construct(&newArray[this->currentSize], val);
					this->clear();
					this->allocator.deallocate(this->array, this->maxSize);
					this->array = newArray;
					this->maxSize++;
				}
				else
					this->allocator.construct(&this->array[this->currentSize], val);
				this->currentSize = saveCurrent + 1;
			}

			void	pop_back() {
				if (currentSize > 0) {
					this->allocator.destroy(&this->array[this->currentSize - 1]);
					this->currentSize--;
				}
			}

			iterator insert(iterator position, const value_type &val) {
				size_type	saveCurrent = this->currentSize;
				difference_type	size = position - this->begin();
				value_type	*newArray;
				
				if (this->currentSize + 1 > this->maxSize) {
					newArray = this->allocator.allocate(this->maxSize + 1);
					
					for (difference_type i = 0; i < size; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
					this->allocator.construct(&newArray[size], val);
					for (size_type i = size + 1; i < this->currentSize; i++)
						this->allocator.construct(&newArray[i], this->array[i - 1]);
					this->maxSize++;
				}
				else
				{
					newArray = this->allocator.allocate(this->maxSize);
					
					for (difference_type i = 0; i < size; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
					this->allocator.construct(&newArray[size], val);
					for (size_type i = size + 1; i < this->currentSize; i++)
						this->allocator.construct(&newArray[i], this->array[i - 1]);
				}
				this->clear();
				this->allocator.deallocate(this->array, this->maxSize);
				this->array = newArray;
				this->currentSize = saveCurrent + 1;
				return (iterator(&this->array[size]));
			}

			void	insert(iterator position, size_type n, const value_type &val) {
				difference_type	size = position - this->begin();
				size_type		saveCurrent = this->currentSize;
				difference_type i = 0;
				size_type		j = 0;
				value_type		*newArray;

				if (this->currentSize + 1 > this->maxSize) {
					newArray = this->allocator.allocate(this->maxSize + n);
					
					while (i < size) {
						this->allocator.construct(&newArray[i], this->array[i]);
						i++;
					}
					j = i;
					while (size < static_cast<long>(n)) {
						this->allocator.construct(&newArray[i], val);
						size++;
						i++;
					}
					while (j < this->currentSize) {
						this->allocator.construct(&newArray[i], this->array[i]);
						j++;
					}
					this->maxSize = this->maxSize + n;
				}
				else {
					newArray = this->allocator.allocate(this->maxSize);
					
					while (i < size) {
						this->allocator.construct(&newArray[i], this->array[i]);
						i++;
					}
					j = i;
					while (size < static_cast<long>(n)) {
						this->allocator.construct(&newArray[i], val);
						size++;
						i++;
					}
					while (j < this->currentSize) {
						this->allocator.construct(&newArray[i], this->array[i]);
						j++;
					}
				}
				this->clear();
				this->allocator.deallocate(this->array, this->maxSize);
				this->array = newArray;
				this->currentSize = saveCurrent;
			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				difference_type	size = position - this->begin();
				size_type		saveCurrent = this->currentSize;
				difference_type	sizeToAdd = ft::distance(first, last);
				value_type		*newArray;
				difference_type i = 0;
				size_type		j = 0;
				
				if (this->currentSize + size > this->maxSize)
				{
					newArray = this->allocator.allocate(this->maxSize + sizeToAdd);
					while (i < size) {
						this->allocator.construct(&newArray[i], this->array[i]);
						i++;
					}
					j = i;
					while (first != last) {
						this->allocator.construct(&newArray[i], *first);
						first++;
						i++;
					}
					while (j < this->currentSize) {
						this->allocator.construct(&newArray[i], this->array[j]);
						i++;
						j++;
					}
				}
				else
				{
					newArray = this->allocator.allocate(this->maxSize);
					while (i < size) {
						this->allocator.construct(&newArray[i], this->array[i]);
						i++;
					}
					j = i;
					while (first != last) {
						this->allocator.construct(&newArray[i], *first);
						first++;
						i++;
					}
					while (j < this->currentSize) {
						this->allocator.construct(&newArray[i], this->array[j]);
						i++;
						j++;
					}
				}
				this->clear();
				this->allocator.deallocate(this->array, this->maxSize);
				this->array = newArray;
				this->currentSize = saveCurrent;
			}

			iterator erase(iterator position) {
				if (iterator == this->end()) {
					this->allocator.destroy(&this->array[this->currentSize - 1]);
					this->currentSize--;
					return (this->array[currentSize - 1]);
				}
				else {
					value_type		*newArray = this->allocator.allocate(this->maxSize - 1);
					difference_type	pos = position - this->begin();
					
					for (difference_type i = 0; i < position; i++)
						this->allocator.construct(&newArray[i], this->array[i]);
				}
			}

			iterator erase(iterator first, iterator last) {
				
			}
			
			void	clear() {
				for (size_type i = 0; i < this->currentSize; i++)
					this->allocator.destroy(&this->array[i]);
				this->currentSize = 0;
			}
	};
}
