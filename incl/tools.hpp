/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal <edal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:35:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/02 14:13:14 by edal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP
namespace ft
{
	
	template <class T>
	struct Node
	{
		T		*data;
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
}


#endif