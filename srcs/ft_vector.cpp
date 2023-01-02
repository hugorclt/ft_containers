/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:41 by hrecolet          #+#    #+#             */
/*   Updated: 2022/12/24 09:34:33 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.hpp"
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

int	main()
{
	/* --------------------------- Default Constructor -------------------------- */
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	/* ---------------------------- Fill Constructor ---------------------------- */
	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);

	/* -------------------------- Iterator Constructor -------------------------- */
	ft::vector<int>::iterator ft_begin = ft_vec2.begin();
	ft::vector<int>::iterator ft_last = ft_vec2.end();
	std::vector<int>::iterator std_begin = std_vec2.begin();
	std::vector<int>::iterator std_last = std_vec2.end();
	
	ft::vector<int>		ft_vec3(ft_begin, ft_last);
	std::vector<int>	std_vec3(std_begin, std_last);

	/* ---------------------------- Copy Constructor ---------------------------- */
	ft::vector<int>		ft_vec4(ft_vec2);
	std::vector<int>	std_vec4(std_vec2);

	ft::vector<int> foo (3,0);
	ft::vector<int> bar (5,4);

	bar = foo;
	foo = ft::vector<int>(3, 2);

	std::cout << "Size of foo: " << *foo.begin() << '\n';
	std::cout << "Size of bar: " << *bar.begin() << '\n';

	/* --------------------------------- size() --------------------------------- */
	std::cout << "\033[4mvector.size() :\033[0m" << std::endl;
	ft_compare(ft_vec1.size(), std_vec1.size(), 0, 1);
	ft_compare(ft_vec2.size(), std_vec2.size(), 1, 1);
	ft_compare(ft_vec3.size(), std_vec3.size(), 2, 1);
	ft_compare(ft_vec4.size(), std_vec4.size(), 3, 1);
	std::cout << std::endl;
	
	/* ------------------------------- max_size() ------------------------------- */
	std::cout << "\033[4mvector.max_size() :\033[0m" << std::endl;
	ft_compare(ft_vec2.max_size(), std_vec2.max_size(), 1, 1);
	std::cout << std::endl;
	
	// /* -------------------------------- resize() -------------------------------- */
	// std::cout << "\033[4mvector.resize() :\033[0m" << std::endl;
	// ft_vec2.resize(5, 3);
	// std_vec2.resize(5, 3);
	// for (size_t i = 0; i < std_vec2.size(); i++)
	// 	ft_compare(ft_vec2[i], std_vec2[i], 0, 1);


	// std::cout << std::endl;
	// ft_vec2.resize(1, 1);
	// std_vec2.resize(1, 1);
	// for (size_t i = 0; i < std_vec2.size(); i++)
	// 	ft_compare(ft_vec2[i], std_vec2[i], 1, 1);
		

	// std::cout << std::endl;
	// ft_vec2.resize(4, 5);
	// std_vec2.resize(4, 5);
	// for (size_t i = 0; i < std_vec2.size(); i++)
	// 	ft_compare(ft_vec2[i], std_vec2[i], 2, 1);
		
		
	// std::cout << std::endl;
	// ft_vec2.resize(0, 0);
	// std_vec2.resize(0, 0);
	// for (size_t i = 0; i < std_vec2.size(); i++)
	// 	ft_compare(ft_vec2[i], std_vec2[i], 3, 1);
		
		
	// std::cout << std::endl;
	// ft_vec2.resize(1);
	// std_vec2.resize(1);
	// for (size_t i = 0; i < std_vec2.size(); i++)
	// 	ft_compare(ft_vec2[i], std_vec2[i], 4, 1);

	// std::cout << std::endl;
	// try {
	// 	ft_vec2.resize(-10, 0);
	// 	std_vec2.resize(-1, 0);
	// 	for (size_t i = 0; i < std_vec2.size(); i++)
	// 		ft_compare(ft_vec2[i], std_vec2[i], 5, 1);
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << std::endl;
	
	// /* ------------------------------- capacity() ------------------------------- */
	// std::cout << "\033[4mvector.capacity() :\033[0m" << std::endl;
	// ft_vec1.resize(3, 4);
	// std_vec1.resize(3, 4);
	// ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 0, 1);
	// ft_vec1.resize(8, 4);
	// std_vec1.resize(8, 4);
	// ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 1, 1);
	// ft_vec1.resize(4, 4);
	// std_vec1.resize(4, 4);
	// ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 2, 1);
	// std::cout << std::endl;

	// /* --------------------------------- empty() -------------------------------- */
	// std::cout << "\033[4mvector.empty() :\033[0m" << std::endl;
	// ft_compare(ft_vec1.empty(), std_vec1.empty(), 0, 1);
	// ft_compare(ft_vec3.empty(), std_vec3.empty(), 1, 1);
	// std::cout << std::endl;

	// /* -------------------------------- reserve() ------------------------------- */
	// std::cout << "\033[4mvector.reserve() :\033[0m" << std::endl;
	// ft_vec1.reserve(10);
	// std_vec1.reserve(10);
	// ft_vec3.reserve(2);
	// std_vec3.reserve(2);
	// ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 0, 1);
	// for (size_t i = 0; i < ft_vec3.size(); i++)
	// 	ft_compare(ft_vec3[i], std_vec3[i], 1, 1);
	// ft_vec3.reserve(6);
	// std_vec3.reserve(6);
	// for (size_t i = 0; i < ft_vec3.size(); i++)
	// 	ft_compare(ft_vec3[i], std_vec3[i], 2, 1);
	// ft_vec1.reserve(3);
	// std_vec1.reserve(3);
	// ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 3, 1);
	// std::cout << std::endl;
	
	// /* ---------------------------------- at() ---------------------------------- */
	// std::cout << "\033[4mvector.at() :\033[0m" << std::endl;
	// for (size_t i = 0; i < ft_vec2.size(); i++)
	// 	ft_compare(ft_vec2.at(i), std_vec2.at(i), i, 1);
	// try {
	// 	//std_vec1.at(10);
	// 	ft_vec1.at(10);
	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// /* ---------------------------------- front --------------------------------- */
	// std::cout << "\033[4mvector.front() :\033[0m" << std::endl;
	// ft_compare(ft_vec2.front(), std_vec2.front(), 0, 1);
	// std::cout << std::endl;

	// /* ---------------------------------- back ---------------------------------- */
	// std::cout << "\033[4mvector.back() :\033[0m" << std::endl;
	// ft_compare(ft_vec2.back(), std_vec2.back(), 0, 1);
	// std::cout << std::endl;

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

