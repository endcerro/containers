/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/05/26 17:09:09 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include <list>

// struct test
// {
// 	int a;
// 	int b;
// };

int main()
{
	// i++
	std::cout << "------------------------------------------" << std::endl;
	// ++i
	// ft::list<int> t ;
	// std::list<int> l;
	// for(int i = 0; i < 10; i++)
	// {
	// 	l.push_back(i);
	// 	// t.push_back(i);
	// }
	

	// // ft::list<int>::iterator ti = t.begin();
	// std::list<int>::iterator li = l.begin();
	

	// // ft::list<int>::iterator ti2 = t.begin();
	// std::list<int>::iterator li2 = l.begin();

	std::list<int> base;
	ft::list<int> custom;

	// printf("%p %p\n", base.begin(), base.end());
	// std::cout << base.begin() << " "<< base.end() << "|";	
	// std::cout << custom.begin() << " "<< custom.end() << "|";	

	// custom.push_front(1);
	// base.push_front(1);
	// base.push_back(10);
	// custom.push_back(10);
	// custom.push_front(11);
	base.push_front(11);
	// custom.push_back(11);

	std::cout << *(--base.end()) << std::endl;
	// custom.print(custom.begin(), custom.end());
	// base.push_back(10);
	// custom.push_back(10);

	// custom.push_back(4);
	// base.push_back(4);

	// custom.push_back(42);
	// base.push_back(42);

	// base.push_front(11);
	// custom.push_front(11);
	
	// base.push_front(12);
	// custom.push_front(12);

	// base.push_front(13);
	// custom.push_front(13);

	// base.insert(++base.begin(), 850);
	// custom.insert(++custom.begin(), 850);

	// for(ft::list<int>::iterator i = custom.begin(); i != custom.end(); i++)
	// {
	// 	// std::cout << "loop" << std::endl;
	// 	std::cout << *i << "|";
	// }
	// std::cout << "\n---------------------------------------\n";
	for(std::list<int>::iterator i = base.begin(); i != base.end(); i++)
		std::cout << *i << "|";
	// std::cout << "\n";

	// ti2++;
	// ti2++;
	// ti2++;
	// ti++;		
	// ti2++;
	
	// ti2++; li2++;
	// ti2++; li2++;
	// ti2++; li2++;
	// ti2++; li2++;

	// li++; ti++;
	// ti++;
	// std::list<int> test;// = l;
	// test.push_back(42);
	// test.insert(test.begin(), l.begin(), l.end());
	// t.push_back(42);
	
	// t.insert(t.begin(), l.begin(), l.end());
	// // test.insert(ti, l.begin(), l.end());

	// // li = l.erase(li, li2);
	// // ti = t.erase(++ti);
	// // li = l.erase(++li);
	// // t.print(t.begin(), t.end());

	// std::cout << "TI :" << *ti << "\n";
	// std::cout << "li :" << *li << "\n";
	// std::cout << std::endl;
	// for(std::list<int>::iterator i = l.begin(); i != l.end(); i++)
	// {
	// 	std::cout << *i << "|";//<< std::endl;
	// }
	// std::cout << std::endl;

	// ft::list<int>::iterator e = t.end();
	// // t.print(t.begin(), t.end());
	// while (s != e)
	// {
	// 	std::cout << *s << std::endl;
	// 	++s;
	// }
	// std::list<int> u;
	
	// u.push_back(5);
	// u.push_back(6);
	// u.push_back(7);
	// u.push_back(8);
	// std::list<int>::iterator ui = u.begin();
	
	// u.erase(ui);


	// std::cout << "UI :" << *ui << "\n";
	
	

	// // ft::ft_list<int> (t);
	// // u.print();
	// // ft::ft_list<int> v = t;
	// // t.print();
	// // ft::ft_list<int>::reverse_iterator rev = t.rbegin();
	// // ++rev;
	// // ++rev;	
	
	// // ++rev;
	// // t.erase(rev);
	// std::cout << "T B4--------------------------------\n";
	// t.print(t.begin(), t.end());
	// std::cout << "U B4--------------------------------\n";
	// u.print(u.begin(), u.end());
	
	// t.swap(u);

	// std::cout << "T AF--------------------------------\n";
	// t.print(t.begin(), t.end());
	// std::cout << "U AF--------------------------------\n";
	// u.print(u.begin(), u.end());

	// t.print(t.rbegin(), t.rend());
	// t.rprint();

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