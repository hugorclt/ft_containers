/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:41 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/17 13:41:17 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.hpp"
#include "proto.hpp"
#include <vector>
#include <map>

using namespace ft;
using namespace std;

void	do_capacity_test(void)
{
	size();
	maxsize();
	resize();
	capacity();
	empty();
	reserve();
}

void	do_access_test(void)
{
	at();
	operat();
	front();
	back();
}

void	do_modifier_test(void)
{
	assign();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
}

// int	main()
// {
// 	std::cout << WHITE << "\t\tVECTOR:" << RESET << std::endl;
// 	constructor();
// 	std::cout << WHITE << "CAPACITY_TEST:" << RESET << std::endl;
// 	do_capacity_test();
// 	std::cout << WHITE << "ACCESS_TEST:" << RESET << std::endl;
// 	do_access_test();
// 	std::cout << WHITE << "MODIFIER_TEST:" << RESET << std::endl;
// 	do_modifier_test();
// }

template <class T>
void	print(ft::vector<ft::vector<T> >& lst)
{
	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(ft::vector<T>& lst)
{
	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}


int main ()
{
	ft::vector<int> test(3, 1);

	for (ft::vector<int>::iterator it = test.begin(); it < test.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
