/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:43:35 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/21 00:00:54 by edal--ce         ###   ########.fr       */
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
		public :
			class iterator;
			class const_iterator;
			class reverse_iterator;
			class const_reverse_iterator;
			
			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename std::size_t 						size_type;
			typedef typename std::ptrdiff_t 					difference_type;

		private :
			pointer 		_arr;
			size_type 		_max_size;
			size_type 		_size;
			allocator_type 	_alloc;

			void growarr(size_type n)
			{
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{		
					_alloc.construct(&(tmp[i]), _arr[i]);
					_alloc.destroy(&(_arr[i]));
				}
				_alloc.deallocate(_arr, _max_size);
				_arr = tmp;
				_max_size = n;
			}

		public :
			
			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc)
			{
				_arr = _alloc.allocate(10);
				_size = 0;
				_max_size = 10;
			};
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc)
			{
				_arr = _alloc.allocate(n + 1);
				_max_size = n + 1;
				_size = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&(_arr[i]), val);
			};

			template <class InputIterator>
			vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc)
			{
				size_type i = 0;
				InputIterator firstC = first;
				InputIterator lastC = last;				
				while (firstC != lastC && ++i)
					++firstC; 
				_arr = _alloc.allocate(i + 1);
				_max_size = i + 1;
				_size = 0;
				while (first != last)
					push_back(*(first++));
			};

			vector(const vector &v)
			{
				_max_size = v._max_size;
				_size = v._size;
				_arr = _alloc.allocate(_max_size);
				for (size_type i = 0; i < _size; i++)
					_arr[i] = v._arr[i];
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
					typedef typename std::ptrdiff_t 			difference_type;
					typedef typename vector::value_type 		value_type;
					typedef typename vector::pointer 			pointer;
					typedef typename vector::const_pointer		const_pointer;
					typedef typename vector::reference 			reference;
					typedef typename vector::const_reference 	const_reference;
					pointer _ptr;

				public :
					explicit iterator(pointer ptr = 0) : _ptr(ptr) 
					{	}
					iterator operator++(int)
					{
						iterator i = *this;
						++_ptr;
						return i;
					}

					iterator &operator++()
					{		
						++_ptr;
						return *this;
					}

					iterator operator--(int)
					{
						iterator i = *this;
						--_ptr;
						return i;
					}

					iterator &operator--()
					{ 
						--_ptr; 
						return *this;
					}

					reference operator*() const
					{	return *(_ptr); }
					
					pointer operator->() const 
					{	return _ptr;	}
					
					bool operator==(const iterator& it) const
					{	return (_ptr == it._ptr);	}
					
					bool operator!=(const iterator& it) const
					{	return (_ptr != it._ptr);	}

					iterator operator+(int n) const
					{	return iterator(&(_ptr[n]));	}

					long int operator-(iterator t) const
					{	return (_ptr - t._ptr);	}

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
					reference operator[](int n) const
					{
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

					friend iterator operator+(int t ,iterator n)
					{	return (n + t);	}
					friend iterator operator-(int t ,iterator n)
					{	return (n - t);	}
					friend iterator operator+=(int t ,iterator n)
					{	return (n += t);	}
					friend iterator operator-=(int t ,iterator n)
					{	return (n -= t);	}
					friend bool operator!=(const const_iterator b, const iterator& it)
					{	return (b._ptr != it._ptr); 	}
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
			};

			class const_iterator
			{
				friend class vector<T, Alloc>;
				
				private :
					typedef typename std::ptrdiff_t 			difference_type;
					typedef typename vector::value_type 		value_type;
					typedef typename vector::pointer 			pointer;
					typedef typename vector::const_pointer		const_pointer;
					typedef typename vector::reference 			reference;
					typedef typename vector::const_reference 	const_reference;
					pointer _ptr;
				public :

					const_iterator(pointer ptr) : _ptr(ptr) 
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
						--_ptr; 
						return *this;
					}
					const_reference operator*() const
					{	return *(_ptr); }
					
					const_pointer operator->() const 
					{	return _ptr;	}
					
					bool operator==(const const_iterator& it) const
					{	return (_ptr == it._ptr);	}
					
					bool operator!=(const const_iterator& it) const
					{	return (_ptr != it._ptr); }

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
					{	return const_iterator(_ptr - n);	}
					
					const_iterator operator-=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}
					const_reference operator[](int n) const
					{
						return _ptr[n];
					}
					bool operator>(const_iterator t) const
					{	return (_ptr > t._ptr);	}
					
					bool operator>=(const_iterator t) const 
					{	return (_ptr >= t._ptr);	}
					
					bool operator<(const_iterator t) const
					{	return (_ptr < t._ptr);	}

					bool operator<=(const_iterator t) const
					{	return (_ptr <= t._ptr);	}
				
					long int operator-(const_iterator t) const
					{	return (_ptr - t._ptr);	}
					
					friend const_iterator operator+(int t ,const_iterator n)  
					{	return (n + t);	}
					
					friend const_iterator operator-(int t ,const_iterator n)  
					{	return (n - t);	}
					
					friend const_iterator operator+=(int t ,const_iterator n)  
					{	return (n += t);	}
					
					friend const_iterator operator-=(int t ,const_iterator n) 
					{	return (n -= t);	}
					
					friend bool operator!=(const iterator b, const const_iterator& it) 
					{	return (b._ptr != it._ptr);	}
					
					friend bool operator==(const iterator b, const const_iterator& it) 
					{	return (b._ptr == it._ptr);	}
					
					friend bool operator<(const iterator b, const const_iterator& it) 
					{	return (b._ptr < it._ptr);	}
					
					friend bool operator>(const iterator b, const const_iterator& it) 
					{	return (b._ptr > it._ptr);	}
					
					friend bool operator>=(const iterator b, const const_iterator& it) 
					{	return (b._ptr >= it._ptr);	}
					
					friend bool operator<=(const iterator b, const const_iterator& it) 
					{	return (b._ptr <= it._ptr);	}
			};

			class reverse_iterator
			{
				friend class vector<T, Alloc>;

				private :
					typedef typename std::ptrdiff_t 			difference_type;
					typedef typename vector::value_type 		value_type;
					typedef typename vector::pointer 			pointer;
					typedef typename vector::const_pointer		const_pointer;
					typedef typename vector::reference 			reference;
					typedef typename vector::const_reference 	const_reference;
	
					pointer _ptr;

				public :
					reverse_iterator(pointer ptr) : _ptr(ptr) 
					{	}
					reverse_iterator(iterator t) : _ptr(t._ptr - 1) 
					{	}
					reverse_iterator() : _ptr(0) 
					{	};
					reverse_iterator operator++(int) //i++
					{
						reverse_iterator i(*this);
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
					
					iterator base() const
					{	return iterator(_ptr + 1);	}
					
					const_reference operator*() const
					{	return *(_ptr);	}
					
					pointer operator->() const
					{	return _ptr;	}
					
					bool operator==(const reverse_iterator& it) const
					{	return (_ptr == it._ptr);	}

					bool operator!=(const reverse_iterator& it) const
					{	return (_ptr != it._ptr);	}
					
					reverse_iterator operator+(int n) const
					{	return reverse_iterator(_ptr - n);	}
					
					reverse_iterator &operator+=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}
					
					reverse_iterator operator-(int n) const
					{	return reverse_iterator(_ptr + n);	}
					
					reverse_iterator &operator-=(int n)
					{
						_ptr = _ptr + n;
						return *this;
					}
					
					const_reference operator[](int n) const
					{	return _ptr[-n];	}
					
					bool operator>(reverse_iterator t) const
					{	return (_ptr < t._ptr);	}
					
					bool operator>=(reverse_iterator t) const 
					{	return (_ptr <= t._ptr);	}
					
					bool operator<(reverse_iterator t) const
					{	return (_ptr > t._ptr);	}
					
					bool operator<=(reverse_iterator t) const
					{	return (_ptr >= t._ptr);	}
					
					friend reverse_iterator operator+(int t ,reverse_iterator n)
					{	return reverse_iterator(n._ptr - t);	}
					
					friend reverse_iterator operator-(int t ,reverse_iterator n)
					{	return reverse_iterator(n._ptr + t);	}
					
					friend reverse_iterator operator+=(int t ,reverse_iterator n)
					{	return (n -= t);	}
					
					friend reverse_iterator operator-=(int t ,reverse_iterator n)
					{	return (n += t);	}
					
					friend bool operator!=(const reverse_iterator b, const const_reverse_iterator& it) 
					{	return (b._ptr != it._ptr);	}
					
					friend bool operator==(const reverse_iterator b, const const_reverse_iterator& it) 
					{	return (b._ptr == it._ptr);	}
					
					friend bool operator<(const reverse_iterator b, const const_reverse_iterator& it) 
					{	return (b._ptr > it._ptr);	}
					
					friend bool operator>(const reverse_iterator b, const const_reverse_iterator& it) 
					{	return (b._ptr < it._ptr);	}
					
					friend bool operator>=(const reverse_iterator b, const const_reverse_iterator& it) 
					{	return (b._ptr <= it._ptr);	}
					
					friend bool operator<=(const reverse_iterator b, const const_reverse_iterator& it) 
					{	return (b._ptr >= it._ptr);	}
			};
			class const_reverse_iterator
			{
				friend class vector<T, Alloc>;
				
				private :

					typedef typename std::ptrdiff_t 			difference_type;
					typedef typename vector::value_type 		value_type;
					typedef typename vector::pointer 			pointer;
					typedef typename vector::const_pointer		const_pointer;
					typedef typename vector::reference 			reference;
					typedef typename vector::const_reference 	const_reference;
					pointer _ptr;
				
				public :

					const_reverse_iterator(T *ptr) : _ptr(ptr) 
					{	}
					const_reverse_iterator() : _ptr(0) 
					{	};
					const_reverse_iterator(reverse_iterator n) : _ptr(n._ptr)
					{	}
					const_reverse_iterator(const_iterator n) : _ptr(n._ptr - 1)
					{	}
					const_reverse_iterator(iterator n) : _ptr(n._ptr - 1)
					{	}
					const_reverse_iterator operator++(int) //i++
					{
						const_reverse_iterator i(*this);
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
					const_iterator base() const
					{
						return const_iterator(_ptr + 1);
					}
					
					const_reference operator*() const
					{	return *(_ptr);	}

					const_pointer operator->() const 
					{	return _ptr;	}
					
					bool operator==(const const_reverse_iterator& it) const
					{	return (_ptr == it._ptr);	}
					
					bool operator!=(const const_reverse_iterator& it) const
					{	return (_ptr != it._ptr);	}

					const_reverse_iterator operator+(int n) const
					{	return const_reverse_iterator(_ptr - n);	}
					
					const_reverse_iterator &operator+=(int n)
					{
						_ptr = _ptr - n;
						return *this;
					}
					
					const_reverse_iterator operator-(int n) const
					{	return const_reverse_iterator(_ptr + n);}
					
					const_reverse_iterator operator-=(int n)
					{
						_ptr = _ptr + n;
						return *this;
					}
					const_reference operator[](int n) const
					{
						return _ptr[-n];
					}
					long int operator-(const_reverse_iterator t) const
					{	return (t._ptr - _ptr);	}
					
					bool operator>(const_reverse_iterator t) const
					{	return (_ptr < t._ptr);	}
					
					bool operator>=(const_reverse_iterator t) const 
					{	return (_ptr <= t._ptr);	}
					
					bool operator<(const_reverse_iterator t) const
					{	return (_ptr > t._ptr);	}
					
					bool operator<=(const_reverse_iterator t) const
					{	return (_ptr >= t._ptr);	}
			};

			iterator begin() 
			{	return iterator(_arr);	}

			const_iterator begin() const 
			{	return const_iterator(_arr);	}
			
			reverse_iterator rbegin() 
			{	return reverse_iterator(&(_arr[_size - 1]));	}

			const_reverse_iterator rbegin() const 
			{	return const_reverse_iterator(&(_arr[_size - 1]));	}

			iterator end() 
			{	return (iterator(&(_arr[_size])));	}

			const_iterator end() const 
			{	return (const_iterator(&(_arr[_size])));	}
			
			reverse_iterator rend() 
			{	return (reverse_iterator(_arr - 1));	}
			
			const_reverse_iterator rend() const 
			{	return (const_reverse_iterator(_arr - 1));	}

			void clear(void)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_arr[i]));
				_size = 0;
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			
			template <class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type start, InputIterator end)
			{
				clear();
				while (start != end)
					push_back(*(start++));
			}

			void push_back (const value_type& val)
			{
				if (_size + 1 >= _max_size)
					growarr(_max_size * 2);
				_alloc.construct(&(_arr[_size]), val);
				// _arr[_size] = val;
				++_size;
			}

			void pop_back(void)
			{
				if (_size)
					_alloc.destroy(&(_arr[_size--]));
			}

			void resize (size_type n, value_type val = value_type())
			{
				while (n < _size)
					pop_back();
				while (n > _size)
					push_back(val);
			}

			void reserve(size_type n)
			{
				if (n <= _max_size)
					return;
				growarr(n);
			}

			const_reference front(void) const
			{	return _arr[0];	}

			reference front(void)
			{	return _arr[0];	}

			const_reference back(void) const
			{	return _arr[_size - 1];	}

			reference back(void)
			{	return _arr[_size - 1];	}

			reference at(int a)
			{
				if (a >= static_cast<int>(_size) || a < 0)
					throw std::out_of_range("at is fucked up yoo");
				return _arr[a];
			}

			const_reference at(int a) const
			{	
				if (a >= static_cast<int>(_size) || a < 0)
					throw std::out_of_range("at is fucked up yoo");
				return _arr[a];
			}

			size_type size(void) const
			{	return _size;	}

			size_type capacity(void) const
			{	return _max_size;	}

			size_type max_size(void) const
			{	return _alloc.max_size();	}

			bool empty(void) const
			{	return (_size == 0);	}

			void swap (vector& x)
			{
				pointer ptr = _arr;
				allocator_type a = _alloc;
				size_t tmp = _max_size;
				_arr = x._arr;
				x._arr = ptr;
				_max_size = x._max_size;
				x._max_size = tmp;
				tmp = _size;
				_size = x._size;
				x._size = tmp;
				_alloc = x._alloc;
				x._alloc = a;
			}

			reference operator[](size_type n)
			{	return _arr[n];	}

			const_reference operator[](size_type n) const
			{	return _arr[n];	}
			
			template<class IT>
			IT insert (IT position, const value_type& val)
			{
				size_type delta = position._ptr - _arr;
				if(_size + 1 >= _max_size)
				{
					growarr(_max_size * 2);
					position = IT(_arr + delta);
				}
				for (size_type i = _size; i > delta ; i--)
					_arr[i] = _arr[i - 1];
				*position = val;
				++_size;
				return IT(position);
			}

			template<class IT>
			void insert (IT position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i < n; i++)
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
				size_type delta = &(*end) - &(*start);
				if (delta < 0)
				{
					tmp = end;
					end = start;
					start = tmp;
				}
				tmp = start;
				for(size_type i = 0; i < delta; i++)
					start = erase(start);
				return tmp;
			}
	};

	template <class T>
	void swap(vector<T> &x, vector<T> &y)
	{	x.swap(y);	};

	template <class T>
	bool operator==(const vector<T> &lhs, const vector<T> &rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename vector<T>::const_iterator lit = (lhs.begin());
			typename vector<T>::const_iterator rit = (rhs.begin());
			while (lit != lhs.end())
			{
				if (*lit != *rit)
					return false;
				++lit;
				++rit;
			}
			return true;
		}
		return false;
	};

	template <class T>
	bool operator!=(const vector<T> &lhs, const vector<T> &rhs)
	{	return !(lhs == rhs);	};

	template <class T>
	bool operator<(const vector<T> &lhs, const vector<T> &rhs)
	{
		typename vector<T>::const_iterator lit = lhs.begin();
		typename vector<T>::const_iterator rit = rhs.begin();
		while (lit != lhs.end())
		{
			if (rit == rhs.end() || *rit < *lit)
				return false;
			else if (*lit < *rit)
				return true;
			++lit;++rit;
		}
		return (rit != rhs.end());
	};

	template <class T>
	bool operator<=(const vector<T> &lhs, const vector<T> &rhs)
	{	return !(rhs < lhs);	};

	template <class T>
	bool operator>(const vector<T> &lhs, const vector<T> &rhs)
	{	return rhs < lhs;	};

	template <class T>
	bool operator>=(const vector<T> &lhs, const vector<T> &rhs)
	{	return !(lhs < rhs);	};
}

#endif