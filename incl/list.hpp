/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/18 17:58:23 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//http://www.cplusplus.com/reference/list/list/

#ifndef FT_LIST
#define FT_LIST

#include "tools.hpp"
#include <iostream>

//IMPLEMENT ALLOCATORS
namespace ft
{	

	template <class T>
	class list
	{
		private :
			Node<T> *_h;
			Node<T> *_t;
			size_t _s;

		public :
			/* CONSTRUCTORS N DESTRUCTORS */
			list() : _h(0), _t(0),  _s(0) {};
			
			list(const list &f) { *this = f; };

			template<class InputIterator>
			list(InputIterator s, InputIterator e) { assign(s,e); }

			list (size_t n, const T& val) { assign(n, val); }

			~list()
			{ clear(); };

			/* OVERLOADS */

			list& operator=(const list &b)
			{
				assign(b.begin(), b.end());
				_s = b._s;
				return *this;
			};
			
			friend class iterator;
			/* MEMBER FUNS */
			//Use friends
			class iterator
			{
				friend class list<T>;
				public :
					typedef iterator self_type;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					// typedef std::forward_iterator_tag iterator_category;
					iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
					iterator() : _ptr(0) {};
					self_type operator++(int) //i++
					{
						iterator i = *this; 
						_ptr = _ptr->n;
						return i;
					}
					self_type operator++() //i++
					{ 
						_ptr = _ptr->n; 
						return *this;
					}
					self_type operator--(int) //i++
					{
						iterator i = *this; 
						_ptr = _ptr->p;
						return i;
					}
					self_type operator--() //i++
					{ 
						_ptr = _ptr->p; 
						return *this;
					}
					reference operator*() 
					{ return *(_ptr->d); }
					pointer operator->() 
					{ return _ptr->d; }
					bool operator==(const self_type& rhs)
					{ return _ptr == rhs._ptr; }
					bool operator!=(const self_type& rhs) 
					{ return _ptr != rhs._ptr; }
				private :
					Node<T> *_ptr;
			};
			//may use friends
			class reverse_iterator //: virtual public iterator
			{
				friend class list<T>;
				public :
					typedef reverse_iterator self_type;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					reverse_iterator() : _ptr(0) {};
					reverse_iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
					reverse_iterator operator++(int) //i++
					{
						reverse_iterator i = *this; 
						_ptr = _ptr->p;
						return i;
					}
					reverse_iterator operator++() //++i
					{ 
						_ptr = _ptr->p;
						return *this;
					}
					reference operator*() 
					{ 
						return *(_ptr->d); 
					}
					pointer operator->() 
					{ 
						return _ptr->d;
					}
					bool operator==(const reverse_iterator& rhs)
					{ 
						return _ptr == rhs._ptr; 
					}
					bool operator!=(const reverse_iterator& rhs) 
					{ 
						return _ptr != rhs._ptr; 
					}
				private :
					Node<T> *_ptr;
			};

				/* ITERATORS N SHIT 
			NEED TO ADD CONST ITERATORS N STUFF*/

				// friend iterator;		

			iterator begin() const { return iterator(_h); }
			iterator end() const { 
				// std::cout << "NO CRASH YET : "<< _t << std::endl;
				// iterator t =  
				return (iterator(_t->n)); 
			}
			reverse_iterator rbegin() const { return reverse_iterator(_t); }
			reverse_iterator rend() const {	return reverse_iterator(_h->p); }

			template<class IT>
			IT erase(IT pos)
			{
				Node<T> *curr = pos._ptr;
				if (curr->p)
				{
					curr->p->n = curr->n;
					if (curr->n)
						curr->n->p = curr->p;
				}
				else
				{
					// _h = curr->n;
					if ((_h = curr->n))
						curr->n->p = 0;
				}
				if (curr == _t)
					_t = curr->p;
				IT ret(curr->n);
				delete curr->d;
				delete curr;
				return ret;
			}

			template<class IT>
			IT erase(IT start,IT end)
			{
				IT ret = start;
				while (start != end)
					ret = erase(start++);
				return ret;
			}

