/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_proto.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:40:34 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/15 20:00:46 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../includes/map.hpp"
#include "../../includes/RBtree.hpp"
#include <iostream>
#include <string>
#include <map>
#include "../../includes/vector.hpp"

typedef std::map<int, int>	std_typ;
typedef ft::map<int, int>	ft_typ;

void	empty(std_typ std, ft_typ ft);
void	size(std_typ std, ft_typ ft);
void	max_size(std_typ std, ft_typ ft);
void	op(std_typ std, ft_typ ft);
void	swap(std_typ std, ft_typ ft);
void	clear(std_typ std, ft_typ ft);
void	erase(std_typ std, ft_typ ft);
void	insert(std_typ std, ft_typ ft);
void	equal_range(std_typ std, ft_typ ft);
void	upper_bound(std_typ std, ft_typ ft);
void	lower_bound(std_typ std, ft_typ ft);
void	count(std_typ std, ft_typ ft);
void	find(std_typ std, ft_typ ft);