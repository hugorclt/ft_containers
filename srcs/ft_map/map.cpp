/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:27 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/06 05:09:34 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.hpp"
#include "../../includes/RBtree.hpp"
#include <iostream>
#include <string>
#include "../../includes/vector.hpp"

int	main()
{
	ft::RBtree<ft::pair<int, int> >	tree;
	ft::pair<int, int>	pair1 = ft::make_pair(10, 1);
	ft::pair<int, int>	pair2 = ft::make_pair(20, 2);
	ft::pair<int, int>	pair3 = ft::make_pair(30, 3);
	ft::pair<int, int>	pair4 = ft::make_pair(15, 3);
	ft::pair<int, int>	pair5 = ft::make_pair(5, 3);
	tree.addNode(pair1);
	tree.addNode(pair2);
	tree.addNode(pair3);
	tree.addNode(pair4);
	tree.addNode(pair5);
	tree.printTree();
}
