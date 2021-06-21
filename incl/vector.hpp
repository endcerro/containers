/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:43:35 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/17 17:49:07 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// https://www.cplusplus.com/reference/vector/vector/
#ifndef FT_VECTOR
#define FT_VECTOR

#include "tools.hpp"
#include "allocator.hpp"
#include <iostream>
#ifndef D_S
#define D_S 10
#endif
namespace ft 
{
	template <class T, class Alloc = ft::allocator<T> >
	class vector
	{
		private :
			T* _arr;
			size_t _max_size;
			size_t _size;
			Alloc _alloc;

		public :
			//I stole this
			void vecDelete(T* p, size_t n)
			{
				for (size_t x = 0; x < n; ++x)
					_alloc.destroy(&(p[x]));
				_alloc.deallocate(p, n);
			}
			//Stole this as well
			T* vecNew(size_t n)
			{
				T* ret = _alloc.allocate(n);
				for (size_t x = 0; x < n; ++x)
					_alloc.construct(&(ret[x]), T());
				return ret;
			}

			vector (const Alloc &alloc = Alloc()) : _alloc(alloc)
			{
				_arr = vecNew(D_S);
				_size = _max_size = D_S;
			};
			vector (size_t n, const T& val)
			{			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last)
			{		};
			
			size_t size(void) const
			{
				return _size;
			}

			T& operator[](size_t n)
			{
				return _arr[n];
			}
	};
}

#endif