/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:43:35 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/30 16:03:37 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// https://www.cplusplus.com/reference/vector/vector/
#ifndef FT_VECTOR
#define FT_VECTOR

#include "tools.hpp"
#include "allocator.hpp"
#include <stdexcept>
#include <iostream>
#ifndef D_S
#define D_S 5
#endif
namespace ft 
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		private :
			T* _arr;
			size_t _max_size;
			size_t _size;
			Alloc _alloc;

			void growarr(size_t n)
			{
				// std::cout << "creating :" << n << std::endl;
				
				// n = _max_size * 2 + n;

				T* tmp = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(&tmp[i], _arr[i]);
					// tmp[i] = _arr[i];
					_alloc.destroy(&(_arr[i]));
				}
				_alloc.deallocate(_arr, sizeof(T) * _max_size);
				_max_size = n;
				_arr = tmp;
			}

		public :
			typedef T value_type;
			explicit vector (const Alloc &alloc = Alloc()) : _alloc(alloc)
			{
				_arr = _alloc.allocate(D_S);

				// vecNew(D_S);
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

				// std::cout << "CopyConstructor\n";
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
				// std::cout << "Freed " << i << " elements" << std::endl;
				_alloc.deallocate(_arr, sizeof(T) * _max_size);
			}


			vector& operator=(const vector &b)
			{
				assign(b.begin(), b.end());
				return *this;
			};

			class iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
					size_t *size;
					// list<T> *obj;
				public :

					iterator(T *ptr) : _ptr(ptr) 
					{	}
					iterator() : _ptr(0) 
					{	};
					iterator operator++(int t) //i++
					{
						t = 0;
						iterator i = *this;
						++_ptr;
						return i;
					}
					iterator operator++() //i++
					{		
						++_ptr;
						return *this;
					}
					iterator operator--(int t) //i++
					{
						t = 0;
						iterator i = *this;
						// _ptr = _ptr->previous;
						--_ptr;
						return i;
					}
					iterator operator--() //i++
					{ 
						--_ptr;// = _ptr->previous; 
						return *this;
					}
					T& operator*() 
					{ 
						return *(_ptr); 
					}
					T* operator->() 
					{ 
						return *_ptr;//->data; 
					}
					bool operator==(const iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const iterator& it) 
					{
						return (_ptr != it._ptr); 
					}

					// iterator operator+(int n)
					iterator operator+(int n) const
					{
						return iterator(&(_ptr[n]));
					}

					// iterator operator+(int n) const
					// {
					// 	return iterator(t + n);
					// }
					iterator operator+=(int n)
					{
						_ptr = _ptr + n;
						return *this;
					}
					iterator operator-(int n) const
					{
						return iterator(_ptr - n);
					}
					iterator operator-=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}

					friend iterator operator+(int t ,iterator n)
					{
						return (n + t);
					}
					friend iterator operator-(int t ,iterator n)
					{
						return (n - t);
					}
					friend iterator operator+=(int t ,iterator n)
					{
						return (n += t);
					}
					friend iterator operator-=(int t ,iterator n)
					{
						return (n -= t);
					}
					// iterator operator+=(iterator n)
					// {
					// 	// size_t delta = &(*end) - &(*start);
					// 	// _ptr += delta
					// 	// // _ptr = _ptr + n;
					// 	// return *this;
					// }
					size_t operator-(iterator n) const
					{
						size_t delta = &(*_ptr) - &(*n);

						return delta;
					}
					// iterator operator-=(iterator n)
					// {
					// 	// size_t delta = &(*end) - &(*start);
					// 	// _ptr -= delta;
					// 	// return *this;
					// }
			};

			class const_iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
					size_t *size;
					// list<T> *obj;
				public :

					const_iterator(T *ptr) : _ptr(ptr) 
					{	}
					const_iterator() : _ptr(0) 
					{	};
					const_iterator(iterator x) : _ptr(x._ptr)
					{

					}

					const_iterator operator++(int) //i++
					{
						const_iterator i = *this;
						++_ptr;
						return i;
					}
					const_iterator operator++() //i++
					{		
						++_ptr;
						return *this;
					}
					const_iterator operator--(int) //i++
					{
						const_iterator i = *this;
						// _ptr = _ptr->previous;
						--_ptr;
						return i;
					}
					const_iterator operator--() //i++
					{ 
						--_ptr;// = _ptr->previous; 
						return *this;
					}
					const T& operator*() 
					{ 
						return *(_ptr); 
					}
					const T* operator->() 
					{ 
						return *_ptr;//->data; 
					}
					bool operator==(const const_iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const const_iterator& it) 
					{
						return (_ptr != it._ptr); 
					}
					const_iterator operator+(int n) const
					{
						return const_iterator(&(_ptr[n]));
					}
					const_iterator operator+=(int n)
					{
						_ptr = _ptr + n;
						return *this;
					}
					const_iterator operator-(int n) const
					{
						return const_iterator(_ptr - n);
					}
					const_iterator operator-=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}

			};

			class reverse_iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
					size_t *size;
					// list<T> *obj;
				public :
					reverse_iterator(T *ptr) : _ptr(ptr) 
					{	}
					reverse_iterator() : _ptr(0) 
					{	};
					reverse_iterator operator++(int) //i++
					{
						reverse_iterator i = *this;
						--_ptr;
						return i;
					}
					reverse_iterator operator++() //i++
					{		
						--_ptr;
						return *this;
					}
					reverse_iterator operator--(int) //i++
					{
						reverse_iterator i = *this;
						++_ptr;
						return i;
					}
					reverse_iterator operator--() //i++
					{ 
						++_ptr; 
						return *this;
					}
					T& operator*() 
					{ 
						return *(_ptr); 
					}
					T* operator->() 
					{ 
						return *_ptr;//->data; 
					}
					bool operator==(const reverse_iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const reverse_iterator& it) 
					{
						return (_ptr != it._ptr); 
					}
					reverse_iterator operator+(int n) const
					{
						return reverse_iterator((_ptr - n));
					}
					reverse_iterator operator+=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}
					reverse_iterator operator-(int n) const
					{
						return reverse_iterator(_ptr + n);
					}
					reverse_iterator operator-=(int n)
					{
						_ptr = _ptr + n;
						return *this;
					}
			};
			class const_reverse_iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
					size_t *size;

				public :

					const_reverse_iterator(T *ptr) : _ptr(ptr) 
					{	}
					const_reverse_iterator() : _ptr(0) 
					{	};
					const_reverse_iterator(reverse_iterator n) : _ptr(n._ptr)
					{

					}
					const_reverse_iterator operator++(int) //i++
					{
						const_reverse_iterator i = *this;
						--_ptr;
						return i;
					}
					const_reverse_iterator operator++() //i++
					{		
						--_ptr;
						return *this;
					}
					const_reverse_iterator operator--(int) //i++
					{
						const_reverse_iterator i = *this;
						++_ptr;
						return i;
					}
					const_reverse_iterator operator--() //i++
					{ 
						++_ptr; 
						return *this;
					}
					T& operator*() 
					{ 
						return *(_ptr); 
					}
					T* operator->() 
					{ 
						return *_ptr;//->data; 
					}
					bool operator==(const const_reverse_iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const const_reverse_iterator& it) 
					{
						return (_ptr != it._ptr); 
					}
					const_reverse_iterator operator+(int n) const
					{
						return const_reverse_iterator((_ptr - n));
					}
					const_reverse_iterator operator+=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}
					const_reverse_iterator operator-(int n) const
					{
						return const_reverse_iterator(_ptr + n);
					}
					const_reverse_iterator operator-=(int n)
					{
						_ptr = _ptr + n;
						return *this;
					}
			};

			iterator begin() const 
			{ 
				return iterator(_arr);
			}
			reverse_iterator rbegin() const 
			{
				return reverse_iterator(&(_arr[_size - 1]));
			}
			iterator end() const 
			{
				return (iterator(&(_arr[_size])));// + sizeof(T) * (_size)));
			}
			reverse_iterator rend() const 
			{
				return (reverse_iterator(_arr - 1));// + sizeof(T) * (_size)));
			}

			void clear(void)
			{
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(&(_arr[i]));
				_size = 0;
			}

			void assign (size_t n, const T& val)
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

			T& front(void)
			{
				return _arr[0];
			}

			T& back(void)
			{
				return _arr[_size - 1];
			}
			T& at(int a)
			{
				int ns = static_cast<int>(_size);
				if (a >= ns || a < 0)
					throw std::out_of_range("at is fucked up yoo");
				return _arr[a];
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
			void swap (vector& x)
			{
				T* ptr = _arr;
				_arr = x._arr;
				x._arr = ptr;

				size_t tmp = _max_size;
				_max_size = x._max_size;
				x._max_size = tmp;

				tmp = _size;
				_size = x._size;
				x._size = tmp;

				Alloc a = _alloc;
				_alloc = x._alloc;
				x._alloc = a;

			}


			T& operator[](size_t n)
			{
				return _arr[n];
			}
			template<class IT>
			IT insert (IT position, const T& val)
			{
				size_t delta = position._ptr - _arr;
				if(_size + 1 >= _max_size)
				{
					growarr(_size + 1 + D_S);
					position = IT(_arr + delta);
				}
				for (size_t i = _size; i > delta ; i--)
					_arr[i] = _arr[i - 1];
				*position = val;
				++_size;
				return IT(position);
			}

			template<class IT>
    		void insert (IT position, size_t n, const T& val)
    		{
    			for (size_t i = 0; i < n; i++)
    				position = insert(position, val);
    		}	
			template <class IT, class InputIterator>
    		void insert (IT position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type start, InputIterator end)
    		{
    			while (start != end)
    			{
    				// std::cout << "insert at " << &(*position) << std::endl;
    				insert(position++, *(start++));
    				// position++;
    			}
    		}
    		template<class IT>
    		IT erase (IT position)
    		{
    			IT cp = position;
    			_alloc.destroy(&(*position));
    			while (++position != end())
    				*(position - 1) = *(position);
    			_size--;
    			return cp;
    		}
    		template<class IT>
			IT erase (IT start, IT end)
			{
				IT tmp;
				size_t delta = &(*end) - &(*start);
				if (delta < 0)
				{
					tmp = end;
					end = start;
					start = tmp;
				}
				tmp = start;
				for(size_t i = 0; i < delta; i++)
					start = erase(start);
				return tmp;
			}
	};
}

#endif