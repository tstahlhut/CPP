/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:13:00 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/12 17:08:02 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <list>

#define LENGTH	10

int	main( void ) {

	{	//Test 1: Vector container
		std::cout << "--------------------------" << std::endl << "Test 1: vector" << std::endl << std::endl;
	
		std::vector<int>	container;

		for (int i = 0; i < LENGTH; i++)
			container.push_back(i * 1);

		try {
			easyfind(container, 2);
			std::cout << "Value 2 found" << std::endl;
			easyfind(container, 7);
			std::cout << "Value 7 found" << std::endl;

			easyfind(container, -1);
			std::cout << "Value -1 found" << std::endl;
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
	}

	{	//Test 2: Deque container
		std::cout << "--------------------------" << std::endl << "Test 2: deque" << std::endl << std::endl;
	
		std::deque<int>	container;

		for (int i = 0; i < LENGTH; i++)
			container.push_back(i * 2);

		try {
			easyfind(container, 2);
			std::cout << "Value 2 found" << std::endl;
			easyfind(container, 7);
			std::cout << "Value 7 found" << std::endl;
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
	}

	{	//Test 3: List container
		std::cout << "--------------------------" << std::endl << "Test 3: list" << std::endl << std::endl;
	
		std::list<int>	container;

		for (int i = 0; i < LENGTH; i++)
			container.push_back(i * 3);

		try {
			easyfind(container, 6);
			std::cout << "Value 6 found" << std::endl;
			easyfind(container, 7);
			std::cout << "Value 7 found" << std::endl;
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;

}