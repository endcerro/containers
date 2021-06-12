/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/12 16:20:49 by edal--ce         ###   ########.fr       */
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
	b1.sort();
	// printl(c1.begin(), c1.end());
	// c1.reverse();
	ft::list<int>::iterator spot = c1.begin();
	std::list<int>::iterator bpot = b1.begin();

	spot++; bpot++;
	spot++; bpot++;
		
	printl(b1.begin(), b1.end());
	printl(c1.begin(), c1.end());

	std::cout << "Custom : " << *spot << std::endl;
	std::cout << "Base : " << *bpot << std::endl;
	
	spot = c1.erase(spot);
	bpot = b1.erase(bpot);

	std::cout << "Custom : " << *spot << std::endl;
	std::cout << "Base : " << *bpot << std::endl;

	printl(b1.begin(), b1.end());
	printl(c1.begin(), c1.end());

	spot = c1.erase(c1.begin(), spot);
	bpot = b1.erase(b1.begin(), bpot);

	std::cout << "Custom : " << *spot << std::endl;
	std::cout << "Base : " << *bpot << std::endl;

	printl(b1.begin(), b1.end());
	printl(c1.begin(), c1.end());
	// printl(b1.rbegin(), b1.rend());
	// printl(b2.rbegin(), b2.rend());























	return 0;
}