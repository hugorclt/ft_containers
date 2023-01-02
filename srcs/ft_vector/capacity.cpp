/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:13:40 by hrecolet          #+#    #+#             */
/*   Updated: 2022/12/24 09:35:10 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.hpp"
#include <vector>

/* -------------------------------------------------------------------------- */
/*                                    size                                    */
/* -------------------------------------------------------------------------- */
int	size_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.size() != stdVec.size())
		return (1);
	return (0);
}

void size(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "size(): \t\t\t\t\t" << (size_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (size_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (size_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (size_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                  max_size                                  */
/* -------------------------------------------------------------------------- */
int	maxsize_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.max_size() != stdVec.max_size())
		return (1);
	return (0);
}

void maxsize(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "max_size() : \t\t\t\t\t" << (maxsize_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (maxsize_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (maxsize_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (maxsize_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                   resize                                   */
/* -------------------------------------------------------------------------- */

int	resize_test(ft::vector<int> &ftVec, std::vector<int> &stdVec, int n, int val)
{
	ftVec.resize(n, val);
	stdVec.resize(n, val);
	if (ftVec.size() != stdVec.size())
		return (1);
	std::vector<int>::iterator it2 = stdVec.begin();
	for (ft::vector<int>::iterator it = ftVec.begin();  it != ftVec.end(); it++, it2++)
	{
		if (*it != *it2)
			return (1);
	}
	return (0);
}

void resize(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "resize() : \t\t\t\t\t" << (resize_test(ft_vec1, std_vec1, 20, 2) ? "❌" : "✅");
	std::cout << (resize_test(ft_vec2, std_vec2, 2, -1) ? "❌" : "✅");
	std::cout << (resize_test(ft_vec3, std_vec3, 10, 2) ? "❌" : "✅");
	std::cout << (resize_test(ft_vec4, std_vec4, 39, 100) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                  capacity                                  */
/* -------------------------------------------------------------------------- */

int	capacity_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.capacity() != stdVec.capacity())
		return (1);
	return (0);
}

void capacity(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "capacity() : \t\t\t\t\t" << (capacity_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (capacity_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (capacity_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (capacity_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                    empty                                   */
/* -------------------------------------------------------------------------- */

int	empty_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.empty() != stdVec.empty())
		return (1);
	return (0);
}

void empty(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "empty() : \t\t\t\t\t" << (empty_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (empty_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (empty_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (empty_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                   reserve                                  */
/* -------------------------------------------------------------------------- */

int	reserve_test(ft::vector<int> &ftVec, std::vector<int> &stdVec, int n)
{
	ftVec.resize(n);
	stdVec.resize(n);
	if (ftVec.size() != stdVec.size())
		return (1);
	std::vector<int>::iterator it2 = stdVec.begin();
	for (ft::vector<int>::iterator it = ftVec.begin();  it != ftVec.end(); it++, it2++)
	{
		if (*it != *it2)
			return (1);
	}
	return (0);
}

void reserve(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "reserve() : \t\t\t\t\t" << (reserve_test(ft_vec1, std_vec1, 20) ? "❌" : "✅");
	std::cout << (reserve_test(ft_vec2, std_vec2, 2) ? "❌" : "✅");
	std::cout << (reserve_test(ft_vec3, std_vec3, 10) ? "❌" : "✅");
	std::cout << (reserve_test(ft_vec4, std_vec4, 39) ? "❌" : "✅") << RESET << std::endl;
}