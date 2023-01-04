/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:51:39 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/04 17:32:31 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.hpp"
#include "proto.hpp"
#include <iostream>
#include <stack>

int	size_test(ft::stack<int> &ftVec, std::stack<int> &stdVec)
{
	if (ftVec.size() != stdVec.size())
		return (1);
	return (0);
}

void size(void)
{
	ft::stack<int>		ft_vec1;
	std::stack<int>	std_vec1;

	ft::stack<int>		ft_vec2;
	std::stack<int>	std_vec2;
	
	ft::stack<int>		ft_vec3;
	std::stack<int>	std_vec3;

	ft::stack<int>		ft_vec4;
	std::stack<int>	std_vec4;

	std::cout << ORANGE	<< "size(): \t\t\t\t\t" << (size_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (size_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (size_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (size_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

int	empty_test(ft::stack<int> &ftVec, std::stack<int> &stdVec)
{
	if (ftVec.empty() != stdVec.empty())
		return (1);
	return (0);
}

void empty(void)
{
	ft::stack<int>		ft_vec1;
	std::stack<int>	std_vec1;

	ft::stack<int>		ft_vec2;
	std::stack<int>	std_vec2;
	
	ft::stack<int>		ft_vec3;
	std::stack<int>	std_vec3;

	ft::stack<int>		ft_vec4;
	std::stack<int>	std_vec4;

	std::cout << ORANGE	<< "empty() : \t\t\t\t\t" << (empty_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (empty_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (empty_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (empty_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

int	access_push_pop_test(ft::stack<int> &ftVec, std::stack<int> &stdVec)
{
	ftVec.push(1);
	stdVec.push(1);
	if (ftVec.top() != stdVec.top())
	{
		ftVec.push(4);
		stdVec.push(4);
		ftVec.push(42);
		stdVec.push(42);
		ftVec.pop();
		stdVec.pop();
		if (ftVec.top() != stdVec.top())
			return (1);
	}
	return (0);
}

void access_push_pop(void)
{
	ft::stack<int>		ft_vec1;
	std::stack<int>	std_vec1;

	ft::stack<int>		ft_vec2;
	std::stack<int>	std_vec2;
	
	ft::stack<int>		ft_vec3;
	std::stack<int>	std_vec3;

	ft::stack<int>		ft_vec4;
	std::stack<int>	std_vec4;

	std::cout << ORANGE	<< "push(), pop(), top() : \t\t\t\t" << (access_push_pop_test(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (access_push_pop_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (access_push_pop_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (access_push_pop_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}

int	main()
{
	std::cout << WHITE << "\t\tSTACK:" << RESET << std::endl;
	size();
	empty();
	access_push_pop();
}