			void push_back (const T& val)
			{
				//THIS NEEDS TO USE ALLOCATORS IT SEEMS
				if (_t == 0)
				{
					_t = new Node<T>;
					_t->d = new T(val);
					_t->n = _t->p = 0;
				}
				else
				{
					_t->n = new Node<T>;
					_t->n->d = new T(val);
					_t->n->n = 0;
					_t->n->p = _t;
					_t = _t->n;
				}
				if (_h == 0)
					_h = _t;
				++_s;
			}
			void push_front (const T& val)
			{
				//THIS NEEDS TO USE ALLOCATORS IT SEEMS
				if (_h == 0)
				{
					_h = new Node<T>;
					_h->d = new T(val);
					_h->n = _h->p = 0;
				}
				else
				{
					Node<T> *tmp = new Node<T>;
					tmp->d = new T(val);
					tmp->n = _h;
					tmp->p = 0;
					_h = tmp;
				}
				if (_t == 0)
					_t = _h;
				_s++;
			}

			T& front(void) const	{ return *(_h->d); }
			T& back(void) const		{ return *(_t->d); }

			void pop_front(void)
			{
				Node<T> *tmp = _h;
				if (_h)	
					_h = _h->n;
				delete tmp;
				_s--;
			}
			void pop_back(void)
			{
				Node<T>	 *tmp = _t;
				if (_t)
				{
					_t = _t->p;
					_t->n = 0;
				}
				delete tmp;
				_s--;
			}
			void clear(void)
			{
				Node<T> *curr = _h;
				Node<T> *next;
				while (curr)
				{
					next = curr->n;
					delete curr->d;
					delete curr;
					curr = next;
				}
				_h = _t = 0;
				_s = 0;
			}

			template<class IT>
			IT insert (IT p, const T& val)
			{
				ft::Node<T> *new_elem = new Node<T>;
				ft::Node<T> *pos_elem;
				new_elem->d = new T(val);

				if (p == begin() && p == 0)
				{
					push_back(val);
					std::cout << "edge case" << std::endl;
					// iterator ;
					return begin();
				}
				if (_h == 0)
				{
					_h = new_elem;
					_t = new_elem;
					new_elem->n = 0;
					new_elem->p = 0;
					iterator test(new_elem);
					return test;
						// std::cout << "also edge case" << std::endl;	
				}
				else
				{
					new_elem->n = p._ptr;
					new_elem->p = p._ptr->p;
					p._ptr->p = new_elem;
					//ofc it doesn't work
					std::cout << "HERE" << std::endl;
				}
				pos_elem = p._ptr;
				
				// if (p == 0)
				// {
				// 	std::cout << "heeeey" << std::endl;

				// }
				new_elem->d = new T(val);
				new_elem->n = pos_elem;
				new_elem->p = pos_elem->p;
				
				if (pos_elem->p)
					pos_elem->p->n = new_elem;
				else
					_h = new_elem;

				iterator ret(new_elem);
				return ret;
			}

			template<class IT>
			void insert (IT position, size_t n, const T& val)
			{
				for (size_t i = 0; i < n; i++)
				{
					position = insert(position, val);
				}
			}
			
			template <class InputIterator, class IT>
    		void insert (IT position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
    		{
    			while (first != last)
    			{
    				position = insert(position, *first);
    				++position;
    				++first;
    			}
    		}

			//Seems good but watch out for allocators
			void swap(list &base)
			{
				ft::Node<T> *oh = _h;
				ft::Node<T> *ot = _t;
				size_t os = _s;

				_h = base._h;
				_t = base._t;
				_s = base._s;

				base._h = oh;
				base._t = ot;
				base._s = os;

			}
			bool empty(void) const 	{ return (_s > 0 ? true : false); }
			size_t size(void) const { return _s; }
			size_t max_size(void) 	{ return 0;	 };
			
			template <class IT>
			void print(IT s, IT e)
			{
				while (s != e)
				{
					std::cout << *s << std::endl;
					++s;
				}
			};
			void assign(size_t n, const T &val)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
				_s = n;
			}
			template <class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type s, InputIterator e)
			{
				size_t i = 0;
				clear();
				while (s != e && ++i)
					push_back(*(s++));
				_s = i;
			}


	};
}
#endif