/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:38:23 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/12 15:44:30 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://www.cplusplus.com/reference/list/list/

#ifndef FT_LIST
#define FT_LIST

#include <iostream>



namespace ft
{
	template <class T>
	
	class ft_list
	{

		struct Node
		{
			T		d;
			Node	*n;
			Node	*p;
		};

	 	private :
			Node *_h;
			Node *_t;
			size_t _s;

	 	public :
	 		ft_list() : _s(0), _h(0), _t(0)
	 		{
	 			std::cout << "CONSTRUCTOR CALL" << std::endl;
	 		};
			~ft_list()
			{
				std::cout << "DESTRUCTOR CALL" << std::endl;
			};

	 		ft_list& operator=(const ft_list &base){	 		};
				
			size_t empty() 	{			};
			const size_t size() const
			{	
				return _s;
			};
			size_t max_size() 	{			};
		
	};
}
#endif