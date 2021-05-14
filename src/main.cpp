/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/14 14:29:33 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_list.hpp"
#include <list>

// struct test
// {
// 	int a;
// 	int b;
// };

int main()
{
	// i++
	// ++i
	ft::ft_list<int> t;
	// test a;
	// a.a = 2;
	// a.b = 3;
	// test c;
	// c.a = 4;
	// c.b = 5;
	t.push_back(1);
	t.push_back(2);
	t.push_back(3);
	t.push_back(4);

	// ft::ft_list<int> u(t);
	// u.print();
	// ft::ft_list<int> v = t;
	// t.print();
	ft::ft_list<int>::reverse_iterator rev = t.rbegin();
	++rev;
	++rev;	
	
	++rev;
	t.erase(rev);
	t.print();
	std::cout << "--------------------------------\n";
	t.rprint();
	// t.erase(t.end());
	// v.print();
	// v.push_back(420);
	// v.push_back(69);
	// t.push_front(800);
	// // // t.print();
	// std::cout << t.size() << std::endl;
	// std::cout << t.front() << std::endl;
	// std::cout << t.back() << std::endl;
	// // // t.pop_front()
	// std::cout << t.size() << std::endl;	
	// t.print();
	// // t.emplace_front("X1");
	// std::cout << t.size() << std::endl;	
	// t.print();
	// t.clear();
	// std::cout << t.size() << std::endl;	

	// std::cout << t.back() << std::endl;
	// ft::ft_list<int>::iterator i = t.begin();
	// std::cout << "Forwad iterator" << std::endl;
	// for(ft::ft_list<int>::iterator i = t.begin(); i != t.end(); i++)
 //    {
 //        std::cout << *i << "\n"; //<< i->b << "\n";
 //    }
    // std::cout << "Reverse iterator" << std::endl;
    // // a = b


    // t = v;
    // for(ft::ft_list<int>::iterator j = t.begin(); j != t.end(); j++)
    // {
    //     std::cout << *j << "\n";
    // }

	// ft::ft_list<int> y;
	// y.push_back(420);
	// y.push_back(69420);
	// y.push_back(777);

	// ft::ft_list<int> s;
	// // s.push_back(1);
	// // s.push_back(2);
	// s.assign(t.begin(), t.end());
	// // s.print();
	// s.assign(10, 420);
	// s.print();
	// // std::cout << t.front() <<"\n";
	// std::cout << t.back() <<"\n";
	// s.print();
	// s.assign(1, 2);
	// s.print();
	// for(ft::ft_list<int>::iterator i = s.begin(); i != s.end(); i++)
 //    {
 //        std::cout << *i << "\n"; //<< i->b << "\n";
 //    }

	return 0;
}