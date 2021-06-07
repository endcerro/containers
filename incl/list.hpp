/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/07 16:22:26 by edal--ce         ###   ########.fr       */
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
			Node<T> 	*_center;
			size_t		_size;
			int 		_capacity;

		public :
			/* CONSTRUCTORS N DESTRUCTORS */
			//THIS IS ONLY FOR NOW, I 
			list() : _size(0), _capacity(-1) 
			{
				_center = new Node<T>;
				_center->data = new T;
				*(_center->data) = 0;
				_center->next = 0;
				_center->previous = 0;
				_size = 0;
			};
			
			list(const list &f) 
			{
				_center = new Node<T>;
				_center->data = new T;
				*(_center->data) = 0;
				_center->next = 0;
				_center->previous = 0;
				_size = 0; 
				*this = f; 
			};

			template<class InputIterator>
			list(InputIterator s, InputIterator e) 
			{ 
				// list();
				_center = new Node<T>;
				_center->data = new T;
				*(_center->data) = 0;
				_center->next = 0;
				_center->previous = 0;
				_size = 0;
				assign(s, e); 
			}

			list (size_t n, const T& val) : _size(n), _capacity(-1)
			{
				// list();
				_center = new Node<T>;
				_center->data = new T;
				*(_center->data) = 0;
				_center->next = 0;
				_center->previous = 0;
				_size = 0;
				// std::cout << "No crash yet" << std::endl;
				assign(n, val); 
			}
			list (size_t n) : _size(n), _capacity(-1)
			{
				// list();
				_center = new Node<T>;
				_center->data = new T;
				*(_center->data) = 0;
				_center->next = 0;
				_center->previous = 0;
				_size = 0;
				// std::cout << "No crash yet" << std::endl;
				// assign(n, val); 
				for (size_t i = 0; i < n; i++)
				{
					push_back(0);
				}
			}

			~list()
			{ 
				clear();
				delete _center->data;
				delete _center;
			};

			/* OVERLOADS */

			list& operator=(const list &b)
			{
				assign(b.begin(), b.end());
				_size = b._size;
				return *this;
			};
			
			friend class iterator;
	// 		/* MEMBER FUNS */
	// 		//Use friends
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
					iterator() : _ptr(0) 
					{};
					self_type operator++(int) //i++
					{
						iterator i = *this;
						_ptr = _ptr->next;
						return i;
					}
					self_type operator++() //i++
					{
						// if (this != _center)
							_ptr = _ptr->next; 
						return *this;
					}
					self_type operator--(int) //i++
					{
						iterator i = *this;
						_ptr = _ptr->previous;
						return i;
					}
					self_type operator--() //i++
					{ 
						_ptr = _ptr->previous; 
						return *this;
					}
					reference operator*() 
					{ 
						return *(_ptr->data); 
					}
					// pointer operator->() 
					// { return _ptr->d; }
					bool operator==(const self_type& rhs)
					{ return _ptr == rhs._ptr; }
					bool operator!=(const self_type& rhs) 
					{ return _ptr != rhs._ptr; }
				private :
					Node<T> *_ptr;
			};
	// 		//may use friends
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
						_ptr = _ptr->previous;
						return i;
					}
					reverse_iterator operator++() //++i
					{ 
						_ptr = _ptr->previous; 
						return *this;					
					}
					self_type operator--(int) //i++
					{
						iterator i = *this;
						_ptr = _ptr->next;
						return i;
					}
					self_type operator--() //i++
					{ 
						_ptr = _ptr->next; 
						return *this;
					}
					reference operator*() 
					{ 
						return *(_ptr->data); 
					}
					pointer operator->() 
					{ 
						return _ptr->data;
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

	// 			/* ITERATORS N SHIT 
	// 		NEED TO ADD CONST ITERATORS N STUFF*/

			iterator begin() const 
			{ 
				if (_center->next)
					return iterator(_center->next);
				return iterator(_center);
			}
			iterator end() const 
			{
				return (iterator(_center));
			}
			reverse_iterator rbegin() const 
			{ 
				if (_center->previous)
					return reverse_iterator(_center->previous);
				return reverse_iterator(_center);
			}
			reverse_iterator rend() const 
			{	
				return reverse_iterator(_center); 
			}

			template<class IT>
			IT erase(IT pos)
			{
				if (pos == end())
					return pos;
				Node<T> *todel = pos._ptr;
				Node<T> *tmp = todel->next;
				// iterator(todel->next);
				todel->previous->next = todel->next;
				todel->next->previous = todel->previous;
				delete todel->data;
				delete todel;
				_size--;
				*(_center->data) = *(_center->data) - 1;
				return iterator(tmp);
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
				//Case where this is the first one
				Node<T> *elem = new Node<T>;
				elem->data = new T(val);

				Node<T> *old;
				// std::cout << "next:" << _center->next << " prev:" << _center->previous << std::endl;
				if (_center->next == 0)
				{
					// std::cout << "Z1" << std::endl;
					_center->next = elem;
					_center->previous = elem;
					elem->next = _center;
					elem->previous = _center;
				}
				else
				{
					// std::cout << "Z2" << std::endl;
					old = _center->previous;
					_center->previous = elem;
					elem->previous = old;
					elem->next = _center;
					old->next = elem;
				}
				++(*_center->data);
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
				++(*_center->data);
				++_size;
			}

			T& front(void) const	{ 
				if (_center->next)
					return *(_center->next->data);
				return *(_center->data); 
			}
			T& back(void) const		{ 
				if (_center->next)
					return *(_center->previous->data); 
				return *(_center->data); 
			}

			void pop_front(void)
			{
				Node<T> *old = _center->next;

				if (old->next == _center)
					_center->next =_center->previous = 0;
				else
				{
					_center->next = old->next;
					_center->next->previous = _center;
				}
				delete old->data;
				delete old;
				--(*_center->data);
				--_size;
			}
			void pop_back(void)
			{
				Node<T> *old = _center->previous;

				if (old->previous == _center)
					_center->next = _center->previous = 0;
				else
				{
					_center->previous = old->previous;
					old->previous->next = _center;
				}
				delete old->data;
				delete old;
				--(*_center->data);
				--_size;
			}
            void resize (size_t n, T val = T())
            {
                while (n > _size)
                    push_back(val);
                while (n < _size)
                    pop_back();
            }

			void clear(void)
			{
				Node<T> *current = _center;
				Node<T> *next;

				// In order to check if the list has one elem, check head address
				// Don't forget to delete the end element as it should be instancied at all times
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
				_size = 0;
				*(_center->data) = 0;
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

			template<class IT>
			IT insert (IT p, const T& val)
			{

				if (p == begin())
				{
					push_front(val);
					return begin();
				}
				else if (p == end())
				{
					push_back(val);
					return --end();
				}
				else
				{
					Node<T> *new_elem = new Node<T>;
					new_elem->data = new T(val);
					new_elem->next = p._ptr;
					new_elem->previous = p._ptr->previous;
					p._ptr->previous->next = new_elem;
					p._ptr->previous = new_elem;
					_size++;
					*(_center->data) = *(_center->data) + 1;
					return iterator(new_elem);
				}
			}

			template<class IT>
			void insert (IT position, size_t n, const T& val)
			{
				for (size_t i = 0; i < n; i++)
					position = insert(position, val);
			}
			
			template <class InputIterator, class IT>
    		void insert (IT position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type start, InputIterator end)
    		{
    			while (start != end)
    			{
    				position = insert(position, *start);
    				++position;
    				++start;
    			}
    		}
    		template<class IT>
    		void splice(IT position, list<T> &x)
    		{
    			Node<T> *current = position._ptr;
    			Node<T> *next = position._ptr->next;
    			current->next = x._center->next;
    			x._center->next->previous = current;
    			x._center->previous->next = next;
    			x._center->next = x._center;
    			x._center->previous = x._center;
    			
    			next->previous = x._center->previous;
    			_size += x._size;
    			*(_center->data) = _size;
				*(x._center->data) = 0;
    			x._size = 0;
    		}
			template<class IT>
    		void splice (IT position, list<T> &x, IT i)
    		{
    			Node<T> *current = position._ptr;
    			Node<T> *next = position._ptr->next;

    			i._ptr->next->previous = i._ptr->previous;
    			i._ptr->previous->next = i._ptr->next;
    			x._size--;
    			--(*x._center->data);

    			i._ptr->next = current->next;
    			i._ptr->previous = current;

    			current->next->previous = i._ptr;
    			current->next = i._ptr;

    			_size++;
    			++(*_center->data);

    		}
    		template<class IT>
    		void splice(IT position, list& x, IT first, IT last)
    		{
    			while (first != last)
    			{
    				splice(position, x, first++);
    				// first++;
    			}
    		}
	// 		//Seems good but watch out for allocators
			void swap(list &base)
			{
				ft::Node<T> *old_head = _center->next;
				ft::Node<T> *old_tail = _center->previous;
				T *old_data = _center->data;
				size_t old_size = _size;

				_center->next = base._center->next;
				_center->previous = base._center->previous;
				_center->data = base._center->data;

				if (_center->next)
				{
					_center->next->previous = _center;
					_center->previous->next = _center;
				}

				base._center->next = old_head;
				base._center->previous = old_tail;
				base._center->data = old_data;
				
				if (base._center->next)
				{
					base._center->next->previous = base._center;
					base._center->previous->next = base._center;
				}

				_size = base._size;
				base._size = old_size;
			}
			bool empty(void) const 	
			{ 
				if (_center->next != _center && _center->next != 0)
					return false;
				return true;
			}
			size_t size(void) const { return _size; }
			size_t max_size(void) 	{ return _capacity;	 };
			
	// 		template <class IT>
	// 		void print(IT s, IT e)
	// 		{
	// 			while (s != e)
	// 			{
	// 				std::cout << *s << std::endl;
	// 				++s;
	// 			}
	// 		};
			void assign(size_t n, const T &val)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}
			template <class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type s, InputIterator e)
			{
				clear();
				while (s != e)
					push_back(*(s++));
			}
	};
}
#endif
