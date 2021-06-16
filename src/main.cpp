/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/16 11:36:16 by edal--ce         ###   ########.fr       */
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
template <typename T>
void test(T &c1)
{
	c1.unique(ft::binaryPredicateTest<typename T::value_type>);
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
	// i++
	std::cout << "------------------------------------------" << std::endl;

	ft::list<int> 	c1;
	ft::list<int> 	c2;
	std::list<int> 	b1;
	std::list<int> 	b2;

	for (int i = 1; i <= 10; i++)
	{
		if (i % 2)
		{
			c1.push_back(i * 2);
			c2.push_back(-i * 2);
			b1.push_back( i * 2);
			b2.push_back(-i * 2);
		}
		else
		{
			c1.push_back(i);
			c2.push_back(-i);
			b1.push_back(i);
			b2.push_back(-i);	
		}
		// c1.push_back(i);
		// c2.push_back(-i);
		// b1.push_back(i);
		// b2.push_back(-i);
	}
	// printl(c1.begin(), c1.end());
	// printl(c2.begin(), c2.end());
	// printl(b1.begin(), b1.end());
	// printl(b2.begin(), b2.end());

	// b1.splice(b1.begin(), b2);
	// c1.splice(c1.begin(), c2);
	// std::cout << "SPLICE\n----------------------------------\n";
	// printl(c1.rbegin(), c1.rend());
	// printl(c2.rbegin(), c2.rend());
	
	// printl(b1.rbegin(), b1.rend());
	// printl(b2.rbegin(), b2.rend());
	// c2.clear();
	// b2.clear();
	// c2.assign(5, 420);
	// b2.assign(5, 420);

	// printl(c1.rbegin(), c1.rend());
	// printl(c2.rbegin(), c2.rend());
	
	// printl(b1.rbegin(), b1.rend());
	// printl(b2.rbegin(), b2.rend());

	// b1.splice(b1.begin(), b2);//, b2.begin(), (++b2.begin()));
	// c1.splice(c1.begin(), c2, ++c2.begin());

	// printl(c1.begin(), c1.end());
	// printl(c2.begin(), c2.end());

	// c1.remove(800);
	// printl(c1.begin(), c1.end());
	// c1.remove(7);
	c1.sort();
	// b1.sort();
	// printl(c1.begin(), c1.end());
	// c1.reverse();
	ft::list<int>::iterator spot = c1.begin();
	ft::list<int>::iterator bpot = c2.begin();

	spot++; bpot++;
	spot++; bpot++;
		
	// printl(c2.begin(), c2.end());
	// printl(c1.begin(), c1.end());

	// std::cout << "Custom : " << *spot << std::endl;
	// std::cout << "Base : " << *bpot << std::endl;
	
	// spot = c1.erase(spot);
	// // bpot = b1.erase(bpot);

	// std::cout << "Custom : " << *spot << std::endl;
	// std::cout << "Base : " << *bpot << std::endl;

	// // printl(b1.begin(), b1.end());
	// printl(c1.begin(), c1.end());

	// spot = c1.erase(c1.begin(), spot);
	// bpot = b1.erase(b1.begin(), bpot);

	// std::cout << "Custom : " << *spot << std::endl;
	// std::cout << "Base : " << *bpot << std::endl;

	// printl(b1.begin(), b1.end());
	// c1.clear();
	// // c2.clear();
	// // c1.push_back(150);
	// // c1.push_back(2);
	// // c1.push_back(8);
	// // c2.push_back(20);
	// // c2.push_back(12);
	// // c2.push_back(800);
	// // c2.push_back(7);
	// // c2.push_back(1);
	// std::list<int> t1;
	// // std::list<int> t2;
	// t1.push_back(1);
	// t1.push_back(2);
	// t1.push_back(3);
	// t1.push_back(4);
	// c1.push_back(1);
	// c1.push_back(2);
	// c1.push_back(3);

	// printl(c1.begin(), c1.end());
	// printl(t1.begin(), t1.end());

	// t1.splice(t1.begin(), t1, t1.begin(), t1.end());//, t1.begin(), t1.end());
	// // c1.pop_back();
	// // c1.pop_back();
	// // c1.pop_back();
	// // c1.pop_back();
	// // c1.pop_back();
	// std::cout << "Custom : \n";
	// printl(c1.begin(), c1.end());
	// std::cout << "Base : \n";
	// printl(t1.begin(), t1.end());
	// printl(c2.begin(), c2.end());
	// printl(t2.begin(), t2.end());
	// std::cout << c1.size() << std::endl;
	// std::cout << c2.size() << std::endl;
	// std::cout << t1.size() << std::endl;
	// std::cout << t2.size() << std::endl;
	// c1.sort();
	// b1.sort();
	// printl(b1.rbegin(), b1.rend());
	// printl(b2.rbegin(), b2.rend());
	whathefuck();






















	return 0;
}