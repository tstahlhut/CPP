/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:05:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 12:53:57 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this source file the PhoneBook class is defined.

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	//std::cout << "construtor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "destructor called" << std::endl;
	return;
}

int	PhoneBook::numberContacts = 0;

void	PhoneBook::addContact(void)
{
	int	index;

	index = this->numberContacts;
	if (index >= 7)
		index -= 7;
	this->contacts[index].setFirstName();
	this->contacts[index].setLastName();
	this->contacts[index].setNickname();
	this->contacts[index].setPhoneNumber();
	this->contacts[index].setDarkestSecret();	

	if (this->numberContacts < 8)
		this->numberContacts += 1;
	std::cout << "New contact successfully added! You now have " 
			<< this->numberContacts << " contact(s)." << std::endl;
	
	return ;
}

void	PhoneBook::searchContact(void)
{
	int	inputIndex;

	if (numberContacts == 0)
	{
		std::cout << "You have no contacts in your phonebook. ADD a contact first, to search." << std::endl;
		return ;
	}

	this->printContactList();
	std::cout << "Who's your favourite? Enter index of contact you would like to display" << std::endl;
	std:: cin >> inputIndex;
	while (std::cin.fail() || inputIndex < 1 || inputIndex > this->numberContacts)
	{
		std::cout << "Typo? This index does not exist in your phonebook." << std::endl << std::endl;
		std::cout << "Please try again:" << std::endl;
		std::cin.clear();
		std::cin.ignore();
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
	while (i < this->numberContacts)
	{
		//Contact row
		std::cout << std::setw(10)<< i + 1 << std::setw(1) << columnSeparator;
		this->printContactInfo(contacts[i].getFirstName());
		this->printContactInfo(contacts[i].getLastName());
		this->printContactInfo(contacts[i].getNickname());
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
	std::cout << std::setw(16) << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << std::setw(16) << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << std::setw(16) << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << std::setw(16) << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << std::setw(16) << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
	return ;
}