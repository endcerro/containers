/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/07 14:00:16 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include <list>

// struct test
// {
// 	int a;
// 	int b;
// };
template <class T>
void print2(std::list<T> &base, ft::list<T> &custom)
{

	std::cout << "base : " << std::endl;
	for(std::list<int>::iterator i = base.begin(); i != base.end(); i++)
		std::cout << *i << "|";
	std::cout << "\n---------------------------------------\n";
	std::cout << "custom : " << std::endl;
	for(ft::list<int>::iterator i = custom.begin(); i != custom.end(); i++)
		std::cout << *i << "|";
	std::cout << std::endl;
}

int main()
{
	// i++
	std::cout << "------------------------------------------" << std::endl;

	std::list<int> base_list;
	ft::list<int> 	custom_list;
	for (int i = 0; i < 10; i++)
	{
		base_list.push_back(i);
		custom_list.push_back(i);
	}

	print2(base_list, custom_list);


	std::list<int>::iterator bi = base_list.begin();
	ft::list<int>::iterator bc = custom_list.begin();
		
	bi++;
	bc++;

	bi++;
	bc++;

	bi = base_list.erase(bi);
	bc = custom_list.erase(bc);
	std::cout << *bi << std::endl;
	std::cout << *bc << std::endl;
	print2(base_list, custom_list);



































	return 0;
}