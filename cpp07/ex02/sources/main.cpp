/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:04 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/08/22 14:28:32 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../includes/Array.hpp"
#include "Array.tpp" // I guess I have to include it because it is a template?

#define NUM	5

int	main( void ) {

	try {

//Test 1: empty array
	std::cout << "--------------------------" << std::endl << "Test 1: empty array" << std::endl << std::endl;
	Array<int>	empty;
	std::cout << "Empty array created; size: " << empty.size() << std::endl;

//Test 2: int array
	std::cout << std::endl << "--------------------------" << std::endl << "Test 2: int array" << std::endl << std::endl;
	Array<int>	intArray(NUM);
	std::cout << intArray << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i + 1;
	std::cout << intArray << std::endl;
	
	std::cout << "Access third element: " << intArray[3] << std::endl;
	intArray[3] = 42;
	std::cout << "Access third element: " << intArray[3] << std::endl;
	
//	std::cout << intArray[NUM] << std::endl;

//Test 3: float array
	std::cout << std::endl << "--------------------------" << std::endl << "Test 3: float array" << std::endl << std::endl;
	Array<float>	floatArray(NUM);
	std::cout << floatArray << std::endl;

	for (unsigned int i = 0; i < floatArray.size(); i++)
		floatArray[i] = i + 1.42;
	std::cout << floatArray << std::endl;
	
	std::cout << "Access third element: " << floatArray[3] << std::endl;

//Test 4: char array
	std::cout << std::endl << "--------------------------" << std::endl << "Test 4: char array" << std::endl << std::endl;
	Array<char>	charArray(NUM);
	std::cout << charArray << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++)
		charArray[i] = i + 97;
	std::cout << charArray << std::endl;

//Test 5: copy array

	std::cout << std::endl << "--------------------------" << std::endl << "Test 5: copy array" <<  std::endl << std::endl;
	Array<char>	char2(charArray);
	std::cout << "old array:\t\t" << charArray << std::endl;
	std::cout << "new array:\t\t" << char2 << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++)
		char2[i] = i + 97 + NUM;
	std::cout << "modified new array:\t" << char2 << std::endl;
	std::cout << "old array:\t\t" << charArray << std::endl;

//Test 6: assignment operator

	std::cout << std::endl << "--------------------------" << std::endl << "Test 6: assignment operator" <<  std::endl << std::endl;
	charArray = char2;

	std::cout << "old array:\t" << charArray << std::endl;
	std::cout << "new array:\t" << char2 << std::endl;

//Test 7: modify an element
	std::cout << std::endl << "--------------------------" << std::endl << "Test 7: modify an element" <<  std::endl << std::endl;
	
	std::cout << charArray << std::endl;
	charArray[NUM - 1] = 'z';
	std::cout << "Last element: " << charArray[NUM - 1] << std::endl << std::endl;

	std::cout << intArray << std::endl;
	intArray[0] = 42;
	std::cout << "First element: " << intArray[0] << std::endl;	
	

	const Array<int>	constArray(intArray);

	std::cout << constArray << std::endl;
	std::cout << "First element: " << intArray[0] << std::endl;	
	//	constArray[0] = 0;

//Test 8: string array
	std::cout << std::endl << "--------------------------" << std::endl << "Test 8: string array" <<  std::endl << std::endl;

	Array<std::string>	strArray(NUM);

	std::string	word = "aw";
	for (unsigned int i = 0; i < strArray.size(); i++) {
		strArray[i] = word;
		word.append("w");
	}

	std::cout << strArray << std::endl;

	std::cout << std::endl << "--------------------------" << std::endl;

	}

	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}


	
	return 0;
}