/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:52:15 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/04 19:52:54 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utility.hpp"
#include "iterator.hpp"
#include <iostream>
#include <memory>
#include "RBtree.hpp"

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
			// typedef 																value_compare
			typedef Allocator														allocator_type;
			typedef typename allocator_type::reference 								reference;
			typedef typename allocator_type::const_reference 						const_reference;
			typedef typename allocator_type::pointer 								pointer;
			typedef typename allocator_type::const_pointer 							const_pointer;
			// typedef typename ft::random_access_iterator<value_type> 				iterator;
			// typedef typename ft::random_access_iterator<const value_type>			const_iterator;
			// typedef typename ft::reverse_random_access_iterator<value_type> 		reverse_iterator;
			// typedef typename ft::reverse_random_access_iterator<const value_type>	const_reverse_iterator;
			// typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
			typedef size_t 															size_type;
		private:

		public:
	};
}