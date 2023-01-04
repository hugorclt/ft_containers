/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:56:18 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/04 20:03:12 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utility.hpp"
#include <iostream>
#include <memory>

#define BLACK	1
#define RED		0
#define LEAF	2
namespace ft {
	template<class Type>
	struct Node {
		Type		_pair;
		int			_type;
		Node<Type>	*_parent;
		Node<Type>	*_left;
		Node<Type>	*_right;

		Node(void) : _type(LEAF), _parent(NULL), _left(NULL), _right(NULL) {}
		
		Node(Type &elem) : _pair(elem), _type(BLACK), _parent(NULL), _left(NULL), _right(NULL) {}

		Node(Type &elem, int type, Node<Type> parent) : _pair(elem), _type(type), _parent(parent), _left(NULL), _right(NULL)  {}
	};

	template<class Type, class Alloc = std::allocator< Node<Type> > >
	class RBtree {
		private:
			Node<Type>	*_root;
			Node<Type>	_nllnode;
			Alloc		_allocator;

		public:
			RBtree(Type &elem)
			{
				_root = _allocator.allocate(1);
				_allocator.construct(_root, Node<Type>(elem));
				_nllnode = Node<Type>();
			}

			~RBtree(void)
			{
				destroyNode(_root);
			}

			void destroyNode(Node<Type>	*node)
			{
				if (node == NULL)
					return ;
				destroyNode(node->_right);
				destroyNode(node->_left);
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
			}
	};
}