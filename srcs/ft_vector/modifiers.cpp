/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:10:51 by hrecolet          #+#    #+#             */
/*   Updated: 2022/12/05 17:57:31 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_vector.hpp"
#include <vector>

/* -------------------------------------------------------------------------- */
/*                                   assign                                   */
/* -------------------------------------------------------------------------- */

int	assign_test_fill(ft::vector<int> &ftVec, std::vector<int> &stdVec, int n, int val)
{
	ftVec.assign(n, val);
	stdVec.assign(n, val);
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

int	assign_test_range(ft::vector<int> &ftVec, std::vector<int> &stdVec, ft::vector<int> &ftVec2, std::vector<int> &stdVec2)
{
	ftVec.assign(ftVec2.begin(), ftVec2.end());
	stdVec.assign(stdVec2.begin(), stdVec2.end());
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

void assign(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "assign() : \t\t\t\t\t" << (assign_test_fill(ft_vec1, std_vec1, 3, 2) ? "❌" : "✅");
	std::cout << (assign_test_fill(ft_vec2, std_vec2, 2, 4) ? "❌" : "✅");
	std::cout << (assign_test_fill(ft_vec3, std_vec3, 10, 1) ? "❌" : "✅");
	std::cout << (assign_test_fill(ft_vec4, std_vec4, 39, 8) ? "❌" : "✅");
	std::cout << (assign_test_range(ft_vec1, std_vec1, ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (assign_test_range(ft_vec2, std_vec2, ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (assign_test_range(ft_vec3, std_vec3, ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (assign_test_range(ft_vec4, std_vec4, ft_vec3, std_vec3) ? "❌" : "✅") << RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                  push_back                                 */
/* -------------------------------------------------------------------------- */

int	push_back_test(ft::vector<int> &ftVec, std::vector<int> &stdVec, int n)
{
	ftVec.push_back(n);
	stdVec.push_back(n);
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

int	push_back_max_size(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	if (ftVec.capacity() != stdVec.capacity())
		return (1);
	return (0);
}

void push_back(void)
{
	ft::vector<int>		ft_vec1;
	std::vector<int>	std_vec1;

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "push_back() : \t\t\t\t\t" << (push_back_test(ft_vec1, std_vec1, 3) ? "❌" : "✅");
	std::cout << (push_back_test(ft_vec2, std_vec2, 2) ? "❌" : "✅");
	std::cout << (push_back_test(ft_vec3, std_vec3, 10) ? "❌" : "✅");
	std::cout << (push_back_test(ft_vec4, std_vec4, 39) ? "❌" : "✅");
	std::cout << (push_back_max_size(ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (push_back_max_size(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (push_back_max_size(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (push_back_max_size(ft_vec4, std_vec4) ? "❌" : "✅") << std::endl;
}


/* -------------------------------------------------------------------------- */
/*                                  pop_back                                  */
/* -------------------------------------------------------------------------- */

int	pop_back_test(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	ftVec.pop_back();
	stdVec.pop_back();
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

void pop_back(void)
{
	ft::vector<int>		ft_vec1(1, 1);
	std::vector<int>	std_vec1(1, 1);

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "pop_back() : \t\t\t\t\t" << (pop_back_test(ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (pop_back_test(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (pop_back_test(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (pop_back_test(ft_vec4, std_vec4) ? "❌" : "✅") << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                  insert                                    */
/* -------------------------------------------------------------------------- */

int	insert_test_one(ft::vector<int> &ftVec, std::vector<int> &stdVec, int n)
{
	ftVec.insert(ftVec.end(), n);
	stdVec.insert(stdVec.end(), n);
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

int	insert_test_fill(ft::vector<int> &ftVec, std::vector<int> &stdVec, int n, int val)
{
	ftVec.insert(ftVec.begin(), n, val);
	stdVec.insert(stdVec.begin(), n, val);
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

int	insert_test_range(ft::vector<int> &ftVec, std::vector<int> &stdVec, ft::vector<int> &ftVec2, std::vector<int> &stdVec2)
{
	ftVec.insert(ftVec.begin(), ftVec2.begin(), ftVec2.end());
	stdVec.insert(stdVec.begin(), stdVec2.begin(), stdVec2.end());
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

void insert(void)
{
	ft::vector<int>		ft_vec1(1, 1);
	std::vector<int>	std_vec1(1, 1);

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "insert() : \t\t\t\t\t" << (insert_test_one(ft_vec1, std_vec1, 10) ? "❌" : "✅");
	std::cout << (insert_test_one(ft_vec2, std_vec2, 23) ? "❌" : "✅");
	std::cout << (insert_test_one(ft_vec3, std_vec3, 82) ? "❌" : "✅");
	std::cout << (insert_test_one(ft_vec4, std_vec4, 0) ? "❌" : "✅");
	std::cout << (insert_test_fill(ft_vec1, std_vec1, 10, 2) ? "❌" : "✅");
	std::cout << (insert_test_fill(ft_vec2, std_vec2, 2, 1) ? "❌" : "✅");
	std::cout << (insert_test_fill(ft_vec3, std_vec3, 45, 1) ? "❌" : "✅");
	std::cout << (insert_test_fill(ft_vec4, std_vec4, 53, 3) ? "❌" : "✅");
	std::cout << (insert_test_range(ft_vec1, std_vec1, ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (insert_test_range(ft_vec2, std_vec2, ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (insert_test_range(ft_vec3, std_vec3, ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (insert_test_range(ft_vec4, std_vec4, ft_vec3, std_vec3) ? "❌" : "✅") << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                    erase                                   */
/* -------------------------------------------------------------------------- */

int	erase_one(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	ftVec.erase(ftVec.begin());
	stdVec.erase(stdVec.begin());
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

int	erase_test_range(ft::vector<int> &ftVec, std::vector<int> &stdVec)
{
	ftVec.erase(ftVec.begin(), ftVec.end());
	stdVec.erase(stdVec.begin(), stdVec.end());
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

void erase(void)
{
	ft::vector<int>		ft_vec1(1, 1);
	std::vector<int>	std_vec1(1, 1);

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "erase() : \t\t\t\t\t" << (erase_one(ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (erase_one(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (erase_one(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (erase_one(ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (erase_test_range(ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (erase_test_range(ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (erase_test_range(ft_vec3, std_vec3) ? "❌" : "✅");
	std::cout << (erase_test_range(ft_vec4, std_vec4) ? "❌" : "✅") << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                    swap                                    */
/* -------------------------------------------------------------------------- */

int	swap_test(ft::vector<int> &ftVec, std::vector<int> &stdVec, ft::vector<int> &ftVec2, std::vector<int> &stdVec2)
{
	ftVec.swap(ftVec2);
	stdVec.swap(stdVec2);
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

void swap(void)
{
	ft::vector<int>		ft_vec1(1, 1);
	std::vector<int>	std_vec1(1, 1);

	ft::vector<int>		ft_vec2(4, 2);
	std::vector<int>	std_vec2(4, 2);
	
	ft::vector<int>		ft_vec3(10, 1);
	std::vector<int>	std_vec3(10, 1);

	ft::vector<int>		ft_vec4(40, 3);
	std::vector<int>	std_vec4(40, 3);

	std::cout << ORANGE	<< "swap() : \t\t\t\t\t" << (insert_test_range(ft_vec1, std_vec1, ft_vec2, std_vec2) ? "❌" : "✅");
	std::cout << (swap_test(ft_vec2, std_vec2, ft_vec1, std_vec1) ? "❌" : "✅");
	std::cout << (swap_test(ft_vec3, std_vec3, ft_vec4, std_vec4) ? "❌" : "✅");
	std::cout << (swap_test(ft_vec4, std_vec4, ft_vec3, std_vec3) ? "❌" : "✅") << std::endl;
}