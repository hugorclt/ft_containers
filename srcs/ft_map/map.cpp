/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:14:27 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/16 14:57:15 by hrecolet         ###   ########.fr       */
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

// int	main()
// {
// 	std::map<int, int>	stdMap;
// 	ft::map<int, int>	ftMap;

// 	for (int i = 0; i < 20; i++)
// 	{
// 		stdMap.insert(std::make_pair(i, i));
// 		ftMap.insert(ft::make_pair(i, i));
// 	}
// 	std::std::cout << WHITE << "\t\tMAP:" << RESET << std::endl;
// 	std::std::cout << WHITE << "CAPACITY_TEST:" << RESET << std::endl;
// 	do_capacity_test(stdMap, ftMap);
// 	std::std::cout << WHITE << "ACCESS_TEST:" << RESET << std::endl;
// 	do_access_test(stdMap, ftMap);
// 	std::std::cout << WHITE << "MODIFIER_TEST:" << RESET << std::endl;
// 	do_modifier_test(stdMap, ftMap);
// 	std::std::cout << WHITE << "OPERATION_TEST:" << RESET << std::endl;
// 	operation(stdMap, ftMap);
// }
/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

//const_bidirectionnal_iterator<Node<ft::pair<const std::basic_string<char>, int> > >
//bidirectionnal_iterator<Node<ft::pair<const std::basic_string<char>, int> > >

#include <iomanip> 
using namespace ft;
template <class Key, class T>
void	print(map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  pair<char,int> highest = *mymap.rbegin();          // last element

  map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}
