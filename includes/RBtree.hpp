/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:56:18 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/04 20:57:20 by hrecolet         ###   ########.fr       */
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

			void	_allocateRoot(Type &elem)
			{
				Node<Type>	*node;
				
				node = _allocator.allocate(1);
				_allocator.construct(&_root, Node(elem));
				return (node);
			}

			void	_allocateNode(Type &elem, int type, Node<Type> parent)
			{
				Node<Type>	*node;
				
				node = _allocator.allocate(1);
				_allocator.construct(&_root, Node(elem, type, parent));
				return (node);
			}

		public:
			RBtree(const Alloc& alloc = Alloc())
			{
				_root = NULL;
				_nllnode = Node();
				_allocator = alloc;
			}

			~RBtree(void)
			{
				clear(_root);
			}

			void clear(Node<Type>	*node)
			{
				if (node == NULL)
					return ;
				destroyNode(node->_right);
				destroyNode(node->_left);
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
			}

			void	addNode(Type &elem)
			{
				if (_root == NULL)
					_root = _allocateRoot(elem);
			}
	};
}