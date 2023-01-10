/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:27 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/10 11:19:42 by hrecolet         ###   ########.fr       */
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
	ft::RBtree<ft::pair<int, int> >	tree;
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
	tree.addNode(pair1);
	tree.addNode(pair2);
	tree.addNode(pair3);
	tree.addNode(pair4);
	tree.addNode(pair5);
	tree.addNode(pair6);
	tree.addNode(pair7);
	tree.addNode(pair8);
	tree.addNode(pair9);
	tree.addNode(pair10);
	tree.addNode(pair11);
	tree.addNode(pair12);
	tree.deleteNode(tree.search(pair2));
	tree.printTree();
	
	// ft::map<int, int>::iterator it = tree.begin();
	// for (int i = 0; i < 10; i++)
	// {
	// 	it++;	
	// }

	std::cout << tree.getSize() << std::endl;
}
