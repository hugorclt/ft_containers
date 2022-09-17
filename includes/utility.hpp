/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:28:10 by hrecolet          #+#    #+#             */
/*   Updated: 2022/09/17 14:35:17 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./iterator.hpp"

namespace ft {
	
	/* -------------------------------------------------------------------------- */
	/*                         Lexicographical comparison                         */
	/* -------------------------------------------------------------------------- */
	template <class InputIterator1, class InputIterator2>
	bool	lexixographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool	lexixographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1 || first2 != last2)
		{
			if (comp(*first1, *first2))
				return (true);
			else if (comp(*first2, *first1))
				return (false);
			++first1;
			++first2;
		}
		return (first1 == last1 && first2 != last2);
	}
	
	/* -------------------------------------------------------------------------- */
	/*                                    pair                                    */
	/* -------------------------------------------------------------------------- */
	template <class T1, class T2>
	struct pair {
		T1 first;
		T2 second;
		/* ------------------------------- Constructor ------------------------------ */
		//Default Constructor
		pair() {};
		//Copy Constructor
		template<class U, class V>
		pair(const pair<U,V> &oth) { *this = oth; };
		//Initialization Constructor
		pair(const T1 &first, const T2 &second) : first(first), second(second) {};
		/* -------------------------------- Operator -------------------------------- */
		pair &operator=(const pair &pr) {
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
		template<class U, class V>
		friend bool operator==(const pair<U, V> &lhs, const pair<U, V> &rhs);
		template<class U, class V>
		friend bool operator!=(const pair<U, V> &lhs, const pair<U, V> &rhs);
		template<class U, class V>
		friend bool operator<(const pair<U, V> &lhs, const pair<U, V> &rhs);
		template<class U, class V>
		friend bool operator<=(const pair<U, V> &lhs, const pair<U, V> &rhs);
		template<class U, class V>
		friend bool operator>(const pair<U, V> &lhs, const pair<U, V> &rhs);
		template<class U, class V>
		friend bool operator>=(const pair<U, V> &lhs, const pair<U, V> &rhs);
	};
	
	/* ------------------------- friend operator of pair ------------------------ */
	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (!(lhs == rhs));
	}
	template<class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template<class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (!(rhs < lhs));
	}
	template<class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (rhs < lhs);
	}
	template<class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (!(lhs < rhs));
	}
	
	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	};

	struct false_type {
		static const bool	value = false;
		operator bool() const { return value; }; 
	};

	struct true_type {
		static const bool	value = true;
		operator bool() const { return value; }; 
	};

	/* -------------------------------------------------------------------------- */
	/*                                  remove_cv                                 */
	/* -------------------------------------------------------------------------- */

	template<class T>
	struct remove_cv {
		typedef T type;
	};

	template<class T>
	struct remove_cv<const T> {
		typedef T type;
	};

	template<class T>
	struct remove_cv<volatile T> {
		typedef T type;
	};

	template<class T>
	struct remove_cv<const volatile T> {
		typedef T type;
	};

	/* -------------------------------------------------------------------------- */
	/*                                 is_integral                                */
	/* -------------------------------------------------------------------------- */
	template <typename T> struct is_integral_base : ft::false_type {};
	template <> struct is_integral_base<bool> : ft::true_type {};
	template <> struct is_integral_base<char> : ft::true_type {};
	template <> struct is_integral_base<wchar_t> : ft::true_type {};
	template <> struct is_integral_base<short> : ft::true_type {};
	template <> struct is_integral_base<int> : ft::true_type {};
	template <> struct is_integral_base<long> : ft::true_type {};
	template <> struct is_integral_base<long long> : ft::true_type {};
	template <> struct is_integral_base<unsigned char> : ft::true_type {};
	template <> struct is_integral_base<unsigned short int> : ft::true_type {};
	template <> struct is_integral_base<unsigned int> : ft::true_type {};
	template <> struct is_integral_base<unsigned long int> : ft::true_type {};
	template <> struct is_integral_base<unsigned long long int> : ft::true_type {};
	
	template<typename T> struct is_integral : is_integral_base<typename ft::remove_cv<T>::type > {};

	/* -------------------------------------------------------------------------- */
	/*                                  enable_if                                 */
	/* -------------------------------------------------------------------------- */
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> {
		typedef T	type;
	};
}
