/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifier.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:07:31 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 19:47:14 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_proto.hpp"

bool	insert_test(std_typ std, ft_typ ft, int key, int value)
{
	std.insert(std::make_pair(key, value));
	ft.insert(ft::make_pair(key, value));
	if (std.size() != ft.size())
		return (true);
	return (false);
}

void	insert(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "insert:	\t\t\t\t\t\t" << (insert_test(std, ft, 98, 1) ? "❌" : "✅");
	std::cout << (insert_test(std, ft, 32, 3) ? "❌" : "✅");
	std::cout << (insert_test(std, ft, -10, 1) ? "❌" : "✅");
	std::cout << (insert_test(std, ft, -6, 2) ? "❌" : "✅")<< RESET << std::endl;
}

bool	erase_test(std_typ std, ft_typ ft, int key)
{
	std.erase(key);
	ft.erase(key);
	if (std.size() != ft.size())
		return (true);
	return (false);
}

void	erase(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "erase: \t\t\t\t\t\t\t" << (erase_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (erase_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (erase_test(std, ft, 2) ? "❌" : "✅");
	std::cout << (erase_test(std, ft, 5) ? "❌" : "✅")<< RESET << std::endl;
}

bool	clear_test(std_typ std, ft_typ ft)
{
	ft.clear();
	std.clear();
	if (std.size() != ft.size())
		return (true);
	return (false);
}


void	clear(std_typ std, ft_typ ft)
{
	std::map<int, int>	stdMap;
	ft::map<int, int>	ftMap;
	
	std::cout << ORANGE	<< "clear: \t\t\t\t\t\t\t" << (clear_test(std, ft) ? "❌" : "✅");
	std::cout << (clear_test(stdMap, ftMap) ? "❌" : "✅")<< RESET << std::endl;
}

bool	swap_test(std_typ std, ft_typ ft, std_typ std2, ft_typ ft2)
{
	ft.swap(ft2);
	std.swap(std2);
	
	if (std.size() != ft.size())
		return (true);
	return (false);
}


void	swap(std_typ std, ft_typ ft)
{
	std::map<int, int>	stdMap;
	ft::map<int, int>	ftMap;
	
	std::cout << ORANGE	<< "swap: \t\t\t\t\t\t\t" << (swap_test(stdMap, ftMap, std, ft) ? "❌" : "✅");
	std::cout << (swap_test(std, ft, stdMap, ftMap) ? "❌" : "✅")<< RESET << std::endl;
}