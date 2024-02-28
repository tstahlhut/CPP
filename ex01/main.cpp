/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:10:52 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/02/27 12:40:46 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int	main(void)
{
	PhoneBook		phone_book;
	std::string		input;

	std::cout << "Program programming ... phonebook ..." << std::endl
		<< "Welcome to your Phone Book!" << std::endl
		<< "You have no contacts :(" << std::endl
		<< "You can ADD a new contact or EXIT." << std::endl;
	while (1)
	{
		std::cin >> input;
		if (input.compare(0,input.length(), "ADD") == 0)
			phone_book.add_contact();
			//std::cout << "You want to add a new contact. Great!" << std::endl;
		else if (input.compare(0,input.length(), "SEARCH") == 0)
			std::cout << "You want to search the phonebook." << std::endl;
		else if (input.compare(0,input.length(), "EXIT") == 0)
			return (0);
		std::cout << "--- MyPhoneBook: ADD, SEARCH or EXIT ..." << std::endl;
	}
	return (0);
}