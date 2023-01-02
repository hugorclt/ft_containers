/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:17:32 by hrecolet          #+#    #+#             */
/*   Updated: 2022/12/24 09:34:46 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.hpp"
#include <vector>

int	constructor_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
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

void constructor(void)
{
	/* --------------------------- Default Constructor -------------------------- */
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	/* ---------------------------- Fill Constructor ---------------------------- */
	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);

	/* -------------------------- Iterator Constructor -------------------------- */
	
	ft::vector<int>		ft_vec3(ft_vec2.begin(), ft_vec2.end());
	std::vector<int>	std_vec3(std_vec2.begin(), std_vec2.end());

	/* ---------------------------- Copy Constructor ---------------------------- */
	ft::vector<int>		ft_vec4(ft_vec2);
	std::vector<int>	std_vec4(std_vec2);

	std::cout << ORANGE	<< "Constructor Test (default constructor): \t" << (constructor_test(ft_vec1, std_vec1) ? "❌" : "✅") << RESET << std::endl;
	std::cout << ORANGE	<< "Constructor Test (fill constructor): \t\t" << (constructor_test(ft_vec2, std_vec2) ? "❌" : "✅") << RESET << std::endl;
	std::cout << ORANGE	<< "Constructor Test (iterator constructor): \t" << (constructor_test(ft_vec3, std_vec3) ? "❌" : "✅") << RESET << std::endl;
	std::cout << ORANGE	<< "Constructor Test (copy constructor): \t\t" << (constructor_test(ft_vec4, std_vec4) ? "❌" : "✅") << RESET << std::endl;
}