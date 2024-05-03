/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:07:44 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 10:23:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//In this source file the Contact class is defined.

#include "Contact.class.hpp"

// Definition of the constructor
Contact::Contact(void)
{
	//std::cout << "Contact constructor called" << std::endl;
	return;
}

//Definition of destructor
Contact::~Contact(void)
{
	//std::cout << "Contact destructor called" << std::endl;
	return;
}

// Setter functions
// better to not use cin in the setter functions and use cin in the phonebook class
void	Contact::setFirstName(void)
{
	int	i = 1;

	while (i)
	{
		std::cout << "Enter First Name: " << std::endl;
		std::cin >> this->_firstName;
		// clear error flag in case cin failed
		std::cin.clear();
		//ignore everything until next newline (i.e. clear buffer)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		i = 0;
	}
	return;
}

void	Contact::setLastName(void)
{
	int	i = 1;

	while (i)
	{
		std::cout << "Enter Last Name: " << std::endl;
		std::cin >> this->_lastName;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		i = 0;
	}
	return;
}

void	Contact::setNickname(void)
{
	int	i = 1;

	while (i)
	{
		std::cout << "Enter Nickname: " << std::endl;
		std::cin >> this->_nickname;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		i = 0;
	}
	return;
}

void	Contact::setPhoneNumber(void)
{
	int	i = 1;

	while (i)
	{
		std::cout << "Enter phone number: " << std::endl;
		std::cin >> this->_phoneNumber;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		i = 0;
	}
	return;
}

void	Contact::setDarkestSecret(void)
{
	int	i = 1;

	while (i)
	{
		std::cout << "Enter the person's darkest secret: " << std::endl;
		std::cin >> this->_darkestSecret;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		i = 0;
	}
	return;
}

//getter functions

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}


/* Notes:
	If I use std::cin to read input, the whitespaces at the beginning
	will be ignored. This means that only hitting enter has no effect
	other than it proves a newline in the terminal.
	To change that behavior, you can add: std::cin >> std::noskipws;
	The cin buffer has to be cleared with 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Otherwise, if you enter for example two names when prompted to enter the first
	name, the second one will be assigned to last name directly without prompting
	for input first. 
	*/