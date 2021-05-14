/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:35:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/14 08:40:22 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP
namespace ft
{
	
	template <class T>
	struct Node
	{
		T		*d;
		Node	*n;
		Node	*p;
	};

	template<bool B, class Z = void>
	struct enable_if {};

	template<class Z>
	struct enable_if<true, Z> { typedef Z type; };	
}


#endif