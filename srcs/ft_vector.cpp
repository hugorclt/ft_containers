/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:41 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/02 15:59:30 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_vector.hpp"
#include <vector>

using namespace std::chrono;


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

int	main()
{
	//Default Constructor
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	//Fill Constructor
	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);

	//Iterator Constructor
	ft::vector<int>		ft_vec3;
	std::vector<int>	std_vec3;

	//Copy Constructor
	ft::vector<int>		ft_vec4(ft_vec2);
	std::vector<int>	std_vec4(std_vec2);

	//size()
	std::cout << "\033[4mvector.size() :\033[0m" << std::endl;
	ft_compare(ft_vec1.size(), std_vec1.size(), 0, 1);
	ft_compare(ft_vec2.size(), std_vec2.size(), 1, 1);
	ft_compare(ft_vec3.size(), std_vec3.size(), 2, 1);
	ft_compare(ft_vec4.size(), std_vec4.size(), 3, 1);
	std::cout << std::endl;
	
	//max_size()
	std::cout << "\033[4mvector.max_size() :\033[0m" << std::endl;
	ft_compare(ft_vec2.max_size(), std_vec2.max_size(), 1, 1);
	std::cout << std::endl;
	
	//resize()
	std::cout << "\033[4mvector.resize() :\033[0m" << std::endl;
	ft_vec2.resize(5, 3);
	std_vec2.resize(5, 3);
	for (size_t i = 0; i < std_vec2.size(); i++)
		ft_compare(ft_vec2[i], std_vec2[i], 0, 1);
	std::cout << std::endl;
	ft_vec2.resize(1, 1);
	std_vec2.resize(1, 1);
	for (size_t i = 0; i < std_vec2.size(); i++)
		ft_compare(ft_vec2[i], std_vec2[i], 1, 1);
	std::cout << std::endl;
	ft_vec2.resize(4, 5);
	std_vec2.resize(4, 5);
	for (size_t i = 0; i < std_vec2.size(); i++)
		ft_compare(ft_vec2[i], std_vec2[i], 2, 1);
	std::cout << std::endl;
	ft_vec2.resize(0, 0);
	std_vec2.resize(0, 0);
	for (size_t i = 0; i < std_vec2.size(); i++)
		ft_compare(ft_vec2[i], std_vec2[i], 3, 1);
	std::cout << std::endl;
	ft_vec2.resize(1);
	std_vec2.resize(1);
	for (size_t i = 0; i < std_vec2.size(); i++)
		ft_compare(ft_vec2[i], std_vec2[i], 4, 1);
	std::cout << std::endl;
	try {
		ft_vec2.resize(-10, 0);
		std_vec2.resize(-1, 0);
		for (size_t i = 0; i < std_vec2.size(); i++)
			ft_compare(ft_vec2[i], std_vec2[i], 4, 1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	//capacity()
	std::cout << "\033[4mvector.capacity() :\033[0m" << std::endl;
	ft_vec1.resize(3, 4);
	std_vec1.resize(3, 4);
	ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 0, 1);
	ft_vec1.resize(8, 4);
	std_vec1.resize(8, 4);
	ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 1, 1);
	ft_vec1.resize(4, 4);
	std_vec1.resize(4, 4);
	ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 2, 1);
	std::cout << std::endl;

	//empty()
	std::cout << "\033[4mvector.empty() :\033[0m" << std::endl;
	ft_compare(ft_vec1.empty(), std_vec1.empty(), 0, 1);
	ft_compare(ft_vec3.empty(), std_vec3.empty(), 1, 1);
	std::cout << std::endl;

	//reserve()
	std::cout << "\033[4mvector.reserve() :\033[0m" << std::endl;
	ft_vec1.reserve(10);
	std_vec1.reserve(10);
	ft_vec3.reserve(2);
	std_vec3.reserve(2);
	ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 0, 1);
	ft_compare(ft_vec3.capacity(), std_vec3.capacity(), 1, 1);
	ft_vec1.reserve(3);
	std_vec1.reserve(3);
	ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 2, 1);
	std::cout << std::endl;

	//shrink_to_fit()
	std::cout << "\033[4mvector.shrink_to_fit() :\033[0m" << std::endl;
	std_vec1.shrink_to_fit();
	ft_vec1.shrink_to_fit();
	ft_compare(ft_vec1.capacity(), std_vec1.capacity(), 0, 1);
	std::cout << std::endl;

	//shrink_to_fit()
	std::cout << "\033[4mvector.at() :\033[0m" << std::endl;
	for (size_t i = 0; i < ft_vec1.size(); i++)
		ft_compare(ft_vec1.at(i), std_vec1.at(i), 0, 1);
	try {
		ft_vec1.at(10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}