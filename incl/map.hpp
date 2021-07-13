/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/13 16:22:31 by edal--ce         ###   ########.fr       */
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
			typedef ft::pair<key_type, T>   value_type;
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

			Node *rightRightCase(Node *node)
			{	return rotate_left(node);	}
			Node *leftRightCase(Node *node)
			{
				node->left = rotate_left(node->left);
				return leftLeftCase(node);
			}
			Node *rightLeftCase(Node *node)
			{
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

			void printnode(Node *node) //TODEL
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

			Node *searchNode(const Key &k)
			{	return searchNode(_root, k);	}

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
			static Node *getPrev(Node *n)
			{
				if (n->left != NULL)
					return getrightmostnode(n->left);
			 
				while (n->parent != NULL && n == n->parent->left)
					n = n->parent;
				return n->parent;
			}
	
			Node *rotate_right(Node *A)
			{
				Node *P = A->parent;
				Node *B = A->left;

				A->left = B->right;
				if (B->right != NULL)
					B->right->parent = A;
				B->right = A;
				A->parent = B;
				B->parent = P;
				if (P != NULL && P->left == A)
					P->left = B;
				else if (P != NULL)
					P->right = B;
				update(A);
				update(B);
				return B;
			}
			Node *rotate_left(Node *A)
			{
				Node *P = A->parent;
				Node *B = A->right;
				A->right = B->left;
				if (B->left !=  NULL)
					B->left->parent = A;
				B->left = A;
				A->parent = B;
				B->parent = P;
				if (P != NULL && P->right == A)
					P->right = B;
				else if (P != NULL)
					P->left = B;
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

			Node *ninsert(Node *node, const value_type &val)
			{
				if (node == NULL)
				{
					node = createNode(val);
					return node;
				}
				if (_comp(node->data.first, val.first) > 0)
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
			Node *remove(Node *node ,Key key)
			{
				if (_comp(node->data.first, key))
					node->right  = remove(node->right , key);
				else if (key != node->data.first)
					node->left = remove(node->left, key);
				else
				{
					if (node->left == NULL)
						return node->right;
					else if (node->right == NULL)
						return node->left; 
					else
					{
						if (node->left->height > node->right->height)
						{
							Node *tmp = getrightmostnode(node->left);
							T tmpval = tmp->data.second;
							Key tmpkey = tmp->data.first;
							node->data.first = tmpkey;
							node->data.second = tmpval;
							node->left = remove(node->left, tmpkey); 
						}
						else
						{
							Node *tmp = getleftmostnode(node->right);
							T tmpval = tmp->data.second;
							Key tmpkey = tmp->data.first;
							node->data.first = tmpkey;
							node->data.second = tmpval;
							node->right = remove(node->right, tmpkey);
						}
					}
				}
				update(node);
				return balance(node);
			}

		public :

			explicit map (const Compare& comp = Compare(), const Alloc& alloc = Alloc()) :_root(0), _comp(comp), _size(0), _alloc(alloc)
			{	}
			
			template <class InputIterator>  
			map (InputIterator first, InputIterator last,   const Compare& comp = Compare(), const Alloc& alloc = Alloc()) :_root(0), _comp(comp) , _size(0), _alloc(alloc)
			{
				while (first != last)
					insert(*(first++));
			}
			~map()
			{	clear();	}
			
			bool operator==(const map &m)
			{
				iterator base = begin();
				iterator ext = m.begin();
				while (base != end() && ext != end())
					if (*(base++) != *(ext++))
						return false;
				if (base == end() && ext == m.end())
					return true;
				return false;
			}

			bool operator!=(const map &m)
			{	return !(*this == m);	}


			void printtest(Node *curr)	//TODEL
			{
				if (curr == NULL)
					return;
				std::cout << "\n----\n";
				printnode(curr);
				printtest(curr->left);
				printtest(curr->right);

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

			pair<iterator, bool> insert (const value_type &v)
			{
				pair<iterator, bool> ret;
				Node *tmp = searchNode(v.first);
				if (tmp != NULL)
				{
					ret.first = iterator(tmp);
					ret.second = false;
				}
				else
				{
					_root = ninsert(_root, v);
					ret.first = iterator(searchNode(v.first));
					ret.second = true;
					++_size;    
				}
				return ret;
			}

			iterator insert (iterator position, const value_type& val)
			{
				static_cast<void> (position);

				Node *tmp = searchNode(val.first);
				iterator it(tmp);
				if (tmp == 0)
					it = insert(val).first;
				return it;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*(first++));
			}
			void remove(Key key)
			{
				if (searchNode(key))
				{
					remove(_root, key);
					--_size; 
				}
			}

			
			void erase (iterator position)
			{
				remove(position->first);
			}
			size_t erase (const key_type& k)
			{
				size_t s = size();
				remove(k);
				return (size() - s); 
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first++);
				}
			}

			iterator begin()
			{
				return iterator  (getleftmostnode(_root));
			}
			const_iterator begin() const
			{
				return const_iterator  (getleftmostnode(_root));
			}
			iterator end()
			{
				return iterator(NULL);
			}
			const_iterator end() const
			{
				return const_iterator(NULL);
			}
			// reverse_iterator rbegin()
			// {
			// 	return reverse_iterator  (getrightmostnode(_root));
			// }
			// const_reverse_iterator rbegin() const
			// {
			// 	return const_reverse_iterator  (getrightmostnode(_root));
			// }
			// reverse_iterator rend()
			// {
			// 	return reverse_iterator(NULL);
			// }
			// const_reverse_iterator rend() const
			// {
			// 	return const_reverse_iterator(NULL);
			// }

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
			const_iterator find(const Key& key) const
			{

				for (const_iterator t = begin(); t != end(); t++)
				{
					if ((*t).first == key)
						return (t);
				}
				return end();
			}
			mapped_type& operator[](const key_type& k)
			{
				Node* tmp = searchNode(_root, k);

				if (tmp)
					return tmp->data.second;
				ninsert(_root, ft::pair<key_type, mapped_type>(k, mapped_type()));
				return (searchNode(_root, k)->data.second);
			}

			iterator lower_bound(const key_type &key)
			{
				iterator it = begin();

				for (; it != end(); ++it)
					if (!_comp(it->first, key))
						break;
				
				return it;  
			}

			const_iterator lower_bound(const key_type &key) const
			{
				const_iterator it = begin();

				for (; it != end(); ++it)
					if (!_comp(it->first, key))
						break;
				return it;  
			}

			iterator upper_bound(const key_type &key)
			{
				iterator it = begin();

				for (; it != end(); ++it)
					if (_comp(key, it->first))
						break;
				
				return it;  
			}

			const_iterator upper_bound(const key_type &key) const
			{
				const_iterator it = begin();

				for (; it != end(); ++it)
					if (_comp(key, it->first))
						break;
				
				return it;  
			}
			// pair<iterator,iterator> equal_range(const key_type& k)
   //          {
   //              iterator it = upper_bound(k);

   //              if (it != begin())
   //              {
   //                  --it;

   //                  if (_comp(it->first, k) || _comp(k, it->first))
   //                      ++it;
   //              }

   //              iterator next(it);
   //              if (it != end())
   //                  ++next;
                
   //              return pair<iterator, iterator>(it, next);
   //          }
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const
            {
                const_iterator it = upper_bound(k);

                if (it != begin())
                {
                    --it;

                    if (_comp(it->first, k) || _comp(k, it->first))
                        ++it;
                }

                const_iterator next(it);
                if (it != end())
                    ++next;
                
                return pair<const_iterator, const_iterator>(it, next);
            }
			pair<iterator,iterator> equal_range(const key_type& k)
            {
                iterator it = upper_bound(k);

                if (it != begin())
                {
                    --it;

                    if (_comp(it->first, k) || _comp(k, it->first))
                        ++it;
                }

                iterator next(it);
                if (it != end())
                    ++next;
                
                return pair<iterator, iterator>(it, next);
            }

			
			size_t count(const Key &key)
			{
				for (iterator t = begin(); t != end(); t++)
					if ((*t).first == key)
						return 1;
				return 0;
			}
			void clear()
			{
				iterator start = begin();
				while (start != end())
					erase(start++);
			}
			key_compare key_comp() const
			{
				return _comp;
			}

			value_compare value_comp() const
			{
				return value_compare(_comp);
			}
			
			bool empty() const
			{   return (_size == 0);    }
			
			size_t size() const
			{   return (_size); }
			
			size_t max_size() const
			{   return (_alloc.max_size()); }

			class iterator
			{
				friend class map<key_type, mapped_type, Compare,Alloc>;
				private :
					Node *_ptr;
					// Node *_prev;
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
					reference operator*() const
					{ 
						return (_ptr->data);
					}
					value_type* operator->() const
					{ 
						return &(_ptr->data);
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
					iterator &operator--()
					{
						_ptr = ft::map<Key, T>::getPrev(_ptr);
						return *this;
					}
					iterator operator--(int)
					{
						iterator tmp = *this;
						_ptr = ft::map<Key, T>::getPrev(_ptr);
						return tmp;
					}
					iterator operator++(int)
					{
						iterator tmp = *this;
						_ptr = ft::map<Key, T>::getNext(_ptr);
						return tmp;
					}
	
			};

			class const_iterator
			{
				// friend iterator;
				friend class map<key_type, mapped_type, Compare,Alloc>;
				private :
					Node *_ptr;
					// Node *_prev;
					typedef Key                                                 key_type;
					typedef Compare                                         key_compare;
					typedef T                                               mapped_type;
					
					typedef ft::pair<key_type, mapped_type>           value_type;
					typedef long int                                        difference_type;
					typedef size_t                                          size_type;
					typedef value_type&                                     reference;
					// typedef std::bidirectional_const_iterator_tag                                     const_iterator_category;
					// typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
					// typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
					typedef Node*                                                               nodePtr;
				public :

					const_iterator(Node *ptr = 0) : _ptr(ptr)
					{ }
					const_iterator(iterator it) : _ptr(it._ptr)
					{ }
					~const_iterator()
					{ }
					const_iterator& operator=(const const_iterator& assign)
					{
						if (this != &assign)
							_ptr = assign._ptr;
						return (*this);
					}
					Node *getNode()
					{
						return (_ptr);
					}
					reference operator*() const
					{ 
						return (_ptr->data);
					}
					const value_type* operator->() const
					{ 
						return &(_ptr->data);
					}
					bool operator==(const const_iterator &__x) const
					{
						return _ptr == __x._ptr;
					}

					bool operator!=(const const_iterator &__x) const
					{
						return _ptr != __x._ptr;
					}
					
					const_iterator &operator++()
					{
						_ptr = ft::map<Key, T>::getNext(_ptr);
						return *this;
					}
					const_iterator operator++(int)
					{
						const_iterator tmp = *this;
						_ptr = ft::map<Key, T>::getNext(_ptr);
						return tmp;
					}
					const_iterator &operator--()
					{
						_ptr = ft::map<Key, T>::getPrev(_ptr);
						return *this;
					}
					const_iterator operator--(int)
					{
						const_iterator tmp = *this;
						_ptr = ft::map<Key, T>::getPrev(_ptr);
						return tmp;
					}
	
			};
	};
}


#endif