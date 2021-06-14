#include <math.h>       /* fabs */
#include "../incl/list.hpp"
// #include "../vector/vector.hpp"
#include <iostream>
#include <vector>
// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

template <class T>
void advance(T &it, int n)
{
	while (n-- > 0)
		++it;
}


// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a predicate implemented as a function:
	bool single_digit (const int& value)
	{ return (value<10); }

	// a predicate implemented as a class:
	struct is_odd {
		bool operator() (const int& value) { return (value%2)==1; }
	};

	// a binary predicate implemented as a function:
	bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

int     main()
{
	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CONSTRUCTEUR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		// constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4,100);                       // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third

		// ft::list<int> fourth (second);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "The contents of fifth are: 16 2 77 29"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "The contents of fifth are: ";
		for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';

		std::cout << "\nThe contents of fifth are: ";
		ft::list<int>::iterator it;
		for (it = --fifth.end(); it != fifth.begin(); --it)
			std::cout << *it << ' ';
		std::cout << *it << ' ';

		std::cout << "\nsize list = " << fifth.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          OPERATEUR=" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> first (3);      // list of 3 zero-initialized ints
		ft::list<int> second (5);     // list of 5 zero-initialized ints

		second = first;
		first = ft::list<int>();

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Size of first: 0\nSize of second: 3"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          BEGIN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 75 23 65 42 13"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;

		ft::list<int>::iterator it;
		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it != mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

		std::cout << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          END" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 75 23 65 42 13"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
			std::cout << ' ' << *it;

		ft::list<int>::iterator it;
		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it != mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

		std::cout << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RBEGIN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist backwards: 5 4 3 2 1"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std::cout << ' ' << *rit;

		ft::list<int>::reverse_iterator it;
		std::cout << "\nmylist backwards:";
		for (it = --mylist.rend(); it != mylist.rbegin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

		std::cout << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          REND" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist backwards: 5 4 3 2 1"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;

		ft::list<int>::reverse_iterator it;
		std::cout << "\nmylist backwards:";
		for (it = --mylist.rend(); it != mylist.rbegin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

		std::cout << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          EMPTY" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		
		ft::list<int> mylist;
		int sum (0);

		for (int i=1;i<=10;++i) mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "total: 55"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

  		std::cout << "total: " << sum << '\n';
		  
		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

		std::cout << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> myints;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "0. size: 0\n1. size: 10\n2. size: 20\n3. size: 19"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.begin(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=myints.begin(); it != myints.end(); ++it)
			std::cout << ' ' << *it;

		ft::list<int>::iterator it;
		std::cout << "\nmylist contains:";
		for (it = --myints.end(); it != myints.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it << std::endl;

	}

	// std::cout << "\n\033[1;33m======================================================" << std::endl;
	// std::cout << "          MAX_SIZE" << std::endl;
	// std::cout << "======================================================\033[37m\n" << std::endl;
	// {

	// 	unsigned int i;
	// 	ft::list<int> mylist;

	// 	std::cout << "Enter number of elements: ";
	// 	std::cin >> i;

	// 	if (i<mylist.max_size()) mylist.resize(i);
	// 	else std::cout << "That size exceeds the limit.\n";

	// }

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          FRONT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;

		mylist.push_back(77);
		mylist.push_back(22);

		// now front equals 77, and back 22

		mylist.front() -= mylist.back();


		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist.front() is now 55"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist.front() is now " << mylist.front() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;

		mylist.push_back(10);

		while (mylist.back() != 0)
		{
			mylist.push_back ( mylist.back() -1 );
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 10 9 8 7 6 5 4 3 2 1 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin() ; --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          ASSIGN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> first;
		ft::list<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first

		int myints[]={1776,7,4};
		first.assign (myints,myints+3);            // assigning from array

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Size of first: 3\nSize of second: 7"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';

		std::cout << "mylist first:";
		for (ft::list<int>::iterator it=first.begin(); it!=first.end() ; ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist first:";
		ft::list<int>::iterator it;
		for (it = --first.end(); it!=first.begin() ; --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nmylist second:";
		for (ft::list<int>::iterator it=second.begin(); it!=second.end() ; ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist second:";
		for (it = --second.end(); it!=second.begin() ; --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          PUSH_FRONT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 300 200 100 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          POP_FRONT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Popping out the elements in mylist: 100 200 300\nFinal size of mylist is 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
			std::cout << ' ' << mylist.front();
			mylist.pop_front();
		}

		std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << std::endl;		

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          PUSH_BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		int myint;

		// std::cout << "Please enter some integers (enter 0 to end):\n";

		// do {
		// 	std::cin >> myint;
		// 	mylist.push_back (myint);
		// } while (myint);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);
	
		std::cout << "mylist stores " << mylist.size() << " numbers.\n";

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          POP_BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "The elements of mylist summed 600"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "The elements of mylist summed " << sum << '\n';
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          INSERT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		std::vector<int> myvector (2,30);
		mylist.insert (it,myvector.begin(),myvector.end());
													// 1 10 20 30 30 20 2 3 4 5
													//               ^

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 1 10 20 30 30 20 2 3 4 5"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          ERASE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		ft::list<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i) mylist.push_back(i*10);

									// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		advance (it2,6);            // ^                 ^
		++it1;                      //    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
									//    ^

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 10 30 60 80 90"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
			std::cout << ' ' << *it1;

		std::cout << "\nmylist contains:";
		for (it1 = --mylist.end(); it1!=mylist.begin(); --it1)
			std::cout << ' ' << *it1;
		std::cout << ' ' << *it1;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SWAP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> first (3,100);   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "first contains: 200 200 200 200 200 \nsecond contains: 100 100 100 "<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "first contains:";
		for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
			std::cout << ' ' << *it;

		std::cout << "\nfirst contains:";
		ft::list<int>::iterator it;
		for (it = --first.end(); it!=first.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << first.size() << std::endl;

		std::cout << "second contains:";
		for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;

		std::cout << "\nsecond contains:";
		for (it = --second.end(); it!=second.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << second.size() << std::endl;

		std::cout << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RESIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;

		// set some initial content:
		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 1 2 3 4 5 100 100 100 0 0 0 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CLEAR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;
		ft::list<int>::iterator it;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 100 200 300\nmylist contains: 1101 2202"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SPLICE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
										// mylist2 (empty)
										// "it" still points to 2 (the 5th element)
												
		mylist2.splice (mylist2.begin(),mylist1, it);
										// mylist1: 1 10 20 30 3 4
										// mylist2: 2
										// "it" is now invalid.
		it = mylist1.begin();
		advance(it,3);           // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
										// mylist1: 30 3 4 1 10 20

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist1 contains: 30 3 4 1 10 20\nmylist2 contains: 2"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
		
		std::cout << "\nmylist1 contains:";
		for (it = --mylist1.end(); it!=mylist1.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist1.size() << std::endl;

		std::cout << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			std::cout << ' ' << *it;
		
		std::cout << "\nmylist1 contains:";
		for (it = --mylist2.end(); it!=mylist2.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist2.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          REMOVE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		int myints[]= {17,89,7,14};
		ft::list<int> mylist (myints,myints+4);

		mylist.remove(89);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 17 7 14"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          REMOVE_IF" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		int myints[]= {15,36,7,17,20,39,4,1};
		ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

		mylist.remove_if (single_digit);           // 15 36 17 20 39

		mylist.remove_if (is_odd());               // 36 20

		

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 36 20"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          UNIQUE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
		ft::list<double> mylist (mydoubles,mydoubles+10);
		
		mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
									// 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
									// 15.3,  72.25, 73.0,  73.35

		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
											// 15.3,  72.25, 73.0

		mylist.unique (is_near());           //  2.72, 12.15, 72.25

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 2.72 12.15 72.25"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<double>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          MERGE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (3.7);
		second.push_back (7.1);
		second.push_back (1.4);

		first.sort();
		second.sort();

		first.merge(second);

		// (second is now empty)

		second.push_back (2.1);

		first.merge(second,mycomparison);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "first contains: 1.4 2.2 2.9 2.1 3.1 3.7 7.1"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "first contains:";
		for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;

				std::cout << "\nfirst contains:";
		ft::list<double>::iterator it;
		for (it = --first.end(); it!=first.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << first.size() << std::endl;

	}
	
	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SORT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<std::string> mylist;
		ft::list<std::string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: Three one two\nmylist contains: one Three two"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;
		
		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;		

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          REVERSE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> mylist;

		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.reverse();

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mylist contains: 9 8 7 6 5 4 3 2 1"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmylist contains:";
		ft::list<int>::iterator it;
		for (it = --mylist.end(); it!=mylist.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << mylist.size() << std::endl;

		std::cout << '\n';		

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RELATIONAL OPERATOR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		ft::list<int> b;
		b.push_back(10);
		b.push_back(20);
		b.push_back(30);
		ft::list<int> c;
		c.push_back(30);
		c.push_back(20);
		c.push_back(10);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a and b are equal\nb and c are not equal\nb is less than c\nc is greater than b\na is less than or equal to b\na is greater than or equal to b"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SWAP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::list<int> foo (3,100);   // three ints with a value of 100
		ft::list<int> bar (5,200);   // five ints with a value of 200

		ft::swap(foo,bar);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "foo contains: 200 200 200 200 200\nbar contains: 100 100 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "foo contains:";
		for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		
		std::cout << "\nfoo contains:";
		ft::list<int>::iterator it;
		for (it = --foo.end(); it!=foo.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << foo.size() << std::endl;

		std::cout << "bar contains:";
		for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nbar contains:";
		for (it = --bar.end(); it!=bar.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize list = " << bar.size() << std::endl;

	}


	return 0;
}