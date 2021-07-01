/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:43:35 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/01 17:15:25 by edal--ce         ###   ########.fr       */
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
#define D_S 10
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
				T* tmp = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
				{		
					_alloc.construct(&(tmp[i]), _arr[i]);
					_alloc.destroy(&(_arr[i]));
				}
				_alloc.deallocate(_arr, _max_size);
				_arr = tmp;
				_max_size = n;
			}

		public :
			class iterator;
			class const_iterator;
			class reverse_iterator;
			class const_reverse_iterator;
			typedef T value_type;
			explicit vector (const Alloc &alloc = Alloc()) : _alloc(alloc)
			{
				_arr = _alloc.allocate(10);//D_S);
				_size = 0;
				_max_size = 10;//D_S;
			};
			explicit vector (size_t n, const T& val = T(), const Alloc &alloc = Alloc()) : _alloc(alloc)
			{
				_arr = _alloc.allocate(n + 1);// + D_S);
				_max_size = n + 1;// + D_S;
				_size = n;
				for (size_t i = 0; i < n; i++)
					_alloc.construct(&(_arr[i]), val);
			};

			template <class InputIterator>
			vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const Alloc &alloc = Alloc()) : _size(0), _alloc(alloc)
			{
				InputIterator firstC = first;
				InputIterator lastC = last;
				size_t i = 0;
				
				while (firstC != lastC && ++i)
					++firstC; 

				_arr = _alloc.allocate(i + 1);// + D_S);
				_max_size = i + 1;// + D_S;
				_size = 0;
				while (first != last)
					push_back(*(first++));
			};

			vector(const vector &v)
			{
				// std::cerr << "HERE" << std::endl;
				_max_size = v._max_size;
				_size = v._size;
				_arr = _alloc.allocate(_max_size);
				for (size_t i = 0; i < _size; i++)
					_arr[i] = v._arr[i];
					// _alloc.construct(&(_arr[i]), v._arr[i]);
			}

			~vector(void)
			{
				clear();
				_alloc.deallocate(_arr, _max_size);
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
					// size_t *size;
					// list<T> *obj;
				public :

					iterator(T *ptr) : _ptr(ptr) 
					{	}
					iterator() : _ptr(0) 
					{	};
					iterator operator++(int) //i++
					{
						iterator i = *this;// = *this;
						++_ptr;
						return i;
					}
					iterator &operator++() //i++
					{		
						++_ptr;
						return *this;
					}
					iterator operator--(int) //i++
					{
						iterator i = *this;
						--_ptr;
						return i;
					}
					iterator &operator--()
					{ 
						// std::cout << "here\n";
						--_ptr; 
						return *this;
					}
					T& operator*() 
					{ 
						return *(_ptr); 
					}
					T* operator->() 
					{ 
						return _ptr;//->data; 
					}
					bool operator==(const iterator& it)
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const iterator& it) const
					{
						return (_ptr != it._ptr); 
					}

					// iterator operator+(int n)
					iterator operator+(int n) const
					{
						return iterator(&(_ptr[n]));
					}

					long int operator-(iterator t)
					{
						return (_ptr - t._ptr);
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
					T& operator[](int n) const
					{
						// _ptr += n;
						return _ptr[n];
					}
					bool operator>(iterator t) const
					{
						return (_ptr > t._ptr);
					}
					bool operator>=(iterator t) const
					{
						return (_ptr >= t._ptr);
					}
					bool operator<(iterator t) const
					{
						return (_ptr < t._ptr);
					}
					bool operator<=(iterator t) const
					{
						return (_ptr <= t._ptr);
					}
					// bool operator==(iterator t)
					// {
					// 	return (t._ptr == _ptr);
					// }
					// friend bool operator==(iterator n, iterator t)
					// {
					// 	return (n._ptr == t._ptr);
					// }
					// bool operator!=(iterator t)
					// {
					// 	return (t._ptr != _ptr);
					// }
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
					friend bool operator!=(const const_iterator b, const iterator& it)
					{
						return (b._ptr != it._ptr); 
					}
					friend bool operator==(const const_iterator b, const iterator& it)
					{
						return (b._ptr == it._ptr); 
					}
					friend bool operator<(const const_iterator b, const iterator& it)
					{
						return (b._ptr < it._ptr); 
					}
					friend bool operator>(const const_iterator b, const iterator& it)
					{
						return (b._ptr > it._ptr); 
					}
					friend bool operator>=(const const_iterator b, const iterator& it)
					{
						return (b._ptr >= it._ptr); 
					}
					friend bool operator<=(const const_iterator b, const iterator& it)
					{
						return (b._ptr <= it._ptr); 
					}
					// iterator operator+=(iterator n)
					// {
					// 	// size_t delta = &(*end) - &(*start);
					// 	// _ptr += delta
					// 	// // _ptr = _ptr + n;
					// 	// return *this;
					// }
					// int operator-(iterator n) const
					// {
					// 	size_t delta = &(*_ptr) - &(*n);
					// 	return delta;
					// }
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
					// size_t *size;
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
					const_iterator &operator++() //i++
					{		
						++_ptr;
						return *this;
					}
					const_iterator operator--(int) //i++
					{
						const_iterator i = *this;
						--_ptr;
						return i;
					}
					const_iterator &operator--() //i++
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
						return _ptr;//->data; 
					}
					bool operator==(const const_iterator& it) const
					{ 
						return (_ptr == it._ptr); 
					}
					bool operator!=(const const_iterator& it) const
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
					bool operator>(const_iterator t) const
					{
						return (_ptr > t._ptr);
					}
					bool operator>=(const_iterator t) const 
					{
						return (_ptr >= t._ptr);
					}
					bool operator<(const_iterator t) const
					{
						return (_ptr < t._ptr);
					}
					bool operator<=(const_iterator t) const
					{
						return (_ptr <= t._ptr);
					}
				
					long int operator-(const_iterator t) const
					{
						return (_ptr - t._ptr);
					}
					friend const_iterator operator+(int t ,const_iterator n)  
					{
						return (n + t);
					}
					friend const_iterator operator-(int t ,const_iterator n)  
					{
						return (n - t);
					}
					friend const_iterator operator+=(int t ,const_iterator n)  
					{
						return (n += t);
					}
					friend const_iterator operator-=(int t ,const_iterator n) 
					{
						return (n -= t);
					}
					friend bool operator!=(const iterator b, const const_iterator& it) 
					{
						return (b._ptr != it._ptr); 
					}
					friend bool operator==(const iterator b, const const_iterator& it) 
					{
						return (b._ptr == it._ptr); 
					}
					friend bool operator<(const iterator b, const const_iterator& it) 
					{
						return (b._ptr < it._ptr); 
					}
					friend bool operator>(const iterator b, const const_iterator& it) 
					{
						return (b._ptr > it._ptr); 
					}
					friend bool operator>=(const iterator b, const const_iterator& it) 
					{
						return (b._ptr >= it._ptr); 
					}
					friend bool operator<=(const iterator b, const const_iterator& it) 
					{
						return (b._ptr <= it._ptr); 
					}

			};

			class reverse_iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
					// size_t *size;
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
					reverse_iterator &operator++() //i++
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
					reverse_iterator &operator--() //i++
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
					bool operator!=(const reverse_iterator& it) const
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
					long int operator-(reverse_iterator t)
					{
						return (_ptr - t._ptr);
					}
			};
			class const_reverse_iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					T *_ptr;
					// size_t *size;

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
					const_reverse_iterator &operator++() //i++
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
					const_reverse_iterator &operator--() //i++
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
					bool operator!=(const const_reverse_iterator& it) const
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
					long int operator-(const_reverse_iterator t)
					{
						return (_ptr - t._ptr);
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
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type start, InputIterator end)
			{
				clear();
				while (start != end)
					push_back(*(start++));
			}

			
			void push_back (const T& val)
			{
				if (_size + 1 >= _max_size)
					growarr(_max_size * 2); //+ D_S);
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

			T& front(void) const
			{
				return _arr[0];
			}

			T& back(void) const
			{
				return _arr[_size - 1];
			}

			T& at(int a) const
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
				return (_size == 0);
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
			bool operator==(const vector &t) const
			{
				if (_size != t._size)
					return 0;
				for (size_t i = 0; i < _size; i++)
				{
					if (_arr[i] != t._arr[i])
						return 0;
				}
				return 1;
			}
			bool operator!=(const vector &t) const
			{
				return (!(*this == t));
			}
			bool operator>(const vector &t) const
			{
				size_t i = 0;
				while (i < _size && i < t._size)
				{
					if (_arr[i] < t._arr[i])
						return 0;
					i++;
				}
				if (i == _size)
					return 0;
				return 1;
			}
			bool operator<(const vector &t) const
			{
				if (*this == t)
					return 0;
				return !(*this > t);
			}
			bool operator>=(const vector &t) const
			{
				return (*this > t || *this == t);
			}
			bool operator<=(const vector &t) const
			{
				return (*this < t || *this == t);
			}

			template<class IT>
			IT insert (IT position, const T& val)
			{
				size_t delta = position._ptr - _arr;
				if(_size + 1 >= _max_size)
				{
					growarr(_max_size * 2);// + D_S);
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
    				position = insert(position, *(start++));
    				position++;
    			}
    		}
    		template<class IT>
    		IT erase (IT position)
    		{
    			IT cp = position;
    			while (++position != end())
    				*(position - 1) = *(position);
    			--_size;
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
				// --_size;
				return tmp;
			}
	};
	template <class T>
	void swap(vector<T> &x, vector<T> &y)
	{
		x.swap(y);
	}
}

#endif