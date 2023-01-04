/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:00:42 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/04 17:28:47 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <exception>

namespace ft {
	template<class T, class Container = vector<T> >
	class stack {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type	_vec;

		public:
			/* ------------------------------- constructor ------------------------------ */
			explicit stack(const container_type& ctnr = container_type())
			{
				_vec = ctnr;
			}

			/* --------------------------------- methods -------------------------------- */
			bool empty() const
			{
				return (_vec.empty());
			}

			size_type size() const
			{
				return (_vec.size());
			}

			value_type& top()
			{
				return (_vec.back());
			}

			const value_type& top() const
			{
				return (_vec.back());
			}

			void push (const value_type& val)
			{
				_vec.push_back(val);
			}

			void	pop(void)
			{
				_vec.pop_back();
			}

			/* -------------------------- relationnal_operator -------------------------- */
			template <class Type, class ContainerT>
			friend bool operator==(const stack<Type,ContainerT>& lhs, const stack<Type,ContainerT>& rhs);
			template <class Type, class ContainerT>
			friend bool operator!=(const stack<Type,ContainerT>& lhs, const stack<Type,ContainerT>& rhs);
			template <class Type, class ContainerT>
			friend bool operator<(const stack<Type,ContainerT>& lhs, const stack<Type,ContainerT>& rhs);
			template <class Type, class ContainerT>
			friend bool operator>(const stack<Type,ContainerT>& lhs, const stack<Type,ContainerT>& rhs);
			template <class Type, class ContainerT>
			friend bool operator>=(const stack<Type,ContainerT>& lhs, const stack<Type,ContainerT>& rhs);
			template <class Type, class ContainerT>
			friend bool operator<=(const stack<Type,ContainerT>& lhs, const stack<Type,ContainerT>& rhs);
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._vec == rhs._vec);
	}
	
	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._vec != rhs._vec);
	}
	
	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._vec < rhs._vec);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._vec > rhs._vec);
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._vec <= rhs._vec);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._vec >= rhs._vec);
	}
}