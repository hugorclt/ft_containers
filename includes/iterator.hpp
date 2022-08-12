/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:56:07 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/02 15:56:21 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

namespace ft {
	template <typename iterator>
	struct iterator_traits {
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
		
	};

	struct random_access_category_tag {};

	template <typename T>
	class vectorRandomIterator {			
		public:

			//Definition
			typedef T							value_type;
			typedef unsigned long long			difference_type;
			typedef	T*							pointer;
			typedef T&							reference;
			typedef random_access_category_tag	iterator_category;
			
			//Constructor - Destructor
			vectorRandomIterator(pointer	pointee = NULL) : elem(pointee) {};

			//operator
			vectorRandomIterator &operator=(vectorRandomIterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			reference	operator*() const {return (*this->elem); };
			pointer		operator->() const {return (this->value); };
			reference	operator[]( const difference_type &offset) const {return (*this->elem + offset); };

			//Increment operator
			vectorRandomIterator	&operator++() {this->elem++; return (*this); };
			vectorRandomIterator	operator++(int) {vectorRandomIterator tmp = *this; ++(*this); return (tmp); }
			vectorRandomIterator	&operator--() {this->elem--; return (*this); };
			vectorRandomIterator	operator--(int) {vectorRandomIterator tmp = *this; --(*this); return (tmp); }

			//Arithmetic operator
			vectorRandomIterator	operator+(const difference_type &diff) {return (vectorRandomIterator(this->elem + diff)); };
			vectorRandomIterator	operator-(const difference_type &diff) {return (vectorRandomIterator(this->elem - diff)); };
			
			//Comparison operator
			bool	operator==(vectorRandomIterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(vectorRandomIterator &iter) const {return (this->elem != iter.elem); };
			bool	operator>=(vectorRandomIterator &iter) const {return (this->elem >= iter.elem); };
			bool	operator<=(vectorRandomIterator &iter) const {return (this->elem <= iter.elem); };
			bool	operator>(vectorRandomIterator &iter) const {return (this->elem < iter.elem); };
			bool	operator<(vectorRandomIterator &iter) const {return (this->elem > iter.elem); };

			//create const iterator
			operator vectorRandomIterator<const value_type>() const {return (vectorRandomIterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	}; 
	
	//with just a type
	// template <typename T>
	// class iterator_traits {
	// 	public:
	// 		typedef typename random_access_iterator_tag	iterator_category;
	// 		typedef typename T							value_type;
	// 		typedef typename ptdrdiff_t					difference_type;
	// 		typedef typename t*							pointer;
	// 		typedef typename T&							reference;
		
	// };

	

	
}