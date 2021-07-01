/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:34:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/07/01 18:56:35 by edal--ce         ###   ########.fr       */
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

void test()
{

	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::reverse_iterator it = vct.rbegin();


	std::vector<int> Svct(size);
	std::vector<int>::reverse_iterator Sit = Svct.rbegin();
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
	{

		it[i] = (size - i) * 5;
		Sit[i] = (size - i) * 5;
	}

	it = it + 5;
	it = 1 + it;
	it = it - 4;

	Sit = Sit + 5;
	Sit = 1 + Sit;
	Sit = Sit - 4;
	
	std::cout << *(it ) << std::endl;
	std::cout << *(Sit ) << std::endl;
	// std::cout << *(it -= 1) << std::endl;
	// std::cout << *(it += 2) << std::endl;
	// std::cout << *(it -= 1) << std::endl;

	// *(it -= 2) = 42;
	// *(it += 2) = 21;

	// std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	// std::cout << "(it == const_it): " << (ite == it) << std::endl;
	// std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	// std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	print2(Svct, vct);
	// return (0);
	
	
}




int main()
{

	// whathefuck();
	// htest();
  
	test();
	return 0;
	// ft::vector<int> custom;
	// std::vector<int> base;


	// for (int i = 0; i < 10; i++)
	// {
	// 	custom.push_back(i);
	// 	base.push_back(i);
	// }

	// ft::vector<int>::reverse_iterator cit = custom.rbegin();//, cite = custom.rend();
	// std::vector<int>::reverse_iterator bit = base.rbegin();//, bite = base.rend();

	// // for (; cit != cite; ++cit)
	// // 	*cit = (cite - cit);
	// // for (; bit != bite; ++bit)
	// // 	*bit = (bite - bit);


	// print2(base, custom);

	// // std::cout << "C from :" << &(*custom.begin()) << " to " << &(*custom.end()) << std::endl;
	// // std::cout << "B from :" << &(*base.begin()) << " to " << &(*base.end()) << std::endl;

	// // std::cout << "custom :" << &(*cit) << "|\n";// << *cite << std::endl;
	// // std::cout << "base :" << &(*bit) << "|\n";// << *bite << std::endl;

	// if (cit == custom.rend())
	// {
	// 	std::cout << "cite is end " << std::endl;
	// 	// std::cout << *(--(--cite)) << std::endl;
	// }
	// if (bit == base.rend())
	// {
	// 	std::cout << "bite is end " << std::endl;
	// 	// std::cout << *(--(--bite)) << std::endl;
	// }

	// bit = base.begin();
	// cit = custom.begin();
	// print2(base,custom);
	// ft::vector<int> custom_vct_range(cit, --(cite));
	// std::vector<int> base_vct_range(bit, --(bite));
	// --cite;
	// --bite;
	
	// std::cout << *(cit - 0) << std::endl;
	// std::cout << *(bit - 0)  << std::endl;
	// // for (int i = 0; bit != bite; ++bit)
	// // 	*bit = ++i * 5;
	// // for (int i = 0; cit != cite; ++cit)
	// // 	*cit = ++i * 5;


	// print2(base, custom);

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