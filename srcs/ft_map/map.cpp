/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:27 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 20:00:38 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_proto.hpp"

void	do_capacity_test(std_typ std, ft_typ ft)
{
	empty(std, ft);
	size(std, ft);
	max_size(std, ft);
}

void	do_access_test(std_typ std, ft_typ ft)
{
	op(std, ft);
}

void	do_modifier_test(std_typ std, ft_typ ft)
{
	insert(std, ft);
	erase(std, ft);
	swap(std, ft);
	clear(std, ft);
}

void	operation(std_typ std, ft_typ ft)
{
	find(std, ft);
	count(std, ft);
	lower_bound(std, ft);
	upper_bound(std, ft);
	equal_range(std, ft);
}

int	main()
{
	std::map<int, int>	stdMap;
	ft::map<int, int>	ftMap;

	for (int i = 0; i < 20; i++)
	{
		stdMap.insert(std::make_pair(i, i));
		ftMap.insert(ft::make_pair(i, i));
	}
	std::cout << WHITE << "\t\tMAP:" << RESET << std::endl;
	std::cout << WHITE << "CAPACITY_TEST:" << RESET << std::endl;
	do_capacity_test(stdMap, ftMap);
	std::cout << WHITE << "ACCESS_TEST:" << RESET << std::endl;
	do_access_test(stdMap, ftMap);
	std::cout << WHITE << "MODIFIER_TEST:" << RESET << std::endl;
	do_modifier_test(stdMap, ftMap);
	std::cout << WHITE << "OPERATION_TEST:" << RESET << std::endl;
	operation(stdMap, ftMap);
}

