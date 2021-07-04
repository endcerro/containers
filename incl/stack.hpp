/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/04 20:17:26 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK
#define FT_STACK

#include "list.hpp"

namespace ft
{
	template < class T, class Container = ft::list<T> >
	class stack
	{
		public :
			typedef Container container_type;
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
			Container _storage;

		public :
		
			explicit stack(const Container &stor = container_type()) : _storage(stor) {}

			bool empty() const
			{	return _storage.empty();	}

			size_t size() const
			{	return _storage.size();	}

			T &top()
			{	return _storage.back();	}

			const T &top() const
			{	return _storage.back();	}

			void push(const T &val)
			{	_storage.push_back(val);	}

			void pop()
			{	_storage.pop_back();	}
			
			bool operator==(const stack &rhs) const
			{	return (_storage == rhs._storage);	};
			
			bool operator!=(const stack &rhs) const
			{	return (_storage != rhs._storage);	};
			
			bool operator>(const stack &rhs) const
			{	return (_storage > rhs._storage);	};
			
			bool operator<(const stack &rhs) const
			{	return (_storage < rhs._storage);	};
			
			bool operator<=(const stack &rhs) const
			{	return (_storage <= rhs._storage);	};
			
			bool operator>=(const stack &rhs) const
			{	return (_storage >= rhs._storage);	};
	};
}


#endif