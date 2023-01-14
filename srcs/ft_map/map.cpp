/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:27 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/14 10:45:09 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.hpp"
#include "../../includes/RBtree.hpp"
#include <iostream>
#include <string>
#include <map>
#include "../../includes/vector.hpp"

int	main()
{
	ft::map<int, int>	tree;
	ft::pair<int, int>	pair1 = ft::make_pair(10, 1);
	ft::pair<int, int>	pair2 = ft::make_pair(20, 2);
	ft::pair<int, int>	pair3 = ft::make_pair(30, 3);
	ft::pair<int, int>	pair4 = ft::make_pair(15, 3);
	ft::pair<int, int>	pair5 = ft::make_pair(5, 3);
	ft::pair<int, int>	pair6 = ft::make_pair(21, 3);
	ft::pair<int, int>	pair7 = ft::make_pair(11, 1);
	ft::pair<int, int>	pair8 = ft::make_pair(24, 2);
	ft::pair<int, int>	pair9 = ft::make_pair(32, 3);
	ft::pair<int, int>	pair10 = ft::make_pair(19, 3);
	ft::pair<int, int>	pair11 = ft::make_pair(90, 3);
	ft::pair<int, int>	pair12 = ft::make_pair(80, 3);
	tree.insert(pair1);
	tree.insert(pair2);
	tree.insert(pair3);
	tree.insert(pair4);
	tree.insert(pair5);
	tree.insert(pair6);
	tree.insert(pair7);
	tree.insert(pair8);
	tree.insert(pair9);
	tree.insert(pair10);
	tree.insert(pair11);
	tree.insert(pair12);
	// tree.printTree();
	
	
	for (ft::map<int, int>::iterator it = tree.end(); it != tree.begin(); it--)
	{
		std::cout << it->first << std::endl;
	}

	// std::cout << tree.getSize() << std::endl;
}
