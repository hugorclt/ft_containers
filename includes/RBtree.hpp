/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:56:18 by hrecolet          #+#    #+#             */
/*   Updated: 2023/01/13 18:40:29 by hrecolet         ###   ########.fr       */
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
		typedef		Type	value_type;
		Type		_pair;
		int			_type;
		Node<Type>	*_parent;
		Node<Type>	*_left;
		Node<Type>	*_right;
		Node<Type>	*_nllnode;

		Node(Node<Type> *nllnode) : _type(LEAF), _parent(NULL), _left(NULL), _right(NULL), _nllnode(nllnode) {}
		
		Node(const Type &elem) : _pair(elem), _type(BLACK), _parent(NULL), _left(NULL), _right(NULL) {}

		Node(const Type &elem, int type, Node<Type> *parent, Node<Type> *nllnode) : _pair(elem), _type(type), _parent(parent), _left(NULL), _right(NULL), _nllnode(nllnode)  {}

		Node(Node<Type> *parent, Node<Type> *nllnode) : _type(LEAF), _parent(parent), _left(NULL), _right(NULL), _nllnode(nllnode)  {}\
	};
		

	template<class Type, class Alloc = std::allocator< Node<Type> > >
	class RBtree {
		public:
			typedef Node<Type>														*NodePtr;
			typedef typename ft::bidirectionnal_iterator<Node<Type> > 				iterator;
			typedef typename ft::bidirectionnal_iterator<const Node<Type> >			const_iterator;
			typedef typename ft::reverse_bidirectionnal_iterator<Node<Type> > 		reverse_iterator;
			typedef typename ft::reverse_bidirectionnal_iterator<const Node<Type> >	const_reverse_iterator;
		private:
			Node<Type>	*_root;
			Node<Type>	*_nllnode;
			Alloc		_allocator;

			NodePtr	_allocateNode(const Type &elem, int type, NodePtr parent)
			{
				NodePtr	node;
				
				node = _allocator.allocate(1);
				_allocator.construct(node, Node<Type>(elem, type, parent, _nllnode));
				node->_left = _nllnode;
				node->_right = _nllnode;
				return (node);
			}

			void	_printTree(NodePtr node, int space)
			{
				int	i;

				i = STEP_PRINT_TREE;
				if (!node || node == _nllnode)
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
				if (childToChange->_left != _nllnode)
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
				if (childToChange->_right != _nllnode)
					childToChange->_right->_parent = node;
				childToChange->_parent = node->_parent;
				if (childToChange->_parent == NULL)
					_root = childToChange;
				else if (node == node->_parent->_left)
					node->_parent->_left = childToChange;
				else
					node->_parent->_right = childToChange;
				childToChange->_right = node;
				node->_parent = childToChange;
			}

			void	_transplantNode(NodePtr from, NodePtr to)
			{
				if (!from->_parent)
					_root = to;
				else if (from->_parent->_left == from)
					from->_parent->_left = to;
				else
					from->_parent->_right = to;
				to->_parent = from->_parent;
			}

			/* -------------------------------------------------------------------------- */
			/*                               fix delete node                              */
			/* -------------------------------------------------------------------------- */
			void	_deleteNodeFix(NodePtr nodeToFix)
			{
				NodePtr sibling;
				
				while (nodeToFix != _root && nodeToFix->_type == BLACK)
				{
					if (nodeToFix == nodeToFix->_parent->_left)
					{
						sibling = nodeToFix->_parent->_right;
						if (sibling->_type == RED)
						{
							sibling->_type = BLACK;
							sibling->_parent = RED;
							_leftRotate(sibling->_parent);
							sibling = nodeToFix->_parent->_right;
						}
						if (sibling->_left->_type == BLACK && sibling->_right->_type == BLACK)
						{
							sibling->_type = RED;
							nodeToFix = nodeToFix->_parent;
						}
						else
						{
							if (sibling->_right->_type == BLACK)
							{
								sibling->_left->_type = BLACK;
								sibling->_type = RED;
								_rightRotate(sibling);
								sibling = nodeToFix->_parent->_right;
							}
							nodeToFix->_parent->_type = sibling->_type;
							nodeToFix->_parent->_type = BLACK;
							sibling->_right->_type = BLACK;
							_leftRotate(nodeToFix->_parent);
							nodeToFix = _root;
						}
					}
					else
					{
						sibling = nodeToFix->_parent->_left;
						if (sibling->_type == RED)
						{
							sibling->_type = BLACK;
							nodeToFix->_parent->_type = RED;
							_rightRotate(nodeToFix->_parent);
							sibling = nodeToFix->_parent->_left;
						}
						if (sibling->_right->_type == BLACK && sibling->_right->_type == BLACK)
						{
							sibling->_type = RED;
							nodeToFix = nodeToFix->_parent;
						}
						else
						{
							if (sibling->_left->_type == BLACK)
							{
								sibling->_right->_type = BLACK;
								sibling->_type = RED;
								_leftRotate(sibling);
								sibling = nodeToFix->_parent->_left;
							}
							sibling->_type = nodeToFix->_parent->_type;
							nodeToFix->_parent->_type = BLACK;
							sibling->_left->_type = BLACK;
							_rightRotate(nodeToFix->_parent);
							nodeToFix = _root;
						}
					}
				}
				nodeToFix->_type = BLACK;
			}

			/* -------------------------------------------------------------------------- */
			/*                                 fix insert                                 */
			/* -------------------------------------------------------------------------- */			
			void	_insertFix(NodePtr &newNode)
			{
				NodePtr uncle;
				
				while (newNode->_parent->_type == RED)
				{
					if (newNode->_parent == newNode->_parent->_parent->_right)
					{
						uncle = newNode->_parent->_parent->_left;
						if (uncle && uncle->_type == RED)
						{
							uncle->_type = BLACK;
							newNode->_parent->_type = BLACK;
							newNode->_parent->_parent->_type = RED;
							newNode = newNode->_parent->_parent;
						}
						else
						{
							if (newNode == newNode->_parent->_left)
							{
								newNode = newNode->_parent;
								_rightRotate(newNode);
							}
							newNode->_parent->_type = BLACK;
							newNode->_parent->_parent->_type = RED;
							_leftRotate(newNode->_parent->_parent);
						}
					}
					else
					{
						uncle = newNode->_parent->_parent->_right;
						if (uncle && uncle->_type == RED)
						{
							uncle->_type = BLACK;
							newNode->_parent->_type = BLACK;
							newNode->_parent->_parent->_type = RED;
							newNode = newNode->_parent->_parent;
						}
						else
						{
							if (newNode == newNode->_parent->_right)
							{
								newNode = newNode->_parent;
								_leftRotate(newNode);
							}
							newNode->_parent->_type = BLACK;
							newNode->_parent->_parent->_type = RED;
							_rightRotate(newNode->_parent->_parent);
						}
					}
					if (newNode == _root)
						break ;
				}
				_root->_type = BLACK;
			}

			int	_getSizeHelper(NodePtr node) const
			{
				if (node == _nllnode)
					return (0);
				else
					return (_getSizeHelper(node->_left) + 1 + _getSizeHelper(node->_right));
				
			}

		public:

			/* -------------------------------------------------------------------------- */
			/*                          constructor / destructor                          */
			/* -------------------------------------------------------------------------- */
			RBtree(const Alloc& alloc = Alloc())
			{
				_nllnode = _allocator.allocate(1);
				_allocator.construct(_nllnode, Node<Type>(_nllnode));
				_root = _nllnode;
				_allocator = alloc;
			}

			~RBtree(void)
			{
				clear(_root);
				_allocator.deallocate(_nllnode, 1);
			}

			void clear(NodePtr	node)
			{
				(void)node;
				if (node == NULL || node == _nllnode)
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
				while (node->_left != _nllnode) {
					node = node->_left;
				}
				return node;
			}

			NodePtr	search(const Type &value)
			{
				NodePtr node = _root;
				
				while (node != _nllnode)
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

			NodePtr	search(const Type &value) const
			{
				NodePtr node = _root;
				
				while (node != _nllnode)
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

			NodePtr	search(NodePtr nodeToSearch)
			{
				NodePtr node = _root;
				
				while (node != _nllnode)
				{
					if (node->_pair.first == nodeToSearch->_pair.first)
						return (node);
					if (node->_pair.first > nodeToSearch->_pair.first)
						node = node->_left;
					else
						node = node->_right;
				}
				return (NULL);
			}

			NodePtr	search(NodePtr nodeToSearch) const
			{
				NodePtr node = _root;
				
				while (node != _nllnode)
				{
					if (node->_pair.first == nodeToSearch->_pair.first)
						return (node);
					if (node->_pair.first > nodeToSearch->_pair.first)
						node = node->_left;
					else
						node = node->_right;
				}
				return (NULL);
			}

			/* -------------------------------------------------------------------------- */
			/*                                add / delete                                */
			/* -------------------------------------------------------------------------- */

			void	addNode(const Type &elem)
			{
				NodePtr	newNode = _allocateNode(elem, RED, NULL);
				NodePtr parentNode = NULL;
				NodePtr leafNode = _root;
				
				while (leafNode != _nllnode)
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

				_insertFix(newNode);
			}

			void	deleteNode(NodePtr nodeToDelete)
			{
				if (!nodeToDelete)
					return ;
				int	nodeDelType = nodeToDelete->_type;
				NodePtr toTransplant;
				
				if (nodeToDelete->_left == _nllnode)
				{
					toTransplant = nodeToDelete->_right;
					_transplantNode(nodeToDelete, nodeToDelete->_right);
				}
				else if (nodeToDelete->_right == _nllnode)
				{
					toTransplant = nodeToDelete->_left;
					_transplantNode(nodeToDelete, nodeToDelete->_left);
				}
				else
				{
					NodePtr min = minimum(nodeToDelete->_right);
					nodeDelType = min->_type;
					toTransplant = min->_right;
					if (toTransplant && min->_parent == nodeToDelete)
						toTransplant->_parent = min;
					else
					{
						_transplantNode(min, min->_right);
						min->_right = nodeToDelete->_right;
						min->_right->_parent = min;
					}
					_transplantNode(nodeToDelete, min);
					min->_left = nodeToDelete->_left;
					min->_left->_parent = min;
					min->_type = nodeDelType;
				}
				
				_allocator.destroy(nodeToDelete);
				_allocator.deallocate(nodeToDelete, 1);
				
				if (nodeDelType == BLACK)
					_deleteNodeFix(toTransplant);
			}

			NodePtr	leftMost(void) const
			{
				NodePtr node = _root;

				while(node->_left != _nllnode)
					node = node->_left;
				return (node);
			}

			NodePtr	rightMost(void) const
			{
				NodePtr node = _root;

				while(node->_right != _nllnode)
					node = node->_right;
				return (node);
			}

			NodePtr getRoot(void)
			{
				return (_root);
			}

			size_t getSize(void) const
			{
				return (_getSizeHelper(_root));
			}

			iterator begin(void)
			{
				return (iterator(leftMost()));
			}

			const_iterator begin(void) const
			{
				return (const_iterator(leftMost()));
			}

			iterator end(void)
			{
				return (iterator(rightMost()->_right));
			}

			const_iterator end(void) const
			{
				return (const_iterator(rightMost()->_right));
			}

			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(rightMost()));
			}

			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(rightMost()));
			}

			reverse_iterator rend(void)
			{
				return (reverse_iterator(leftMost()->_left));
			}

			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(leftMost()->_left));
			}

			void	swap(RBtree &rhs)
			{
				ft::swapT(this->_root, rhs._root);
				ft::swapT(this->_allocator, rhs._allocator);
				ft::swapT(this->_nllnode, rhs._nllnode);
			}
	};
}