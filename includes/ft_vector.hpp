/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/04 12:09:35 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <memory>
#include <iostream>
#include "define.hpp"
#include <exception>
#include "iterator.hpp"

namespace ft {
	//Template : allocator<T> to allocate memory accordingly to the type of the vector
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		private:
			T		*array;
			size_t	currentCapacity;
			size_t	maxCapacity;
			size_t	maxSize;
			Alloc	allocator;
			
			
		public:
			/*************Member Type*************/
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef typename allocator_type::reference		reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef	vectorRandomIterator<value_type>		iterator;
			typedef	vectorRandomIterator<const value_type>		const_iterator;
			//ADD REVERSE ITERATOR HERE AND ITERATOR TOO
			typedef ptrdiff_t	difference_type;
			typedef	size_t		size_type;

			/*************Constructor*************/
			//Default Constructor
			vector() : array(NULL), currentCapacity(0), maxCapacity(0), maxSize(MAX_VECTOR_SIZE) {}
			
			//Fill Constructor
			vector(size_type n, const T value) {
				if (n < 0)
					throw (std::length_error("error: size can't be negative"));
				if (n > MAX_VECTOR_SIZE)
					throw (std::length_error("error: value too big"));
				this->maxSize = MAX_VECTOR_SIZE;
				this->maxCapacity = n;
				this->currentCapacity = n;
				if (n > 0)
					this->array = allocator.allocate(n);
				else
					this->array = NULL;
				for (size_type i = 0; i < n; i++)
					this->array[i] = value;
			}
			
			//Range Constructor
			vector(iterator begin, iterator end) {
				iterator	saveBegin = begin;
				size_type		size = 0;
				while (saveBegin != end)
				{
					size++;
					saveBegin++;
				}
				this->currentCapacity = size;
				this->maxCapacity = size;
				this->maxSize = MAX_VECTOR_SIZE;
				if (size != 0)
					this->array = allocator.allocate(size);
				else
					this->array = NULL;
				for (int i = 0;begin != end; i++, begin++)
					this->array[i] = begin;
			}
			
			//Copy Constructor
			vector(const vector &to_cpy) {
				this->array = NULL;
				*this = to_cpy;
			}
			
			/*************Destructor*************/
			//Default destructor
			~vector() {
				if (this->array != NULL)
					delete []this->array;
			}

			/*************Operator*************/
			//Assignement operator
			vector	&operator=(const vector & x) {
				if (this->array != NULL)
					delete	[]this->array;
				this->array = new T[x.maxCapacity];
				this->currentCapacity = x.currentCapacity;
				this->maxCapacity = x.maxCapacity;
				this->maxSize = x.maxSize;
				for (size_type i = 0; i < x.maxCapacity; i++)
					this->array[i] = x.array[i];
				return (*this);
			}

			reference	&operator[](size_type val) {
				int	&ref = this->array[val];
				return (ref);
			}

			const_reference	&operator[](size_type val) const {
				const int	&ref = this->array[val];
				return (ref);
			}

			/*************Methods*************/
			iterator	begin(void) {
				if (this->currentCapacity > 0)
					return (&this->array[0]);
				return (NULL);
			}
			const_iterator	begin(void) const {
				if (this->currentCapacity > 0)
					return (this->array);
				return (NULL);
			}

			size_type	size(void) const {
				return (this->currentCapacity);
			}

			size_type	max_size(void) const {
				return (this->maxSize);
			}

			size_type	capacity(void) const {
				return (this->maxCapacity);
			}

			void	resize(size_type n, value_type val) {
				if (n < 0)
					throw (std::length_error("error: vector::resize"));
				if (n > MAX_VECTOR_SIZE)
					throw (std::length_error("error: vector::resize"));
				else if (n < this->currentCapacity)
				{
					for (size_type i = n; i < this->currentCapacity; i++)
						this->array[i] = 0;
					this->currentCapacity = n;
				}
				else if (n > this->currentCapacity)
				{
					if (n > this->maxCapacity)
					{
						value_type	*tmp = new value_type[n];
						for (size_type i = 0; i < this->currentCapacity; i++)
							tmp[i] = this->array[i];
						delete []this->array;
						this->array = tmp;
					}
					for (size_type i = this->currentCapacity; i < n; i++)
						this->array[i] = val;
					this->currentCapacity = n;
					this->maxCapacity = n;
				}
			}

			void	resize(size_type n) {
				if (n < 0)
					throw (std::length_error("error: vector::resize"));
				if (n > MAX_VECTOR_SIZE)
					throw (std::length_error("error: vector::resize"));
				else if (n < this->currentCapacity)
				{
					for (size_type i = n; i < this->currentCapacity; i++)
						this->array[i] = 0;
					this->currentCapacity = n;
				}
				else if (n > this->currentCapacity)
				{
					if (n > this->maxCapacity)
					{
						value_type	*tmp = new value_type[n];
						for (size_type i = 0; i < this->currentCapacity; i++)
							tmp[i] = this->array[i];
						delete []this->array;
						this->array = tmp;
					}
					for (size_type i = this->currentCapacity; i < n; i++)
						this->array[i] = 0;
					this->currentCapacity = n;
					this->maxCapacity = n;
				}
			}

			bool	empty(void) const {
				if (this->currentCapacity == 0)
					return (true);
				return (false);
			}

			void	reserve(size_type n) {
				if (n > MAX_VECTOR_SIZE)
					throw (std::length_error("error: value too big"));
				if (n <= this->maxCapacity)
					return ;
				value_type *tmp = new value_type[n];
				for (size_type i = 0; i < this->maxCapacity; i++)
					tmp[i] = this->array[i];
				delete []array;
				this->array = tmp;
				this->maxCapacity = n;
			}

			void	shrink_to_fit(void) {
				this->maxCapacity = this->currentCapacity;
			}

			reference	at(size_type n) {
				if (n < 0 || n > this->currentCapacity - 1)
					throw std::out_of_range("error: out of range");
				value_type	&ref = this->array[n];
				return (ref);
			}

			const_reference	at(size_type n) const {
				if (n < 0 || n > this->currentCapacity - 1)
					throw std::out_of_range("error: out of range");
				const value_type	&ref = this->array[n];
				return (ref);
			}
	};
}