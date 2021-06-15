/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/15 15:54:42 by edal--ce         ###   ########.fr       */
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
	c1.clear();
	c2.clear();
	c1.push_back(150);
	c1.push_back(2);
	c1.push_back(8);
	c2.push_back(20);
	c2.push_back(12);
	c2.push_back(800);
	c2.push_back(7);
	c2.push_back(1);
	std::list<int> t1;
	std::list<int> t2;
	t1.push_back(150);
	t1.push_back(2);
	t1.push_back(8);
	t2.push_back(20);
	t2.push_back(12);
	t2.push_back(800);
	t2.push_back(7);
	t2.push_back(1);




	
	// printl(c1.begin(), c1.end());
	// printl(t1.begin(), t1.end());
	// printl(c2.begin(), c2.end());
	
	// printl(t2.begin(), t2.end());
	
	// std::cout << c1.size() << std::endl;
	// std::cout << c2.size() << std::endl;
	
	// t1.assign(c1.begin(), c1.end());
	// t2.assign(c2.begin(), c2.end());

	
	// c1.splice(c1.begin(), c2);
	c1.sort(); c2.sort(); t1.sort(); t2.sort();
	printl(c1.begin(), c1.end());
	printl(t1.begin(), t1.end());
	// printl(c2.begin(), c2.end());
	// printl(t2.begin(), t2.end());


	// test<ft::list<int> >(c1);
	// test<ft::list<int> >(c2);
	// test<std::list<int> >(t1);
	// test<std::list<int> >(t2);
	c1.clear();
	t1.clear();
	c1.push_back(7);
	c1.push_back(7);
	c1.push_back(7);
	t1.push_back(7);
	t1.push_back(7);
	t1.push_back(7);

	c1.unique();
	t1.unique();
	// c1.pop_back();
	// c1.pop_back();
	// c1.pop_back();
	// c1.pop_back();
	// c1.pop_back();
	std::cout << "Custom : \n";
	printl(c1.begin(), c1.end());
	std::cout << "Base : \n";
	printl(t1.begin(), t1.end());
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























	return 0;
}