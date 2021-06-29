/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/29 16:52:01 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include "../incl/vector.hpp"
#include "../incl/stack.hpp"

#include <vector>

#include <list>

// struct test
// {
// 	int a;
// 	int b;
// };
template <class T>
void print2(ft::list<T> &base, ft::list<T> &custom)
{

	std::cout << "base : " << std::endl;
	for(ft::list<int>::iterator i = base.begin(); i != base.end(); i++)
		std::cout << *i << "|";
	std::cout << "\n---------------------------------------\n";
	std::cout << "custom : " << std::endl;
	for(ft::list<int>::iterator i = custom.begin(); i != custom.end(); i++)
		std::cout << *i << "|";
	std::cout << std::endl;
}
template <class IT>
void printl(IT begin, IT end)
{
	std::string line;
	while (begin != end)
	{
		std::cout << *(begin++)<< " ";
		// std::cin >> line;	
	}
	std::cout << std::endl;
}

void whathefuck()
{
	ft::list<int> custom;
	std::list<int> base;

	for (int i = 0; i < 20; i++)
	{
		custom.push_back(i);
		base.push_back(i);
	}

	ft::list<int>::const_iterator cci = custom.begin();
	std::list<int>::const_iterator bci = base.begin();

	while (cci != custom.end())
	{
		std::cout << *(cci++) << std::endl;
		// *cci = -(*cci);
	}

	while (bci != base.end())
	{
		std::cout << *(bci++) << std::endl;
		// *bci = -(*bci);
	}

}

int main()
{

	// whathefuck();
	
	// ft::stack<int> st1;
	// ft::stack<int> st2;


	ft::list<int> list;
	std::list<int> base_list;

	for (int i  = 0 ; i < 20; i++)
	{
		list.push_back(i);
		base_list.push_back(i);

	}

	ft::vector<int> test;//(list.begin(), list.end());
	std::vector<int> base;//(base_list.begin(), base_list.end());

	test.assign(list.begin(), list.end());
	base.assign(base_list.begin(), base_list.end());
	// ft::vector<int>::reverse_iterator itt = test.rbegin();

	// std::vector<int>::reverse_iterator bitt = base.rbegin();
	std::cout << "Custom :\n";
	for (ft::vector<int>::const_reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;

	std::cout << "Base :\n";
	for (std::vector<int>::const_reverse_iterator it = base.rbegin(); it != base.rend(); it++)
		std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;













	return 0;
}