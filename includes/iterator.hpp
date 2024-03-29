/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:56:07 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/18 10:34:21 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stddef.h>

namespace ft {
	
	/*
	@Definition of iterator struct, it's a base class template so it does not provide
	any implementation, it just define some types for algorithms
	*/
	template <typename Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef	T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
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

	template<typename T>
	class bidirectionnal_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename T::value_type															node_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;

			//Constructor - Destructor
			bidirectionnal_iterator(pointer	pointee = NULL) : elem(pointee) {};
			bidirectionnal_iterator(const bidirectionnal_iterator &cpy) : elem(cpy.elem) {};
			
			virtual ~bidirectionnal_iterator() {}

			//operator
			bidirectionnal_iterator &operator=(const bidirectionnal_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			node_type	operator*() const {return (this->elem->_pair); };
			node_type	*operator->() const {return (&(this->elem->_pair)); };

			//Increment operator
			bidirectionnal_iterator	&operator++() {
				value_type	*nllnode = elem->_nllnode;
				if (elem == elem->_nllnode)
					return (*this);
				if (elem->_right != elem->_nllnode)
				{
					elem = elem->_right;
					while (elem->_left != elem->_nllnode)
					{
						elem = elem->_left;
					}
				}
				else
				{
					while (elem->_parent && elem == elem->_parent->_right)
					{
						elem = elem->_parent;
					}
					elem = elem->_parent;
				}
				if (elem == NULL)
					elem = nllnode;
				return (*this);
			}
			
			bidirectionnal_iterator	operator++(int) {
				bidirectionnal_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			
			bidirectionnal_iterator	&operator--() {
				if (elem == elem->_nllnode)
					elem = elem->_parent;
				else if (elem->_left != elem->_nllnode)
				{
					elem = elem->_left;
					while (elem->_right != elem->_nllnode)
						elem = elem->_right;
				}
				else
				{
					while (elem->_parent != elem->_nllnode && elem == elem->_parent->_left)
						elem = elem->_parent;
					elem = elem->_parent;
				}
				return (*this);
			}
			
			bidirectionnal_iterator	operator--(int) {
				bidirectionnal_iterator	tmp = *this;
				operator--();
				return (tmp);
			}

			value_type	*getElem(void) const
			{
				return (elem);
			}

			//Comparison operator
			bool	operator==(const bidirectionnal_iterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(const bidirectionnal_iterator &iter) const 
			{
				return (this->elem != iter.elem);
			};

			//create const iterator
			operator bidirectionnal_iterator<const value_type>() const {return (bidirectionnal_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	};

	template<typename T>
	class const_bidirectionnal_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef const typename T::value_type													node_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;

			//Constructor - Destructor
			const_bidirectionnal_iterator(pointer	pointee = NULL) : elem(pointee) {};
			const_bidirectionnal_iterator(const const_bidirectionnal_iterator &cpy) : elem(cpy.elem) {};
			const_bidirectionnal_iterator(const bidirectionnal_iterator<T> &it) : elem(it.getElem()) {}
			virtual ~const_bidirectionnal_iterator() {}

			//operator
			const_bidirectionnal_iterator &operator=(const const_bidirectionnal_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			node_type	operator*() const {return (this->elem->_pair); };
			node_type	*operator->() const {return (&(this->elem->_pair)); };

			//ft::pair<const int, std::basic_string<char> > *
			//const ft::pair<const int, std::basic_string<char> > *
			
			//ft::pair<const int, std::basic_string<char> > *
			//const ft::pair<const int, std::basic_string<char> > *'

			//Increment operator
			const_bidirectionnal_iterator	&operator++() {
				value_type	*nllnode = elem->_nllnode;
				if (elem == elem->_nllnode)
					return (*this);
				if (elem->_right != elem->_nllnode)
				{
					elem = elem->_right;
					while (elem->_left != elem->_nllnode)
					{
						elem = elem->_left;
					}
				}
				else
				{
					while (elem->_parent && elem == elem->_parent->_right)
					{
						elem = elem->_parent;
					}
					elem = elem->_parent;
				}
				if (elem == NULL)
					elem = nllnode;
				return (*this);
			}
			
			const_bidirectionnal_iterator	operator++(int) {
				const_bidirectionnal_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			
			const_bidirectionnal_iterator	&operator--() {
				if (elem == elem->_nllnode)
					elem = elem->_parent;
				else if (elem->_left != elem->_nllnode)
				{
					elem = elem->_left;
					while (elem->_right != elem->_nllnode)
						elem = elem->_right;
				}
				else
				{
					while (elem->_parent != elem->_nllnode && elem == elem->_parent->_left)
						elem = elem->_parent;
					elem = elem->_parent;
				}
				return (*this);
			}
			
			const_bidirectionnal_iterator	operator--(int) {
				const_bidirectionnal_iterator	tmp = *this;
				operator--();
				return (tmp);
			}

			

			//Comparison operator
			bool	operator==(const const_bidirectionnal_iterator &iter) const {

				return (this->elem == iter.elem); 
			};
			bool	operator!=(const const_bidirectionnal_iterator &iter) const 
			{
				return (this->elem != iter.elem);
			};

			//create const iterator
			operator const_bidirectionnal_iterator<const value_type>() const {return (const_bidirectionnal_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	};

	template<typename T>
	class reverse_bidirectionnal_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename value_type::value_type													node_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;

			//Constructor - Destructor
			reverse_bidirectionnal_iterator(pointer	pointee = NULL) : elem(pointee) {};
			reverse_bidirectionnal_iterator(const reverse_bidirectionnal_iterator &cpy) : elem(cpy.elem) {};
			virtual ~reverse_bidirectionnal_iterator() {}

			//operator
			reverse_bidirectionnal_iterator &operator=(const reverse_bidirectionnal_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			node_type	operator*() const {return (this->elem->_pair); };
			node_type	*operator->() const {return (&(this->elem->_pair)); };
			
			//ft::pair<const int, std::basic_string<char> > *
			//const ft::pair<const int, std::basic_string<char> > *'

			//Increment operator
			reverse_bidirectionnal_iterator	&operator++() {
				value_type	*nllnode = elem->_nllnode;
				if (elem == elem->_nllnode)
					return (*this);
				else if (elem->_left != elem->_nllnode)
				{
					elem = elem->_left;
					while (elem->_right != elem->_nllnode)
						elem = elem->_right;
				}
				else
				{
					while (elem->_parent && elem == elem->_parent->_left)
						elem = elem->_parent;
					elem = elem->_parent;
				}
				if (elem == NULL)
					elem = nllnode;
				return (*this);
			}
			
			reverse_bidirectionnal_iterator	operator++(int) {
				reverse_bidirectionnal_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			
			reverse_bidirectionnal_iterator	&operator--() {
				if (elem == elem->_nllnode)
				{
					while (elem->_parent != NULL)
						elem = elem->_parent;
					while (elem->_left != elem->_nllnode)
						elem = elem->_left;
				}
				else if (elem->_right != elem->_nllnode)
				{
					elem = elem->_right;
					while (elem->_left != elem->_nllnode)
						elem = elem->_left;
				}
				else
				{
					while (elem->_parent && elem == elem->_parent->_right)
					{
						elem = elem->_parent;
					}
					elem = elem->_parent;
				}
				return (*this);
			}
			
			reverse_bidirectionnal_iterator	operator--(int) {
				reverse_bidirectionnal_iterator	tmp = *this;
				operator--();
				return (tmp);
			}

			value_type	*getElem(void) const
			{
				return (elem);
			}

			//Comparison operator
			bool	operator==(const reverse_bidirectionnal_iterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(const reverse_bidirectionnal_iterator &iter) const 
			{
				return (this->elem != iter.elem);
			};

			//create const iterator
			operator reverse_bidirectionnal_iterator<const value_type>() const {return (reverse_bidirectionnal_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	};

	template<typename T>
	class const_reverse_bidirectionnal_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef const typename value_type::value_type													node_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;

			//Constructor - Destructor
			const_reverse_bidirectionnal_iterator(pointer	pointee = NULL) : elem(pointee) {};
			const_reverse_bidirectionnal_iterator(const const_reverse_bidirectionnal_iterator &cpy) : elem(cpy.elem) {};
			const_reverse_bidirectionnal_iterator(const reverse_bidirectionnal_iterator<T> &it) : elem(it.getElem()) {}
			virtual ~const_reverse_bidirectionnal_iterator() {}

			//operator
			const_reverse_bidirectionnal_iterator &operator=(const const_reverse_bidirectionnal_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			node_type	operator*() const {return (this->elem->_pair); };
			node_type	*operator->() const {return (&(this->elem->_pair)); };
			
			//ft::pair<const int, std::basic_string<char> > *
			//const ft::pair<const int, std::basic_string<char> > *'

			//Increment operator
			const_reverse_bidirectionnal_iterator	&operator++() {
				value_type	*nllnode = elem->_nllnode;
				if (elem == elem->_nllnode)
					return (*this);
				if (elem == elem->_nllnode)
					elem = elem->_parent;
				else if (elem->_left != elem->_nllnode)
				{
					elem = elem->_left;
					while (elem->_right != elem->_nllnode)
						elem = elem->_right;
				}
				else
				{
					while (elem->_parent && elem == elem->_parent->_left)
						elem = elem->_parent;
					elem = elem->_parent;
				}
				if (elem == NULL)
					elem = nllnode;
				return (*this);
			}
			
			const_reverse_bidirectionnal_iterator	operator++(int) {
				const_reverse_bidirectionnal_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			
			const_reverse_bidirectionnal_iterator	&operator--() {
				if (elem == elem->_nllnode)
				{
					while (elem->_parent != NULL)
						elem = elem->_parent;
					while (elem->_left != elem->_nllnode)
						elem = elem->_left;
				}
				else if (elem->_right != elem->_nllnode)
				{
					elem = elem->_right;
					while (elem->_left != elem->_nllnode)
						elem = elem->_left;
				}
				else
				{
					while (elem->_parent && elem == elem->_parent->_right)
					{
						elem = elem->_parent;
					}
					elem = elem->_parent;
				}
				return (*this);
			}
			
			const_reverse_bidirectionnal_iterator	operator--(int) {
				const_reverse_bidirectionnal_iterator	tmp = *this;
				operator--();
				return (tmp);
			}

			

			//Comparison operator
			bool	operator==(const const_reverse_bidirectionnal_iterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(const const_reverse_bidirectionnal_iterator &iter) const 
			{
				return (this->elem != iter.elem);
			};

			//create const iterator
			operator const_reverse_bidirectionnal_iterator<const value_type>() const {return (const_reverse_bidirectionnal_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	};

	template <typename T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T> {
		public:
			//Definition
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
			
			//Constructor - Destructor
			random_access_iterator(pointer	pointee = NULL) : elem(pointee) {};
			random_access_iterator(const random_access_iterator &cpy) : elem(cpy.elem) {};
			virtual ~random_access_iterator() {}

			//operator
			random_access_iterator &operator=(const random_access_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			reference	operator*() const {return (*this->elem); };
			pointer		operator->() const {return (this->elem); };
			reference	operator[]( const difference_type &offset) const {return (this->elem[offset]); };

			//Increment operator
			random_access_iterator	&operator++() {this->elem++; return (*this); };
			random_access_iterator	operator++(int) {random_access_iterator tmp = *this; ++elem; return (tmp); }
			random_access_iterator	&operator--() {this->elem--; return (*this); };
			random_access_iterator	operator--(int) {random_access_iterator tmp = *this; --elem; return (tmp); }

			// Arithmetic operator
			// random_access_iterator	operator+(const random_access_iterator &rhs) {return (random_access_iterator(this->elem + rhs.elem)); };
			// random_access_iterator	operator-(const random_access_iterator &rhs) {return (random_access_iterator(this->elem - rhs.elem)); };
			
			random_access_iterator	operator+=(const int &rhs) { *this = *this + rhs; return(*this); };
			random_access_iterator	operator-=(const int &rhs) { *this = *this - rhs; return(*this); };
			random_access_iterator	operator-(const int &rhs) { return (random_access_iterator(this->elem - rhs)); }
			random_access_iterator operator+(const int &rhs) {return (random_access_iterator(this->elem + rhs)); }
			
			difference_type	operator-(const random_access_iterator &it) { return (this->elem - it.elem); }

			//Comparison operator
			bool	operator==(const random_access_iterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(const random_access_iterator &iter) const {return (this->elem != iter.elem); };
			bool	operator>=(const random_access_iterator &iter) const {return (this->elem >= iter.elem); };
			bool	operator<=(const random_access_iterator &iter) const {return (this->elem <= iter.elem); };
			bool	operator>(const random_access_iterator &iter) const {return (this->elem > iter.elem); };
			bool	operator<(const random_access_iterator &iter) const { return (this->elem < iter.elem); };

			//create const iterator
			operator random_access_iterator<const value_type>() const {return (random_access_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	};

	template <typename T>
	class reverse_random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T> {
		public:
			//Definition
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
			
			//Constructor - Destructor
			reverse_random_access_iterator(pointer	pointee = NULL) : elem(pointee) {};
			reverse_random_access_iterator(const reverse_random_access_iterator &cpy) : elem(cpy.elem) {};
			virtual ~reverse_random_access_iterator() {}

			//operator
			reverse_random_access_iterator &operator=(const reverse_random_access_iterator &to_cpy) {
				this->elem = to_cpy.elem;
				return (*this);
			}

			//Dereference operator
			reference	operator*() const {return (*this->elem); };
			pointer		operator->() const {return (this->elem); };
			reference	operator[]( const difference_type &offset) const {return (this->elem[offset * -1]); };

			//Increment operator
			reverse_random_access_iterator	&operator++() {this->elem--; return (*this); };
			reverse_random_access_iterator	operator++(int) {reverse_random_access_iterator tmp = *this; --elem; return (tmp); }
			reverse_random_access_iterator	&operator--() {this->elem++; return (*this); };
			reverse_random_access_iterator	operator--(int) {reverse_random_access_iterator tmp = *this; ++elem; return (tmp); }

			// Arithmetic operator
			// reverse_random_access_iterator	operator+(const reverse_random_access_iterator &rhs) {return (reverse_random_access_iterator(this->elem + rhs.elem)); };
			// reverse_random_access_iterator	operator-(const reverse_random_access_iterator &rhs) {return (reverse_random_access_iterator(this->elem - rhs.elem)); };
			
			reverse_random_access_iterator	operator+=(const int &rhs) { elem = elem - rhs; return(*this); };
			reverse_random_access_iterator	operator-=(const int &rhs) { elem = elem + rhs; return(*this); };
			reverse_random_access_iterator	operator-(const int &rhs) { return (reverse_random_access_iterator(this->elem + rhs)); }
			reverse_random_access_iterator operator+(const int &rhs) {return (reverse_random_access_iterator(this->elem - rhs)); }
			
			difference_type	operator-(const reverse_random_access_iterator &it) { return (this->elem - it.elem); }

			//Comparison operator
			bool	operator==(const reverse_random_access_iterator &iter) const {return (this->elem == iter.elem); };
			bool	operator!=(const reverse_random_access_iterator &iter) const {return (this->elem != iter.elem); };
			bool	operator>=(const reverse_random_access_iterator &iter) const {return (this->elem >= iter.elem); };
			bool	operator<=(const reverse_random_access_iterator &iter) const {return (this->elem <= iter.elem); };
			bool	operator>(const reverse_random_access_iterator &iter) const {return (this->elem > iter.elem); };
			bool	operator<(const reverse_random_access_iterator &iter) const {return (this->elem < iter.elem); };

			//create const iterator
			operator reverse_random_access_iterator<const value_type>() const {return (reverse_random_access_iterator<const value_type>(this->elem)); };

			private:
				pointer	elem;
	};


	template<class It>
	typename ft::iterator_traits<It>::difference_type
	do_distance(It first, It last, std::input_iterator_tag)
	{
		typename ft::iterator_traits<It>::difference_type result = 0;
		while (first != last)
		{
			++first;
			++result;
		}
		return (result);
	}

	template<class It>
	typename ft::iterator_traits<It>::difference_type
	do_distance(It first, It last, std::random_access_iterator_tag)
	{
		return last - first;
	}

	template<class It>
	typename ft::iterator_traits<It>::difference_type
	distance(It first, It last)
	{
		return (do_distance(first, last, typename ft::iterator_traits<It>::iterator_category()));
	}
}
