/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/09 16:03:24 by edal--ce         ###   ########.fr       */
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
			};
		private :
	
			Node	*_root;
			Node	*_end;

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

                return tmp;
            }
		
		public :

			explicit map (const Compare& comp = Compare(), const Alloc& alloc = Alloc())
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
			
			void insert (Key key, T val)
			{

				// if (searchNode(k) != NULL)
				// {

				// }
				if (_root == NULL)
				{
					_root = new Node();
					_root->left = NULL;
					_root->right = NULL;
					_root->parent = 0;
					_root->data = value_type(key, val);
					std::cout << "Insert at top\n";
					return ;
				}
				int done = 0;
				Node *curr = _root;
				while (done == 0)
				{
					if (curr->data.first > key)
					{
						// std::cout << "key " << key << " is smaller than " << curr->data.first << std::endl;
						if (curr->left == NULL)
						{
							// std::cout << "insert"<< std::endl;
							curr->left = createNode(value_type(key, val));
							curr->left->parent = curr;
							++_size;
							return ;
						}
						else
						{
							// std::cout << "continue"<< std::endl;
							curr = curr->left;
							continue;
						}
					}
					else if (curr->data.first < key)
					{
						// std::cout << "key " << key << " is greater than " << curr->data.first << std::endl;
						if (curr->right == NULL)
						{
							// std::cout << "insert"<< std::endl;
							curr->right = createNode(value_type(key, val));
							curr->right->parent = curr;
							++_size;
							return ;
						}
						else
						{
							// std::cout << "continue"<< std::endl;
							curr = curr->right;
							continue;
						}
					}
					else
					{
						// std::cout << "Key is already inserted\n";
						return;
					}
				}
				// getleftmostnode(_root)->
			}

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
			}
			void printtest(Node *curr)
			{
				if (curr == NULL)
					return;
				std::cout << "\n----\n";// << curr->data.first;
				// std::cout << "|" << curr->data.second << std::endl;
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
				else if (k == curr->data.first)
					return curr;
				else if (k > curr->data.first)
					return searchNode(curr->right, k);
				else if (k < curr->data.first)
					return searchNode(curr->left, k);		
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

			iterator begin()
			{
				Node *ret = _root;

				while (ret->left != 0)
				{
					ret = ret->left;
				}
				return iterator(ret);
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