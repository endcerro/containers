/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:35:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/23 20:04:02 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <new>
#include <string>
#include <iostream>

namespace ft
{

	template <class T>
	struct less
	{
		typedef T first_argument_type;
		typedef T second_argument_type;
		typedef bool result_type;

		bool operator()(const T &x, const T &y) const { return x < y; }
	};
	
	template <class T1, class T2>
	struct pair
	{
		T1 first;
		T2 second;

		pair() : first(), second() {}

		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

		pair(const T1 &a, const T2 &b) : first(a), second(b) {}

		pair &operator=(const pair &pr)
		{

			first = pr.first;
			second = pr.second;
			return *this;
		}

		operator std::pair<T1, T2>()
		{
			return std::pair<T1, T2>(first, second);
		}
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}
	template <typename T1, typename T2, typename U>
	struct binary_function
	{
		typedef T1 first_argument_type;

		typedef T2 second_argument_type;

		typedef U result_type;
	};
	
	template <class T>
	struct Node
	{
		T		*data;
		size_t     size;
		Node	*next;
		Node	*previous;
	};

	template<bool B, class Z = void>
	struct enable_if {};

	template<class Z>
	struct enable_if<true, Z> { typedef Z type; };	
	
	template <class, class = void>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };
	
	template <>
	struct is_integral<wchar_t> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };
	
	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	/*BE CAREFUL WITH THESE */
	template <typename T>
	inline bool binaryPredicateTest(const T& a, const T& b) { return a < b; } // Inline keywork to avoid duplicate symbol error

	template <>
	inline bool binaryPredicateTest<int>(const int& a, const int& b) {
	// std::cout << "PREDICATE : " << a << "<" << b << " = " << (a < b) << std::endl;

	 return a < b; 
	}

	template <>
	inline bool binaryPredicateTest<char>(const char& a,const char& b) { return a < b; }

	template <>
	inline bool binaryPredicateTest<std::string>(const std::string& a, const std::string& b) { return a < b; }
}


#endif