/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:41:19 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/03 16:51:33 by edal--ce         ###   ########.fr       */
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
			// typedef T value_type;
			typedef Container container_type;
			// typedef std::size_t size_type;
		
		private :

			Container _storage;
			// int _capacity;
			// int _size;

		public :
		
			explicit stack(const Container &stor = container_type()) : _storage(stor) {}

			bool empty() const
			{
				return _storage.empty();
			}

			size_t size() const
			{
				return _storage.size();
			}

			T &top()
			{
				return _storage.back();
			}

			const T &top() const
			{
				return _storage.back();
			}

			void push(const T &val)
			{
				_storage.push_back(val);
			}

			void pop()
			{
				_storage.pop_back();
			}

			void print()
			{
				typename Container::iterator test = _storage.begin();
				while (test != _storage.end())
				{
					std::cout << *test++ << std::endl;
				}
			}
		// };
	// };

	// template <class T, class Container>
	// bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	// {
	// 	return lhs._cont == rhs._cont;
	// }

	// template <class T, class Container>
	// bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	// {
	// 	return !(lhs == rhs);
	// }

	// template <class T, class Container>
	// bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	// {
	// 	return lhs._cont < rhs._cont;
	// }

	// template <class T, class Container>
	// bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	// {
	// 	return !(rhs < lhs);
	// }

	// template <class T, class Container>
	// bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	// {
	// 	return rhs < lhs;
	// }

	// template <class T, class Container>
	// bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	// {
	// 	return !(lhs < rhs);
	// }
	};
}


#endif