/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:10:52 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 10:12:35 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

void	cin_error_handling()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int	main(void)
{
	PhoneBook		MyPhoneBook;
	std::string		input;

	while (1)
	{
		std::cin >> input;
		if (std::cin.eof()) //if ctrl-Z is pressed
			input = "exit";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == "ADD" || input == "add" || input == "Add")
			MyPhoneBook.addContact();
		else if (input == "SEARCH" || input == "search" || input == "Search")
			MyPhoneBook.searchContact();
		else if (input == "EXIT" || input == "exit" || input == "Exit")
			return (0);
		std::cout <<std::endl << "--- MyPhoneBook: ADD, SEARCH or EXIT ..." << std::endl;
	}
	return (0);
}