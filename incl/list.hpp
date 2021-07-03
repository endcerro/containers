/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/03 16:29:24 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//http://www.cplusplus.com/reference/list/list/

#ifndef FT_LIST
#define FT_LIST

#include "tools.hpp"
#include "allocator.hpp"
#include <iostream>

//IMPLEMENT ALLOCATORS
namespace ft
{	

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		private : 
			Node<T> 	*_center;
			int 		_capacity;
			Alloc 		_alloc;

			void 	init(void)
			{
				_center = new Node<T>;
				// _center = _alloc.allocate(1);
				_center->data = reinterpret_cast<T *>(&_center->size);
				_center->size = 0;
				_center->next = _center;
				_center->previous = _center;	
			}

		public :
			class iterator;
			class const_iterator;
			class reverse_iterator;
			class const_reverse_iterator;

			// typedef list self_type;
			typedef T value_type;
			// typedef T& reference;
			// typedef T* pointer;
			list() : _capacity(-1) 
			{
				init();
			};
			
			list(const list &f) 
			{
				init();
				*this = f; 
			};

			template<class InputIterator>
			list(InputIterator s, InputIterator e) 
			{ 
				init();
				assign(s, e); 
			}

			list (size_t n, const T& val) : _capacity(-1)
			{
				init();
				assign(n, val); 
			}
			list (size_t n) : _capacity(-1)
			{
				init();
				for (size_t i = 0; i < n; i++)
					push_back(T());
			}

			~list()
			{ 
				clear();
				delete _center;
			};

			list& operator=(const list &b)
			{
				assign(b.begin(), b.end());
				return *this;
			};
			
			// friend class iterator;
			/* MEMBER FUNS */
			//Use friends
			class iterator
			{
				friend class list<T>;
				public :
					iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
					iterator() : _ptr(0) 
					{};
					iterator operator++(int) //i++
					{
						iterator i = *this;
						_ptr = _ptr->next;
						return i;
					}
					iterator &operator++() //i++
					{		
						_ptr = _ptr->next; 
						return *this;
					}
					iterator operator--(int) //i++
					{
						iterator i = *this;
						_ptr = _ptr->previous;
						return i;
					}
					iterator &operator--() //i++
					{ 
						_ptr = _ptr->previous; 
						return *this;
					}
					T& operator*() 
					{ 
						return *(_ptr->data); 
					}
					T* operator->() 
					{ 
						return _ptr->data; 
					}
					bool operator==(const iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const iterator& it) 
					{
						return (_ptr != it._ptr); 
					}
					// iterator operator+(iterator& it, int n)
					// iterator operator+(int n)
					// {
					// 	return iterator(_ptr[n]);
					// }
					friend bool operator!=(const const_iterator b, const iterator& it)
					{
						return (b._ptr != it._ptr); 
					}
				private :
					Node<T> *_ptr;
			};

			// friend class reverse_iterator;
			class const_iterator
			{
				friend class list<T>;
				public :
					const_iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
					const_iterator() : _ptr(0) 
					{};
					const_iterator(iterator x) : _ptr(x._ptr) 
					{ }
					const_iterator operator++(int) //i++
					{
						const_iterator i = *this;
						_ptr = _ptr->next;
						return i;
					}
					const_iterator &operator++() //i++
					{
						
						_ptr = _ptr->next; 
						return *this;
					}
					const_iterator operator--(int) //i++
					{
						const_iterator i = *this;
						_ptr = _ptr->previous;
						return i;
					}
					const_iterator &operator--() //i++
					{ 
						_ptr = _ptr->previous; 
						return *this;
					}
					const T& operator*() 
					{ 
						return (*(_ptr->data)); 
					}
					const T* operator->() 
					{ 
						return _ptr->data; 
					}
					bool operator==(const const_iterator& it) const
					{
						return _ptr == it._ptr;
					}
					bool operator!=(const const_iterator& it) const
					{
						return _ptr != it._ptr;
					}
					friend bool operator!=(const iterator b, const const_iterator& it)
					{
						return (b._ptr != it._ptr); 
					}
				private :
					Node<T> *_ptr;
			};
			
