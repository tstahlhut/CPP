/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:07:44 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/02/27 13:10:31 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//In this source file the Contact class is defined.

#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>
#include "Contact.class.hpp"

// Definition of the constructor
Contact::Contact(void)
{
	//this->set_first_name();
	/*std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickame: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;*/
	return;
}

//Definition of destructor
Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return;
}

// Setter functions

void	Contact::setFirstName(void)
{
	int	i = 1;

	while (i)
	{
		std::cout << "Enter First Name: " << std::endl;
		std::cin >> this->_firstName;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "You entered: " << this->_firstName << std::endl;
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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "You entered: " << this->_lastName << std::endl;
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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "You entered: " << this->_nickname << std::endl;
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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "You entered: " << this->_phoneNumber << std::endl;
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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "You entered: " << this->_darkestSecret<< std::endl;
		i = 0;
	}
	return;
}

/* Notes:
	If I use std::cin to read input, the whitespaces at the beginning
	will be ignored. This means that only hitting enter has no effect
	other than it proves a newline in the terminal.
	To change that behavior, you can add: std::cin >> std::noskipws;
	*/

//getter functions

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string	Contact::getNickname() const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}