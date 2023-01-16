/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:02:00 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 19:06:00 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_proto.hpp"

bool	operator_test(std_typ std, ft_typ ft, int index)
{
	if (std[index] != ft[index])
		return (true);
	return (false);
}

void	op(std_typ std, ft_typ ft)
{
	std::cout << ORANGE	<< "operator[]: \t\t\t\t\t\t" << (operator_test(std, ft, 1) ? "❌" : "✅");
	std::cout << (operator_test(std, ft, 3) ? "❌" : "✅");
	std::cout << (operator_test(std, ft, 9) ? "❌" : "✅");
	std::cout << (operator_test(std, ft, 6) ? "❌" : "✅")<< RESET << std::endl;
}