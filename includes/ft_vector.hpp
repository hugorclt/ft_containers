/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/09/13 12:58:03 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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
			typedef	T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference 					reference;
			typedef typename allocator_type::const_reference 			const_reference;
			typedef typename allocator_type::pointer 					pointer;
			typedef typename allocator_type::const_pointer 				const_pointer;
			typedef random_access_iterator<value_type> 			iterator;
			typedef random_access_iterator<const value_type>	const_iterator;
			typedef random_access_iterator<value_type> 			reverse_iterator; //FIIIIIIXXXXX
			typedef	random_access_iterator<const value_type>	const_reverse_iterator; //FIIIXXX
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t 										size_type;
		
		private:
			T				*array;
			size_t			currentSize; //current element in the vector
			size_t			maxCapacity; //vector maximum number of alloc == MAX_VECTOR_SIZE
			size_t			maxSize; //vector max capacity allocated actually
			allocator_type	allocator;
			
		public:
			/* -------------------------------------------------------------------------- */
			/*                                 constructor                                */
			/* -------------------------------------------------------------------------- */
			
			explicit	vector(const allocator_type& alloc = allocator_type()) : array(NULL), currentSize(0), maxCapacity(MAX_VECTOR_SIZE), maxSize(0) {(void)alloc;}
			
			explicit	vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {
				(void)alloc;
				this->array = this->allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->array[i] = val;
				this->currentSize = n;
				this->maxCapacity = MAX_VECTOR_SIZE;
				this->maxSize = n;
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				int	size = 0;
				InputIterator saveFirst = first;
				(void)alloc;
				
				while (first != last)
				{
					size++;
					first++;
				}
				this->array = this->allocator.allocate(size);
				for (int i = 0; saveFirst != last; i++, saveFirst++)
					this->array[i] = *saveFirst;
				this->currentSize = size;
				this->maxCapacity = MAX_VECTOR_SIZE;
				this->maxSize = size;
			}

			vector(const vector& x) {
				this->array = this->allocator.allocate(x.maxSize);
				this->currentSize = x.currentSize;
				*(this->array) = *(x.array);
				this->maxCapacity = x.maxCapacity;
				this->maxSize = x.maxSize;
			}

			/* -------------------------------------------------------------------------- */
			/*                                 destructor                                 */
			/* -------------------------------------------------------------------------- */
			~vector() {
				this->allocator.destroy(this->array);
				this->allocator.deallocate(this->array, this->maxSize);
			}

			/* -------------------------------------------------------------------------- */
			/*                                  operator                                  */
			/* -------------------------------------------------------------------------- */
			

			/* -------------------------------------------------------------------------- */
			/*                                  iterator                                  */
			/* -------------------------------------------------------------------------- */
			iterator	begin() {
				return (iterator(this->array));
			}

			iterator	end() {
				return (iterator(&this->array[this->currentSize]));
			}
	};
}
