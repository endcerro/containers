/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/06 16:17:18 by edal--ce         ###   ########.fr       */
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
			// typedef Container container_type;
			// class iterator;
			// class const_iterator;
			// class reverse_iterator;
			// class const_reverse_iterator;
			typedef T 			value_type;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T*			pointer;
			typedef const T*	const_pointer;
	
		private :
			struct Node
			{
				Node *parent;
				Node *left;
				Node *right;
				ft::pair<const Key, T> data;
			};
			size_t 	_size;
			Alloc 	_alloc;
			Node 	*top
			// Container _storage;

		public :
			explicit map (const Compare& comp = Compare(), const Alloc& alloc = Alloc())
			{	std::cout << "Default constructor called";	}



			// template <class InputIterator>
  	// 		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			// {	}
			// map (const map& x)
			// {	std::cout << "Copy constructor called\n";	}
			bool empty() const
			{	return (_size > 0);	}
			
			size_t size() const
			{	return (_size);	}
			
			size_t max_size() const
			{	return (_alloc.max_size());	}
	};
}


#endif