/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:56:07 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/14 10:30:35 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

namespace ft {

	/*
	@Tag used for algorithm to know the type of iterator, in iterator_category
	They are just used to know the type of the iterator so they are empty.
	*/
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	
	/*
	@Definition of iterator struct, it's a base class template so it does not provide
	any implementation, it just define some types for algorithms
	*/
	template <typename Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef	T	value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
	
	/*
	@IDK KESAKO CPLUSPLUS.COM 
	*/
	template <typename iterator>
	struct iterator_traits {
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
		
	};

	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {			
		public:
			//Definition
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			
			//Constructor - Destructor
			random_access_iterator(pointer	pointee = NULL) : elem(pointee) {};
			random_access_iterator(const random_access_iterator &cpy) : elem(cpy.elem) {};
			virtual ~random_access_iterator() {}

			//operator
			random_access_iterator &operator=(random_access_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			reference	operator*() const {return (*this->elem); };
			pointer		operator->() const {return (this->value); };
			reference	operator[]( const difference_type &offset) const {return (*this->elem + offset); };

			//Increment operator
			random_access_iterator	&operator++() {this->elem++; return (*this); };
			random_access_iterator	operator++(int) {random_access_iterator tmp = *this; ++(*this); return (tmp); }
			random_access_iterator	&operator--() {this->elem--; return (*this); };
			random_access_iterator	operator--(int) {random_access_iterator tmp = *this; --(*this); return (tmp); }

			//Arithmetic operator
			random_access_iterator	operator+(const difference_type &diff) {return (random_access_iterator(this->elem + diff)); };
			random_access_iterator	operator-(const difference_type &diff) {return (random_access_iterator(this->elem - diff)); };
			
			//Comparison operator
			bool	operator==(random_access_iterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(random_access_iterator &iter) const {return (this->elem != iter.elem); };
			bool	operator>=(random_access_iterator &iter) const {return (this->elem >= iter.elem); };
			bool	operator<=(random_access_iterator &iter) const {return (this->elem <= iter.elem); };
			bool	operator>(random_access_iterator &iter) const {return (this->elem < iter.elem); };
			bool	operator<(random_access_iterator &iter) const {return (this->elem > iter.elem); };

			//create const iterator
			operator random_access_iterator<const value_type>() const {return (random_access_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	}; 	
}