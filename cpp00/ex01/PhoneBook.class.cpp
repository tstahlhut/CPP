/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:05:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 10:17:30 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this source file the PhoneBook class is defined.

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << std::endl << std::endl
		<< "Welcome to your Phone Book!" << std::endl << std::endl
		<< "        You have no contacts :(" << std::endl
		<< "        You can ADD a new contact or EXIT." << std::endl;

	this->_numberContacts = 0;
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "destructor called" << std::endl;
	return;
}

void	PhoneBook::addContact(void)
{
	this->_contacts[_index % 8].setFirstName();
	this->_contacts[_index % 8].setLastName();
	this->_contacts[_index % 8].setNickname();
	this->_contacts[_index % 8].setPhoneNumber();
	this->_contacts[_index % 8].setDarkestSecret();

	this->_index += 1;

	if (this->_numberContacts < 8)
		this->_numberContacts += 1;
	std::cout << "New contact successfully added! You now have " 
			<< this->_numberContacts << " contact(s)." << std::endl;
	
	return ;
}

void	PhoneBook::searchContact(void)
{
	int	inputIndex;

	if (_numberContacts == 0)
	{
		std::cout << "You have no contacts in your phonebook. ADD a contact first, to search." << std::endl;
		return ;
	}

	this->printContactList();
	std::cout << "Who's your favourite? Enter index of contact you would like to display:" << std::endl;
	std:: cin >> inputIndex;
	while (std::cin.fail() || inputIndex < 1 || inputIndex > this->_numberContacts)
	{
		if (std::cin.eof())
			return ;
		std::cout << std::endl << "Typo? This index does not exist in your phonebook." << std::endl;
		this->printContactList();
		std::cout << "Please try again:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> inputIndex;
	}
	this->displayContact(inputIndex);
	return ;
}

void	PhoneBook::printContactList(void)
{
	int	i = 0;
	const char	columnSeparator = '|';

//Header row
	std::cout << std::right << std::endl;
	std::cout << std::setw(10) << "index" << std::setw(1) << columnSeparator
		<< std::setw(10) << "First Name" << std::setw(1) << columnSeparator
		<< std::setw(10) << "Last Name" << std::setw(1) << columnSeparator 
		<< std::setw(10) << "Nickname" << std::setw(1) << columnSeparator << std::endl << std::endl;
	while (i < this->_numberContacts)
	{
		//Contact row
		std::cout << std::setw(10)<< i + 1 << std::setw(1) << columnSeparator;
		this->printContactInfo(_contacts[i].getFirstName());
		this->printContactInfo(_contacts[i].getLastName());
		this->printContactInfo(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	return ;

}


void	PhoneBook::printContactInfo(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += '.';
	}

	std::cout << std::setw(10) << str << std::setw(1) << '|';
	return ;
}

void	PhoneBook::displayContact(int index)
{
	index -= 1;

	std::cout << std::left << std::endl;
	std::cout << std::setw(16) << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << std::setw(16) << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << std::setw(16) << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << std::setw(16) << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << std::setw(16) << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
	return ;
}