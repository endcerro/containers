/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/10 18:52:47 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP
#define FT_MAP

#include "tools.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public :

			
			typedef ft::pair<Key, T> 			value_type;
			// typedef T&			reference;
			// typedef const T&	const_reference;
			// typedef T*			pointer;
			// typedef const T*	const_pointer;
			struct Node
			{
				Node *parent;
				Node *left;
				Node *right;
				ft::pair<Key, T> data;

				int balancef;
				int height;
			};
		private :
	
			Node	*_root;
			Node	*_end;
			Compare _comp;
			// Alloc 	_alloc;
			size_t 	_size;
			Alloc 	_alloc;

			Node* createNode(const value_type& pair)
            {
                Node* tmp = new Node();

                // _allocPair.construct(&tmp->content, pair);
                tmp->parent = 0;
                tmp->left = 0;
                tmp->right = 0;
                tmp->data = pair;
                tmp->height = 0;
                tmp->balancef = 0;
                return tmp;
            }
            Node *leftLeftCase(Node *node)
			{
				// std::cout << "R1\n"; 
				return rotate_right(node);
			}

			Node *rightRightCase(Node *node)
			{
				// std::cout << "R2\n";
				return rotate_left(node);
			}
			Node *leftRightCase(Node *node)
			{
				// std::cout << "R3\n";
				node->left = rotate_left(node->left);
				return leftLeftCase(node);
			}
			Node *rightLeftCase(Node *node)
			{
				// std::cout << "R4\n";
				node->right = rotate_right(node->right);
				return rightRightCase(node);
			}

			Node *balance(Node *node)
			{
				if (node->balancef == -2)
				{
					if (node->left->balancef <= 0)
						return leftLeftCase(node);
					else
						return leftRightCase(node);
				}
				else if (node->balancef == 2)
				{
					if (node->right->balancef >= 0)
						return rightRightCase(node);
					else
						return rightLeftCase(node);	
				}
				return node;
			}
		
		public :

			explicit map (const Compare& comp = Compare(), const Alloc& alloc = Alloc()) :_root(0), _comp(comp), _alloc(alloc)
			{	
				_end = createNode(pair<Key, T>(Key(), T()));
				// _top = NULL;// Node;
				// _bottom = new Node;
				// _bottom->parent = _top;
				// _top->left = _bottom;
				// _top->right = _bottom;

			}
			~map()
			{			}
			
			Node *groot()
			{
				return _root;
			}

			void printnode(Node *node)
			{
				std::cout << "Node :" << node << std::endl;
				std::cout << "data = " << node->data.first;
				std::cout << "|" << node->data.second << std::endl;
				std::cout << "parent :" << node->parent << std::endl;
				std::cout << "left :" << node->left << std::endl;
				std::cout << "right :" << node->right << std::endl;
				std::cout << "height :" << node->height << std::endl;
				std::cout << "bf :" << node->balancef << std::endl;

			}
			void printtest(Node *curr)
			{
				if (curr == NULL)
					return;
				std::cout << "\n----\n";
				printnode(curr);
				printtest(curr->left);
				printtest(curr->right);

			}
			Node *searchNode(const Key &k)
			{
				return searchNode(_root, k);
			}
			Node *searchNode(Node *curr, const Key &k)
			{
				if (curr == NULL)
					return NULL;
				
				else if (k > curr->data.first)
					return searchNode(curr->right, k);
				else if (k < curr->data.first)
					return searchNode(curr->left, k);		
				else
					return curr;
			}
			static Node *getleftmostnode(Node *curr)
			{
				if (curr->left != NULL)
					return getleftmostnode(curr->left);
				return curr;
			}
			static Node *getrightmostnode(Node *curr)
			{
				if (curr->right != NULL)
					return getleftmostnode(curr->right);
				return curr;
			}
			static Node *getNext(Node *n)
			{
				if (n->right != NULL)
     				return getleftmostnode(n->right);
		 	 
				while (n->parent != NULL && n == n->parent->right)
    				n = n->parent;
			 	return n->parent; 				
			}
  
			class iterator
			{
				private :
					Node *_ptr;
					// Node *_prev;

				public :

					iterator(Node *ptr = 0) : _ptr(ptr)
					{ }
					~iterator()
					{ }
			       	iterator& operator=(const iterator& assign)
	        		{
	            	    if (this != &assign)
	            	        _ptr = assign._ptr;
	            	    return (*this);
	           		}
	           		Node *getNode()
	           		{
		           		return (_ptr);
		           	}
		           	value_type& operator*()
		           	{
		           		return (_ptr->data);
		           	}
		           	bool operator==(const iterator &__x) const
					{
						return _ptr == __x._ptr;
					}

					bool operator!=(const iterator &__x) const
					{
						return _ptr != __x._ptr;
					}
					iterator &operator++()
					{
						_ptr = ft::map<Key, T>::getNext(_ptr);
						return *this;
					}
					iterator operator++(int)
					{
						iterator tmp = *this;
						_ptr = ft::map<Key, T>::getNext(_ptr);
						return tmp;
					}
	
			};
			size_t getsubtreeheight(Node *curr, size_t n = 0)
			{
				size_t r = 0;
				size_t l = 0;

				if (curr != NULL && curr != _end)
				{
					if (curr->right != 0)
						r = getsubtreeheight(curr->right, n + 1);
					l = getsubtreeheight(curr->left, n + 1);
					return l < r ? r : l;
				}
				return n - 1;
			}
			void printsubheight()
			{
				for (iterator i = begin(); i != end(); i++)
				{
					std::cout << "leaf " << (*i).first << " weight : " << getsubtreeheight(i.getNode()) << std::endl;
				}
			}
			Node *rotate_right(Node *A)
			{
				std::cout << "RIGHT ROTATION" << std::endl;
				Node *P = A->parent;
				Node *B = A->left;


				A->left = B->right;
				if (B->right != NULL)
				{
					B->right->parent = A;
				}
				B->right = A;
				A->parent = B;
				B->parent = P;
				if (P != NULL)
				{
					if (P->left == A)
						P->left = B;
					else
						P->right = B;
				}
				update(A);
				update(B);
				return B;
			}
			Node *rotate_left(Node *A)
			{
				std::cout << "RIGHT ROTATION" << std::endl;
				Node *P = A->parent;
				Node *B = A->right;
				A->right = B->left;
				if (B->left !=  NULL)
				{
					B->left->parent = A;
				}
				B->left = A;
				A->parent = B;
				B->parent = P;
				if (P != NULL)
				{
					if (P->right == A)
						P->right = B;
					else
						P->left = B;
				}
				update(A);
				update(B);
				return B;
			}
			void update(Node *node)
			{
				int left_h = -1;
				int right_h = -1;
				
				if (node->left != NULL)
					left_h = node->left->height;
				if (node->right != NULL)
					right_h = node->right->height;
				
				if (left_h > right_h)
					node->height = 1 + left_h;
				else
					node->height = 1 + right_h;				

				node->balancef = right_h - left_h;
			}

			
			

			Node *ninsert(Node *node,Key key, T val)
			{
				if (node == NULL)
				{
					node = createNode(ft::pair<Key, T>(key, val));
					return node;
				}

				if (_comp(node->data.first, key) > 0)
				{
					node->right = ninsert(node->right, key, val);
					node->right->parent = node;		
				}
				else 
				{			
					node->left = ninsert(node->left, key, val);
					node->left->parent  = node;
				}
				update(node);
				return balance(node) ;
			}

			void insert(Key key, T val)
			{
				if (searchNode(key))
					return;
				_root = ninsert(_root, key, val);
				++_size;
			}	

			iterator begin()
			{
				return iterator(getleftmostnode(_root));
			}
			iterator end()
			{
				return iterator(NULL);
			}
			iterator find(const Key& key)
			{

				for (iterator t = begin(); t != end(); t++)
				{
					if ((*t).first == key)
					{
						return (t);
					}
				}
				return end();	
			}
			size_t count(const Key &key)
			{
				// if (_root == 0)
				// 	return 0;
				for (iterator t = begin(); t != end(); t++)
				{
					if ((*t).first == key)
						return 1;
				}
				return 0;
			}
			// void clear()
			// {
			Compare key_comp() const
			{
				return Compare();
			}
			// }
			bool empty() const
			{	return (_size > 0);	}
			
			size_t size() const
			{	return (_size);	}
			
			size_t max_size() const
			{	return (_alloc.max_size());	}
	};
}


#endif