/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/01 15:44:52 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/list.hpp"
#include "../incl/vector.hpp"
#include "../incl/stack.hpp"

#include <vector>

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

void whathefuck()
{
	ft::vector<int> custom(5);
	std::vector<int> base(5);

	ft::vector<int>::iterator cit = custom.begin(), cite = custom.end();
	std::vector<int>::iterator bit = base.begin(), bite = base.end();

	std::cout << "len: " << (cite - cit) << std::endl;
	for (; cit != cite; ++cit)
		*cit = (cite - cit);

	std::cout << "len: " << (bite - bit) << std::endl;
	for (; bit != bite; ++bit)
		*bit = (bite - bit);

	// for (int i = 0; i < 10; i++)
	// {
	// 	custom.push_back(i);
	// 	base.push_back(i);
	// }


	ft::vector<int> ccustom(custom);
	std::vector<int> cbase(base);




	print2(cbase, ccustom);
	print2(cbase, ccustom);

}

// void test()
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

// 	std::cout << "len: " << (ite - it) << std::endl;
// 	for (; it != ite; ++it)
// 		*it = (ite - it);

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 5;

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 7;
// 	vct_copy.push_back(42);
// 	vct_copy.push_back(21);

// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);

// 	vct = vct_copy;
// 	vct_copy = vct_range;
// 	vct_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);
// 	return (0);
// }




int main()
{

	// whathefuck();
	// htest();
  
	// return 0;
	ft::vector<int> custom(10);
	std::vector<int> base(10);

	ft::vector<int>::iterator cit = custom.begin(), cite = custom.end();
	std::vector<int>::iterator bit = base.begin(), bite = base.end();

	for (; cit != cite; ++cit)
		*cit = (cite - cit);
	for (; bit != bite; ++bit)
		*bit = (bite - bit);


	print2(base, custom);

	// std::cout << "C from :" << &(*custom.begin()) << " to " << &(*custom.end()) << std::endl;
	// std::cout << "B from :" << &(*base.begin()) << " to " << &(*base.end()) << std::endl;

	// std::cout << "custom :" << &(*cit) << "|\n";// << *cite << std::endl;
	// std::cout << "base :" << &(*bit) << "|\n";// << *bite << std::endl;

	if (cite == custom.end())
	{
		std::cout << "cite is end " << std::endl;
		// std::cout << *(--(--cite)) << std::endl;
	}
	if (bite == base.end())
	{
		std::cout << "bite is end " << std::endl;
		// std::cout << *(--(--bite)) << std::endl;
	}

	// bit = base.begin();
	// cit = custom.begin();
	// print2(base,custom);
	// ft::vector<int> custom_vct_range(cit, --(cite));
	// std::vector<int> base_vct_range(bit, --(bite));
	--(--cite);
	--(--bite);
	// --cite;
	// --bite;
	
	std::cout << *cite << std::endl;
	std::cout << *bite << std::endl;
	// for (int i = 0; bit != bite; ++bit)
	// 	*bit = ++i * 5;
	// for (int i = 0; cit != cite; ++cit)
	// 	*cit = ++i * 5;


	print2(base, custom);

	// for (int i = 0; cit != cite; ++cit)
	// 	*cit = ++i * 5;

	// for (int i = 0; bit != bite; ++bit)
	// 	*bit = ++i * 5;


	// print2(base_vct_range, custom_vct_range);
	// std::cout << *cit << "|" << *--(--cite) << std::endl;
	// std::cout << *bit << "|" << *--(--bite) << std::endl;


	// whathefuck();
	return 0;








	return 0;
}