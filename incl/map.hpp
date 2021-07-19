/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/19 02:59:34 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP
#define FT_MAP

#include "tools.hpp"
#include "vector.hpp"

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
		    	//Left heavy subtree.
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
				if (n->right == end)
					return end;
				if (n->right != NULL && n->right != end)//)
					return getleftmostnode(n->right, end);
			 
				while (n->parent != NULL && n->parent != end && n == n->parent->right)
					n = n->parent;
				return n->parent;               
			}

			static Node *getPrev(Node *n, Node *end)
			{
				if (n->left != NULL && n->left != end)
					return getrightmostnode(n->left, end);
			 
				while (n->parent != NULL && n->parent != end && n == n->parent->left)
					n = n->parent;
				return n->parent;
			}
			// Node *rotate_left(Node *node)
			// {
			//     Node *newParent = node->right;
			//     // if (newParent == _end)
			//     // 	newParent = NULL;
			//     node->right = newParent->left;
			//     newParent->left = node;
			//     update(node);
			//     update(newParent);
			//     return newParent;
		 //  	}

			// Node *rotate_right(Node *node) 
			// {
			// 	Node *newParent = node->left;
			//     // if (newParent == _end)
			//     // 	newParent = NULL;
			//     node->left = newParent->right;
			//     newParent->right = node;
			//     update(node);
			//     update(newParent);
			//     return newParent;
			// }
			
			Node *rotate_right(Node *curr)
			{
				Node *parent = curr->parent;
				if (parent == _end)
					parent = NULL;

				Node *heavy = curr->left;

				curr->left = heavy->right;

				if (heavy->right != NULL && heavy->right != _end)
				{
					heavy->right->parent = curr;
				}
				heavy->right = curr;
				curr->parent = heavy;
				heavy->parent = parent;
				if (parent != NULL)
				{
					if (parent->left == curr)
						parent->left = heavy;
					else
						parent->right = heavy;
				}
				return heavy;
			}

			Node *rotate_left(Node *curr) 
			{
				Node *parent = curr->parent;
				if (parent == _end)
					parent = NULL;

				Node *heavy = curr->right;

				curr->right = heavy->left;

				if (heavy->left != NULL && heavy->left != _end)
				{
					heavy->left->parent = curr;
				}
				heavy->left = curr;
				curr->parent = heavy;
				heavy->parent = parent;
				if (parent != NULL)
				{
					if (parent->right == curr)
						parent->right = heavy;
					else
						parent->left = heavy;
				}
				return heavy;
	  		}

		

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
				DEBUG = 0;
				_end = new Node;
				_end->parent = NULL;
				_end->left = NULL;
				_end->right = NULL;
				while (first != last)
					insert(*(first++));
			}
			map(const map &m)
			{
				DEBUG = 0;
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
			void swap(map &x)
			{
				Node *tmp_node = _end;
				_end = x._end;
				x._end = tmp_node;

				tmp_node = _root;
				_root = x._root;
				x._root = tmp_node;

				size_t tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;

				key_compare tmp_comp = _comp;
				_comp = x._comp;
				x._comp = tmp_comp;
			}

			void setdbg(bool set)
			{	DEBUG = set;	}

			map& operator=(const map &m) //TO CHANGE
			{
				clear();
				for (const_iterator t = m.begin(); t != m.end(); t++)
					insert(*t);
				return *this;
			}
			
			Node *searchNode(const Key &k) const
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

			Node *searchNode(Node *curr, const Key &k) const
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

			static void printnode(Node *node) //TODEL
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
				return balance(node);

				// return node;
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
			iterator insert (iterator position, const value_type& val)
			{
				Node *tmp = searchNode(val.first);
				iterator ret = position;

				if (tmp)
				{
					ret = iterator(tmp, _end, _comp);
					// return ();
				}
				else
				{
					ret = insert(val).first;
				}
				return ret;
			}
			template <class InputIterator>
 	 		void insert (InputIterator first, InputIterator last)
 	 		{
 	 			while (first != last)
 	 			{
 	 				insert(*(first++));
 	 			}
 	 		}

		  	Node *nremove(Node *node)
		  	{
		  		//Case where no childs, ez one
		  		if ((node->left == NULL || node->left == _end) && (node->right == NULL || node->right == _end))
		  		{
		  			// std::cout << "Case 1\n";
		  			if (node->parent != NULL)
		  			{
		  				if (node->parent->left == node)
		  					node->parent->left = NULL;
		  				else
		  					node->parent->right = NULL;
		  				delete node;
		  				return NULL;
		  			}
		  		}	//Two childs, hard one
		  		else if (node->left != NULL && node->left != _end && node->right != NULL && node->right != _end) 
		  		{
		  			// std::cout << "Case 2\n";
		  			Node *small_successor = getleftmostnode(node->right, _end);
		  			//Node *big_successor = getleftmostnode(node->right, _end);
		  			value_type tmp = small_successor->data; //Value copied, now to delete the succ
		  			nremove(tmp.first);
		  			node->data = tmp;	
		  			
		  		}	//Only one child
		  		else if (node->left == NULL || node->left == _end)
		  		{
		  			// std::cout << "Case 3\n";
		  			Node tmp;
		  			
		  			tmp.left = node->right->left;			//Get the nodes below future removed node
		  			tmp.right = node->right->right;		
		  			tmp.data =  node->right->data;
		  			//TMP IS NOW = node->right

		  			if (tmp.left != NULL)
		  			{
		  				// std::cout << "updated ch1\n";
		  				tmp.left->parent = node;
		  			}				
		  			if (tmp.right != NULL)
		  			{
		  				// std::cout << "updated ch2\n";
		  				tmp.right->parent = node;
		  			}
		  			
		  			// std::cout << "2deleting " << (node->right) << std::endl;
		  			
		  			delete node->right;
		  			
		  			node->right = tmp.right;
		  			node->left = tmp.left;
		  			node->data = tmp.data;

		  			// if (node->right != )

		  			// node->left = node->right->left;

		  		}
		  		else if (node->right == NULL || node->right == _end)
		  		{
		  			// std::cout << "Case 4\n";
		  			Node tmp;
		  			
		  			tmp.left = node->left->left;
		  			tmp.right = node->left->right;			//Get the nodes below future removed node
		  			tmp.data =  node->left->data;
		  			//TMP IS NOW = node->left

		  			if (tmp.right != NULL)					
		  				tmp.right->parent = node;
		  			if (tmp.left != NULL)
		  				tmp.left->parent = node;

		  			// std::cout << "3deleting " << (node->left) << std::endl;
		  			delete node->left;

		  			node->left = tmp.left;
		  			node->right = tmp.right;
		  			node->data = tmp.data;
		  		}
		  		return node;

		  	}
			bool nremove(const key_type &k) 
			{
 	  			// if (elem == null) return false;
				Node *target = searchNode(k);
				if (target != NULL) 
			    {
			    	if (target == _root)
			    		_root = nremove(_root);
		    		else
		    			nremove(target);
		    		// --_size;
		      		upd_end();
		      		return true;
		    	}
		    	// upd_end();
			    return false;
		  	}

		  	void remove(key_type k)	//THIS IS THE HANDLER
		  	{
		  			if (nremove(k))
		  				--_size;
		  	}
		  	void remove(iterator start, iterator end)
		  	{
  				ft::vector<key_type> fuckyou;
				int i = 0;
				// std::cout << "FUCKING HERE\n";
				iterator buff;
				while (start != end)
				{
					fuckyou.push_back((start++)->first);
					i++;
				}

				for (int j = 0; j < i; j++)
				{
					remove(fuckyou[j]);
				}
		  	}
		  	void erase(iterator pos)
		  	{
		  		remove(pos->first);
		  	}
		  	void erase(iterator first, iterator last)
		  	{
		  		remove(first, last);
		  		upd_end();
		  		return;
		  	}
		  	size_t erase (const key_type& k)
		  	{
		  		bool ret = (searchNode(k)) ? true : false;
		  		remove(k);
		  		return ret;
		  	}

		  	bool empty() const
		  	{
		  		return (_size == 0);
		  	}

			iterator begin()
			{
				if (_root != NULL)
					return iterator(_end->left ,_end, _comp);
				else
					return end();
			}

			const_iterator begin() const
			{
				if (_root != NULL)
					return const_iterator(_end->left ,_end, _comp);
				else
					return end();
			}

			iterator end()
			{
				return iterator(_end, _end, _comp);
			}

			const_iterator end() const
			{
				return const_iterator(_end, _end, _comp);
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





			size_t count(const Key &key) const	//REWORKED
			{
				if (_size == 0 || (searchNode(key) == 0))
					return 0;
				
				// const_iterator t = begin();
				// while (t->first < key)
				// 	++t;
				return 1;
				// return (t->first == key);
			}

			size_t size() const
			{
				return _size;
			}
			size_t max_size() const
			{
				return _alloc.max_size();
			}

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
				if (_size == 0 || _root == 0)
					return ;
				// std::cout << "Root is " << _root << std::endl;
				clear(_root);
				_size = 0;
				_root = 0;
				upd_end();
			}
			iterator lower_bound(const key_type &k)
			{
				if (_size == 0)
					return end();
				iterator it(begin());
				while (it !=  end() && _comp((*it).first, k) == true)
					++it;
				return it;
			}

			const_iterator lower_bound(const key_type &k) const
			{
				if (_size == 0)
					return end();
				const_iterator it(begin());
				while (it != end() && _comp((*it).first, k) == true)
					++it;
				return it;
			}

			iterator upper_bound(const key_type &k)
			{
				if (_size == 0)
					return iterator(_end, _end, _comp);
				iterator it(begin());
				while (it != end() && _comp(k, (*it).first) == false)
					++it;
				return it;
			}

			const_iterator upper_bound(const key_type &k) const
			{
				if (_size == 0)
					return end();
				const_iterator it(begin());
				while (it != end() && _comp(k, (*it).first) == false)
					++it;
				return it;
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				return ft::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k));
			}

			ft::pair<iterator, iterator> equal_range(const key_type &k)
			{
				return ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k));
			}
		
			key_compare key_comp() const
			{
				return _comp;
			}

			value_compare value_comp() const
			{
				return value_compare(_comp);
			}
		    iterator find (const key_type& k)
		    {
		    	Node *tmp = searchNode(k);
		    	if (tmp)
		    		return iterator(tmp, _end, _comp);
		    	else
		    		return end();
		    }
			const_iterator find (const key_type& k) const
			{
		    	Node *tmp = searchNode(k);
		    	if (tmp)
		    		return const_iterator(tmp, _end, _comp);
		    	else
		    		return end();
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
						if (_ptr == _end)
							return *this;

						// iterator tmp = *this;
						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}

					iterator operator++(int)
					{
						// std::cout << "Current ptr is " << _ptr << std::endl;
						// ft::map<Key, T, Compare, Alloc>::printnode(_ptr);
						// std::cout << "Right is " << &(_ptr->right) << std::endl;
						if (_ptr == _end)
							return *this;

						iterator tmp = *this;
						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}

					iterator &operator--()
					{	
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}
					iterator operator--(int)
					{
						iterator tmp = *this;
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}


			};
			class const_iterator
			{
				friend class map<key_type, mapped_type, Compare,Alloc>;
				private :
					

					typedef Key								key_type;
					typedef Compare							key_compare;
					typedef T								mapped_type;
					
					typedef const ft::pair<key_type, mapped_type>	value_type;
					typedef long int						difference_type;
					typedef size_t							size_type;
					typedef const value_type&						reference;
					typedef const Node*							nodePtr;
					// typedef std::bidirectional_iterator_tag                                     iterator_category;
					// typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
					// typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
					Node 		*_ptr;
					Node 		*_end;
					key_compare _comp;
				public :

					const_iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _ptr(ptr), _end(end), _comp(comp)
					{ }
					const_iterator(const iterator &i) : _ptr(i._ptr), _end(i._end), _comp(i._comp)
					{ }
					~const_iterator()
					{ }
					const_iterator& operator=(const const_iterator& assign)
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
					bool operator==(const const_iterator &__x) const
					{	return _ptr == __x._ptr;	}

					bool operator!=(const const_iterator &__x) const
					{	return _ptr != __x._ptr;	}

					const_iterator &operator++()
					{
						if (_ptr == _end)
							return *this;

						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}

					const_iterator operator++(int)
					{
						if (_ptr == _end)
							return *this;

						const_iterator tmp = *this;
						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}
					const_iterator &operator--()
					{	
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}
					const_iterator operator--(int)
					{
						const_iterator tmp = *this;
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}
			};

			class reverse_iterator
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
					// typedef std::bidirectional_reverse_iterator_tag                                     reverse_iterator_category;
					// typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
					// typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
					Node 		*_ptr;
					Node 		*_end;
					key_compare _comp;
				public :

					reverse_iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _ptr(ptr), _end(end), _comp(comp)
					{ }
					reverse_iterator(iterator &it) : _ptr(it._ptr), _end(it._end), _comp(it._comp)
					{ }
					~reverse_iterator()
					{ }
					reverse_iterator& operator=(const reverse_iterator& assign)
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
					bool operator==(const reverse_iterator &__x) const
					{	return _ptr == __x._ptr;	}

					bool operator!=(const reverse_iterator &__x) const
					{	return _ptr != __x._ptr;	}

					reverse_iterator &operator--()
					{
						if (_ptr == _end)
							return *this;

						// reverse_iterator tmp = *this;
						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}

					reverse_iterator operator--(int)
					{
						// std::cout << "Current ptr is " << _ptr << std::endl;
						// ft::map<Key, T, Compare, Alloc>::printnode(_ptr);
						// std::cout << "Right is " << &(_ptr->right) << std::endl;
						if (_ptr == _end)
							return *this;

						reverse_iterator tmp = *this;
						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}

					reverse_iterator &operator++()
					{	
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}
					reverse_iterator operator++(int)
					{
						reverse_iterator tmp = *this;
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}


			};
			class const_reverse_iterator
			{
				friend class map<key_type, mapped_type, Compare,Alloc>;
				private :
					

					typedef Key								key_type;
					typedef Compare							key_compare;
					typedef T								mapped_type;
					
					typedef const ft::pair<key_type, mapped_type>	value_type;
					typedef long int						difference_type;
					typedef size_t							size_type;
					typedef const value_type&						reference;
					typedef const Node*							nodePtr;
					// typedef std::bidirectional_iterator_tag                                     iterator_category;
					// typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
					// typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
					Node 		*_ptr;
					Node 		*_end;
					key_compare _comp;
				public :

					const_reverse_iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _ptr(ptr), _end(end), _comp(comp)
					{ }
					const_reverse_iterator(reverse_iterator &it) : _ptr(it._ptr), _end(it._end), _comp(it._comp)
					{ }
					const_reverse_iterator(const_iterator &i) : _ptr(i._ptr), _end(i._end), _comp(i._comp)
					{ }
					const_reverse_iterator(iterator &i) : _ptr(i._ptr), _end(i._end), _comp(i._comp)
					{ }
					
					~const_reverse_iterator()
					{ }
					const_reverse_iterator& operator=(const const_reverse_iterator& assign)
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
					bool operator==(const const_reverse_iterator &__x) const
					{	return _ptr == __x._ptr;	}

					bool operator!=(const const_reverse_iterator &__x) const
					{	return _ptr != __x._ptr;	}

					const_reverse_iterator &operator--()
					{
						if (_ptr == _end)
							return *this;

						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}

					const_reverse_iterator operator--(int)
					{
						if (_ptr == _end)
							return *this;

						const_reverse_iterator tmp = *this;
						if (_ptr->right != NULL)
						{
							if (_ptr->right->left == NULL || _ptr->right == _end)
								_ptr = _ptr->right;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(og->data.first, _ptr->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}
					const_reverse_iterator &operator++()
					{	
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return *this;
					}
					const_reverse_iterator operator++(int)
					{
						const_reverse_iterator tmp = *this;
						if (_ptr == _end)
						{
							_ptr = _end->right;
							// return *this;
						}
						else if (_ptr == _end->left)
						{
							_ptr = _end;
							// return *this;
						}
						else if (_ptr->left != NULL)
						{
							if (_ptr->left->right == NULL)
								_ptr = _ptr->left;
							else
								_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
						}
						else if (_ptr->parent != NULL)
						{
							Node *og = _ptr;
							_ptr = _ptr->parent;
							while (_comp(_ptr->data.first, og->data.first) == false)
								_ptr = _ptr->parent;
						}
						return tmp;
					}
			};












	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename map<Key, T, Compare, Alloc>::const_iterator lit(lhs.begin());
			typename map<Key, T, Compare, Alloc>::const_iterator rit(rhs.begin());
			while (lit != lhs.end())
			{
				if (*lit != *rit)
					return false;
				++lit;
				++rit;
			}
			return true;
		}
		return false;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		typename map<Key, T, Compare, Alloc>::const_iterator lit = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator rit = rhs.begin();

		while (lit != lhs.end())
		{
			if (rit == rhs.end() || *rit < *lit)
				return false;
			else if (*lit < *rit)
				return true;
			++lit;
			++rit;
		}
		return rit != rhs.end();
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	}
}


#endif