/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/12 16:48:05 by edal--ce         ###   ########.fr       */
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
			T		d;
			Node	*n;
			Node	*p;
		};

	 	private :
			Node *_h;
			Node *_t;
			size_t _s;

	 	public :
	 		ft_list() : _s(0), _h(0), _t(0)
	 		{
	 			// std::cout << "CONSTRUCTOR CALL" << std::endl;
	 		};
			~ft_list()
			{
				// std::cout << "DESTRUCTOR CALL" << std::endl;
				Node *curr = _h;
				Node *next = 0;
				while (curr != 0)
				{
					next = curr->n;
					delete (curr);
					curr = next;
				}
			};


	 		ft_list& operator=(const ft_list &base){	 		};
			void push_back (const T& val)
			{
				if (_t == 0)
				{
					_t = new Node;
					_t->d = val;
					_t->n = 0;
					_t->p = 0;
				}
				else
				{
					_t->n = new Node;
					_t->n->d = val;
					_t->n->n = 0;
					_t->n->p = _t;
					_t = _t->n;
				}
				if (_h == 0)
					_h = _t;
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
			void push_front (const T& val)
			{
				if (_h == 0)
				{
					_h = new Node;
					_h->d = val;
					_h->n = 0;
					_h->p = 0;
				}
				else
				{
					Node *tmp = new Node; 
					tmp->d = val;
					tmp->n = _h;
					tmp->p = 0;
					_h = tmp;
				}
				if (_t == 0)
					_t = _h;
				_s++;
			}	
			void pop_front(void)
			{
				Node *tmp = _h;
				if (_h)	
					_h = _h->n;
 				delete tmp;
				_s--;				
			}
			void emplace_front(T t)
			{
				push_front(t);
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
			bool empty() const 	
			{
				return (_s > 0 ? true : false);
			};
			const size_t size() const
			{	
				return _s;
			};
			size_t max_size() 	{			};
			void print()
			{
				Node *curr = _h;
				Node *next = 0;
				while (curr != 0)
				{
					next = curr->n;
					std::cout << curr->d << std::endl;
					curr = next;
				}
			};
	};
}
#endif