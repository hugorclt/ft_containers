/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:56:18 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/06 05:40:08 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utility.hpp"
#include <iostream>
#include <memory>

#define BLACK	1
#define RED		0
#define LEAF	2
#define STEP_PRINT_TREE 5

namespace ft {
	template<class Type>
	struct Node {
		Type		_pair;
		int			_type;
		Node<Type>	*_parent;
		Node<Type>	*_left;
		Node<Type>	*_right;

		Node() : _type(LEAF), _parent(NULL), _left(NULL), _right(NULL) {}
		
		Node(Type &elem) : _pair(elem), _type(BLACK), _parent(NULL), _left(NULL), _right(NULL) {}

		Node(Type &elem, int type, Node<Type> *parent) : _pair(elem), _type(type), _parent(parent), _left(NULL), _right(NULL)  {}

		Node(Node<Type> *parent) : _type(LEAF), _parent(parent), _left(NULL), _right(NULL)  {}
	};

	template<class Type, class Alloc = std::allocator< Node<Type> > >
	class RBtree {
		private:
			typedef Node<Type>	*NodePtr;
			Node<Type>	*_root;
			Node<Type>	_nllnode;
			Alloc		_allocator;

			NodePtr	_allocateNode(Type &elem, int type, NodePtr parent)
			{
				NodePtr	node;
				
				node = _allocator.allocate(1);
				_allocator.construct(node, Node<Type>(elem, type, parent));
				return (node);
			}

			NodePtr	_allocateLeaf(NodePtr parent)
			{
				NodePtr	node;
				
				node = _allocator.allocate(1);
				_allocator.construct(node, Node<Type>(parent));
				return (node);
			}

			void	_printTree(NodePtr node, int space)
			{
				int	i;

				i = STEP_PRINT_TREE;
				if (!node || node->_type == LEAF)
					return ;
				space += STEP_PRINT_TREE;
				_printTree(node->_right, space);
				std::cout << std::endl;
				while (i < space)
				{
					std::cout << " ";
					i++;
				}
				if (node->_type != LEAF)
					std::cout << node->_pair.first << std::endl;
				_printTree(node->_left, space);
			}

			void	_leftRotate(NodePtr node)
			{
				NodePtr childToChange = node->_right;
				node->_right = childToChange->_left;
				if (childToChange->_left)
					childToChange->_left->_parent = node;
				childToChange->_parent = node->_parent;
				if (node->_parent == NULL)
					_root = childToChange;
				else if (node == node->_parent->_left)
					node->_parent->_left = childToChange;
				else
					node->_parent->_right = childToChange;
				childToChange->_left = node;
				node->_parent = childToChange;
			}

			void	_rightRotate(NodePtr node)
			{
				NodePtr childToChange = node->_left;
				node->_left = childToChange->_right;
				if (childToChange->_right)
					childToChange->_right->_parent = node;
				childToChange->_parent = node->_parent;
				if (childToChange->_parent)
					_root = childToChange;
				else if (node == node->_parent->_left)
					node->_parent->_left = childToChange;
				else
					node->_parent->_right = childToChange;
				childToChange->_left = node;
				node->_parent = childToChange;
			}


		public:

			/* -------------------------------------------------------------------------- */
			/*                          constructor / destructor                          */
			/* -------------------------------------------------------------------------- */
			RBtree(const Alloc& alloc = Alloc())
			{
				_root = NULL;
				_nllnode = Node<Type>();
				_allocator = alloc;
			}

			~RBtree(void)
			{
				clear(_root);
			}

			void clear(NodePtr	node)
			{
				if (node == NULL)
					return ;
				clear(node->_right);
				clear(node->_left);
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
			}

			/* -------------------------------------------------------------------------- */
			/*                                    utils                                   */
			/* -------------------------------------------------------------------------- */

			void	printTree(void)
			{
				_printTree(_root, 0);
			}

			NodePtr	minimum(NodePtr node)
			{
				std::cout << "value:" << node->_pair.first << std::endl; //to fix le node va trop loiin
				node = node->_right;
				while (node)
					node = node->_left;
				return (node);
			}

			NodePtr	search(Type &value)
			{
				NodePtr node = _root;
				
				while (node)
				{
					if (node->_pair.first == value.first)
						return (node);
					if (node->_pair.first > value.first)
						node = node->_left;
					else
						node = node->_right;
				}
				return (NULL);
			}

			/* -------------------------------------------------------------------------- */
			/*                                add / delete                                */
			/* -------------------------------------------------------------------------- */

			void	addNode(Type &elem)
			{
				NodePtr	newNode = _allocateNode(elem, RED, NULL);
				NodePtr parentNode = NULL;
				NodePtr leafNode = _root;
				
				while (leafNode != NULL)
				{
					parentNode = leafNode;
					if (newNode->_pair.first < leafNode->_pair.first)
						leafNode = leafNode->_left;
					else
						leafNode = leafNode->_right;
				}
				
				newNode->_parent = parentNode;
				if (parentNode == NULL)
					_root = newNode;
				else if (newNode->_pair.first < parentNode->_pair.first)
					parentNode->_left = newNode;
				else
					parentNode->_right = newNode;
				
				if (newNode->_parent == NULL)
				{
					newNode->_type = BLACK;
					return ;
				}

				if (newNode->_parent->_parent == NULL)
					return ;

				insertFix(newNode);
				std::cout << minimum(_root) << std::endl;
			}

			/* -------------------------------------------------------------------------- */
			/*                                 fix insert                                 */
			/* -------------------------------------------------------------------------- */
			
			void	insertFixHelper(NodePtr &newNode, NodePtr &uncle, void (RBtree::*rotateA)(NodePtr), void (RBtree::*rotateB)(NodePtr))
			{
				if (uncle && uncle->_type == RED)
				{
					newNode->_parent->_parent->_right->_type = BLACK;
					newNode->_parent->_parent->_left->_type = BLACK;
					newNode->_parent->_parent->_type = RED;
					newNode = newNode->_parent->_parent;
				}
				else
				{
					if (newNode == newNode->_parent->_left)
					{
						newNode = newNode->_parent;
						(this->*rotateA)(newNode);
					}
					newNode->_parent->_type = BLACK;
					newNode->_parent->_parent->_type = RED;
					(this->*rotateB)(newNode->_parent->_parent);
				}
			}

			void	insertFix(NodePtr &newNode)
			{
				while (newNode->_parent->_type == RED)
				{
					if (newNode->_parent == newNode->_parent->_parent->_right)
					{
						NodePtr uncle = newNode->_parent->_parent->_left;
						insertFixHelper(newNode, uncle, &RBtree::_rightRotate, &RBtree::_leftRotate);
					}
					else
					{
						NodePtr uncle = newNode->_parent->_parent->_right;
						insertFixHelper(newNode, uncle, &RBtree::_leftRotate, &RBtree::_rightRotate);
					}
					if (newNode == _root)
						break ;
				}
				_root->_type = BLACK;
			}

	};
}