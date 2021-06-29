/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/29 22:56:05 by edal--ce         ###   ########.fr       */
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

	for (int i  = 0 ; i < 10; i++)
	{
		list.push_back(i);
		base_list.push_back(-i);

	}

	ft::vector<int> test;//(list.begin(), list.end());
	std::vector<int> base;//(base_list.begin(), base_list.end());

	test.assign(list.begin(), list.end());
	// base.assign(base_list.begin(), base_list.end());
	// ft::vector<int>::reverse_iterator itt = test.rbegin();
	test.push_back(42);
	// std::vector<int>::reverse_iterator bitt = base.rbegin();
	// std::cout << "Custom :\n";
	// for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
	// 	std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;

	// std::cout << "Base :\n";
	// for (std::vector<int>::iterator it = base.begin(); it != base.end(); it++)
	// 	std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;




	ft::vector<int>::iterator opt = test.begin();
	std::vector<int>::iterator bopt = base.begin();

	// bopt = base.insert(bopt + 4 , 420);
	// base.insert(bopt + 4, 5, 69);
		// test.reserve(80);
	
	// opt = test.insert(opt, 68);
	// opt = test.insert(opt, 67);
	// opt = test.insert(opt, 66);
	// opt = test.insert(opt, 65);
	// std::cout << test.capacity() << "\n OPT = " << *opt <<  std::endl;

	// test.insert(opt, 65);

	// test.insert(opt, 5, 69);
	std::cout << "Custom :\n";
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;
	test.insert(test.end() ,12, 850);
	test.insert(test.begin(), base_list.begin(), base_list.end());
	// test.dec_one(test.end());
	// test.dec_one(test.begin());
	// test.dec_one(test.begin());
	// test.dec_one(test.begin());
	// test.dec_one(test.begin());
	std::cout << "Custom :\n";
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;
	// std::cout << "Base :\n";
	// for (std::vector<int>::iterator it = base.begin(); it != base.end(); it++)
	// 	std::cout << *(it) << " @: "<< &(*(it)) <<std::endl;
	// // int amt = 18;
	// std::cout << *(opt += amt) << std::endl;
	// std::cout << *(bopt += amt) << std::endl;

	// std::cout << *(opt -= 8) << std::endl;
	// std::cout << *(bopt -= 8) << std::endl;


	// std::cout << *(opt += 1) << std::endl;
	// std::cout << *(bopt += 1) << std::endl;






	return 0;
}