/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:41 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/04 19:22:10 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.hpp"
#include "proto.hpp"
#include <vector>
#include <map>

void	do_capacity_test(void)
{
	size();
	maxsize();
	resize();
	capacity();
	empty();
	reserve();
}

void	do_access_test(void)
{
	at();
	operat();
	front();
	back();
}

void	do_modifier_test(void)
{
	assign();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
}

int	main()
{
	std::cout << WHITE << "\t\tVECTOR:" << RESET << std::endl;
	constructor();
	std::cout << WHITE << "CAPACITY_TEST:" << RESET << std::endl;
	do_capacity_test();
	std::cout << WHITE << "ACCESS_TEST:" << RESET << std::endl;
	do_access_test();
	std::cout << WHITE << "MODIFIER_TEST:" << RESET << std::endl;
	do_modifier_test();
}

