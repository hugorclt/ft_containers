/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:57:12 by hrecolet          #+#    #+#             */
/*   Updated: 2022/12/02 12:10:33 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_vector.hpp"
#include <vector>

/* -------------------------------------------------------------------------- */
/*                                     at                                     */
/* -------------------------------------------------------------------------- */
int	at_test(ft::vector<int> &ftVec, std::vector<int> &stdVec, int index)
{
	try {
		if (ftVec.at(index) != stdVec.at(index))
			return (1);
	} catch (std::exception &eft) {
		try {
			stdVec.at(index);
		} catch (std::exception &estd) {
			return (0);
		}
	}
	return (0);
}

void at(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "at(): \t\t\t\t\t\t" << (at_test(ft_vec4, std_vec4, 1) ? "❌" : "✅");
	std::cout << (at_test(ft_vec2, std_vec2, 0) ? "❌" : "✅");
	std::cout << (at_test(ft_vec3, std_vec3, -1) ? "❌" : "✅");
	std::cout << (at_test(ft_vec4, std_vec4, 10) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                              operator[]                                    */
/* -------------------------------------------------------------------------- */
int	operat_test(ft::vector<int> &ftVec, std::vector<int> &stdVec, int index)
{
	if (ftVec[index] != stdVec[index])
		return (1);
	return (0);
}

void operat(void)
{
	ft::vector<int>		ft_vec1(1, 2);
	std::vector<int>	std_vec1(1, 2);

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "operat(): \t\t\t\t\t" << (operat_test(ft_vec4, std_vec4, 0) ? "❌" : "✅");
	std::cout << (operat_test(ft_vec2, std_vec2, 3) ? "❌" : "✅");
	std::cout << (operat_test(ft_vec3, std_vec3, 5) ? "❌" : "✅");
	std::cout << (operat_test(ft_vec4, std_vec4, 10) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                    front                                   */
/* -------------------------------------------------------------------------- */
int	front_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.front() != stdVec.front())
		return (1);
	return (0);
}

void front(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "front(): \t\t\t\t\t" << (front_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (front_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (front_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (front_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                    back                                    */
/* -------------------------------------------------------------------------- */

int	back_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.front() != stdVec.front())
		return (1);
	return (0);
}

void back(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "back(): \t\t\t\t\t" << (back_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (back_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (back_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (back_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}
