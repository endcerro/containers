/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/12 17:11:39 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.hpp"
#include <list>
int main()
{
	ft::ft_list<std::string> t;
	t.push_back("haha");
	t.push_back("Sample");
	t.push_front("I'll be first ty");
	// t.print();
	// std::cout << t.size() << std::endl;
	// std::cout << t.front() << std::endl;
	// std::cout << t.back() << std::endl;
	// t.pop_front()
	std::cout << t.size() << std::endl;	
	t.print();
	// t.emplace_front("X1");
	std::cout << t.size() << std::endl;	
	t.print();
	t.clear();
	std::cout << t.size() << std::endl;	

	// std::cout << t.back() << std::endl;



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