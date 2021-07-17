/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/17 20:10:08 by edal--ce         ###   ########.fr       */
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

			typedef Key     key_type;
			typedef T       mapped_type;
			typedef ft::pair<key_type, mapped_type>   value_type;
			typedef Compare key_compare;
			class iterator;
			class const_iterator;
			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator()(const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					}
			};
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
	
			Node    *_root;
			Node    *_end;
			key_compare _comp;
			bool	DEBUG;
			// Alloc    _alloc;
			size_t  _size;
			Alloc   _alloc;

			Node* createNode(const value_type& pair)
			{
				Node* tmp = new Node();
				tmp->parent = 0;
				tmp->left = 0;
				tmp->right = 0;
				tmp->data = pair;
				tmp->height = 0;
				tmp->balancef = 0;
				return tmp;
			}
			Node *leftLeftCase(Node *node)
			{	return rotate_right(node);	}
			
			Node *leftRightCase(Node *node)
			{
				node->left = rotate_left(node->left);
				return leftLeftCase(node);
			}
			
			Node *rightRightCase(Node *node)
			{	return rotate_left(node);	}
			

			Node *rightLeftCase(Node *node)
			{
				node->right = rotate_right(node->right);
				return rightRightCase(node);
			}
			Node *balance(Node *node) 
			{
		    // Left heavy subtree.
		    	if (node->balancef == -2) 
		    	{	
		    		// std::cout << "ROTATION\n";
			      	if (node->left->balancef <= 0) 
			        	return leftLeftCase(node);
					else 
			        	return leftRightCase(node);
		    	} 
		    	else if (node->balancef == 2) 
		    	{
		    		// std::cout << "ROTATION\n";
			    	if (node->right->balancef >= 0) 
		        		return rightRightCase(node);
					else 
		        		return rightLeftCase(node);
		    	}
		    	return node;
		  }
			// Node *balance(Node *node)
			// {
			// 	// if (node == _end)
			// 	// 	std::cout << "BALANCING END" << std::endl;
			// 	// if (node->balancef == -2)
			// 	// {
			// 	// 	if (node->left->balancef <= 0)
			// 	// 		return leftLeftCase(node);
			// 	// 	else
			// 	// 		return leftRightCase(node);
			// 	// }
			// 	// else if (node->balancef == 2)
			// 	// {
			// 	// 	if (node->right->balancef >= 0)
			// 	// 		return rightRightCase(node);
			// 	// 	else
			// 	// 		return rightLeftCase(node); 
			// 	// }
			// 	return node;
			// }


			

			static Node *getleftmostnode(Node *curr, Node *end)
			{
				if (curr->left != NULL && curr->left != end)
					return getleftmostnode(curr->left, end);
				return curr;
			}
			static Node *getrightmostnode(Node *curr, Node *end)
			{
				if (curr->right != NULL && curr->right != end)
					return getrightmostnode(curr->right, end);
				return curr;
			}
			static Node *getNext(Node *n, Node *end)
			{
				if (n->right != NULL && n->right != end)//)
					return getleftmostnode(n->right, end);
			 
				while (n->parent != NULL && n->parent != end && n == n->parent->right)
					n = n->parent;
				return n->parent;               
			}
			// static Node *getPrev(Node *n, Node *end)
			// {
			// 	if (n->left != NULL && n->left != end)
			// 		return getrightmostnode(n->left);
			 
			// 	while (n->parent != NULL && n->parent != end && n == n->parent->left)
			// 		n = n->parent;
			// 	return n->parent;
			// }
			Node *rotate_left(Node *node)
			{
			    Node *newParent = node->right;
			    node->right = newParent->left;
			    newParent->left = node;
			    update(node);
			    update(newParent);
			    return newParent;
		  	}

			Node *rotate_right(Node *node) 
			{
				Node *newParent = node->left;
			    node->left = newParent->right;
			    newParent->right = node;
			    update(node);
			    update(newParent);
			    return newParent;
			}
			
			// Node *rotate_right(Node *curr)
			// {
			// 	Node *parent = curr->parent;
			// 	if (parent == _end)
			// 		parent = NULL;

			// 	Node *heavy = curr->left;

			// 	curr->left = heavy->right;

			// 	if (heavy->right != NULL && heavy->right != _end)
			// 	{
			// 		heavy->right->parent = curr;
			// 	}
			// 	heavy->right = curr;
			// 	curr->parent = heavy;
			// 	heavy->parent = parent;
			// 	if (parent != NULL)
			// 	{
			// 		if (parent->left == curr)
			// 			parent->left = heavy;
			// 		else
			// 			parent->right = heavy;
			// 	}
			// 	return heavy;
			// }

			// Node *rotate_left(Node *curr) 
			// {
			// 	Node *parent = curr->parent;
			// 	if (parent == _end)
			// 		parent = NULL;

			// 	Node *heavy = curr->right;

			// 	curr->right = heavy->left;

			// 	if (heavy->left != NULL && heavy->left != _end)
			// 	{
			// 		heavy->left->parent = curr;
			// 	}
			// 	heavy->left = curr;
			// 	curr->parent = heavy;
			// 	heavy->parent = parent;
			// 	if (parent != NULL)
			// 	{
			// 		if (parent->right == curr)
			// 			parent->right = heavy;
			// 		else
			// 			parent->left = heavy;
			// 	}
			// 	return heavy;
	  // 		}

		

			void update(Node *node) 
			{
    			int leftNodeHeight = (node->left == NULL || node->left == _end) ? -1 : node->left->height;
    			int rightNodeHeight = (node->right == NULL || node->right == _end) ? -1 : node->right->height;

    			if (leftNodeHeight > rightNodeHeight)
    				node->height = 1 + leftNodeHeight;	
    			else
    				node->height = 1 + rightNodeHeight;	
    			node->balancef = rightNodeHeight - leftNodeHeight;
  			}

		public :

			explicit map (const Compare& comp = Compare(), const Alloc& alloc = Alloc()) :_root(0), _comp(comp), _size(0), _alloc(alloc)
			{
				_end = new Node;//createNode(value_type());
				// _end->data
				DEBUG = 0;
				_end->parent = NULL;
				_end->left = NULL;
				_end->right = NULL;
			}
			
			template <class InputIterator>  
			map (InputIterator first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) :_root(0), _comp(comp) , _size(0), _alloc(alloc)
			{
				_end = new Node;
				_end->parent = NULL;
				_end->left = NULL;
				_end->right = NULL;
				while (first != last)
					insert(*(first++));
			}
			map(const map &m)
			{
				_end = new Node;
				_end->parent = NULL;
				_end->left = NULL;
				_end->right = NULL;
				for (const_iterator t = m.begin(); t != m.end(); t++)
					insert(*t);
			}
			~map()
			{	
				clear();
				delete _end;
			}

			void setdbg(bool set)
			{	DEBUG = set;	}

			map& operator=(const map &m) //TO CHANGE
			{
				clear();
				// for (const_iterator t = m.begin(); t != m.end(); t++)
				// 	insert(*t);
				return *m;
			}
			
			Node *searchNode(const Key &k)
			{	return searchNode(_root, k);	}
			
			void printend()
			{
				std::cout << "END NODE ";
				printnode(_end);
			}

			void printtest(Node *curr)	//TODEL
			{
				if (curr == _root)
					printend();
				if (curr == NULL || curr == _end)
					return;
				std::cout << "\n----\n";
				printnode(curr);
				printtest(curr->left);
				printtest(curr->right);

			}

			Node *searchNode(Node *curr, const Key &k)
			{
				if (curr == NULL || curr == _end)
					return NULL;
				else if (_comp(k, curr->data.first))
					return searchNode(curr->left, k);
				else if (k != curr->data.first)
					return searchNode(curr->right, k);       
				return curr;
			}

			void upd_end()
			{
				if (_root == 0)
					return ;
				if (DEBUG)
					std::cout << "Updating end..";
				_end->parent = _root;
				_end->parent->parent = _end;
				_end->left = getleftmostnode(_root, _end);
				_end->left->left = _end;
				_end->right = getrightmostnode(_root, _end);
				_end->right->right = _end;
				if (DEBUG)
				{
					std::cout << "|left_end=" << _end->left->data.first;
					std::cout << "|right_end=" << _end->right->data.first;
					std::cout << "|parent_end=" << _end->parent->data.first;
				}
			}

			Node *groot()				//TODEL
			{	return _root;	}
			Node *gend()				//TODEL
			{	return _end;	}

			void printnode(Node *node) //TODEL
			{
				std::cout << "Node :" << node << std::endl;
				std::cout << "data = " << node->data.first << std::endl;
				// std::cout << "|" << node->data.second << std::endl;
				std::cout << "parent :" << node->parent << std::endl;
				std::cout << "left :" << node->left << std::endl;
				std::cout << "right :" << node->right << std::endl;
				std::cout << "height :" << node->height << std::endl;
				std::cout << "bf :" << node->balancef << std::endl;

			}
			Node *ninsert(Node *node, const value_type &val)
			{
				if (node == NULL || node == _end)
				{
					node = createNode(val);
					return node;
				}
				else if (_comp(node->data.first, val.first) > 0)
				{
					node->right = ninsert(node->right, val);
					node->right->parent = node;     
				}
				else
				{
					node->left = ninsert(node->left, val);
					node->left->parent  = node;
				}
				update(node);
				return balance(node) ;
			}
			pair<iterator,bool> insert (const value_type& val)
			{
				pair<iterator, bool> ret;
				Node *tmp = searchNode(_root, val.first);

				if (tmp != NULL)
				{
					ret.second = false;
					ret.first = iterator(tmp, _end, _comp);
				}
				else
				{
					ret.second = true;
					_root = ninsert(_root, val);
					tmp = searchNode(_root, val.first);
					ret.first = iterator(tmp, _end, _comp);
					++_size;
				}
				upd_end();
				return ret;
			}

			iterator begin()
			{
				if (_root != NULL)
					return iterator(_end->left ,_end, _comp);
				else
					return end();
			}

			iterator end()
			{
				return iterator(_end, _end, _comp);
			}


			mapped_type& operator[](const key_type& k)
			{
				Node* tmp = searchNode(_root, k);

				if (tmp)
					return tmp->data.second;
				insert(ft::pair<key_type, mapped_type>(k, mapped_type()));
				tmp = searchNode(_root, k);
				return (tmp->data.second);
			}





			// size_t count(const Key &key)	//REWORKED
			// {
			// 	if (_size == 0)
			// 		return 0;
			// 	iterator t = begin();
			// 	while (t->first < key)
			// 		++t;
			// 	return (t->first == key);
			// }

			void clear(Node *n)				//REWORKED SHOULD BE PRIVATE
			{
				if (n->left != NULL && n->left != _end)
				{
					clear(n->left);
					n->left = 0;
				}
				if (n->right != NULL && n->right != _end)
				{
					clear(n->right);
					n->right = 0;
				}
				delete n;
			}

			void clear()					//REWORKED
			{
				if (_size == 0)
					return ;
				clear(_root);
				_size = 0;
				_root = 0;
				upd_end();
			}
	

			class iterator
			{
				friend class map<key_type, mapped_type, Compare,Alloc>;
				private :
					

					typedef Key								key_type;
					typedef Compare							key_compare;
					typedef T								mapped_type;
					
					typedef ft::pair<key_type, mapped_type>	value_type;
					typedef long int						difference_type;
					typedef size_t							size_type;
					typedef value_type&						reference;
					typedef Node*							nodePtr;
					// typedef std::bidirectional_iterator_tag                                     iterator_category;
					// typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
					// typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
					Node 		*_ptr;
					Node 		*_end;
					key_compare _comp;
				public :

					iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _ptr(ptr), _end(end), _comp(comp)
					{ }
					~iterator()
					{ }
					iterator& operator=(const iterator& assign)
					{
						if (this == &assign)
							return *this;
						_ptr = assign._ptr;
						_end = assign._end;
						_comp = assign._comp;
						return *this;
					}
					Node *getNode()					//TODEL
					{	return (_ptr);			}
					reference operator*() const
					{	return (_ptr->data);	}
					value_type* operator->() const
					{	return &(_ptr->data);	}
					bool operator==(const iterator &__x) const
					{	return _ptr == __x._ptr;	}

					bool operator!=(const iterator &__x) const
					{	return _ptr != __x._ptr;	}

					iterator &operator++()
					{
						_ptr = ft::map<Key, T, Compare, Alloc>::getNext(_ptr, _end);
						return *this;
					}
					iterator operator++(int)
					{
						iterator tmp = *this;
						_ptr = ft::map<Key, T, Compare, Alloc>::getNext(_ptr, _end);
						return tmp;
					}
			};

	};
}


#endif