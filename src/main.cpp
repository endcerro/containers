/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/06/05 18:17:41 by edal--ce         ###   ########.fr       */
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
void print2(std::list<T> &base, ft::list<T> &custom)
{

	std::cout << "base : " << std::endl;
	for(std::list<char>::iterator i = base.begin(); i != base.end(); i++)
		std::cout << *i << "|";
	std::cout << "\n---------------------------------------\n";
	std::cout << "custom : " << std::endl;
	for(ft::list<char>::iterator i = custom.begin(); i != custom.end(); i++)
		std::cout << *i << "|";
	std::cout << std::endl;
}

int test_push()
{
	std::list<int> base;
	ft::list<int> custom;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			base.push_back(i);
			base.push_front(-i);
			custom.push_back(i);
			custom.push_front(-i);
		}
		else
		{
			base.push_front(-i);
			base.push_back(i);
			custom.push_back(i);
			custom.push_front(-i);
		}
	}
	std::list<int>::iterator bi = base.begin();
	ft::list<int>::iterator ci = custom.begin();

	while (bi != base.end())
	{
		std::cout << *(bi++)<< ' '  << std::endl;
	}
	std::cout << std::endl;
	while (ci != custom.end())
	{
		std::cout << *(ci++) << ' ' << std::endl;
	}
	std::cout << std::endl;

	return 0;

}

int main()
{
	// i++
	std::cout << "------------------------------------------" << std::endl;

	std::list<char> base_list;
	// base_list.push_back(69);
	// base_list.push_back(42);
	// // base_list.print();
	// base_list.push_back(777);
	// base_list.print();

	ft::list<char> int_list;
	// int_list.push_back(69);
	// int_list.push_back(42);
	// // int_list.print();
	// int_list.push_front(666);
	// int_list.push_back(777);
	// int_list.print();
	// int_list.pop_front();
	// int_list.print();
	// int_list.push_front(111);
	// int_list.push_back(222);
	// 	// int_list.pop_back();
	// int_list.print();
	// int_list.pop_front();
	// int_list.print();
	// int_list.push_front(333);
	// int_list.push_back(444);
	// int_list.print();
	// std::cout << "Pop back" << std::endl;
	// int_list.pop_back();
	// int_list.print();
	// int_list.push_front(555);
	// int_list.push_back(888);
	// int_list.print();

 // = int_list.begin();
	// int_iterator++;
	ft::list<char> char_list;
	// char_list.push_back();
	char_list.push_back('e');
	char_list.push_back('f');
	char_list.push_back('g');
	char_list.push_back('h');

	int_list.push_back('a');
	int_list.push_back('b');
	int_list.push_back('c');
	int_list.push_back('d');
	std::list<char> test;
	// test.insert(test.begin(), int_list.begin(), int_list.end());
	test.push_back('w');
	test.push_back('x');
	test.push_back('y');
	test.push_back('z');

	// ft::list<char>::reverse_iterator int_iterator = int_list.rbegin();
	// std::list<char>::reverse_iterator base_iterator = test.rbegin();
	// int_list.print();
	// char_list.print();
	int_list.swap(char_list);
	// int_list.print();
	// char_list.print();
	
	char_list.clear();
	// test.clear();
	char_list.push_back(4);
	// test.push_back(4);
	char_list.pop_front();

	std::cout << char_list.empty() <<'\n';
	std::cout << test.empty() <<'\n';
	char_list.clear();
	test.clear();
	std::list<char> demo;
	demo.push_back('a');
	demo.push_back('b');
	demo.push_back('c');


	char_list.push_front('c');
	char_list.push_back('d');

	test.push_front('c');
	test.push_back('d');

	char_list.insert(char_list.begin(), demo.begin(), demo.end());
	test.insert(test.begin(),demo.begin(), demo.end());




	// print2(test, char_list);

	ft::list<char>::iterator var = char_list.begin();
	std::list<char>::iterator var2 = test.begin();
	++var;
	++var2;
	++var;
	++var2;
	++var;
	++var2;

	char_list.erase(char_list.begin(), var);
	test.erase(test.begin(), var2);

	print2(test, char_list);

	ft::list<int> nocrash;
	ft::list<int> crash(4,2);
	nocrash.print();
	crash.print();

	return 0;
}