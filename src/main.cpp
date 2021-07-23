/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/23 19:53:41 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include "../incl/vector.hpp"
#include "../incl/stack.hpp"
#include "../incl/map.hpp"

#include <map>
#include <vector>
#include <stack>
#include <list>
#include <string>

int main()
{
	ft::map<int, char> custom;
	std::map<int, char> base;

	for (int i = 1; i < 10; i++)
	{
		custom.insert(ft::make_pair(i, static_cast<char> (i)));
		base.insert(std::pair<int, char>(i, static_cast<char> (i)));
	}

	ft::map<int, char>::iterator cit = custom.begin();
	std::map<int, char>::iterator bit = base.begin();

	while (cit != custom.end())
	{
		std::cout << (cit++)->first << "|";
	}
	std::cout << std::endl;

	while (bit != base.end())
	{
		std::cout << (bit++)->first << "|";
	}
	std::cout << std::endl;

	bit = base.begin();
	cit = custom.begin();

	++cit;++cit;
	++bit;++bit;

	ft::map<int, char>::reverse_iterator rcit(cit);// = custom.begin();
	std::map<int, char>::reverse_iterator rbit(bit);// = base.begin();





	std::cout << (rcit)->first << std::endl;
	std::cout << (rbit)->first << std::endl;

	std::cout << (cit2)->first << std::endl;
	std::cout << (bit2)->first << std::endl;


	// std::cout << (rcit.base())->first << std::endl;
	// if (rcit.base() == custom.end())
	// {
	// 	std::cout << "based\n";
	// }
	// if (rbit.base() == base.end())
	// {
	// 	std::cout << "based\n";
	// }
	// std::cout << (rbit.base())->first << std::endl;

	return 0;
}