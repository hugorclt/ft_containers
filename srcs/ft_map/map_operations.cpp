/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:49:08 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 20:09:43 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_proto.hpp"

bool	find_test(std_typ std, ft_typ ft, int index)
{
	std_typ::iterator	stdit = std.find(index);
	ft_typ::iterator	ftit = ft.find(index);

	if (stdit->first != ftit->first)
		return (true);
	return (false);
}

void	find(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "find: \t\t\t\t\t\t\t" << (find_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (find_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (find_test(std, ft, 9) ? "❌" : "✅");
	std::cout << (find_test(std, ft, 6) ? "❌" : "✅")<< RESET << std::endl;
}

bool	count_test(std_typ std, ft_typ ft, int index)
{
	if (std.count(index) != ft.count(index))
		return (true);
	return (false);
}

void	count(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "count: \t\t\t\t\t\t\t" << (count_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (count_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (count_test(std, ft, 9) ? "❌" : "✅");
	std::cout << (count_test(std, ft, 6) ? "❌" : "✅")<< RESET << std::endl;
}

bool	lower_bound_test(std_typ std, ft_typ ft, int index)
{
	std_typ::iterator	stdit = std.lower_bound(index);
	ft_typ::iterator	ftit = ft.lower_bound(index);

	if (stdit->first != ftit->first)
		return (true);
	return (false);
}

void	lower_bound(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "lower_bound: \t\t\t\t\t\t" << (lower_bound_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (lower_bound_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (lower_bound_test(std, ft, 9) ? "❌" : "✅");
	std::cout << (lower_bound_test(std, ft, 6) ? "❌" : "✅")<< RESET << std::endl;
}

bool	upper_bound_test(std_typ std, ft_typ ft, int index)
{
	std_typ::iterator	stdit = std.upper_bound(index);
	ft_typ::iterator	ftit = ft.upper_bound(index);

	if (stdit->first != ftit->first)
		return (true);
	return (false);
}

void	upper_bound(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "upper_bound: \t\t\t\t\t\t" << (upper_bound_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (upper_bound_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (upper_bound_test(std, ft, 9) ? "❌" : "✅");
	std::cout << (upper_bound_test(std, ft, 6) ? "❌" : "✅")<< RESET << std::endl;
}

bool	equal_range_test(std_typ std, ft_typ ft, int index)
{
	std::pair<std_typ::iterator, std_typ::iterator>	stdit = std.equal_range(index);
	ft::pair<ft_typ::iterator, ft_typ::iterator>	ftit = ft.equal_range(index);

	if (stdit.first->first != ftit.first->first)
		return (true);
	if (stdit.second->first != ftit.second->first)
		return (true);
	return (false);
}

void	equal_range(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "equal_range: \t\t\t\t\t\t" << (equal_range_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (equal_range_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (equal_range_test(std, ft, 9) ? "❌" : "✅");
	std::cout << (equal_range_test(std, ft, 6) ? "❌" : "✅")<< RESET << std::endl;
}