/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/09 16:14:41 by edal--ce         ###   ########.fr       */
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


void print2(std::vector<int> &base, ft::vector<int> &custom)
{
	std::cout << "Custom 	: ";
	for (ft::vector<int>::iterator it = custom.begin(); it != custom.end(); it++)
		std::cout << *(it) << "|";
	std::cout << std::endl;
	std::cout << "Base 	: ";
	for (std::vector<int>::iterator it = base.begin(); it != base.end(); it++)
		std::cout << *(it) << "|";
	std::cout << std::endl;	
}

int main()
{

	ft::map<int, char> custom;
	std::map<int, char> base;

	custom.insert(5, 'a');
	custom.insert(3, 'b');
	custom.insert(2, 'b');
	// custom.insert(7, 'c');
	// // custom.insert(10, 'c');
	// custom.insert(9, 'd');
	// custom.insert(3, 'e');
	// custom.insert(11, 'f');
	// custom.insert(6, 'f');
	// custom.insert(156, 'b');
	// custom.insert(3, 'y');
	// cuton.insert(std::make_pair(12, 'a'));
	
	// std::cout << custom.count(13) << std::endl;
	// std::cout << custom.count(10) << std::endl;
	std::cout<< "---------------------------------------\n";
	// custom.printtest(custom.groot());
	// ft::Node<int, char> *tmp = ;
	// if (tmp)
	// std::cout << custom.searchNode(5)->data.second << std::endl; 

	ft::map<int, char>::iterator it = custom.begin();


	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << (*it).first << std::endl;
	// ++it;
	// std::cout << &(*it) << std::endl;
	// ++it;
	// std::cout << &(*it) << std::endl;
	// ++it;
	for(ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	{
		std::cout << (*i).first << std::endl;
		// std::cout << (*i).first << std::endl;
	}

	// std::cout << (base[5] = 'k') << std::endl;

	return 0;
}