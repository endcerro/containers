/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/23 15:53:58 by edal--ce         ###   ########.fr       */
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
#include <string>


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

// void pret(ft::pair<ft::map<int, char>::iterator, bool> ret)
// {
// 	std::cout << "ID =" << (ret.first)->first << "|" << ret.second << std::endl;
// }



std::string randstr(const size_t n)
{
	std::string ret;
	static const char tab[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	ret.reserve(n);
	for (size_t i = 0; i < n; ++i)
		ret += tab[rand() % 61];
	return ret;
}

// void test()
// {
// 	ft::map<std::string, int> m;

// 	m.insert(ft::make_pair<std::string, int>("D", 42));
// 	m.insert(ft::make_pair<std::string, int>("V", -15));
// 	m.insert(ft::make_pair<std::string, int>("E", 684));
// 	m.insert(ft::make_pair<std::string, int>("A", -43518));
// 	m.insert(ft::make_pair<std::string, int>("B", -4215));
// 	m.insert(ft::make_pair<std::string, int>("Z", 6871));
// 	m.insert(ft::make_pair<std::string, int>("G", 0));
// 	m.insert(ft::make_pair<std::string, int>("R", -15));
// 	m.insert(ft::make_pair<std::string, int>("T", 68768415));
// 	m.insert(ft::make_pair<std::string, int>("U", -144));
// 	m.insert(ft::make_pair<std::string, int>("H", -7852));

// 	ft::map<std::string, int> mbis(m);

// 	ft::map<std::string, int>::iterator it(m.insert(ft::make_pair<std::string, int>("E", 123)).first);
// 	std::cout << (*it).second << std::endl
// 			  << std::endl;

// 	it = m.begin();
// 	while (it != m.end())
// 	{
// 		std::cout << (*it).first << '	' << (*it).second << std::endl;
// 		++it;
// 	}	ft::map<std::string, int>::reverse_iterator rit(m.rbegin());
// 	while (rit != m.rend())
// 	{
// 		std::cout << (*rit).first << '	' << (*rit).second << std::endl;
// 		++rit;
// 	}
// 	for (ft::map<std::string, int>::const_reverse_iterator crit = m.rbegin(); crit != m.rend(); ++crit)
// 		std::cout << (*crit).first << '	' << (*crit).second << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "m size == " << m.size() << std::endl;

// 	mbis.erase(mbis.find("Z"), mbis.end());

// 	mbis.erase(mbis.find("D"), mbis.end());
// 	m.erase(m.find("D"), m.find("Z"));
// 	m.erase(m.find("B"), m.find("V"));
// 	m.erase(m.find("A"), m.find("V"));
// 	m.erase(m.find("Z"));
// 	m.erase(m.find("A"));
// 	m.erase(m.find("G"));
// 	m.erase(m.find("D"), m.find("R"));

// 	std::cout << (*m.upper_bound("T")).first << std::endl;
// 	std::cout << (*m.lower_bound("T")).first << std::endl;
// 	std::cout << std::endl;

// 	m["N"] = 58;
// 	m["N"] = 332;

// 	it = m.end();
// 	while (--it != m.begin())
// 		std::cout << (*it).first << '	' << (*it).second << std::endl;
// 	std::cout << (*it).first << '	' << (*it).second << std::endl;

// 	it = mbis.end();
// 	while (--it != mbis.begin())
// 		std::cout << (*it).first << '	' << (*it).second << std::endl;
// 	std::cout << (*it).first << '	' << (*it).second << std::endl;

// 	std::cout << "m size == " << m.size() << std::endl;

// 	// m.clear();
// 	m.erase(m.begin(), m.end());
// 	std::cout << "m size == " << m.size() << std::endl
// 			  << std::endl;


// 	for (int i = 0; i < 1000; ++i)
// 		m.insert(ft::make_pair<std::string, int>(randstr(rand() % 17 + 1), rand() % 1024));

// 	// NS::map<std::string, int>::const_iterator cit(m.begin());
// 	// while (cit != m.end())
// 	// {
// 	// 	std::cout << (*cit).first << '	' << (*cit).second << std::endl;
// 	// 	++cit;
// 	// }
// 	// std::cout << std::endl;

// }
#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;


static int iter = 0;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		std::cout << "IT ADDR " << &(*it) << std::endl;
		std::cout << "ITE ADDR " << &(*ite) << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	std::cout <<"SIZE IS "<< mp.size() << std::endl;
	printSize(mp);
}

void test()
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	// printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	// printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	// printSize(mp);
	// mp.erase(mp.begin(), mp.end());
	// ft::map<T1, T2>::iterator test = mp.begin();
	
	// while (test != mp.end())
	// {
	// 	std::cout << test->first << std::endl;
	// }	

	// std::cout << test->first << std::endl;
	// std::cout << test->second << std::endl;
	ft_erase(mp, mp.begin(), mp.end());
}

