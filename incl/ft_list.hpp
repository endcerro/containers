/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/14 10:38:59 by edal--ce         ###   ########.fr       */
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
	class ft_list
	{
		private :
			Node<T> *_h;
			Node<T> *_t;
			size_t _s;

		public :
			/* CONSTRUCTORS N DESTRUCTORS */
			ft_list() : _h(0), _t(0),  _s(0) {};
			
			ft_list(const ft_list &f) { *this = f; };

			template<class InputIterator>
			ft_list(InputIterator s, InputIterator e) { assign(s,e); }

			ft_list (size_t n, const T& val) { assign(n, val); }

			~ft_list()
			{	clear();	};

			/* OVERLOADS */

			ft_list& operator=(const ft_list &b)
			{
				assign(b.begin(), b.end());
				_s = b._s;
				return *this;
			};
			
			/* MEMBER FUNS */
			class iterator
			{
				public:
					typedef iterator self_type;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					// typedef std::forward_iterator_tag iterator_category;
					typedef int difference_type;
					// iterator(pointer ptr) : _ptr(ptr) 
					// { }
					iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
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
					reference operator*() 
					{ 
						return *(_ptr->d); 
					}
					pointer operator->() 
					{ 
						return _ptr->d;
					}
					bool operator==(const self_type& rhs)
					{ 
						return _ptr == rhs._ptr; 
					}
					bool operator!=(const self_type& rhs) 
					{ 
						return _ptr != rhs._ptr; 
					}
				private :
					Node<T> *_ptr;
			};

			class reverse_iterator : virtual public iterator
			{
				public :
					typedef reverse_iterator self_type;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					// typedef std::forward_iterator_tag iterator_category;
					typedef int difference_type;

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

		

			iterator begin() const { return iterator(_h); }
			iterator end() const { return iterator(_t->n); }
			reverse_iterator rbegin() const { return reverse_iterator(_t); }
			reverse_iterator rend() const {	return reverse_iterator(_h->p); }

			void erase(iterator pos)
			{
				// delete ;

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
			bool empty(void) const 	{ return (_s > 0 ? true : false); }
			size_t size(void) const { return _s; }
			size_t max_size(void) 	{			};
			
			//TO DEL
			void print(void)
			{
				Node<T> *curr = _h;
				Node<T> *next = 0;
				while (curr != 0)
				{
					next = curr->n;
					std::cout << *(curr->d) << std::endl;
					curr = next;
				}
			};
			
			void assign(size_t n, const T &val)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
				_s = n;
			}

			//C++98 !COMPLIANT
			template <class InputIterator, class = typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type>
			void assign(InputIterator s, InputIterator e)
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