			class reverse_iterator
			{
				friend class list<T>;
				public :
					// typedef reverse_iterator self_type;
					typedef T value_type;
					// typedef T& reference;
					// typedef T* pointer;
					reverse_iterator() : _ptr(0) {};
					reverse_iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
					reverse_iterator(iterator t) : _ptr(t._ptr->previous) 
					{ }
					reverse_iterator operator++(int) //i++
					{
						reverse_iterator i = *this;
						_ptr = _ptr->previous;
						return i;
					}
					reverse_iterator &operator++() //++i
					{ 
						_ptr = _ptr->previous; 
						return *this;					
					}
					reverse_iterator operator--(int) //i++
					{
						reverse_iterator i = *this;
						_ptr = _ptr->next;
						return i;
					}
					reverse_iterator &operator--() //i++
					{ 
						_ptr = _ptr->next; 
						return *this;
					}
					iterator base() const
					{
						return iterator(_ptr->next);
					}
					T& operator*() 
					{
						// if (_ptr == end()._ptr)
						// 	return (&end()._ptr->size);
						return *(_ptr->data); 
					}
					T* operator->() 
					{ 
						return _ptr->data;
					}
					bool operator==(const reverse_iterator& it)
					{ 
						return _ptr == it._ptr; 
					}
					bool operator!=(const reverse_iterator& it) 
					{ 
						return _ptr != it._ptr; 
					}
					friend bool operator!=(const reverse_iterator b, const const_reverse_iterator& it) 
					{
						return (b._ptr != it._ptr); 
					}
				private :
					Node<T> *_ptr;
			};
			class const_reverse_iterator //: virtual public iterator
			{
				friend class list<T>;
				public :
					// typedef const_reverse_iterator self_type;
					// typedef T value_type;
					// typedef T& reference;
					// typedef T* pointer;
					const_reverse_iterator() : _ptr(0) {};
					const_reverse_iterator(Node<T> *ptr) : _ptr(ptr) 
					{ }
					const_reverse_iterator(const_iterator t) : _ptr(t._ptr->previous) 
					{ }
					const_reverse_iterator(iterator t) : _ptr(t._ptr->previous) 
					{ }
					const_reverse_iterator(reverse_iterator x) : _ptr(x._ptr) 
					{ }

					const_reverse_iterator operator++(int) //i++
					{
						const_reverse_iterator i = *this;
						_ptr = _ptr->previous;
						return i;
					}
					const_reverse_iterator &operator++() //++i
					{ 
						_ptr = _ptr->previous; 
						return *this;					
					}
					const_reverse_iterator operator--(int) //i++
					{
						const_reverse_iterator i = *this;
						_ptr = _ptr->next;
						return i;
					}
					const_reverse_iterator &operator--() //i++
					{ 
						_ptr = _ptr->next; 
						return *this;
					}
					const_iterator base() const
					{
						return const_iterator(_ptr->next);
					}
					const T& operator*()
					{ 
						return (*(_ptr->data)); 
					}
					const T* operator->() 
					{ 
						return _ptr->data;
					}
					bool operator==(const const_reverse_iterator& it)
					{ 
						return _ptr == it._ptr; 
					}
					bool operator!=(const const_reverse_iterator& it) 
					{ 
						return _ptr != it._ptr; 
					}
				private :
					Node<T> *_ptr;
			};

			/* ITERATORS N SHIT 
			NEED TO ADD CONST ITERATORS N STUFF*/

			iterator begin() const 
			{ 
				if (_center->next)
					return iterator(_center->next);
				return iterator(_center);
			}
			// const iterator begin() const 
			// { 
			// 	if (_center->next)
			// 		return iterator(_center->next);
			// 	return iterator(_center);
			// }
			iterator end() const 
			{
				return (iterator(_center));
			}
			// const iterator end() const 
			// {
			// 	return (iterator(_center));
			// }
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
				iterator ret = iterator(todel->next);
				todel->previous->next = todel->next;
				todel->next->previous = todel->previous;
				_alloc.destroy(todel->data);
				_alloc.deallocate(todel->data, sizeof(T));
				// delete todel->data;
				delete todel;
				_center->size--;
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
				Node<T> *old;
				Node<T> *elem = new Node<T>;
				elem->data = _alloc.allocate(1);
				_alloc.construct(elem->data, val);
				// elem->data = new T(val);

