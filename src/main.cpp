/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal <edal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/02 14:29:07 by edal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include <list>

// struct test
// {
// 	int a;
// 	int b;
// };
/*template <class T>
void print2(std::list<T> &base, ft::list<T> &custom)
{

	std::cout << "base : " << std::endl;
	for(std::list<int>::iterator i = base.begin(); i != base.end(); i++)
		std::cout << *i << "|";
	std::cout << "\n---------------------------------------\n";
	std::cout << "custom : " << std::endl;
	// for(ft::list<int>::iterator i = custom.begin(); i != custom.end(); i++)
	// 	std::cout << *i << "|";
	std::cout << std::endl;
}*/

int main()
{
	// i++
	std::cout << "------------------------------------------" << std::endl;

	ft::list<int> int_list;
	int_list.push_back(42);
	int_list.push_back(420);
	int_list.push_front(69);
	int_list.print();
	// std::list<char> char_list;
	// std::list<int> filler;
	// ft::list<int> first;
	// ft::list<int> second (4,42);
	// base.push_front(42);
	// first.push_front(42);
	// // first.push_front(41);
	// print2(base, first);
/*	for (ft::list<int>::iterator i = first.begin(); i != first.end(); i++ )
	{
		std::cout << *i << std::endl;
	}*/

	// std::cout << *first.begin() << std::endl;
	// std::cout << *first.end() << std::endl;
	// first.push_back(24);
	// base.push_front(42);
	// std::cout << *base.begin() << std::endl;
	// std::cout << *base.end() << std::endl;

	// for (int i = 0; i < 10; i++)
	// {
	// 	filler.push_back(i);
	// }
	// // filler.insert(filler.begin(), 5 ,8);
	// base.push_front(10);
	// custom.push_front(10);

	// base.push_back(11);
	// custom.push_back(11);

	// base.push_back(12);
	// custom.push_back(12);



	// base.insert(base.begin(), 50);
	// custom.insert(custom.begin(), 50);

	// base.insert(base.begin(), filler.begin(), filler.end());
	// custom.insert(custom.begin(), filler.begin(), filler.end());
	// // base.insert(base.end(), filler.begin(), filler.end());
	// // custom.insert(custom.end(), filler.begin(), filler.end());

	// print2(base, custom);
	// std::cout << "custom : " << std::endl;
	// for(ft::list<int>::iterator i = custom.begin(); i != custom.end(); i++)
	// 	std::cout << *i << "|";
	// std::cout << "\n---------------------------------------\n";
	// std::cout << "base : " << std::endl;
	// for(std::list<int>::iterator i = base.begin(); i != base.end(); i++)
	// 	std::cout << *i << "|";
	// std::cout << "\n";

	// ti2++;
	// ti2++;
	// ti2++;
	// ti++;		
	// ti2++;
	
	// ti2++; li2++;
	// ti2++; li2++;
	// ti2++; li2++;
/*	ti2++; li2++;

	li++; ti++;
	ti++;
	std::list<int> test;// = l;
	test.push_back(42);
	test.insert(test.begin(), l.begin(), l.end());
	t.push_back(42);*/
	
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