/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/12 18:44:56 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include "../incl/vector.hpp"
#include "../incl/stack.hpp"
#include "../incl/map.hpp"

#include <map>
#include <vector>
#include <stack>
#include <list>


void print2(std::vector<int> &base, ft::vector<int> &custom)
{
	std::cout << "Custom 	: ";
	for (ft::vector<int>::iterator it = custom.begin(); it != custom.end(); it++)
		std::cout << *(it) << "|";
	std::cout << std::endl;
	std::cout << "Base 	: ";
	for (std::vector<int>::iterator it = base.begin(); it != base.end(); it++)
		std::cout << *(it) << "|";
	std::cout << std::endl;	
}
#define T1 char
#define T2 int
typedef ft::pair<const T1, T2> T3;
void bug()
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));

	ft::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
	ft::map<T1, T2>::iterator it;

	lst.clear();
	// is_empty(mp);
	// printSize(mp);

	// is_empty(mp2);
	mp2 = mp;
	// is_empty(mp2);

	it = mp.begin();
	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	// printSize(mp);
	// printSize(mp2);

	mp2.clear();
	// is_empty(mp2);
	// printSize(mp2);
}

void pret(ft::pair<ft::map<int, char>::iterator, bool> ret)
{
	std::cout << "ID =" << (ret.first)->first << "|" << ret.second << std::endl;
}

int main()
{

	// bug();
	// return 0;

	ft::map<int, char> custom;
	std::map<int, char> base;

	// custom.insert(15, 'b');
	// // custom.printtest(custom.groot());
	// custom.insert(5, 'b');

	// custom.printtest(custom.groot());
	// std::cout << "\n\n";
	// custom.insert(10, 'b');
		
	int ssize = 0;

	pret(custom.insert(ft::pair<int, char>(240, 'b')));
	pret(custom.insert(ft::pair<int, char>(10, 'b')));
	pret(custom.insert(ft::pair<int, char>(15, 'b')));
	

	pret(custom.insert(ft::pair<int, char>(20, 'C')));
	pret(custom.insert(ft::pair<int, char>(500, 'a')));
		
	pret(custom.insert(ft::pair<int, char>(520, 'a')));
	pret(custom.insert(ft::pair<int, char>(540, 'a')));
	pret(custom.insert(ft::pair<int, char>(420, 'a')));
	pret(custom.insert(ft::pair<int, char>(690, 'a')));
	pret(custom.insert(ft::pair<int, char>(693, 'a')));
	pret(custom.insert(ft::pair<int, char>(692, 'a')));
	pret(custom.insert(ft::pair<int, char>(0, 'a')));
	pret(custom.insert(ft::pair<int, char>(4, 'b')));
	pret(custom.insert(ft::pair<int, char>(7, 'c')));
	pret(custom.insert(ft::pair<int, char>(9, 'd')));
	pret(custom.insert(ft::pair<int, char>(3, 'e')));
	pret(custom.insert(ft::pair<int, char>(11, 'f')));
	pret(custom.insert(ft::pair<int, char>(6, 'f')));
	pret(custom.insert(ft::pair<int, char>(156, 'b')));
	pret(custom.insert(ft::pair<int, char>(240, 'b')));
	// custom.insert(3, 'y');

	// custom.remove(20);
	// custom.remove(690);
	// cuton.insert(std::make_pair(12, 'a'));
	
	// std::cout << custom.count(13) << std::endl;
	// std::cout << custom.count(10) << std::endl;
	std::cout<< "---------------------------------------\n";
	std::cout << custom.size() << " " << ssize << std::endl;
	// ft::Node<int, char> *tmp = ;
	// if (tmp)
	// std::cout << custom.searchNode(5)->data.second << std::endl; 
	// custom.printsubheight();
	// // ft::map<int, char>::iterator it = custom.begin();
	// custom.printtest(custom.groot());
	
	// for(ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	// {
	// 	std::cout << (*i).first << std::endl;
	// 	// std::cout << (*i).first << std::endl;
	// }
	// // custom.
	// // custom.rotate_right(custom.groot());
	// // custom.printtest(custom.groot());
	// // custom.rotate_left(custom.groot());
	// // custom.printtest(custom.groot());	
	for(ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	{
		std::cout << (*i).first << std::endl;
		// std::cout << (*i).first << std::endl;
	}
	// std::cout << (base[5] = 'k') << std::endl;

	return 0;
}