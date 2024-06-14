/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:32:36 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/14 13:10:57 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include "MutantStack.tpp"

#include <list>

int main( void )
{

// MutantStack Test
	{
		std::cout << "--------------------------" << std::endl << "MutantStack Test" << std::endl << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Top: " << mstack.top() << std::endl;

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		
		mstack.push(0);

		std::cout << "Size: " << mstack.size() << std::endl;

//Test 1: iterator begin & end
		std::cout << "--------------------------" << std::endl << "Test 1: iterator begin & end" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		*it = 7; // can be modified
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);

//Test 2: reverse iterators rbegin & rend
		std::cout << "--------------------------" << std::endl << "Test 2: reverse iterators rbegin & rend" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
	//	*rit = 2; // can be modified
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}

//Test 3: const iterators cbegin & cend
		std::cout << "--------------------------" << std::endl << "Test 3: const iterators cbegin & cend" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		MutantStack<int>::const_iterator cit = mstack.cbegin();
		MutantStack<int>::const_iterator cite = mstack.cend();
		++cit;
		--cit;
		//*cit = 2; //->cannot be modified
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}

//Test 4: const reverse iterators crbegin & crend
		std::cout << "--------------------------" << std::endl << "Test 4: const reverse iterators crbegin & crend" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
		MutantStack<int>::const_reverse_iterator crite = mstack.crend();
		++crit;
		--crit;
	//	*crit = 2; //->cannot be modified
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
	}

	// List Comparison
	std::cout << "--------------------------" << std::endl << "List Comparision" << std::endl << std::endl;

	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "Top: " << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << "Top: " << mstack.back() << std::endl;

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		
		mstack.push_back(0);

		std::cout << "Size: " << mstack.size() << std::endl;

//Test 1: iterator begin & end
		std::cout << "--------------------------" << std::endl << "Test 1: iterator begin & end" << std::endl << std::endl;

		std::cout << "Print stack: " << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

//Test 2: reverse iterators rbegin & rend
		std::cout << "--------------------------" << std::endl << "Test 2: reverse iterators rbegin & rend" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		std::list<int>::reverse_iterator rit = mstack.rbegin();
		std::list<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
	//	*rit = 2; // can be modified
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
/* //const iterators only work in C++11: out comment "-std=c++98" in Makefile to compile code below
//Test 3: const iterators cbegin & cend
		std::cout << "--------------------------" << std::endl << "Test 3: const iterators cbegin & cend" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		std::list<int>::const_iterator cit = mstack.cbegin();
		std::list<int>::const_iterator cite = mstack.cend();
		++cit;
		--cit;
		// *cit = 2; //->cannot be modified
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}

//Test 4: const reverse iterators crbegin & crend
		std::cout << "--------------------------" << std::endl << "Test 4: const reverse iterators crbegin & crend" << std::endl << std::endl;


		std::cout << "Print stack: " << std::endl;
		std::list<int>::const_reverse_iterator crit = mstack.crbegin();
		std::list<int>::const_reverse_iterator crite = mstack.crend();
		++crit;
		--crit;
	//	*crit = 2; //->cannot be modified
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
*/
	}


	return 0;
}