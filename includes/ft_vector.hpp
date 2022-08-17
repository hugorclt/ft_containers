/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:57:59 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/12 12:30:26 by hrecolet         ###   ########.fr       */
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
		public:
		

		private:
			T		*array;
			size_t	currentCapacity;
			size_t	maxCapacity;
			size_t	maxSize;
			Alloc	allocator;
	};
}