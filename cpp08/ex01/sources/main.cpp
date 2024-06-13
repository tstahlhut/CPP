/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:32:36 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/13 10:57:41 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

//#include <vector>

int	main( void ) {

	Span	test(42); //Span with 42 elements
		
//Test 0: Exceptions
	std::cout << "--------------------------" << std::endl << "Test 0: Exceptions" << std::endl << std::endl;

	try { 

	//Test exception if no element is in span
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << test << std::endl;
	}

	try {
	//add an element to Span
		test.addNumber(10);

	//Test exception if only one element is in span
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << test << std::endl;
	}

	try {
	//Test if range that should be added is too large
	std::deque<int>	range;

	for (int i = 0; i < 42; i++)
		range.push_back(i * 2);

	test.addRange(range.begin(), range.end());
	}
	
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << test << std::endl;
	}

	try {

	//Test exception if too many numbers are added
		for (int i = 0; i < 42; i++)
			test.addNumber(i);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << test << std::endl;
	}

//Test 1: subject
	std::cout << "--------------------------" << std::endl << "Test 1: subject" << std::endl << std::endl;

	try {
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() <<  std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << test << std::endl;
	}


//Test 2: addNumbers
	std::cout << "--------------------------" << std::endl << "Test 2: addNumbers" << std::endl << std::endl;

	Span	span(100000);

	try {
		for (int i = 0; i < 10001; i++)
			span.addNumber(i); //* 42);

		std::cout << span << std::endl;

		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;

		span.addNumber(1);
		span.addNumber(42000);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;

	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << test << std::endl;
	}

	
	return 0;
}