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
	PhoneBook		MyPhoneBook;
	std::string		input;

	std::cout << "Program programming ... phonebook ..." << std::endl
		<< "Welcome to your Phone Book!" << std::endl
		<< "You have no contacts :(" << std::endl
		<< "You can ADD a new contact or EXIT." << std::endl;
	while (1)
	{
		std::cin >> input;
		if (input == "ADD" || input == "add" || input == "Add")
			MyPhoneBook.addContact();
			//std::cout << "You want to add a new contact. Great!" << std::endl;
		else if (input == "SEARCH" || input == "search" || input == "Search")
			MyPhoneBook.searchContact();
		else if (input == "EXIT" || input == "exit" || input == "Exit")
			return (0);
		std::cout << "--- MyPhoneBook: ADD, SEARCH or EXIT ..." << std::endl;
	}
	return (0);
}