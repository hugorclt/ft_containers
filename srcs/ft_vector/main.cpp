/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:41 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/03 16:54:45 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.hpp"
#include "proto.hpp"
#include <vector>

template <typename T>
void	ft_compare(T x, T y, int test_number, int display_output)
{
	if (x == y)
		std::cout << "\e[0;32mTest#" << test_number << " : ";
	else
		std::cout << "\e[0;31mTest#" << test_number << " : ";
	if (display_output == 1)
		std::cout << x << " == " << y << "\033[0m" << std::endl;
}

template <typename T>
void	ft_print_vector(T vec)
{
	for (unsigned long i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
}

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

int	main()
{
	ft::vector<int>	test(100, 1);

	for (std::pair<size_t, ft::vector<int>::const_reverse_iterator> i(0, test.rbegin()); i.first < test.size(); ++i.first)
	{
		std::cout << i.first << " for i: " << i.second[i.first] << std::endl;
	}
	// std::cout << WHITE << "\t\tVECTOR:" << RESET << std::endl;
	// constructor();
	// std::cout << WHITE << "CAPACITY_TEST:" << RESET << std::endl;
	// do_capacity_test();
	// std::cout << WHITE << "ACCESS_TEST:" << RESET << std::endl;
	// do_access_test();
	// std::cout << WHITE << "MODIFIER_TEST:" << RESET << std::endl;
	// do_modifier_test();
	// /* --------------------------------- assign --------------------------------- */
	// std::cout << "\033[4mvector.assign() :\033[0m" << std::endl;

	// ft::vector<int>::iterator	ft_iter1 = ft_vec2.begin();
	// ft::vector<int>::iterator	ft_iter2 = ft_vec2.end();
	// /*FIIIIIXXX
	// ft_begin = ft_vec2.begin();
	// ft_last = ft_vec2.end();
	// */	
	// std::vector<int>::iterator std_iter1 = std_vec2.begin();
	// std::vector<int>::iterator std_iter2 = std_vec2.end();

	// ft_vec1.assign(ft_iter1, ft_iter2);
	// std_vec1.assign(std_iter1, std_iter2);
	// for (size_t i = 0; i < ft_vec1.size(); i++)
	// 	ft_compare(ft_vec1[i], std_vec1[i], 0, 1);

	// ft_vec1.assign(14, 1);
	// std_vec1.assign(14, 1);
	// for (size_t i = 0; i < ft_vec1.size(); i++)
	// 	ft_compare(ft_vec1[i], std_vec1[i], 1, 1);
	
	// ft_vec1.assign(2, 3);
	// std_vec1.assign(2, 3);
	// for (size_t i = 0; i < ft_vec1.size(); i++)
	// 	ft_compare(ft_vec1[i], std_vec1[i], 2, 1);
	// std::cout << std::endl;

	// /* ---------------------------------- push_back ---------------------------------- */
	// std::cout << "\033[4mvector.push_back() :\033[0m" << std::endl;
	// ft_vec2.push_back(10);
	// std_vec2.push_back(10);
	// ft_compare(ft_vec2.back(), std_vec2.back(), 0, 1);
	// ft_vec2.push_back(11);
	// std_vec2.push_back(11);
	// ft_vec2.push_back(12);
	// std_vec2.push_back(12);
	// ft_vec2.push_back(13);
	// std_vec2.push_back(13);
	// ft_vec2.push_back(14);
	// std_vec2.push_back(14);
	// ft_compare(ft_vec2.back(), std_vec2.back(), 1, 1);
	// std::cout << std::endl;
	
	// /* ---------------------------------- pop_back ---------------------------------- */
	// std::cout << "\033[4mvector.pop_back() :\033[0m" << std::endl;
	// ft_vec2.pop_back();
	// std_vec2.pop_back();
	// ft_compare(ft_vec2.back(), std_vec2.back(), 0, 1);
	// ft_vec2.pop_back();
	// std_vec2.pop_back();
	// ft_vec2.pop_back();
	// std_vec2.pop_back();
	// ft_compare(ft_vec2.back(), std_vec2.back(), 1, 1);
	// std::cout << std::endl;

	// /* ---------------------------------- insert ---------------------------------- */
	// std::cout << "\033[4mvector.insert() :\033[0m" << std::endl;
	
	// ft::vector<int>::iterator	ft_vec3_iter1 = ft_vec3.begin();
	// std::vector<int>::iterator	std_vec3_iter1 = std_vec3.begin();

	// ft_vec3.insert(ft_vec3_iter1, 50);
	// std_vec3.insert(std_vec3_iter1, 50);
	// ft_compare(ft_vec3.front(), std_vec3.front(), 0, 1);
	// std_vec3.reserve(10);
	// ft_vec3.reserve(10);
	
	// std::vector<int>::iterator std_vec3_iter2 = std_vec3.begin();
	// ft::vector<int>::iterator ft_vec3_iter2 = ft_vec3.begin();
	// ft_vec3.insert(ft_vec3_iter2, 55);
	// std_vec3.insert(std_vec3_iter2, 55);
	// ft_compare(ft_vec3.front(), std_vec3.front(), 1, 1);

	// std::vector<int>::iterator std_vec3_iter3 = std_vec3.begin();
	// ft::vector<int>::iterator ft_vec3_iter3 = ft_vec3.begin();
	// ft_vec3.insert(ft_vec3_iter3, 2, 60);
	// std_vec3.insert(std_vec3_iter3, 2, 60);
	// ft_compare(ft_vec3.front(), std_vec3.front(), 2, 1);
	
	// std::vector<int>::iterator std_vec3_iter6 = std_vec3.begin();
	// ft::vector<int>::iterator ft_vec3_iter6 = ft_vec3.begin();
	// ft::vector<int>::iterator	ft_vec2_iter4 = ft_vec2.begin();
	// std::vector<int>::iterator	std_vec2_iter4 = std_vec2.begin();
	// ft::vector<int>::iterator	ft_vec2_iter5 = ft_vec2.end();
	// std::vector<int>::iterator	std_vec2_iter5 = std_vec2.end();\
	
	// ft_vec3.insert(ft_vec3_iter6, ft_vec2_iter4, ft_vec2_iter5);
	// std_vec3.insert(std_vec3_iter6, std_vec2_iter4, std_vec2_iter5);
	// ft_compare(ft_vec3.front(), std_vec3.front(), 3, 1);
	// std::cout << std::endl;

	// /* ---------------------------------- erase --------------------------------- */
	// std::cout << "ft" << std::endl;
	// ft_print_vector(ft_vec3);
	// std::cout << "std" << std::endl;
	// ft_print_vector(std_vec3);
	// ft::vector<int>::iterator	ft_vec2_iter9 = ft_vec3.begin();
	// std::vector<int>::iterator	std_vec2_iter9 = std_vec3.begin();
	// ft_vec3.erase(ft_vec2_iter9);
	// std_vec3.erase(std_vec2_iter9);
	// std::cout << "ft" << std::endl;
	// ft_print_vector(ft_vec3);
	// std::cout << "std" << std::endl;
	// ft_print_vector(std_vec3);

	// ft::vector<int>::iterator	ft_vec2_iter7 = ft_vec3.begin();
	// std::vector<int>::iterator	std_vec2_iter7 = std_vec3.begin();
	// ft::vector<int>::iterator	ft_vec2_iter8 = ft_vec3.end();
	// std::vector<int>::iterator	std_vec2_iter8 = std_vec3.end();
	// ft_vec3.erase(ft_vec2_iter7, std_vec2_iter7);
	// std_vec3.erase(ft_vec2_iter8, std_vec2_iter8);
	// std::cout << "ft" << std::endl;
	// ft_print_vector(ft_vec3);
	// std::cout << "std" << std::endl;
	// ft_print_vector(std_vec3);
	// std::cout << std::endl;
}

