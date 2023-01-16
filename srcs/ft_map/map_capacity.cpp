/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_capacity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:40:14 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 19:00:56 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_proto.hpp"

bool	empty_test(std_typ std, ft_typ ft)
{
	if (std.empty() == ft.empty())
		return (false);
	return (true);
}

void	empty(std_typ std, ft_typ ft)
{
	std::map<int, int>	stdMap;
	ft::map<int, int>	ftMap;
	
	std::cout << ORANGE	<< "empty(): \t\t\t\t\t\t" << (empty_test(std, ft) ? "❌" : "✅");
	std::cout << (empty_test(stdMap, ftMap) ? "❌" : "✅") << RESET << std::endl;
}

bool	size_test(std_typ std, ft_typ ft)
{
	if (std.size() == ft.size())
		return (false);
	return (true);
}

void	size(std_typ std, ft_typ ft)
{
	std::map<int, int>	stdMap;
	ft::map<int, int>	ftMap;
	
	std::cout << ORANGE	<< "size(): \t\t\t\t\t\t" << (size_test(std, ft) ? "❌" : "✅");
	std::cout << (size_test(stdMap, ftMap) ? "❌" : "✅");
	std.erase(1);
	ft.erase(1);
	std::cout << (size_test(stdMap, ftMap) ? "❌" : "✅");
	std.insert(std::make_pair(1, 1));
	ft.insert(ft::make_pair(1, 1));
	std::cout << (size_test(stdMap, ftMap) ? "❌" : "✅")<< RESET << std::endl;
}

bool	max_size_test(std_typ std, ft_typ ft)
{
	if (std.max_size() == ft.max_size())
		return (false);
	return (true);
}

void	max_size(std_typ std, ft_typ ft)
{
	std::map<int, int>	stdMap;
	ft::map<int, int>	ftMap;
	
	std::cout << ORANGE	<< "max_size(): \t\t\t\t\t\t" << (max_size_test(std, ft) ? "❌" : "✅");
	std::cout << (max_size_test(stdMap, ftMap) ? "❌" : "✅")<< RESET << std::endl;
}