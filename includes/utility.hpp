/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:28:10 by hrecolet          #+#    #+#             */
/*   Updated: 2022/09/13 11:42:02 by hrecolet         ###   ########.fr       */
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
	/*                                 is_integral                                */
	/* -------------------------------------------------------------------------- */
	/* -------------------------------- non-const ------------------------------- */
	template <typename T> struct is_integral : ft::false_type {};
	template <> struct is_integral<bool> : ft::true_type {};
	template <> struct is_integral<char> : ft::true_type {};
	template <> struct is_integral<wchar_t> : ft::true_type {};
	template <> struct is_integral<short> : ft::true_type {};
	template <> struct is_integral<int> : ft::true_type {};
	template <> struct is_integral<long> : ft::true_type {};
	template <> struct is_integral<long long> : ft::true_type {};
	template <> struct is_integral<unsigned char> : ft::true_type {};
	template <> struct is_integral<unsigned short int> : ft::true_type {};
	template <> struct is_integral<unsigned int> : ft::true_type {};
	template <> struct is_integral<unsigned long int> : ft::true_type {};
	template <> struct is_integral<unsigned long long int> : ft::true_type {};
	/* ---------------------------------- const --------------------------------- */
	template <> struct is_integral<const bool> : ft::true_type {};
	template <> struct is_integral<const char> : ft::true_type {};
	template <> struct is_integral<const wchar_t> : ft::true_type {};
	template <> struct is_integral<const short> : ft::true_type {};
	template <> struct is_integral<const int> : ft::true_type {};
	template <> struct is_integral<const long> : ft::true_type {};
	template <> struct is_integral<const long long> : ft::true_type {};
	template <> struct is_integral<const unsigned char> : ft::true_type {};
	template <> struct is_integral<const unsigned short int> : ft::true_type {};
	template <> struct is_integral<const unsigned int> : ft::true_type {};
	template <> struct is_integral<const unsigned long int> : ft::true_type {};
	template <> struct is_integral<const unsigned long long int> : ft::true_type {};
	/* -------------------------------- volatile -------------------------------- */
	template <> struct is_integral<volatile bool> : ft::true_type {};
	template <> struct is_integral<volatile char> : ft::true_type {};
	template <> struct is_integral<volatile wchar_t> : ft::true_type {};
	template <> struct is_integral<volatile short> : ft::true_type {};
	template <> struct is_integral<volatile int> : ft::true_type {};
	template <> struct is_integral<volatile long> : ft::true_type {};
	template <> struct is_integral<volatile long long> : ft::true_type {};
	template <> struct is_integral<volatile unsigned char> : ft::true_type {};
	template <> struct is_integral<volatile unsigned short int> : ft::true_type {};
	template <> struct is_integral<volatile unsigned int> : ft::true_type {};
	template <> struct is_integral<volatile unsigned long int> : ft::true_type {};
	template <> struct is_integral<volatile unsigned long long int> : ft::true_type {};
	/* ----------------------------- const-volatile ----------------------------- */
	template <> struct is_integral<const volatile bool> : ft::true_type {};
	template <> struct is_integral<const volatile char> : ft::true_type {};
	template <> struct is_integral<const volatile wchar_t> : ft::true_type {};
	template <> struct is_integral<const volatile short> : ft::true_type {};
	template <> struct is_integral<const volatile int> : ft::true_type {};
	template <> struct is_integral<const volatile long> : ft::true_type {};
	template <> struct is_integral<const volatile long long> : ft::true_type {};
	template <> struct is_integral<const volatile unsigned char> : ft::true_type {};
	template <> struct is_integral<const volatile unsigned short int> : ft::true_type {};
	template <> struct is_integral<const volatile unsigned int> : ft::true_type {};
	template <> struct is_integral<const volatile unsigned long int> : ft::true_type {};
	template <> struct is_integral<const volatile unsigned long long int> : ft::true_type {};

	/* -------------------------------------------------------------------------- */
	/*                                 is_iterator                                */
	/* -------------------------------------------------------------------------- */

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
