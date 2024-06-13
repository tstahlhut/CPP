/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:32:36 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/13 12:34:15 by tstahlhu         ###   ########.fr       */
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

		std::cout << "Print stack: " << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
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

	}
	return 0;
}