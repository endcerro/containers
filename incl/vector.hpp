/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:43:35 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/25 20:04:51 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// https://www.cplusplus.com/reference/vector/vector/
#ifndef FT_VECTOR
#define FT_VECTOR

#include "tools.hpp"
#include "allocator.hpp"
#include <iostream>
#ifndef D_S
#define D_S 5
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

			explicit vector (const Alloc &alloc = Alloc()) : _alloc(alloc)
			{
				_arr = vecNew(D_S);
				_size = 0;
				_max_size = D_S;
			};
			explicit vector (size_t n, const T& val, const Alloc &alloc = Alloc()) : _alloc(alloc)
			{
				_max_size = n + 10;
				_size = n;
				_arr = _alloc.allocate(n + 10);

				for (size_t i = 0; i < n; i++)
					_alloc.construct(&(_arr[i]), val);

			};
			template <class InputIterator>
			vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const Alloc &alloc = Alloc()) : _size(0), _alloc(alloc)
			{
				InputIterator firstC = first;
				InputIterator lastC = last;
				size_t i = 0;
				while (firstC != lastC)
				{
					++firstC; 
					++i;
				}
				_arr = _alloc.allocate(i);
				_max_size = i;
				_size = 0;

				while (first != last)
					push_back(*(first++));
			};

			vector(const vector &v)
			{
				_max_size = v._max_size;
				_size = v._size;

				_arr = _alloc.allocate(_max_size);

				for (size_t i = 0; i < v._size; i++)
					_arr[i] = v._arr[i];

				std::cout << "CopyConstructor\n";
			}

			
			~vector(void)
			{
				// std::cout << "DESTRUCTOR CALLED" << std::endl;
				size_t i= 0;
				while (i < _size)
				{
					// std::cout << "Deal";
					_alloc.destroy(&(_arr[i++]));
					// std::cout << ".... Done" << std::endl;
				}
				std::cout << "Freed " << i << " elements" << std::endl;
				_alloc.deallocate(_arr, sizeof(T) * _max_size);
			}

			friend class iterator;
			/* MEMBER FUNS */
			//Use friends
			class iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
				public :
					iterator(T *ptr) : _ptr(ptr) 
					{ }
					iterator() : _ptr(0) 
					{};
					iterator operator++(int) //i++
					{
						iterator i = *this;
						++_ptr; //= _ptr + sizeof(T);//->next;
						return i;
					}
					iterator operator++() //i++
					{		
						_ptr = _ptr + sizeof(T); 
						return *this;
					}
					// iterator operator--(int) //i++
					// {
					// 	iterator i = *this;
					// 	_ptr = _ptr->previous;
					// 	return i;
					// }
					// iterator operator--() //i++
					// { 
					// 	_ptr = _ptr->previous; 
					// 	return *this;
					// }
					T& operator*() 
					{ 
						return *(_ptr); 
					}
					// T* operator->() 
					// { 
					// 	return _ptr->data; 
					// }
					bool operator==(const iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const iterator& it) 
					{
						return (_ptr != it._ptr); 
					}

			};

			iterator begin() const 
			{ 
				// if (_center->next)
					// return iterator(_center->next);
				return iterator(_arr);
			}
			iterator end() const 
			{
				return (iterator(_arr + sizeof(T) * (_size - 1)));
			}

			void growarr(size_t n)
			{
				std::cout << "growarr" << std::endl;
				
				T* tmp;
				tmp = _alloc.allocate(n);

				for (size_t i = 0; i < _size; i++)
				{
					tmp[i] = _arr[i];
					_alloc.destroy(&(_arr[i]));
				}
				

				_alloc.deallocate(_arr, sizeof(T) * _max_size);
				
				_max_size = n;
				_arr = tmp;

			}

			void push_back (const T& val)
			{
				if (_size == _max_size)
					growarr(_size + 10);
				_arr[_size++] = val;
			}

			void pop_back(void)
			{
				if (_size)
					_alloc.destroy(&(_arr[_size--]));
			}

			void print() const
			{
				for (size_t i = 0; i < _size; i++)
				{
					std::cout << _arr[i] << "|";
				}
				std::cout << std::endl;
			}

			void resize (size_t n, T val = T())
			{
				// size_t i = 0;
				while (n < _size)
					pop_back();
				while (n > _size)
					push_back(val);
			}
			void reserve(size_t n)
			{
				if (n <= _max_size)
					return;
				growarr(n);
			}


			size_t size(void) const
			{
				return _size;
			}

			size_t capacity(void) const
			{
				return _max_size;
			}

			size_t max_size(void) const
			{
				return _alloc.max_size();
			}

			bool empty(void) const
			{
				return (_size > 0);
			}

			T& operator[](size_t n)
			{
				return _arr[n];
			}
	};
}

#endif