				old = _center->previous;
				_center->previous = elem;
				elem->previous = old;
				elem->next = _center;
				old->next = elem;
				++_center->size;
			}

			void push_front (const T& val)
			{
				Node<T> *elem = new Node<T>;
				// elem->data = new T(val);
				elem->data = _alloc.allocate(1);
				_alloc.construct(elem->data, val);
				Node<T> *old = _center->next;
				elem->next = old;
				elem->previous = _center;
				old->previous = elem;
				_center->next = elem;
				++_center->size;
			}

			T& front(void) const //Still not sure about that
			{ 
				if (_center->next)
					return *(_center->next->data);
				return (*_center->data); 
			}
			T& back(void) const	//This one as well
			{
				if (_center->next)
					return *(_center->previous->data); 
				return (*_center->data); 
			}

			void pop_front(void)
			{
				Node<T> *old = _center->next;

				if (_center->next == _center)
					return;

				if (old->next == _center)
					_center->next = _center->previous = _center;
				else
				{
					_center->next = old->next;
					_center->next->previous = _center;
				}
				_alloc.destroy(old->data);
				_alloc.deallocate(old->data, sizeof(T));
				// delete old->data;
				delete old;
				--_center->size;
			}
			void pop_back(void)
			{
				Node<T> *old = _center->previous;

				if (_center->next == _center)
					return;

				if (old->previous == _center)
					_center->next = _center->previous = _center;
				else
				{
					_center->previous = old->previous;
					old->previous->next = _center;
				}
				_alloc.destroy(old->data);
				_alloc.deallocate(old->data, sizeof(T));
				// delete old->data;
				delete old;
				--_center->size;
			}
			void resize (size_t n, T val = T())
			{
				while (n > _center->size)
					push_back(val);
				while (n < _center->size)
					pop_back();
			}

			void clear(void)
			{
				Node<T> *current = _center;
				Node<T> *next;

				if (current->next == _center)
					return ;
				current = current->next;
				while (current != _center)
				{
					next = current->next;
					_alloc.destroy(current->data);
					_alloc.deallocate(current->data, sizeof(T));
					// delete current->data;
					delete current;
					current	= next;
				}
				_center->size = 0;
				_center->next = _center;
				_center->previous = _center;
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
					new_elem->data = _alloc.allocate(1);
					_alloc.construct(new_elem->data, val);
					// new_elem->data = new T(val);
					new_elem->next = p._ptr;
					new_elem->previous = p._ptr->previous;
					p._ptr->previous->next = new_elem;
					p._ptr->previous = new_elem;
					++_center->size;
					return IT(new_elem);
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
					++position; ++start;
				}
			}
			template<class IT>
			void splice(IT position, list<T> &x)
			{
				if (x._center == this->_center) //This may need to go
					return;
				Node<T> *current = position._ptr;

				Node<T> *old_previous = position._ptr->previous;

				current->previous = x._center->previous;
				x._center->previous->next = current;
				x._center->next->previous = old_previous;
				old_previous->next = x._center->next;

				x._center->next = x._center;
				x._center->previous = x._center;

				_center->size += x._center->size;
				x._center->size = 0;
			}
			template<class IT>
			void splice (IT position, list<T> &x, IT i)
			{
				if (i == x.end())
					return;
				i._ptr->next->previous = i._ptr->previous;
				i._ptr->previous->next = i._ptr->next;

				position._ptr->previous->next = i._ptr;
				i._ptr->previous = position._ptr->previous;
				i._ptr->next = position._ptr;
				position._ptr->previous = i._ptr;

				--x._center->size;
				++_center->size;
			}
			template<class IT>
			void splice(IT position, list& x, IT first, IT last)
			{
				while (first != last)
					splice(position, x, first++);
			}

			void swap(list &base)
			{
				ft::Node<T> *tmp = _center;
				_center = base._center;
				base._center = tmp;
			}
			
			bool empty(void) const 	
			{ 
				if (_center->next != _center && _center->next != 0)
					return false;
				return true;
			}
			
			size_t size(void) const 
			{ 
				return _center->size; 
			}
			size_t max_size(void) const//CAPACITY TODO
			{
				return _alloc.max_size();
			};
			void remove (const T& val)
			{
				iterator it = begin();
				while(it != end())
				{
					if (*it == val)
					{
						erase(it);
						it = begin();
					}
					else
						it++;
				}
			}
			template <class Predicate>
			void remove_if (Predicate pred)
			{
				iterator it = begin();
				while(it != end())
				{
					if (pred(*it))
					{
						erase(it);
						it = begin();
					}
					else
						it++;
				}	
			}
			void merge (list& x)
			{
				if (&x != this && x._center->next != x._center)
				{
					iterator itx(x._center->next);
					iterator it(_center->next);
					while (itx != x.end())
					{
						while (it != end() && (*itx < *it == false))
							++it;
						splice(it, x, itx++);
					}
				}

			}
			template <class Compare>
			void merge(list &x, Compare comp)
			{
				if (&x != this)
				{
					if (x._center->next == x._center)
						return;
					iterator itx(x._center->next);
					iterator it(_center->next);

					while (itx != x.end())
					{
						while (it != end() && (comp(*itx, *it) == false))
							++it;
						splice(it, x, itx++);
					}
				}
			}
  			void unique()
  			{
				iterator current = begin();
				iterator prev = current++;;
				
				while (current != end())
				{
					if (*prev == *current && current._ptr != prev._ptr)
						current = erase(current);
					else
						prev = current++;
				}
  			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator current = begin();
				iterator prev =current++;
				while (current != end())
				{
					if (binary_pred(*prev, *current))
						current = erase(current);
					else
						prev = current++;
				}
			}
			void sort()
			{
				Node<T> *curr = _center->next;
				T *tmp;
				while (curr != _center && curr->next != _center)
				{
					if (*curr->data > *curr->next->data)
					{
						tmp = curr->data;
						curr->data = curr->next->data;
						curr->next->data = tmp;
						curr = _center->next;
					}
					else
						curr = curr->next;
				}
			}
			template <class Compare>
			void sort (Compare comp)
			{
				Node<T> *curr = _center->next;
				T *tmp;
				while (curr != _center && curr->next != _center)
				{
					if (comp(*curr->next->data,*curr->data))
					{
						tmp = curr->data;
						curr->data = curr->next->data;
						curr->next->data = tmp;
						curr = _center->next;
					}
					else
						curr = curr->next;
				}
			}
			void reverse()
			{
				Node<T> *curr = _center->next;
				Node<T> *next = _center->next;
				Node<T> *prev;
				_center->next = _center->previous;
				_center->previous = next;
				while (curr != _center)
				{
					next = curr->next;
					prev = curr->previous;
					curr->next = prev;
					curr->previous = next;
					curr = next;
				}	
			}
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
	template <class T>
	bool operator==(const list<T> &l_lst, const list<T> &r_lst)
	{
		if (l_lst.size() == r_lst.size())
		{
			typename list<T>::iterator lit;
			lit = l_lst.begin();
			typename list<T>::iterator rit;
			rit = r_lst.begin();

			while (lit != l_lst.end())
			{
				if (!(*lit == *rit))
					return false;
				++lit;
				++rit;
			}
			return true;
		}
		return false;
	}

	template <class T>
	bool operator!=(const list<T> &l_lst, const list<T> &r_lst)
	{
		return !(l_lst == r_lst);
	}

	template <class T>
	bool operator<(const list<T> &l_lst, const list<T> &r_lst)
	{
		typename list<T>::iterator lit;
		lit = l_lst.begin();
		typename list<T>::iterator rit;
		rit = r_lst.begin();

		while (lit != l_lst.end())
		{
			if (rit == r_lst.end() || *rit < *lit)
				return false;
			else if (*lit < *rit)
				return true;
			++lit;
			++rit;
		}
		return (rit != r_lst.end());
	}

	template <class T>
	bool operator<=(const list<T> &l_lst, const list<T> &r_lst)
	{
		return !(r_lst < l_lst);
	}

	template <class T>
	bool operator>(const list<T> &l_lst, const list<T> &r_lst)
	{
		return (r_lst < l_lst);
	}

	template <class T>
	bool operator>=(const list<T> &l_lst, const list<T> &r_lst)
	{
		return !(l_lst < r_lst);
	}

	template <class T>
	void swap(list<T> &x, list<T> &y)
	{
		x.swap(y);
	}
}
#endif
