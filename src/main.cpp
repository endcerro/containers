/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/17 16:43:34 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include "../incl/vector.hpp"

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
		std::list<int> list1, list2;
		std::list<int>::iterator lit;
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
		{
			list1.push_back(i);
			mylist1.push_back(i);      // mylist1: 1 2 3 4
		}

		for (int i=1; i<=3; ++i)
		{
			list2.push_back(i*10);
			mylist2.push_back(i*10);   // mylist2: 10 20 30
		}
		lit = list1.begin();
		it = mylist1.begin();
		++it;                         // points to 2
		++lit;

		std::cout << "B4 list1 contains:";
		for (lit=list1.begin(); lit!=list1.end(); ++lit)
			std::cout << ' ' << *lit;
		
		std::cout << "\nB4 mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;



		it = mylist1.begin();
		lit = list1.begin();
		++it; ++it; ++it;
		++lit; ++lit; ++lit;

		// advance(it,3);           // "it" points now to 30
		// advance(lit, 3);
		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		list1.splice ( list1.begin(), list1, lit, list1.end());
		
										// mylist1: 30 3 4 1 10 20
		std::cout << "\nAF list1 contains:";
		for (lit=list1.begin(); lit!=list1.end(); ++lit)
			std::cout << ' ' << *lit;


		std::cout << "\nAF mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
}

int main()
{



	ft::vector<int> test;

	test[0] = 42;
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << test[i] << std::endl;	
	}
	
	// std::cout << test[1] << std::endl;
	// std::cout << test[1] << std::endl;














	return 0;
}