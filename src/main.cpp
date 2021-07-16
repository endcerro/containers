/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/16 19:14:26 by edal--ce         ###   ########.fr       */
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


// void print2(std::vector<int> &base, ft::vector<int> &custom)
// {
// 	std::cout << "Custom 	: ";
// 	for (ft::vector<int>::iterator it = custom.begin(); it != custom.end(); it++)
// 		std::cout << *(it) << "|";
// 	std::cout << std::endl;
// 	std::cout << "Base 	: ";
// 	for (std::vector<int>::iterator it = base.begin(); it != base.end(); it++)
// 		std::cout << *(it) << "|";
// 	std::cout << std::endl;	
// }
// #define T1 char
// #define T2 int
// typedef ft::pair<const T1, T2> T3;
// void bug()
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 7;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3('a' + i, lst_size - i));

// 	ft::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
// 	ft::map<T1, T2>::iterator it;

// 	lst.clear();
// 	// is_empty(mp);
// 	// printSize(mp);

// 	// is_empty(mp2);
// 	mp2 = mp;
// 	// is_empty(mp2);

// 	it = mp.begin();
// 	for (unsigned long int i = 3; i < mp.size(); ++i)
// 		it++->second = i * 7;

// 	// printSize(mp);
// 	// printSize(mp2);

// 	mp2.clear();
// 	// is_empty(mp2);
// 	// printSize(mp2);
// }

void pret(ft::pair<ft::map<int, char>::iterator, bool> ret)
{
	std::cout << "ID =" << (ret.first)->first << "|" << ret.second << std::endl;
}

// #define T1 int
// #define T2 int
// typedef _pair<const T1, T2> T3;
template<class T, class IT>
void	ft_comp(const T &mp, const IT &it1, const IT &it2, unsigned int &i)
{

	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}

void test()
{
	std::list<ft::pair<char, int> > lst;
	

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::pair<char, int>('a' + i, lst_size - i));

	ft::map<char, int> mp(lst.begin(), lst.end()), mp2;
	ft::map<char, int>::iterator it;

	lst.clear();
	is_empty(mp);
	// printSize(mp);

	is_empty(mp2);
	mp2 = mp;
	is_empty(mp2);

	it = mp.begin();
	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	// printSize(mp);
	// printSize(mp2);

	mp2.clear();
	is_empty(mp2);
	// printSize(mp2);
}


int main()
{

	// bug();
	// return 0;

	ft::map<int, char> custom;
	std::map<int, char> base;

	test();
	// std::cout << custom.groot() << std::endl;
	// custom[0] = 'a';
	// std::cout << custom[0] << std::endl;
	// custom.printtest(custom.groot());
	// // // custom.printtest(custom.groot());
	// // custom.insert(5, 'b');

	
	// // std::cout << "\n\n";
	// // custom.insert(10, 'b');
		
	// int ssize = 0;

	// // pret(custom.insert(ft::pair<int, char>(240, 'b')));
	// pret(custom.insert(ft::pair<int, char>(10, 'b')));
	// pret(custom.insert(ft::pair<int, char>(15, 'b')));
	

	// pret(custom.insert(ft::pair<int, char>(20, 'C')));
	// pret(custom.insert(ft::pair<int, char>(500, 'a')));
	custom.insert(ft::pair<int, char>(15, 'b'));
	custom.insert(ft::pair<int, char>(10, 'b'));
	custom.insert(ft::pair<int, char>(20, 'b'));	
	custom.insert(ft::pair<int, char>(520, 'a'));
	custom.insert(ft::pair<int, char>(540, 'a'));
	custom.insert(ft::pair<int, char>(420, 'a'));
	custom.insert(ft::pair<int, char>(690, 'a'));
	custom.insert(ft::pair<int, char>(693, 'a'));
	custom.insert(ft::pair<int, char>(692, 'a'));
	custom.insert(ft::pair<int, char>(0, 'a'));


	base.insert(std::pair<int, char>(15, 'b'));
	base.insert(std::pair<int, char>(10, 'b'));
	base.insert(std::pair<int, char>(20, 'b'));	
	base.insert(std::pair<int, char>(520, 'a'));
	base.insert(std::pair<int, char>(540, 'a'));
	base.insert(std::pair<int, char>(420, 'a'));
	base.insert(std::pair<int, char>(690, 'a'));
	base.insert(std::pair<int, char>(693, 'a'));
	base.insert(std::pair<int, char>(692, 'a'));
	base.insert(std::pair<int, char>(0, 'a'));
	

	// std::cout<<"--------------------------------\n\n";
	
	ft::map<int, char>::iterator cit = custom.begin();
	std::map<int, char>::iterator bit = base.begin();

	
	while (cit != custom.end())
	{
		std::cout << (cit++)->first << "|";
	}
	std::cout << std::endl;
	while (bit != base.end())
	{
		std::cout << (bit++)->first << "|";
	}
	std::cout << std::endl;

	// // custom.printnode(custom.gend()->right);
	// // custom.printnode(cit.getNode()->right);
	

	// std::cout << std::endl;
	// // std::cout << (--cit)->first << std::endl;
	// // std::cout << (--bit)->first << std::endl;
	while (--cit != custom.begin())
	{
		std::cout << (cit)->first << "|";
	}
	std::cout << std::endl;

	while (--bit != base.begin())
	{
		std::cout << (bit)->first << "|";
	}
	std::cout << std::endl;
	// std::cout << (cit)->first << std::endl;
	// std::cout << (bit)->first << std::endl;
	// std::cout << bit->first << std::endl;

	// for(ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	// {
	// 	std::cout << i->first << "|"<< i->second<< std::endl;
	// 	// std::cout << (*i).first << std::endl;
	// }
	// for(ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	// {
	// 	std::cout << i->first << "|"<< i->second<< std::endl;
	// 	// std::cout << (*i).first << std::endl;
	// }
	// ft::map<int, char>::iterator test = custom.end();

	// std::cout << "B4 " << test->first << std::endl;
	// --test;
	// std::cout << "AF " <<test->first << std::endl;

	// std::cout << "B4 " << test->first << std::endl;
	// --test;
	// std::cout << "AF " <<test->first << std::endl;
	
	// std::cout << "B4 " << test->first << std::endl;
	// ++test;
	// std::cout << "AF " <<test->first << std::endl;
	// std::cout << "B4 " << test->first << std::endl;
	// ++test;
	// std::cout << "AF " <<test->first << std::endl;
	// std::cout << "B4 " << test->first << std::endl;
	// ++test;
	// std::cout << "AF " <<test->first << std::endl;
	// 	std::cout << "B4 " << test->first << std::endl;
	// ++test;
	// std::cout << "AF " <<test->first << std::endl;


	// ft::map<int, char>::iterator test = custom.begin();
	// std::cout << "Beg is " << test->first << std::endl;
	// ++test; ++test; ++test;
	// std::cout << "+ 3 is " << test->first << std::endl;
	// --test;
	// std::cout << "- 1 is " << test->first << std::endl;
	// // std::cout << (base[5] = 'k') << std::endl;

	return 0;
}