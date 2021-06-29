/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/29 14:37:07 by edal--ce         ###   ########.fr       */
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
	// test.push_back(12);
	// test[1] = 850;
	ft::vector<int> test(list.begin(), list.end());
	std::vector<int> base(base_list.begin(), base_list.end());
	// ft::vector<int> test2(test);
	// test.pop_back();
	// test.pop_back();
	// test.pop_back();
	// test.resize(4);
	// test.resize(10, 8);
	// test.print();

	// test.test();

	// std::cout <<"be/*/*gin : " <<test.begin().getptr() << std::endl;
	// std::cout <<"end :" <<test.end().getptr() << std::endl;*/*/
	
	ft::vector<int>::iterator itt = test.begin();

	while (itt != test.end())
	{
		std::cout << *(itt) << " @: "<< &(*(itt)) <<std::endl;
		++itt;
	}

	std::cout << " @: "<< &(*(itt)) <<std::endl;
	std::vector<int>::iterator b_itt = base.begin();

	while (b_itt != base.end())
	{
		std::cout << *(b_itt) << " @: "<< &(*(b_itt)) <<std::endl;
		++b_itt;
	}

	std::cout << " @: "<< &(*(b_itt)) <<std::endl;



	// test2.print();

	// for (int i = 0; i < st1.size(); i++)
	// {
	// 	std::cout << "kek\n";
	// }











	return 0;
}