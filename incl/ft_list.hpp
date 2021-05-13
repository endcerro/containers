/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/13 17:52:57 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cplusplus.com/reference/list/list/

#ifndef FT_LIST
#define FT_LIST

#include <iostream>


namespace ft
{
	template <class T>
	class ft_list
	{

		struct Node
		{
			T		*d;
			Node	*n;
			Node	*p;
		};

		private :
			Node *_h;
			Node *_t;
			size_t _s;

		public :
			ft_list() : _h(0), _t(0),  _s(0)
			{				};
			~ft_list()
			{	clear();	};

		   //  class const_iterator
		// {
		//     public:
		//         typedef const_iterator self_type;
		//         typedef T value_type;
		//         typedef T& reference;
		//         typedef T* pointer;
		//         typedef int difference_type;
		//         typedef std::forward_iterator_tag iterator_category;
		//         const_iterator(pointer ptr) : ptr_(ptr) { }
		//         self_type operator++() { self_type i = *this; ptr_++; return i; }
		//         self_type operator++(int junk) { ptr_++; return *this; }
		//         const reference operator*() { return *ptr_; }
		//         const pointer operator->() { return ptr_; }
		//         bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		//         bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
		//     private:
		//         pointer ptr_;
		// };
			//Maybe think about const
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
					iterator(Node *ptr) : _ptr(ptr) 
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
					Node *_ptr;
			};

			class reverse_iterator
			{
				public:
					typedef reverse_iterator self_type;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					// typedef std::forward_iterator_tag iterator_category;
					typedef int difference_type;
					// iterator(pointer ptr) : _ptr(ptr) 
					// { }
					reverse_iterator(Node *ptr) : _ptr(ptr) 
					{ }
					self_type operator++(int) //i++
					{
						self_type i = *this; 
						_ptr = _ptr->p;
						return i;
					}
					self_type operator++() //i++
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
					bool operator==(const self_type& rhs)
					{ 
						return _ptr == rhs._ptr; 
					}
					bool operator!=(const self_type& rhs) 
					{ 
						return _ptr != rhs._ptr; 
					}
				private :
					Node *_ptr;
			};


			iterator begin()
			{
				return iterator(_h);
			}

			iterator end()
			{
				return iterator(_t->n);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_t);
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_h->p);
			}

			ft_list& operator=(const ft_list &base)
			{
				clear();
				//need to copy also;
			};
			void push_back (const T& val)
			{
				if (_t == 0)
				{
					_t = new Node;
					
					//THIS NEEDS TO USE ALLOCATORS IT SEEMS
					_t->d = new T(val);
					

					_t->n = 0;
					_t->p = 0;
				}
				else
				{
					_t->n = new Node;
					_t->n->d = new T(val);
					_t->n->n = 0;
					_t->n->p = _t;
					_t = _t->n;
				}
				if (_h == 0)
					_h = _t;
				_s++;
			}
			void push_front (const T& val)
			{
				if (_h == 0)
				{
					_h = new Node;
					_h->d = new T(val);
					_h->n = 0;
					_h->p = 0;
				}
				else
				{
					Node *tmp = new Node; 
					tmp->d = new T(val);
					tmp->n = _h;
					tmp->p = 0;
					_h = tmp;
				}
				if (_t == 0)
					_t = _h;
				_s++;
			}	
			T front(void) const
			{
				return _h->d;
			}
			T back(void) const
			{
				return _t->d;
			}
	
			void pop_front(void)
			{
				Node *tmp = _h;
				if (_h)	
					_h = _h->n;
				delete tmp;
				_s--;				
			}
			void pop_back(void)
			{
				Node *tmp = _t;
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
				Node *curr = _h;
				Node *next;
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
			bool empty() const 	
			{
				return (_s > 0 ? true : false);
			}
			size_t size() const
			{	
				return _s;
			}
			size_t max_size() 	{			};
			//TO DEL
			void print()
			{
				Node *curr = _h;
				Node *next = 0;
				while (curr != 0)
				{
					next = curr->n;
					std::cout << *(curr->d) << std::endl;
					curr = next;
				}
			};
	};
}
#endif