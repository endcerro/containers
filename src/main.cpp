/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/13 17:53:26 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.hpp"
#include <list>

struct test
{
	int a;
	int b;
};

int main()
{
	// i++
	// ++i
	ft::ft_list<test> t;
	test a;
	a.a = 2;
	a.b = 3;
	test c;
	c.a = 4;
	c.b = 5;
	t.push_back(a);
	t.push_back(c);
	// t.push_front(800);
	// // t.print();
	// // std::cout << t.size() << std::endl;
	// // std::cout << t.front() << std::endl;
	// // std::cout << t.back() << std::endl;
	// // t.pop_front()
	// std::cout << t.size() << std::endl;	
	// t.print();
	// // t.emplace_front("X1");
	// std::cout << t.size() << std::endl;	
	// t.print();
	// t.clear();
	// std::cout << t.size() << std::endl;	

	// std::cout << t.back() << std::endl;
	// ft::ft_list<int>::iterator i = t.begin();
	std::cout << "Forwad iterator" << std::endl;
	for(ft::ft_list<test>::iterator i = t.begin(); i != t.end(); i++)
    {
        std::cout << i->a <<" "<< i->b << "\n";
    }
    std::cout << "Reverse iterator" << std::endl;
    for(ft::ft_list<test>::reverse_iterator j = t.rbegin(); j != t.rend(); j++)
    {
        std::cout << j->a <<" "<< j->b << "\n";
    }

	// std::list<std::string> s;
	// s.push_back("haha");
	// s.push_back("Sample");
	// s.push_front("I'll be first ty");
	// // s.print();
	// std::cout << s.size() << std::endl;
	// std::cout << s.front() << std::endl;
	// std::cout << s.back() << std::endl;
	// s.pop_back();
	// std::cout << s.back() << std::endl;
	return 0;
}