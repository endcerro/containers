/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal <edal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/02 16:14:33 by edal             ###   ########.fr       */
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
			Node<T> *_center;
			size_t _size;
			int _capacity;

		public :
			/* CONSTRUCTORS N DESTRUCTORS */
			//THIS IS ONLY FOR NOW, I 
			list() : _size(0), _capacity(-1) 
			{
				_center = new Node<T>;
				_center->data = new int;
				*(_center->data) = 0;
				_center->next = 0;
				_center->previous = 0;
				_size = 0;
			};
			
			// list(const list &f) { *this = f; };

			// template<class InputIterator>
			// list(InputIterator s, InputIterator e) { assign(s,e); }

			// list (size_t n, const T& val) 
			// {
			// 	// for (int i = 0; i < n; i++)
			// 	// {
			// 	// 	push_back
			// 	// }
			// 	assign(n, val); 
			// }

			~list()
			{ 
				clear();
				delete _center->data;
				delete _center;
			};

			/* OVERLOADS */

	// 		list& operator=(const list &b)
	// 		{
	// 			assign(b.begin(), b.end());
	// 			_s = b._s;
	// 			return *this;
	// 		};
			
	// 		friend class iterator;
	// 		/* MEMBER FUNS */
	// 		//Use friends
	// 		class iterator
	// 		{
	// 			friend class list<T>;
	// 			public :
	// 				typedef iterator self_type;
	// 				typedef T value_type;
	// 				typedef T& reference;
	// 				typedef T* pointer;
	// 				// typedef std::forward_iterator_tag iterator_category;
	// 				iterator(Node<T> *ptr) : _ptr(ptr) 
	// 				{ }
	// 				iterator() : _ptr(0) {};
	// 				self_type operator++(int) //i++
	// 				{
	// 					iterator i = *this; 
	// 					if (_ptr->n)
	// 						_ptr = _ptr->n;				
	// 					// _ptr = _ptr->n;
	// 					return i;
	// 				}
	// 				self_type operator++() //i++
	// 				{
	// 				/*	if (this == 0)
	// 					{
	// 						std::cerr << "NULL CASE OPERATOR++ LIST" << std::endl;
	// 						return NULL;
	// 					}*/
	// 					if (_ptr->n)
	// 						_ptr = _ptr->n; 
	// 					return *this;
	// 				}
	// 				self_type operator--(int) //i++
	// 				{
	// 					if (this == 0)
	// 						return NULL;
	// 					iterator i = *this;
	// 					_ptr = _ptr->p;
	// 					return i;
	// 				}
	// 				self_type operator--() //i++
	// 				{ 
	// 					_ptr = _ptr->p; 
	// 					return *this;
	// 				}
	// 				reference operator*() 
	// 				{ return *(_ptr->d); }
	// 				pointer operator->() 
	// 				{ return _ptr->d; }
	// 				bool operator==(const self_type& rhs)
	// 				{ return _ptr == rhs._ptr; }
	// 				bool operator!=(const self_type& rhs) 
	// 				{ return _ptr != rhs._ptr; }
	// 			private :
	// 				Node<T> *_ptr;
	// 		};
	// 		//may use friends
	// 		class reverse_iterator //: virtual public iterator
	// 		{
	// 			friend class list<T>;
	// 			public :
	// 				typedef reverse_iterator self_type;
	// 				typedef T value_type;
	// 				typedef T& reference;
	// 				typedef T* pointer;
	// 				reverse_iterator() : _ptr(0) {};
	// 				reverse_iterator(Node<T> *ptr) : _ptr(ptr) 
	// 				{ }
	// 				reverse_iterator operator++(int) //i++
	// 				{
	// 					reverse_iterator i = *this; 
	// 					_ptr = _ptr->p;
	// 					return i;
	// 				}
	// 				reverse_iterator operator++() //++i
	// 				{ 
	// 					_ptr = _ptr->p;
	// 					return *this;
	// 				}
	// 				reference operator*() 
	// 				{ 
	// 					return *(_ptr->d); 
	// 				}
	// 				pointer operator->() 
	// 				{ 
	// 					return _ptr->d;
	// 				}
	// 				bool operator==(const reverse_iterator& rhs)
	// 				{ 
	// 					return _ptr == rhs._ptr; 
	// 				}
	// 				bool operator!=(const reverse_iterator& rhs) 
	// 				{ 
	// 					return _ptr != rhs._ptr; 
	// 				}
	// 			private :
	// 				Node<T> *_ptr;
	// 		};

	// 			/* ITERATORS N SHIT 
	// 		NEED TO ADD CONST ITERATORS N STUFF*/

	// 			// friend iterator;		

	// 		iterator begin() const { return iterator(_h); }
	// 		iterator end() const { 
	// 			// std::cout << "NO CRASH YET : "<< _t << std::endl;
	// 			// iterator t = 
				
	// 			// if (_/*:*/eturn (iterator(_t->n)); 
	// 			return (iterator(_t));}
	// 		reverse_iterator rbegin() const { return reverse_iterator(_t); }
	// 		reverse_iterator rend() const {	return reverse_iterator(_h->p); }

	// 		template<class IT>
	// 		IT erase(IT pos)
	// 		{
	// 			Node<T> *curr = pos._ptr;
	// 			if (curr->p)
	// 			{
	// 				curr->p->n = curr->n;
	// 				if (curr->n)
	// 					curr->n->p = curr->p;
	// 			}
	// 			else
	// 			{
	// 				// _h = curr->n;
	// 				if ((_h = curr->n))
	// 					curr->n->p = 0;
	// 			}
	// 			if (curr == _t)
	// 				_t = curr->p;
	// 			IT ret(curr->n);
	// 			delete curr->d;
	// 			delete curr;
	// 			return ret;
	// 		}

	// 		template<class IT>
	// 		IT erase(IT start,IT end)
	// 		{
	// 			IT ret = start;
	// 			while (start != end)
	// 				ret = erase(start++);
	// 			return ret;
	// 		}

			void push_back (const T& val)
			{
				//THIS NEEDS TO USE ALLOCATORS IT SEEMS
				//Case where this is the first one
				Node<T> *elem = new Node<T>;
				elem->data = new T(val);

				Node<T> *old;
				std::cout << "next:" << _center->next << " prev:" << _center->previous << std::endl;
				if (_center->next == 0)
				{
					std::cout << "Z1" << std::endl;
					_center->next = elem;
					_center->previous = elem;
					elem->next = _center;
					elem->previous = _center;
				}
				else
				{
					std::cout << "Z2" << std::endl;
					old = _center->previous;
                                        _center->previous = elem;
					elem->previous = old;
					elem->next = _center;
					old->next = elem;
				}
				++_size;
			}

			void push_front (const T& val)
			{
				if (_center->next == 0)
					return (push_back(val));
				Node<T> *elem = new Node<T>;
				elem->data = new T(val);
				Node<T> *old = _center->next;
				elem->next = old;
				elem->previous = _center;
				old->previous = elem;
				_center->next = elem;
				++_size;
			}

	// 		T& front(void) const	{ return *(_h->d); }
	// 		T& back(void) const		{ return *(_t->d); }

			void pop_front(void)
			{
				Node<T> *old = _center->next;

				if (old->next == _center)
				{
					// delete old->data;
					// delete old;
					_center->next = 0;
					_center->previous = 0;
				}
				else
				{

					_center->next = old->next;
					_center->next->previous = 0;
				}
				delete old->data;
				delete old;
				--_size;
			}
	// 		void pop_back(void)
	// 		{
	// 			Node<T>	 *tmp = _t;
	// 			if (_t)
	// 			{
	// 				_t = _t->p;
	// 				_t->n = 0;
	// 			}
	// 			delete tmp;
	// 			_s--;
	// 		}
			void clear(void)
			{
				Node<T> *current = _center;
				Node<T> *next;

				// In order to check if the list has one elem, check head address
				// Don't forget to delete the last element as it should be instancied at all times
				if (current->next == 0)
					return ;
				current = current->next;
				while (current != _center)
				{
					next = current->next;
					delete current->data;
					delete current;
					current	= next;
				}
				_center->next = 0;
				_center->previous = 0;
			}
			void print()
			{
				if (_center->next == 0)
				{

					std::/**/cout << "No elems in here" << std::endl;
					return;
				}
				Node<T> *current = _center->next;
				// current = current->next;
				while (current != _center)
				{
					std::cout << *current->data << '|';
					current = current->next;
				}
				std::cout << std::endl;
			}

	// 		template<class IT>
	// 		IT insert (IT p, const T& val)
	// 		{

	// 			if (p == begin())
	// 			{
	// 				push_front(val);
	// 				return begin();
	// 			}
	// 			else if (p == end())
	// 			{
	// 				push_back(val);
	// 				return end();
	// 			}
	// 			else
	// 			{
	// 				ft::Node<T> *new_elem = new Node<T>;
	// 				new_elem->d = new T(val);
	// 				if (p._ptr->p != 0)
	// 					p._ptr->p->n = new_elem;;
	// 				new_elem->p = p._ptr->p;
	// 				new_elem->n = p._ptr;
	// 				p._ptr->p = new_elem;

	// 				return iterator(new_elem);	
	// 			}
	// 		}

	// 		template<class IT>
	// 		void insert (IT position, size_t n, const T& val)
	// 		{
	// 			for (size_t i = 0; i < n; i++)
	// 			{
	// 				position = insert(position, val);
	// 			}
	// 		}
			
	// 		template <class InputIterator, class IT>
 //    		void insert (IT position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
 //    		{
 //    			while (first != last)
 //    			{
 //    				position = insert(position, *first);
 //    				++position;
 //    				++first;
 //    			}
 //    		}

	// 		//Seems good but watch out for allocators
	// 		void swap(list &base)
	// 		{
	// 			ft::Node<T> *oh = _h;
	// 			ft::Node<T> *ot = _t;
	// 			size_t os = _s;

	// 			_h = base._h;
	// 			_t = base._t;
	// 			_s = base._s;

	// 			base._h = oh;
	// 			base._t = ot;
	// 			base._s = os;

	// 		}
	// 		bool empty(void) const 	{ return (_s > 0 ? true : false); }
	// 		size_t size(void) const { return _s; }
	// 		size_t max_size(void) 	{ return 0;	 };
			
	// 		template <class IT>
	// 		void print(IT s, IT e)
	// 		{
	// 			while (s != e)
	// 			{
	// 				std::cout << *s << std::endl;
	// 				++s;
	// 			}
	// 		};
	// 		void assign(size_t n, const T &val)
	// 		{
	// 			clear();
	// 			for (size_t i = 0; i < n; i++)
	// 				push_back(val);
	// 			_s = n;
	// 		}
	// 		template <class InputIterator>
	// 		void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type s, InputIterator e)
	// 		{
	// 			size_t i = 0;
	// 			clear();
	// 			while (s != e && ++i)
	// 				push_back(*(s++));
	// 			_s = i;
	// 		}
	};
}
#endif
