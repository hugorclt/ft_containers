/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:52:15 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/09 17:39:07 by hrecolet         ###   ########.fr       */
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
			class ValComp : std::binary_function<value_type, value_type, bool>
			{
				protected:
					Compare comp;
					ValComp(Compare c) : comp(c) {};
				
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool	operator()(const value &x, const value &y) const
					{
						return (comp(x.first, y.first));
					}
			};
			
			typedef	Key																key_type;
			typedef	T																mapped_type;
			typedef ft::pair<const key_type, mapped_type>							value_type;
			typedef Compare															key_compare;
			typedef ValComp															value_compare;
			typedef Allocator														allocator_type;
			typedef typename allocator_type::reference 								reference;
			typedef typename allocator_type::const_reference 						const_reference;
			typedef typename allocator_type::pointer 								pointer;
			typedef typename allocator_type::const_pointer 							const_pointer;
			typedef typename ft::bidirectionnal_iterator<value_type> 				iterator;
			typedef typename ft::bidirectionnal_iterator<const value_type>			const_iterator;
			typedef typename ft::reverse_bidirectionnal_iterator<value_type> 		reverse_iterator;
			typedef typename ft::reverse_bidirectionnal_iterator<const value_type>	const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
			typedef size_t 															size_type;
			
		private:
			value_type	_data;
			
		public:
			
	};
}