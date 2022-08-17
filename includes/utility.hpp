/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:28:10 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/17 11:25:15 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <type_traits>

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
	}

	/* -------------------------------------------------------------------------- */
	/*                                 is_integral                                */
	/* -------------------------------------------------------------------------- */
	/* -------------------------------- non-const ------------------------------- */
	template <typename T> struct is_integral : std::false_type {};
	template <> struct is_integral<bool> : std::true_type {};
	template <> struct is_integral<char> : std::true_type {};
	template <> struct is_integral<char16_t> : std::true_type {};
	template <> struct is_integral<char32_t> : std::true_type {};
	template <> struct is_integral<wchar_t> : std::true_type {};
	template <> struct is_integral<short> : std::true_type {};
	template <> struct is_integral<int> : std::true_type {};
	template <> struct is_integral<long> : std::true_type {};
	template <> struct is_integral<long long> : std::true_type {};
	template <> struct is_integral<unsigned char> : std::true_type {};
	template <> struct is_integral<unsigned short int> : std::true_type {};
	template <> struct is_integral<unsigned int> : std::true_type {};
	template <> struct is_integral<unsigned long int> : std::true_type {};
	template <> struct is_integral<unsigned long long int> : std::true_type {};
	/* ---------------------------------- const --------------------------------- */
	template <> struct is_integral<const bool> : std::true_type {};
	template <> struct is_integral<const char> : std::true_type {};
	template <> struct is_integral<const char16_t> : std::true_type {};
	template <> struct is_integral<const char32_t> : std::true_type {};
	template <> struct is_integral<const wchar_t> : std::true_type {};
	template <> struct is_integral<const short> : std::true_type {};
	template <> struct is_integral<const int> : std::true_type {};
	template <> struct is_integral<const long> : std::true_type {};
	template <> struct is_integral<const long long> : std::true_type {};
	template <> struct is_integral<const unsigned char> : std::true_type {};
	template <> struct is_integral<const unsigned short int> : std::true_type {};
	template <> struct is_integral<const unsigned int> : std::true_type {};
	template <> struct is_integral<const unsigned long int> : std::true_type {};
	template <> struct is_integral<const unsigned long long int> : std::true_type {};
	/* -------------------------------- volatile -------------------------------- */
	template <> struct is_integral<volatile bool> : std::true_type {};
	template <> struct is_integral<volatile char> : std::true_type {};
	template <> struct is_integral<volatile char16_t> : std::true_type {};
	template <> struct is_integral<volatile char32_t> : std::true_type {};
	template <> struct is_integral<volatile wchar_t> : std::true_type {};
	template <> struct is_integral<volatile short> : std::true_type {};
	template <> struct is_integral<volatile int> : std::true_type {};
	template <> struct is_integral<volatile long> : std::true_type {};
	template <> struct is_integral<volatile long long> : std::true_type {};
	template <> struct is_integral<volatile unsigned char> : std::true_type {};
	template <> struct is_integral<volatile unsigned short int> : std::true_type {};
	template <> struct is_integral<volatile unsigned int> : std::true_type {};
	template <> struct is_integral<volatile unsigned long int> : std::true_type {};
	template <> struct is_integral<volatile unsigned long long int> : std::true_type {};
	/* ----------------------------- const-volatile ----------------------------- */
	template <> struct is_integral<const volatile bool> : std::true_type {};
	template <> struct is_integral<const volatile char> : std::true_type {};
	template <> struct is_integral<const volatile char16_t> : std::true_type {};
	template <> struct is_integral<const volatile char32_t> : std::true_type {};
	template <> struct is_integral<const volatile wchar_t> : std::true_type {};
	template <> struct is_integral<const volatile short> : std::true_type {};
	template <> struct is_integral<const volatile int> : std::true_type {};
	template <> struct is_integral<const volatile long> : std::true_type {};
	template <> struct is_integral<const volatile long long> : std::true_type {};
	template <> struct is_integral<const volatile unsigned char> : std::true_type {};
	template <> struct is_integral<const volatile unsigned short int> : std::true_type {};
	template <> struct is_integral<const volatile unsigned int> : std::true_type {};
	template <> struct is_integral<const volatile unsigned long int> : std::true_type {};
	template <> struct is_integral<const volatile unsigned long long int> : std::true_type {};

	/* -------------------------------------------------------------------------- */
	/*                                  enable_if                                 */
	/* -------------------------------------------------------------------------- */
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> {
		typedef type T;
	};
}