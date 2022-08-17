/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:27 by hrecolet          #+#    #+#             */
/*   Updated: 2022/08/17 11:12:27 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utility.hpp"
#include <iostream>

int	main()
{
	ft::pair<int, int> a;
	ft::pair<int, int> b;
	
	a = ft::make_pair<int, int>(1, 2);

	std::cout << a.first << std::endl;
	std::cout << a.second << std::endl;

	b.first = 3;
	b.second = 4;
	std::cout << "a" << std::endl;
	std::cout << a.first << std::endl;
	std::cout << a.second << std::endl;
	std::cout << "b" << std::endl;
	std::cout << b.first << std::endl;
	std::cout << b.second << std::endl;
	if (a < b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << std::is_integral<volatile char>::value << std::endl;
	std::cout << ft::is_integral<volatile char>::value << std::endl;
}