int main()
{

	// vectest();
	test();

	return 0;

	ft::map<int, char> custom;

	std::map<int, char> base;

	// test();
	// return 0;
	// custom[0] = 'a';
	// custom[1] = 'b';
	// custom[2] = 'c';
	// custom[3] = 'd';

	custom.insert(ft::make_pair(5, 'a'));
	
	custom.insert(ft::make_pair(2, 'a'));
	
	custom.insert(ft::make_pair(1, 'a'));
	custom.insert(ft::make_pair(7, 'a'));
	custom.insert(ft::make_pair(8, 'a'));
	custom.insert(ft::make_pair(1, 'a'));
	custom.insert(ft::make_pair(9, 'a'));
	custom.insert(ft::make_pair(10, 'a'));
	custom.insert(ft::make_pair(3, 'a'));
	custom.insert(ft::make_pair(4, 'a'));

	// base.insert(std::pair<int, char>(5, 'a'));
	// base.insert(std::pair<int, char>(2, 'a'));
	// base.insert(std::pair<int, char>(6, 'a'));
	// base.insert(std::pair<int, char>(7, 'a'));
	// base.insert(std::pair<int, char>(8, 'a'));
	// base.insert(std::pair<int, char>(1, 'a'));
	// base.insert(std::pair<int, char>(9, 'a'));
	// base.insert(std::pair<int, char>(10, 'a'));
	// base.insert(std::pair<int, char>(3, 'a'));
	// base.insert(std::pair<int, char>(4, 'a'));
	// custom.erase(8);
	custom.erase(1);
	custom.ptree();
	ft::map<int, char>::iterator i = custom.begin();
	ft::map<int, char>::iterator i2 = custom.end();

	while (i != i2)
	{
		std::cout<< i->first << "\n";
		i++;
	}
	// for (ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	// {
	// 	std::cout<< i->first << "|";
	// }
	// std::cout << std::endl;


	// custom.ptree();

	// for (ft::map<int, char>::iterator i = custom.begin(); i != custom.end(); i++)
	// {
	// 	std::cout<< i->first << "|";
	// }
	// ft::map<int, char> custom2(custom);

	// custom.nremove(4);
	// custom.nremove(5);
	// custom.nremove(10);
	// custom.nremove(2);


	// custom.nremove(4);

	// custom.printtest(custom.groot());
	
	// std::cout << "----------------\n";

	// // custom.setdbg(true);
	
	// for(ft::map<int, char>::iterator i = custom.end(); i != custom.begin(); i--)
	// {
	// 	std::cout << i->first << "|"<< i->second<< std::endl;
	// 	// std::cout << (*i).first << std::endl;
	// }

	// ft::map<int, char>::iterator i = custom.end();
	

	// while(--i != custom.end())
	// {
	// 	std::cout << i->first << std::endl;	
	// }

	// --i;
	
	
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// --i;
	// std::cout << i->first << std::endl;
	// 	--i;
	// std::cout << i->first << std::endl;
	// 	--i;
	// std::cout << i->first << std::endl;
	// 	--i;
	// std::cout << i->first << std::endl;
	// 	--i;
	// std::cout << i->first << std::endl;
	
	// i++;
	// std::cout << i->first << std::endl;
	// i++;
	// std::cout << i->first << std::endl;
	// i++;
	// std::cout << i->first << std::endl;
	// i++;
	// std::cout << i->first << std::endl;
	// i++;
	// 	std::cout << i->first << std::endl;
	// i++;
	// 	std::cout << i->first << std::endl;
	// i++;
	// 	std::cout << i->first << std::endl;
	// i++;
	// 		std::cout << i->first << std::endl;
	// i++;
	// 		std::cout << i->first << std::endl;
	// i++;
	// 		std::cout << i->first << std::endl;
	// i++;

	// std::cout << i->first << std::endl;
	// while (i != custom.end())
	// {
	// 	std::cout << (i)->first << std::endl;
	// 	i++;
	// }

	// for (; i != custom.end(); i++)
	// {
	// 	// std::cout << "loop" << std::endl;
	// 	// std::cout << i->first << std::endl;
	// }
	return 0;
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
	// custom.insert(ft::pair<int, char>(15, 'b'));
	// custom.insert(ft::pair<int, char>(10, 'b'));
	// custom.insert(ft::pair<int, char>(20, 'b'));	
	// custom.insert(ft::pair<int, char>(520, 'a'));
	// custom.insert(ft::pair<int, char>(540, 'a'));
	// custom.insert(ft::pair<int, char>(420, 'a'));
	// custom.insert(ft::pair<int, char>(690, 'a'));
	// custom.insert(ft::pair<int, char>(693, 'a'));
	// custom.insert(ft::pair<int, char>(692, 'a'));
	// custom.insert(ft::pair<int, char>(0, 'a'));


	// base.insert(std::pair<int, char>(15, 'b'));
	// base.insert(std::pair<int, char>(10, 'b'));
	// base.insert(std::pair<int, char>(20, 'b'));	
	// base.insert(std::pair<int, char>(520, 'a'));
	// base.insert(std::pair<int, char>(540, 'a'));
	// base.insert(std::pair<int, char>(420, 'a'));
	// base.insert(std::pair<int, char>(690, 'a'));
	// base.insert(std::pair<int, char>(693, 'a'));
	// base.insert(std::pair<int, char>(692, 'a'));
	// base.insert(std::pair<int, char>(0, 'a'));
	

	// // std::cout<<"--------------------------------\n\n";
	
	// ft::map<int, char>::iterator cit = custom.begin();
	// std::map<int, char>::iterator bit = base.begin();

	
	// while (cit != custom.end())
	// {
	// 	std::cout << (cit++)->first << "|";
	// }
	// std::cout << std::endl;
	// while (bit != base.end())
	// {
	// 	std::cout << (bit++)->first << "|";
	// }
	// std::cout << std::endl;

	// // // custom.printnode(custom.gend()->right);
	// // // custom.printnode(cit.getNode()->right);
	

	// // std::cout << std::endl;
	// // // std::cout << (--cit)->first << std::endl;
	// // // std::cout << (--bit)->first << std::endl;
	// while (--cit != custom.begin())
	// {
	// 	std::cout << (cit)->first << "|";
	// }
	// std::cout << std::endl;

	// while (--bit != base.begin())
	// {
	// 	std::cout << (bit)->first << "|";
	// }
	// std::cout << std::endl;
	// std::cout << (cit)->first << std::endl;
	// std::cout << (bit)->first << std::endl;
	// std::cout << bit->first << std::endl;

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